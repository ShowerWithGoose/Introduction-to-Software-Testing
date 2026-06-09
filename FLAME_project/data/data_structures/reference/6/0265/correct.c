#include <stdio.h>
#define PUSH(N) stack[last++] = N

int main(void) {
  int stack[1000];
  int last = 0;
  int op;
  while (scanf("%d", &op) != EOF) {
    if (op == 1) {
      int num;
      scanf("%d", &num);
      PUSH(num);
      // printf("[%d %d]", num, last);
    } else if (op == 0) {
      if (last <= 0) {
        printf("error ");
      } else {
        printf("%d ", stack[--last]);
      }
    } else if (op == -1) {
      return 0;
    }
  }
}
