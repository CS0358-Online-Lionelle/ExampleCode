/**
 * Code along exploring using matrices in C programming.
 *
 * This code will demonstrate how to create, initialize, and manipulate arrays.
 *
 * @author Albert Lionelle
 * @date 2024-04-08
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int rows;
  int cols;
  double *data;
} Matrix;

void printMatrix(Matrix *matrix) {
  for(int i = 0; i < matrix->rows; i++){
      for (int j = 0; j < matrix->cols; j++) {
          printf("%.1lf ", matrix->data[i * matrix->cols + j]);
      }
      printf("\n");
  }
}

// adding matrices - the need to be the same (row x col)

void addToMatrix(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
      printf("Matrices dimensions do not match for addition.\n");
      return;
  }
  for(int i = 0; i < a->rows; i++) {
      for(int j = 0; j < a->cols; j++) {
          a->data[i * a->cols + j] += b->data[i * b->cols + j];
      }
  } 
}

void transposeMatrix(Matrix *result, Matrix *matrix) {
  for(int i = 0; i < matrix->rows; i++) {
      for(int j = 0; j< matrix->cols; j++) {
          result->data[j * result->cols + i] = matrix->data[i * matrix->cols + j];
      }
  }
}

int main() {
  Matrix matrixA = {3, 3, (double []){
      1.0, 2.0, 3.0,
      4.0, 5.0, 6.0,
      7.0, 8.0, 9.0
  }};
  printMatrix(&matrixA);
  printf("\n");

  double data[3][3];
  for(int i = 0, counter = 1; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
          data[i][j] = (counter++ * 10);
      }
  }
  Matrix matrixB = {3, 3, (double *)data};
  printMatrix(&matrixB);
  printf("\n");

  addToMatrix(&matrixB, &matrixA);
  printMatrix(&matrixB);
  printf("\n");

  Matrix results = {3, 3, (double[]){
      0, 0, 0,
      0, 0, 0,
      0, 0, 0
  }};
  printMatrix(&matrixA);
  printf("---- transpose ----\n");
  transposeMatrix(&results, &matrixA);
  printMatrix(&results);
  printf("\n");

  return 0;
}
