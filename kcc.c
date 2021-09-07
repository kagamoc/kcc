#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  char *p = argv[1];

  printf(".text\n");
  printf("  .globl main\n");
  printf("main:\n");
  printf("  mov x0, #%d\n", strtol(p, &p, 10));

  while (*p) {
    if (*p == '+') {
      p++;
      printf("  add x0, x0, #%d\n", strtol(p, &p, 10));
      continue;
    }

    if (*p == '-') {
      p++;
      printf("  sub x0, x0, #%d\n", strtol(p, &p, 10));
      continue;
    }

    fprintf(stderr, "予期しないエラーです: '%c'\n", *p);
    return 1;
  }

  printf("  mov x8, #93\n");
  printf("  svc #0\n");
  return 0;
}

