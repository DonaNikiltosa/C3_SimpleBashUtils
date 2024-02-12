#include <stdio.h>

typedef struct {
  int b;
  int E;
  int n;
  int T;
  int s;
  int v;
  int c;
  int prev;
  int num;
  int eLines;
  int isFirst;
  int isPrint;
} Flags;

void printFile(char *name, Flags *flag);
void parsFlag(char *name, Flags *flag);
void printNum(Flags *flag);
void flagV(Flags *flag);
void flagB(Flags *flag);
void flagN(Flags *flag);
void flagE(Flags *flag);
void flagT(Flags *flag);
void flagS(Flags *flag);
