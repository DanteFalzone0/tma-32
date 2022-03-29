#include <iostream>
#include "tma32.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "error: no file specified\n";
    return 1;
  }

  tma32::vm machine(argv[1]);

  return 0;
}
