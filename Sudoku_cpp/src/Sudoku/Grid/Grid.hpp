#ifndef SUDUKU_GRID_H_
#define SUDUKU_GRID_H_

#include <iostream>
#include <memory>
#include <string>

class Grid {
public:
  Grid();
  Grid(size_t grid_size, size_t box_size);
  Grid(size_t grid_size, size_t box_size, std::string grid);

  // special getter
  int* get_row(size_t r);
  int* get_column(size_t c);
  
  // get the box of given element
  int* get_box(size_t r, size_t c);

  int* parse_str(std::string sudoku_str);

  std::string str();
  // show
  void show();

protected:
  size_t GRID_SIZE;
  size_t BOX_SIZE;
  int* grid_;
};


#endif /* SUDUKU_GRID_H_ */
