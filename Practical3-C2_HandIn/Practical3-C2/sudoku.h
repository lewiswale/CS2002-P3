typedef enum Validity {INVALID, INCOMPLETE, COMPLETE} Validity;

typedef struct sudoku {
  int blockSize;
  int gridSize;
  int *grid;
} sudoku;

void printGrid (sudoku *sku);
Validity check_list (int *checkee, int length);
Validity check_sudoku(sudoku *sku);
Validity row_check (sudoku *sku);
Validity column_check (sudoku *sku);
Validity block_check (sudoku *sku);
void freeGrid (sudoku *sku);
sudoku* copySudoku (sudoku *sku);
sudoku* createSudoku ();
Validity solveSudoku (sudoku *sku);
sudoku* findZero (sudoku *sku, int newNum);
