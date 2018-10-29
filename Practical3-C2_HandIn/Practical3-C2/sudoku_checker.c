#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

int main() {
  sudoku *sku = createSudoku();
  printGrid(sku);
  Validity sudokuValidity = check_sudoku(sku);

  if (sudokuValidity == INVALID) {
    printf("INVALID\n");
  } else if (sudokuValidity == INCOMPLETE) {
    printf("INCOMPLETE\n");
  } else {
    printf("COMPLETE\n");
  }

  freeGrid(sku);
  printf("\n");
}
