#include <stdio.h>
#include <string.h>

typedef struct{
  int b;
  int e;
  int E;
  int n;
  int t;
  int T;
  int s;
  int v;
  char prev;
  int num;
  int eLines;

}Flags;
void printFile(char *name, Flags *flag);
void parsFlag(char *name, Flags *flag);
void printNum(Flags *flag, char c);

int main(int argc, char **argv) {
  Flags *flag;
  for (int i = 1; i < argc; i++) {
    parsFlag(argv[i], flag);
    printFile(argv[i], flag);
  }
}
void printFile(char *name, Flags *flag) {
  FILE *f = fopen(name, "rt");

  if (f != NULL) {
    char c;
    c = fgetc(f);
    if ((c!='\n') && (flag->b == 1)) printNum(flag, c);
    if (flag->n == 1) printNum(flag, c);
    else {putc(c, stdout);}
    while (c != EOF) {
      c = fgetc(f);
      if ((c != '\n') && (flag->b == 1) && (flag->prev == '\n')) printNum(flag, c);
      if ((c == '\n') && (flag->E == 1)) printf("$\n");
      if ((c == '\t') && (flag->T == 1)) printf("^I");
      if ((flag->prev == '\n') && (flag->n == 1)) printNum(flag, c);
      if ((flag->s == 1) && (c == '\n') && (flag->prev == '\n')) {
        flag->eLines = 1;
        putc(c, stdout);
      }
      if ((flag->s == 1) && (c == '\n') && (flag->prev == '\n') && (flag->eLines == 1)) continue;
      if ((flag->s == 1) && (c != '\n') && (flag->prev == '\n') && (flag->eLines == 1)) {
        flag->eLines = 0;
        putc(c, stdout);
      }
      if ((flag->e == 1) && (c >= 0) && (c < 32) && (c != 9) && (c != 10)) printf("^%c", c+64);
      if ((flag->e == 1) && (c == 127)) printf("^%c", c-64);
      if ((flag->e == 1) && (c > 127) && (c < 160)) printf("M-^%c", c-64);
      if ((flag->e == 1) && (c > 159) && (c < 256)) printf("M-%c", c-128);
      if ((c == '\n') && (flag->e == 1)) printf("$\n");
      if ((flag->t == 1) && (c >= 0) && (c < 32) && (c != 9) && (c != 10)) printf("^%c", c+64);
      if ((flag->t == 1) && (c == 127)) printf("^%c", c-64);
      if ((flag->t == 1) && (c > 127) && (c < 160)) printf("M-^%c", c-64);
      if ((flag->t == 1) && (c > 159) && (c < 256)) printf("M-%c", c-128);
      if ((c == '\t') && (flag->t == 1)) printf("^I");


      else {putc(c, stdout);}
      flag->prev = c;
    }
  }
  fclose(f);
}

void parsFlag(char *name, Flags *flag) {
  if ((strcmp(name, "-b") == 0) || (strcmp(name, "--number-nonblank") == 0)) flag->b = 1;
  if (strcmp(name, "-e") == 0) flag->e = 1;
  if ((strcmp(name, "-n") == 0) || (strcmp(name, "--number") == 0)) flag->n = 1;
  if (strcmp(name, "-t") == 0) flag->t = 1;
  if ((strcmp(name, "-s") == 0) || (strcmp(name, "--squeeze-blank") == 0)) flag->s = 1;
  if (strcmp(name, "-T") == 0) flag->T = 1;
  if (strcmp(name, "-E") == 0) flag->E = 1;
  else {return;}
  return;
}

void printNum(Flags *flag, char c) {
  printf("%3d  %c", ++flag->num, c);
  return;
}