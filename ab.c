#include <stdio.h>
int main() {
  int n, a, b, m, find = -1;
  scanf("%d", &n);
  for (a = 1; a <= 9; a++) {
    for (b = a + 1; b <= 9; b++) {
      m = (a * 10 + b) * (b * 10 + a);
      if (m == n) {
        find = 0;
        goto result;
      }
      continue;
    }
  }
result:
  if (find != 0) {
    printf("No Answer");
  } else {
    printf("%d%d", a, b);
  }
  return 0;
}
