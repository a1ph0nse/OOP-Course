add_library(Grid
  OBJECT
    Grid.cpp
)

target_include_directories(Grid
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)