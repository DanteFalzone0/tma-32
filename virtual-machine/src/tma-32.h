#ifndef TMA_32_H
#define TMA_32_H

#include <vector>
#include <cstdint>

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
  uint32_t r0;
  uint32_t r1;
  uint32_t r2;
  uint32_t r3;
  uint32_t r4;
  uint32_t r5;
  uint32_t r6;
  uint32_t r7;
  uint32_t r8;
  uint32_t r9;
  uint32_t r10;
  uint32_t r11;
  uint32_t r12;
  uint32_t r13;
  uint32_t r14;
  uint32_t r15;

public:
  vm(const char *file_path);

};

} // end of namespace

#endif
