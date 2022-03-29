#ifndef TMA32_H
#define TMA32_H

#include <vector>
#include <cstdint>
#include <array>

namespace tma32 {

// class representing the TMA-32 Virtual Machine
class vm {

private:
  // RAM
  std::vector<uint32_t> memory;

  // instruction pointer
  uint32_t ip;

  // stack pointer
  uint32_t sp;

  // registers
  std::array<uint32_t,16> registers;

public:
  vm(const char *file_path);

};

} // end of namespace

#endif
