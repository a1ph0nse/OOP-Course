add_subdirectory(Grid)

add_library(Sudoku
  OBJECT
    Sudoku.cpp
)

target_include_directories(Sudoku
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Grid
)