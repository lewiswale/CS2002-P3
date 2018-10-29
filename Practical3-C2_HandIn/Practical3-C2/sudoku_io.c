#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

void printGrid (sudoku *sku) {
  int format_width = 2;
  for (size_t y = 0; y < sku->gridSize; y++) {
    printf("  \n");
    for (size_t x = 0; x < sku->gridSize; x++) {
      printf(" %*d", format_width, sku->grid[y*sku->gridSize+x]);
    }
  }
  printf("\n");
}

void freeGrid (sudoku *sku) {
  free(sku->grid);
  free(sku);
}

sudoku* copySudoku (sudoku *sku) {
  sudoku *newSku = calloc(1, sizeof(sudoku));
  newSku->blockSize = sku->blockSize;
  newSku->gridSize = sku->gridSize;
  newSku->grid = malloc(newSku->gridSize*newSku->gridSize*sizeof(int));

  for (size_t y = 0; y < sku->gridSize; y++) {
    for (size_t x = 0; x < sku->gridSize; x++) {
      newSku->grid[y*sku->gridSize+x] = sku->grid[y*sku->gridSize+x];
    }
  }

  return newSku;
}

sudoku* createSudoku () {
  int nValue = 0;
  scanf("%d", &nValue);

  int gridSize = nValue * nValue;

  sudoku *sku = calloc(1, sizeof(sudoku));
  sku->blockSize = nValue;
  sku->gridSize = gridSize;
  sku->grid = malloc(sku->gridSize*sku->gridSize*sizeof(int));

  for (size_t y = 0; y < gridSize; ++y) {
    for (size_t x = 0; x < gridSize; ++x) {
      scanf("%d ", &sku->grid[y*gridSize+x]);
    }
  }

  return sku;
}
