#include <stdio.h>
#include <stdlib.h>

int main()
{
     FILE *matr, *graf;
     char m[100];
     char s = ' ';
     int i = 0, a = 0;
     int k, j, rez1, kol;
     char rez2;
     matr = fopen("matrix.txt", "r");
     while (!feof(matr))
     {
          if (a == 0 && s == '\n')
          {
               a = i;
          }
          if (s == '1' || s == '0')
          {
               m[i] = s;
               i++;
          }
          fscanf(matr, "%c", &s);
     }
     for (j = 1; j <= a; j++)
     {
          kol = 0;
          for (k = j; k <= i; k++)
          {
               if (m[k - 1] == '1')
               {
                    if (kol > 0)
                    {
                         printf("%d\n", k / (a + 1) + 1);
                         break;
                    }
                    if (kol == 0)
                    {
                         kol++;
                         printf("%d: ", k / (a + 1) + 1);
                    }
               }
               k += a - 1;
          }
     }
     graf = fopen("graf.gv", "w");
     fprintf(graf, "digraph Grah {\n");
     for (j = 1; j <= a; j++)
     {
          kol = 0;
          for (k = j; k <= i; k++)
          {
               if (m[k - 1] == '1')
               {
                    if (kol > 0)
                    {
                         fprintf(graf, "\"%d\"\n", k / (a + 1) + 1);
                         break;
                    }
                    if (kol == 0)
                    {
                         kol++;
                         fprintf(graf, "\"%d\"-> ", k / (a + 1) + 1);
                    }
               }
               k += a - 1;
          }
     }
     fprintf(graf, "}");
     fclose(graf);

     return 0;
}
