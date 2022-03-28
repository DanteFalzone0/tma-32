#include <iostream>
#include "tma-32.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "error: no file specified\n";
    return 1;
  }

  auto machine = tma32::vm(argv[1]);

  return 0;
}
