#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arguments {
  int e, i, v, c, l, n, h, s, f, o;
  char* pattern;
  int len_pattern;
  int mem_pattern;
} arguments;

void pattern_adding(arguments* arg, char* pattern);
void add_reg_from_file(arguments* arg, char* filepath);
arguments arguments_parser(int argc, char* argv[]);
void output_line(char* line, int n);
void print_match(regex_t* re, char* line);
void processFile(arguments arg, char* path, regex_t* reg);
void output(arguments arg, int argc, char** argv);