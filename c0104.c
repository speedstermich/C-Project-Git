#include <stdio.h>
int main() {

  float F, C;
  scanf("%f", &C);
  F = C * 9 / 5 + 32; /*华氏温度公式*/
  printf("%.1f", F);

  return 0;
}