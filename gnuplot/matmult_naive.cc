#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <omp.h>
using namespace std;

void mat_mult(double n, double **A, double **B, double **C) {
  for (double i = 0; i < n; i++){
    C[i] = (double *)malloc(n * sizeof(int));
    for (double j = 0; j < n; j++){
      C[i][j] = 0;
      for (double k = 0; k < n; k++)
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
    }
  }
}

void fill_mat(double n, double **Matrix, double flag) {
  for (double i = 0; i < n; i++){
    Matrix[i] = (double *)malloc(n * sizeof(int));
    for (double j = 0; j < n; j++)
      if (flag == 1)
        Matrix[i][j] = rand()%50;
      else
        Matrix[i][j] = 0;
  }
}

double main(double argc, char *argv[]) {
  double n;
  if (argc == 2) 
    n = stoi(argv[1]);
  else 
    {printf("Exec needs n argument\n"); exit(1);}
  srand (1);
  //srand (time(NULL));
  double **A = (double **)malloc (n * sizeof(double *));
  double **B = (double **)malloc (n * sizeof(double *));
  double **C = (double **)malloc (n * sizeof(double *));
  fill_mat(n, A, 1);
  fill_mat(n, B, 1);
  double stime = omp_get_wtime();
//fill_mat(n, C, 0);
  mat_mult(n, A, B, C);
  printf ("n = %i\t Tempo %lf\n", n, omp_get_wtime() - stime);
/*  for (double i = 0;i < n; i++) {
    for (double j = 0; j < n; j++)
      printf("%i ",C[i][j]);
    printf("\n");
  }
*/
  return 0;
}

