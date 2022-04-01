#ifndef TMA32_H
#define TMA32_H

#include <vector>
#include <stack>
#include <cstdint>
#include <array>

namespace tma32 {

// class representing the TMA-32 Virtual Machine
class VirtualMachine {

private:
  bool error;

  // RAM
  std::vector<uint32_t> memory;

  // instruction pointer
  uint32_t ip;

  // stack pointer
  uint32_t sp;

  // registers
  std::array<uint32_t, 16> registers;

public:
  VirtualMachine(const char* file_path);
  void execute(void);
  void print_registers(void);
};

} // end of namespace

#endif
