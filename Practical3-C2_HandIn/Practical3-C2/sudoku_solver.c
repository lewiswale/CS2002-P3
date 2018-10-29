#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

int multi = 0;
sudoku *solution;

int main() {
  sudoku *sku = createSudoku();
  Validity solved = solveSudoku(sku);

  if (solved == INVALID) {
    printf("UNSOLVABLE\n");
  }

  if (multi == 1) {
    printGrid(solution);
  } else if (multi > 1) {
    printf("MULTIPLE\n");
  }

  freeGrid(sku);
}

Validity solveSudoku (sudoku *sku) {
  Validity check = check_sudoku(sku);
  if (check == INVALID) {
    return INVALID;
  }

  if (check == COMPLETE) {
    multi++;
    if (multi == 1) {
      solution = copySudoku(sku);
    }
    return COMPLETE;
  }

  if (check == INCOMPLETE) {
    for (size_t i = 1; i < sku->gridSize+1; i++) {
      sudoku *newSku = copySudoku(sku);
      newSku = findZero(newSku, i);
      solveSudoku(newSku);
      freeGrid(newSku);
    }
  }
}

sudoku* findZero (sudoku *sku, int newNum) {
  int zero_found = 0;
  for (size_t y = 0; y < sku->gridSize; y++) {
    for (size_t x = 0; x < sku->gridSize; x++) {
      if (sku->grid[y*sku->gridSize+x] == 0 && zero_found == 0) {
        sku->grid[y*sku->gridSize+x] = newNum;
        return sku;
      }
    }
  }
  return sku;
}
