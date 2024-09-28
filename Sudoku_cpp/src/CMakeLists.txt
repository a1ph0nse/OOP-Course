add_subdirectory(Sudoku)


add_executable(sudoku
  main.cpp
)

target_link_libraries(sudoku
  Sudoku
  Grid
)

target_include_directories(sudoku
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Sudoku
)
