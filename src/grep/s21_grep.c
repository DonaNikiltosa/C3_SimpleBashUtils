#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"

int main(int argc, char** argv) {
  arguments arg = arguments_parser(argc, argv);
  output(arg, argc, argv);
  free(arg.pattern);
  return 0;
}