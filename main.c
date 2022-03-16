#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f1, *f2;
  char arr[1001][1001], s, u;
  int i = 0, j = 0;
  f1 = fopen("matrix_of_incendence18.txt", "r"); // открываем файл
  while (!feof(f1))
  {
    fscanf(f1, "%c", &s);
    if (s != ' ' && s != '\n')
    {
      arr[i][j] = s; // записываем матрицу в массив
      j++;
      if (j == 20)
      {
        i++;
        j = 0;
      }
    }
  f2 = fopen("graf.gv", "w"); // создаем файл для Graphviz
  fprintf(f2, "graph grath {\n"); // Первая строка, чтобы Graphviz октрыл его правильно
  for (int a = 0; a < 20; a++) // записываем список смежности в gv файл
  {
    u = -1;
    for (int y = 0; y < 5; y++)
    {
      if (arr[y][a] != '0')
      {
        if (u == -1)
        {
          fprintf(f2, "%d", y + 1);
          printf("%d", y + 1);
          u = 0;
        }
        else
        {
          printf(" -- %d", y + 1);
          fprintf(f2, " -- %d", y + 1);
        }
      }
    }
    fprintf(f2, ";\n");
    printf(";\n");
  }
  fprintf(f2, "}");
  fclose(f2); // закрываем и сохраняем файл
}
