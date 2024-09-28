Sudoku
========
 
Library Sudoku can be used to solve Sudoku game,
by providing a basic explanation of how to use it.
 
Look how easy it is to use:
 
    from Sudoku import Sudoku
    # Construct your Sukoku Object
    s = Sudoku(grid_size = 9, 
               box_size = 3,
               sudoku_str = "your sudoku game string",
               min_num = 1,
               max_num = 9,
               space = 0)
    # solve Sudoku
    s.solve()
    # show you the answer
    print(s)
 
Features
--------
 
- Accepts Sudoku in string format
- Solve Sudoku automatically
- Other useful method 

Dependency
------------

- numpy 1.24.3

if you want to use test.py
- pytest 7.4.0


Contribute
----------

- Issue Tracker: [github.com/a1ph0nse/OOP-Course/issues](https://github.com/a1ph0nse/OOP-Course)
- Source Code: [github.com/a1ph0nse/OOP-Course](https://github.com/a1ph0nse/OOP-Course)

 