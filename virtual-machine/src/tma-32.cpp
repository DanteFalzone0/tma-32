#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include "tma-32.h"

tma32::vm::vm(const char *file_path) {
    auto bytecode_file = std::ifstream(file_path, std::ios::binary);
    uint32_t current_word;
    while (bytecode_file.read(reinterpret_cast<char*>(&current_word), sizeof(current_word))) {
      std::cout << current_word << "\n";
      this->memory.push_back(current_word);
    }
}
