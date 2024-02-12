#include "flags.h"

#include <stdio.h>
#include <string.h>

void printFile(char *name, Flags *flag) {
  if (name[0] != '-') {
    FILE *f = fopen(name, "r");
    if (f != NULL) {
      while ((flag->c = fgetc(f)) != EOF) {
        flag->isPrint = 1;
        flagS(flag);
        flagB(flag);
        flagN(flag);
        flagE(flag);
        flagV(flag);
        flagT(flag);
        flag->prev = flag->c;
        flag->isFirst = 0;
        if (flag->isPrint == 1) {
          putc(flag->c, stdout);
        } else
          flag->c = 0;
      }
    } else {
      fclose(f);
      return;
    }
    fclose(f);
  } else {
    return;
  }
  return;
}

void parsFlag(char *name, Flags *flag) {
  if ((name[0] == '-') && (name[1] != '-')) {
    if (strchr(name, 'b') != NULL) flag->b = 1;
    if (strchr(name, 'e') != NULL) {
      flag->E = 1;
      flag->v = 1;
    }
    if (strchr(name, 'n') != NULL) flag->n = 1;
    if (strchr(name, 't') != NULL) {
      flag->T = 1;
      flag->v = 1;
    }
    if (strchr(name, 's') != NULL) flag->s = 1;
    if (strchr(name, 'T') != NULL) flag->T = 1;
    if (strchr(name, 'E') != NULL) flag->E = 1;
    if (strchr(name, 'v') != NULL) flag->v = 1;
  } else if ((name[0] == '-') && (name[1] == '-')) {
    if (strcmp(name, "--number-nonblank") == 0) flag->b = 1;
    if (strcmp(name, "--number") == 0) flag->n = 1;
    if (strcmp(name, "--squeeze-blank") == 0) flag->s = 1;
  } else {
    return;
  }
}

void printNum(Flags *flag) {
  printf("%6d\t", ++flag->num);
  return;
}

void flagV(Flags *flag) {
  if (flag->v == 1) {
    if ((flag->c >= 0) && (flag->c < 32) && (flag->c != 9) && (flag->c != 10)) {
      printf("^%c", flag->c + 64);
      flag->isPrint = 0;
    }
    if (flag->c == 127) {
      printf("^%c", flag->c - 64);
      flag->isPrint = 0;
    }
    if ((flag->c >= 128) && (flag->c <= 159)) {
      printf("M-^%c", flag->c - 64);
      flag->isPrint = 0;
    }
    if ((flag->c >= 160) && (flag->c <= 255)) {
      printf("M-%c", flag->c - 128);
      flag->isPrint = 0;
    }

  } else {
    return;
  }
  return;
}

void flagB(Flags *flag) {
  if (flag->b == 1) {
    if ((flag->c != '\n') && (flag->prev == '\n') && (flag->eLines == 0))
      printNum(flag);
    if ((flag->isFirst == 1) && (flag->c != '\n')) {
      flag->isFirst = 0;
      printNum(flag);
    }
  } else {
    return;
  }
  return;
}

void flagN(Flags *flag) {
  if (flag->n == 1) {
    if (flag->prev == '\n' && flag->eLines == 0) printNum(flag);
    if (flag->isFirst == 1) {
      printNum(flag);
      flag->isFirst = 0;
    }
  } else {
    return;
  }
  return;
}

void flagE(Flags *flag) {
  if (flag->E == 1) {
    if (flag->c == '\n' && flag->isPrint == 1) printf("$");
  } else {
    return;
  }
  return;
}

void flagT(Flags *flag) {
  if (flag->T == 1) {
    if (flag->c == 9) {
      printf("^I");
      flag->isPrint = 0;
    }
  } else {
    return;
  }
  return;
}

void flagS(Flags *flag) {
  if (flag->s == 1) {
    if ((flag->c != '\n') && (flag->prev == '\n') && (flag->eLines == 1)) {
      flag->eLines = 0;
      flag->isPrint = 1;
    }
    if ((flag->c == '\n') && (flag->prev == '\n') && (flag->eLines == 1)) {
      flag->isPrint = 0;
    }
    if ((flag->c == '\n') && (flag->prev == '\n') && (flag->eLines == 0)) {
      flag->eLines = 1;
    } else {
      return;
    }
    return;
  }
}