#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#include <conio.h>

char check_graph(int ** a, int n);
int main() {
  int n; // n - количество узлов
  printf("Please enter the number of vertices! "); // Добавление значения количества узлов
  scanf("%d", & n);
  char cur; // cur - текущий введенный символ                                    
  int i, j, h, b, k = 1, length = 0; // length - количество рёбер
  int ** a = (int ** ) malloc(n * sizeof(int * )); // выделение памяти для массива сохранения матрицы смежности графа
  //----------------------//
  //Ввод матрицы смежности//
  //----------------------//
  for (b = 0; b < n; b++) {
    a[b] = (int * ) malloc(sizeof(int));
  }
  cur = getchar(); // Переход на новую строку
  for (i = 0; i < n; i++) {
    printf("%d :", i + 1);
    cur = getchar(); // Берём первый символ
    for (j = 0; cur != '\n'; j++) {
      if ((cur == '1') || (cur == '0')) {
        a[i] = (int * ) realloc(a[i], sizeof(int) * k); // Выделение памяти на один больше символ
        (a[i])[k - 1] = cur - '0'; // Запись значения в массиве 
        k++;
      }
      cur = getchar(); // Получение нового значения
    }
    cur = '\0'; // Для перехода на новую строку         
    length = k - 1; // Определение длины строки
    k = 1;
  }
  printf("\n\n");
  //-----------------//
  //Обозначение узлов//
  //-----------------//
  char x[n];
  printf("\nEnter the names of the vertices: ");
  for (i = 0; i < n; i++) {
    printf("\nx[%d]=", i + 1);
    x[i] = getche();
  }
  printf("\n\n");
  getchar();
  //--------------------//
  //Проверка связанности//                        
  //--------------------//
  if (check_graph(a, n) == 1) {
    printf("\n Graph connected! \n");
  } else printf("\n Graph is not connected! \n");
  //----------------------------------------//
  //Применение Dot_file для построения графа//
  //----------------------------------------//
  FILE * f;
  f = fopen("graph.txt", "w");
  fprintf(f, "graph mygrap{ \n");
  for (i = 0; i < n; i++) {
    fprintf(f, "%c\n", x[i]);
  }
  for (i = 0; i < n; i++)
    for (j = 0; j <= i; j++) {
      if (a[i][j] != 0) {
        for (h = 0; h < (a[i][j]); h++)
          fprintf(f, "%c--%c\n", x[i], x[j]);
      }
    }
  fprintf(f, "}");
  fclose(f);
  //Команды системы, чтобы передавать файл graph.txt в bmp и открывать картинку графа// 
  system("dot E:\\Logic_thuat_toan\\graph.txt -Tbmp -o graph.bmp");
  system("rundll32  \"%ProgramFiles%\\Windows Photo Viewer\\PhotoViewer.dll\", ImageView_Fullscreen E:\\Logic_thuat_toan\\graph.bmp");
  //------------------------------------//
  //Очистка памяти динамических массивов//
  //------------------------------------//
  for (i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);
  return 0;
}
//----------------------------------//
//Функция проверки связанности графа//
//----------------------------------//
char check_graph(int ** a, int n) {
  int * visited = (int * ) malloc(n * sizeof(int)); // выделение памяти для массива посещения узлов
  int i, j, dem = 0;
  char d;
  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }
  visited[0] = 1;
  dem++;
  do {
    d = 1;
    for (i = 0; i < n; i++) {
      if (visited[i] == 1) {
        for (j = 0; j < n; j++) {
          if (visited[j] == 0 && a[i][j] > 0) {
            visited[j] = 1;
            d = 0;
            dem++;
            if (dem == n)
              return 1;
          }
        }
      }
    }
  } while (d == 0);
  return 0;
}