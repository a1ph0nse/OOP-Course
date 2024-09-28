Sudoku
========
 
Library Sudoku can be used to solve Sudoku game,
by providing a basic explanation of how to use it.


How to Use
--------
Look how to use main.cpp to test

    cd Sudoku_cpp
    mkdir -p build
    cd build
    cmake ..
    cmake --build .
    ./bin/sudoku

Look how easy it is to use:
 
    #include <Sudoku.hpp>
    # Construct your Sukoku Object
    s = Sudoku(9, 3, "your sudoku game string", 1, 9, 0);
    # solve Sudoku
    s.solve()
    # show you the answer
    s.show()
 
Features
--------
 
- Accepts Sudoku in string format
- Solve Sudoku automatically
- Other useful method 

Dependency
------------

None

Contribute
----------

- Issue Tracker: [github.com/a1ph0nse/OOP-Course/issues](https://github.com/a1ph0nse/OOP-Course)
- Source Code: [github.com/a1ph0nse/OOP-Course](https://github.com/a1ph0nse/OOP-Course)

 