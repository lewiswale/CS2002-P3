all: sudoku_check sudoku_solver

sudoku_check: sudoku_checker.c sudoku_check.c sudoku_io.c
	gcc sudoku_checker.c sudoku_check.c sudoku_io.c -std=c99 -o sudoku_check

sudoku_solver: sudoku_check.c sudoku_io.c sudoku_solver.c
	gcc sudoku_check.c sudoku_io.c sudoku_solver.c -std=c99 -o sudoku_solver

clean:
	rm -f *.o sudoku_check sudoku_solver
