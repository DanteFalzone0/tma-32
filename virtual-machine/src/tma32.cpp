#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdint>
#include "tma32.h"

tma32::VirtualMachine::VirtualMachine(const char* file_path) {
  auto bytecode_file = std::ifstream(file_path, std::ios::binary);
  uint32_t current_word;
  while (bytecode_file.read(reinterpret_cast<char*>(&current_word), sizeof(current_word))) {
    this->memory.push_back(current_word);
  }
  this->ip = 0;
  this->sp = this->memory.size();
  this->memory.push_back(0); // make sure there's valid data at the address to which sp points
  /* initialize registers to zero */
  for (int i = 0; i < this->registers.size(); i++) {
    this->registers[i] = 0;
  }
  this->error = false;
}

void tma32::VirtualMachine::execute(void) {
  while (!this->error) {
    uint32_t current_instruction = this->memory[this->ip];
    /* To better understand why these variables are named like this,
       read instructions.txt in the assembler/ directory. */
    uint8_t opcode     = (current_instruction & 0xFF000000) >> 24u;
    uint8_t dest_reg   = (current_instruction & 0x00FF0000) >> 16u;
    uint8_t src_reg    = (current_instruction & 0x0000FF00) >> 8u;
    uint8_t target_reg = (current_instruction & 0x000000FF);
    switch (opcode) {
      case 0x41u: // movl
        this->registers[dest_reg] = this->memory[this->ip + 1];
        this->ip += 2;
      break;
      case 0x42u: // movr
        this->registers[dest_reg] = this->registers[src_reg];
        this->ip++;
      break;
      case 0x43u: // jmp
        this->ip = this->registers[target_reg];
      break;
      case 0x44u: // jeq
        if (this->registers[dest_reg] == this->registers[src_reg]) {
          this->ip = this->registers[target_reg];
        } else {
          this->ip++;
        }
      break;
      case 0x45u: // jz
        if (!this->registers[dest_reg]) {
          this->ip = this->registers[target_reg];
        } else {
          this->ip++;
        }
      break;
      case 0x46u: // addu
        this->registers[dest_reg] += this->registers[src_reg];
        this->ip++;
      break;
      case 0x47u: { // addi
        int32_t dest_reg_i, src_reg_i;
        std::memcpy(&dest_reg_i, &this->registers[dest_reg], sizeof(int32_t));
        std::memcpy(&src_reg_i, &this->registers[src_reg], sizeof(int32_t));
        int32_t result_i = dest_reg_i + src_reg_i;
        std::memcpy(&this->registers[dest_reg], &result_i, sizeof(int32_t));
        this->ip++;
      }; break;
      case 0x48u: { // addf
        static_assert(
          sizeof(uint32_t) == sizeof(float),
          "Platform does not have 32-bit floats for some reason???"
        );
        float dest_reg_f, src_reg_f;
        std::memcpy(&dest_reg_f, &this->registers[dest_reg], sizeof(float));
        std::memcpy(&src_reg_f, &this->registers[src_reg], sizeof(float));
        float result_f = dest_reg_f + src_reg_f;
        std::memcpy(&this->registers[dest_reg], &result_f, sizeof(float));
        this->ip++;
      }; break;
      /* TODO implement prnt* instructions */
      default:
        std::cerr << "Invalid instruction 0x";
        std::cerr << std::hex << std::uppercase << static_cast<unsigned int>(opcode) << "\n";
        this->error = true;
    }
    if (this->ip == this->memory.size()) {
      std::cerr << "Reached end of code without encountering a `halt` instruction.\n";
      this->error = true;
    }
  }
}

void tma32::VirtualMachine::print_registers(void) {
  std::cout << "========\n";
  std::cout << std::hex << std::uppercase;
  std::cout << "Instruction pointer: 0x" << this->ip << "\n";
  std::cout << "Stack pointer: 0x" << this->sp << "\n";
  for (int i = 0; i < this->registers.size(); i++) {
    std::cout << "r" << std::dec << i << ": 0x" << std::hex << this->registers[i] << "\n";
  }
}
