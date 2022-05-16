#include <stdio.h>
#include <unistd.h>

#define REGS_FOREACH(_)  _(X) _(Y)
#define OUTS_FOREACH(_)  _(A) _(B) _(C) _(D) _(E) _(F) _(G)
#define RUN_LOGIC        X1 = !X && Y; \
                         Y1 = !X && !Y; \
                         A  = (!X && !Y) || (X && !Y); \
                         B  = 1; \
                         C  = (!X && !Y) || (!X && Y); \
                         D  = (!X && !Y) || (X && !Y); \
                         E  = (!X && !Y) || (X && !Y); \
                         F  = (!X && !Y); \
                         G  = (X && !Y); 

#define DEFINE(X)   static int X, X##1;
#define UPDATE(X)   X = X##1;
#define PRINT(X)    printf(#X " = %d; ", X);

int main() {
  REGS_FOREACH(DEFINE);
  OUTS_FOREACH(DEFINE);
  while (1) { // clock
    RUN_LOGIC;
    OUTS_FOREACH(PRINT);
    REGS_FOREACH(UPDATE);
    putchar('\n');
    fflush(stdout);
    sleep(1);
  }
}


/*
int main() {
  static int X, X1; static int Y, Y1;;
  static int A, A1; static int B, B1; static int C, C1; static int D, D1; static int E, E1; static int F, F1; static int G, G1;;
  while (1) {
    X1 = !X && Y; Y1 = !X && !Y; A = (!X && !Y) || (X && !Y); B = 1; C = (!X && !Y) || (!X && Y); D = (!X && !Y) || (X && !Y); E = (!X && !Y) || (X && !Y); F = (!X && !Y); G = (X && !Y);;
    printf("A" " = %d; ", A); printf("B" " = %d; ", B); printf("C" " = %d; ", C); printf("D" " = %d; ", D); printf("E" " = %d; ", E); printf("F" " = %d; ", F); printf("G" " = %d; ", G);;
    X = X1; Y = Y1;;
    putchar('\n');
    fflush(stdout);
    sleep(1);
  }
}

*/