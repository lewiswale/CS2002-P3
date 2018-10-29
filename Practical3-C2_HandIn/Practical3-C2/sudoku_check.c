#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

Validity check_sudoku (sudoku *sku) {
  Validity rows = row_check(sku);
  Validity columns = column_check(sku);
  Validity blocks = block_check(sku);

  if (rows == INVALID || columns == INVALID || blocks == INVALID) {
    return INVALID;
  } else if (rows == INCOMPLETE || columns == INCOMPLETE || blocks == INCOMPLETE) {
    return INCOMPLETE;
  } else {
    return COMPLETE;
  }
}

Validity row_check (sudoku *sku) {
  int incomplete = 0;
  for (size_t y = 0; y < sku->gridSize; y++) {
    int current_row[sku->gridSize];
    for (size_t x = 0; x < sku->gridSize; x++) {
      current_row[x] = sku->grid[y*sku->gridSize+x];
    }
    Validity check = check_list(current_row, sku->gridSize);
    if (check == INVALID) {
      return INVALID;
    } else if (check == INCOMPLETE) {
      incomplete = 1;
    }
  }
  if (incomplete) {
    return INCOMPLETE;
  } else {
    return COMPLETE;
  }
}

Validity column_check (sudoku *sku) {
  int incomplete = 0;
  for (size_t x = 0; x < sku->gridSize; x++) {
    int current_column[sku->gridSize];
    for (size_t y = 0; y < sku->gridSize; y++) {
      current_column[y] = sku->grid[y*sku->gridSize+x];
    }
    Validity check = check_list(current_column, sku->gridSize);
    if (check == INVALID) {
      return INVALID;
    } else if (check == INCOMPLETE) {
      incomplete = 1;
    }
  }
  if (incomplete) {
    return INCOMPLETE;
  } else {
    return COMPLETE;
  }
}

Validity block_check (sudoku *sku) {
  int incomplete = 0;
  for (size_t block_y = 0; block_y < sku->blockSize; block_y++) {
    for (size_t block_x = 0; block_x < sku->blockSize; block_x++) {
      int current_block[sku->gridSize];
      for (size_t y = 0; y < sku->blockSize; y++) {
        for (size_t x = 0; x < sku->blockSize; x++) {
          current_block[sku->blockSize*x+y] = sku->grid[(y+(block_y*sku->blockSize))*sku->gridSize+(x+(block_x*sku->blockSize))];
        }
      }
      Validity check = check_list(current_block, sku->gridSize);
      if (check == INVALID) {
        return INVALID;
      } else if (check == INCOMPLETE) {
        incomplete = 1;
      }
    }
  }
  if (incomplete) {
    return INCOMPLETE;
  } else {
    return COMPLETE;
  }
}

Validity check_list (int *checkee, int length) {
  int duplicate_found = 0;
  int zero_found = 0;
  for (size_t i = 0; i < length - 1; i++) {
    for (size_t j = i + 1; j < length; j++) {
      if (checkee[i] == checkee[j] && checkee[i] != 0) {
        duplicate_found = 1;
      }
      if (checkee[j] == 0) {
        zero_found = 1;
      }
    }
  }

  if (duplicate_found) {
    return INVALID;
  }

  if (zero_found) {
    return INCOMPLETE;
  }

  return COMPLETE;
}
