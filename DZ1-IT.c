#include <stdint.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#define MAX 30

int main() {
  uint64_t vertical_check = 0;
  uint64_t vertical_found = 0;
  double before_point = 0, after_point = 0;
  int i, l, k;
  char a[MAX];
  printf("Insert to numbers: \n"); // Вводить 2 целых числа, между ними ' ' или '.' или '|'
  gets(a);
  l = strlen(a);
  if (l > 10) // Проверка длины вводимой строки с заданной длиной  
  {
    printf("Input is too long! \n");
    exit(-1);
  }
  for (i = 0; i <= (l - 1); i++) { //Проверка место и количество символ, которым отличаются 2 числа
    if (vertical_check == 0 && (a[i] == ' ' || a[i] == -'.' || a[i] == '|')) {
      vertical_check++;
      k = i;
    }
    if (vertical_check >= 2) {
      printf("Input error! \n");
      break;
    }
  }
  for (i = 0; i <= k - 1; i++) { //Считать числа и преобразовать их в одно число типа double
    before_point += (a[i] - '0') * pow(10, k - i - 1);
  }
  for (i = k + 1; i <= (l - 1); i++) {
    after_point += (a[i] - '0') / pow(10, i - k);
  }
  double value = (double) before_point + (double) after_point;
  printf("%lf", value);
}