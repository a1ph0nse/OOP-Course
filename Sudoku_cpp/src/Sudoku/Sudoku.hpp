#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <string>
#include <utility>
#include <set>
#include <unordered_map>

#include <Grid.hpp>



class Sudoku : public Grid{
public:
  Sudoku();
  Sudoku(size_t grid_size, size_t box_size, int min_num, int max_num, int space);
  Sudoku(size_t grid_size, size_t box_size, std::string grid_str, int min_num, int max_num, int space);

  Sudoku(const Sudoku& s);

  bool write(size_t row, size_t col, int num);

  void reset(size_t grid_size, size_t box_size, std::string grid_str, int min_num, int max_num, int space);

  void show();

  bool check_repeat(int* array);
  bool valid();

  std::pair<int, int> get_first_space();
  std::pair<int, int> get_next_space(size_t r, size_t c);
  
  std::set<size_t> get_candidate(size_t r, size_t c);
  
  void inference();

  bool fill(size_t r, size_t c);

  bool solve();

  

private:
  int min_num;
  int max_num;
  int space;
  bool* revisable_grid_;
};


#endif /* SUDOKU_H_ */
