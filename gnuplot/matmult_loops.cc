#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <omp.h>
using namespace std;

void mat_mult(int n, int **A, int **B, int **C) {
  for (int i = 0; i < n; i++){
    C[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++){
      C[i][j] = 0;
      for (int k = 0; k < n; k++)
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
    }
  }
}

void fill_mat(int n, int **Matrix, int flag) {
  for (int i = 0; i < n; i++){
    Matrix[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
      if (flag == 1)
        Matrix[i][j] = rand()%50;
      else
        Matrix[i][j] = 0;
  }
}

int main(int argc, char *argv[]) {
  int n;
  double stime = omp_get_wtime();
  if (argc == 2) 
    n = stoi(argv[1]);
  else 
    {printf("Exec needs n argument\n"); exit(1);}
  srand (time(NULL));
  int **A = (int **)malloc (n * sizeof(int *));
  int **B = (int **)malloc (n * sizeof(int *));
  int **C = (int **)malloc (n * sizeof(int *));
  fill_mat(n, A, 1);
  fill_mat(n, B, 1);
//fill_mat(n, C, 0);
  mat_mult(n, A, B, C);
  printf ("n = %i\t Tempo %lf\n", n, omp_get_wtime() - stime);
/*  for (int i = 0;i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%i ",C[i][j]);
    printf("\n");
  }
*/
  return 0;
}

