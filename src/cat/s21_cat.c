#include <stdio.h>
#include <string.h>

#include "flags.h"

int main(int argc, char **argv) {
  Flags flag = {};
  flag.isFirst = 1;
  for (int i = 1; i < argc; i++) {
    parsFlag(argv[i], &flag);
  }
  if ((flag.b == 1) && (flag.n == 1)) flag.n = 0;
  for (int i = 1; i < argc; i++) {
    printFile(argv[i], &flag);
  }
  return 0;
}