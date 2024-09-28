add_executable(sudokutest
  SudokuTest.cpp
)

add_test(NAME sudokutest COMMAND sudokutest)

target_link_libraries(sudokutest
  Sudoku
  Grid
  gtest
  gtest_main
)

target_include_directories(sudokutest
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/src/Sudoku
)

include(GoogleTest)
gtest_discover_tests(sudokutest)