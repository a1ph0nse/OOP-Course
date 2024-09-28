#include <Grid.hpp>

Grid::Grid() {
  GRID_SIZE = 9;
  BOX_SIZE = 3;
  grid_ = new int[GRID_SIZE * GRID_SIZE];
}

Grid::Grid(size_t grid_size, size_t box_size){
  GRID_SIZE = grid_size;
  BOX_SIZE = box_size;
  grid_ = new int[GRID_SIZE * GRID_SIZE];
}

Grid::Grid(size_t grid_size, size_t box_size, std::string grid){
  this->GRID_SIZE = grid_size;
  this->BOX_SIZE = box_size;
  this->grid_ = new int[GRID_SIZE * GRID_SIZE];
  int* g = parse_str(grid);
  for(int i = 0; i < grid_size * grid_size; i++) {
    this->grid_[i] = g[i];
    // std::cout << "int: " << this->grid_[i] << '\n';
  }
  // std::cout << "grid_: " << &grid_ << '\n';
}
  
int* Grid::get_row(size_t r) {
  int* res = new int[GRID_SIZE];
  for(int i = 0; i < GRID_SIZE; i++)
    res[i] = grid_[r * GRID_SIZE + i];
  return res;
}

int* Grid::get_column(size_t c) {
  int* res = new int[GRID_SIZE];
  for(int i = 0; i < GRID_SIZE; i++)
    res[i] = grid_[i * GRID_SIZE + c];
  return res;
}
  
// get the box of given element
int* Grid::get_box(size_t r, size_t c) {
  r = r / BOX_SIZE;
  c = c / BOX_SIZE;
  // std::cout << "box r: " << r << ", box c: " << c << '\n';
  int* res = new int[BOX_SIZE * BOX_SIZE];
  for(int i = 0; i < BOX_SIZE; i++) {
    for(int j = 0; j < BOX_SIZE; j++)
      res[i * BOX_SIZE + j] = grid_[(r * BOX_SIZE + i) * GRID_SIZE + c * BOX_SIZE + j];
  }
  return res;
}

int* Grid::parse_str(std::string sudoku_str) {
  int* res = new int[GRID_SIZE * GRID_SIZE];
  for(int i = 0; i < sudoku_str.length(); i++) {
    res[i] = int(sudoku_str[i]) - 48;
    // std::cout << "str: " << sudoku_str[i] << ", int: " << res[i] << '\n';
  }
  
  return res;
}

std::string Grid::str() {
  std::string res;
  for(int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
    res.push_back(char(this->grid_[i] + 48));
  return res;
}

void Grid::show() {

  // std::cout << "[";
  for(int i = 0; i < GRID_SIZE; i++){
    std::cout << "[";
    for(int j = 0; j < GRID_SIZE; j++){
      std::cout << this->grid_[i * GRID_SIZE + j] << ", ";
    }
    std::cout << "],";
    // if(i != GRID_SIZE - 1)
      std::cout << "\n";
  }
  // std::cout << "]\n";
}