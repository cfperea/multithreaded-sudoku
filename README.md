Multi-threaded Sudoku Solver written in C.
==============

The solution is as follows:
--------------

1. Create 1 thread to check if all rows contain all numbers from 1-9.
2. Create 1 thread to check if all columns contain all numbers from 1-9.
3. Create 9 threads to check if all 3x3 squares formed inside the board contain all numbers from 1-9.

Commit changes
--------------

**11/19/2014:** Initial commit. The solver is able to successfully solve one board "hard-coded" in the file.

Future features
--------------

- Add Makefile.
- Accept user-provided Sudoku boards. Maybe through an external file such as XML.
