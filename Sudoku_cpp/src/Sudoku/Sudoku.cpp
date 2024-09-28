#include <Sudoku.hpp>

#include <unistd.h>

Sudoku::Sudoku() : Grid() {
  this->min_num = 1;
  this->max_num = 9;
  this->space = 0;
  this->revisable_grid_ = new bool[GRID_SIZE * GRID_SIZE];
}

Sudoku::Sudoku(size_t grid_size, size_t box_size, int min_num, int max_num, int space) : Grid(grid_size, box_size){
  this->min_num = min_num;
  this->max_num = max_num;
  this->space = space;
  this->revisable_grid_ = new bool[GRID_SIZE * GRID_SIZE];
}

Sudoku::Sudoku(size_t grid_size, size_t box_size, std::string grid_str, int min_num, int max_num, int space) : Grid(grid_size, box_size, grid_str) {
  // int* g = parse_str(grid_str);
  // for(int i = 0; i < grid_size * grid_size; i++) {
  //   std::cout << "int: " << g[i] << '\n';
  // }
  // std::cout << "g: " << &g << '\n';
  this->min_num = min_num;
  this->max_num = max_num;
  this->space = space;
  this->revisable_grid_ = new bool[grid_size * grid_size];
  for(int i = 0; i < grid_size * grid_size; i++) {
    if(this->grid_[i] == this->space)
      this->revisable_grid_[i] = true;
    else
      this->revisable_grid_[i] = false;
  }
}

// copy construct (deep copy)
Sudoku::Sudoku(const Sudoku& s) {
  this->GRID_SIZE = s.GRID_SIZE;
  this->BOX_SIZE = s.BOX_SIZE;
  this->min_num = s.min_num;
  this->max_num = s.max_num;
  this->space = s.space;

  delete this->grid_;
  this->grid_ = new int[GRID_SIZE * GRID_SIZE];
  for(int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
    this->grid_[i] = s.grid_[i];
    
  this->revisable_grid_ = new bool[GRID_SIZE * GRID_SIZE];
  for(int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
    if(this->grid_[i] == this->space)
      this->revisable_grid_[i] = true;
    else
      this->revisable_grid_[i] = false;
  }
}

bool Sudoku::write(size_t row, size_t col, int num) {
    if (this->revisable_grid_[row * GRID_SIZE + col] &&
        (row >= 0 && row < GRID_SIZE) &&
        (col >= 0 && col < GRID_SIZE) &&
        ((num >= min_num && num <= max_num) || num == space)) {
        this->grid_[row * GRID_SIZE + col] = num;
        return true;
    }
    return false;
}

void Sudoku::reset(size_t grid_size, size_t box_size, std::string grid_str, int min_num, int max_num, int space) {
  this->GRID_SIZE = grid_size;
  this->BOX_SIZE = box_size;

  if (this->grid_ != nullptr)
    delete this->grid_;
  this->grid_ = parse_str(grid_str);


  this->min_num = min_num;
  this->max_num = max_num;
  this->space = space;

  for(int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
    if(this->grid_[i] == this->space)
      this->revisable_grid_[i] = true;
    else
      this->revisable_grid_[i] = false;
  }
}

void Sudoku::show() {
  std::cout << "Sudoku Information:" << std::endl;
  std::cout << "GRID_SIZE: " << GRID_SIZE << std::endl;
  std::cout << "BOX_SIZE: " << BOX_SIZE << std::endl;
  std::cout << "min_num: " << min_num << std::endl;
  std::cout << "max_num: " << max_num << std::endl;
  std::cout << "space: " << space << std::endl;
  
  // std::cout << "show grid_: " << &(this->grid_) << '\n';
  this->Grid::show();
  // // std::cout << "[";
  // for(int i = 0; i < GRID_SIZE; i++){
  //   std::cout << "[";
  //   for(int j = 0; j < GRID_SIZE; j++){
  //     std::cout << this->grid_[i * GRID_SIZE + j] << ", ";
  //   }
  //   std::cout << "],";
  //   // if(i != GRID_SIZE - 1)
  //     std::cout << "\n";
  // }
  // // std::cout << "]\n";
}

bool Sudoku::check_repeat(int* array) {
  int num = GRID_SIZE + 1;
  int* repeat = new int[num]();
  bool res = true;
  for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    repeat[array[i] - min_num + 1] += 1;
  for(int i = 1; i < num; i++) {
    if(repeat[i] > 1)
      res = false;
  }
  delete repeat;
  return res;
}

bool Sudoku::valid() {
  bool flag = true;
  for(int i = 0; i < GRID_SIZE; i++)
    flag = flag && check_repeat(get_row(i));
  
  for(int i = 0; i < GRID_SIZE; i++)
    flag = flag && check_repeat(get_column(i));

  for(int i = 0; i < GRID_SIZE / BOX_SIZE; i++) {
    for(int j = 0; j < GRID_SIZE / BOX_SIZE; j++)
      flag = flag && check_repeat(get_box(i * BOX_SIZE, j * BOX_SIZE));
  }
  return flag;
}


std::pair<int, int> Sudoku::get_first_space() {
  std::pair<int, int> res;
  for(int i = 0; i < GRID_SIZE; i++) {
    for(int j = 0; j < GRID_SIZE; j++) {
      if(grid_[i * GRID_SIZE + j] == space) {
        res.first = i;
        res.second = j;
        return res;
      }
    }
  }
  res = std::make_pair<int, int>(-1, -1);
  return res;
}

std::pair<int, int> Sudoku::get_next_space(size_t r, size_t c) {
  std::pair<int, int> res;
  for(int j = c + 1; j < GRID_SIZE; j++) {
    if(grid_[r * GRID_SIZE + j] == space) {
      res.first = r;
      res.second = j;
      return res;
    }
  }

  for(int i = r + 1; i < GRID_SIZE; i++) {
    for(int j = 0; j < GRID_SIZE; j++) {
      if(grid_[i * GRID_SIZE + j] == space) {
        res.first = i;
        res.second = j;
        return res;
      }
    }
  }
  res = std::make_pair<int, int>(-1, -1);
  return res;
}

std::set<size_t> Sudoku::get_candidate(size_t r, size_t c) {
  std::set<size_t> res;
  
  int* array = new int[GRID_SIZE]();
  int* row = get_row(r);
  int* col = get_column(c);
  for(int i = 0; i < GRID_SIZE; i++) {
    if (row[i] != this->space)
      array[row[i] - min_num] = 1;
    if (col[i] != this->space)
      array[col[i] - min_num] = 1;
  }

  int* box = get_box(r, c);
  for(int i = 0; i < BOX_SIZE * BOX_SIZE; i++){
    if (box[i] != this->space) 
      array[box[i] - min_num] = 1;
 
  }
  for(int i = 0; i < GRID_SIZE; i++) {
    if(array[i] == 0)
      res.insert(i + min_num);
  }

  delete row;
  delete col;
  delete box;
  delete array;
  return res;
}


void Sudoku::inference() {
  std::pair<int, int> s = get_first_space();
  std::cout << "inference begin" << std::endl;
  while (s.first != -1 && s.second != -1) {
    std::set<size_t> candidate = get_candidate(s.first, s.second);
    if (candidate.size() != 0) {
      std::cout << "candidates of (" << s.first << ", " << s.second << "): ";
      std::cout << '{';
      for(auto& it : candidate)
        std::cout << it << ", ";
      std::cout << '}' << std::endl;
    }
    s = get_next_space(s.first, s.second);
  }
  std::cout << "inference end" << std::endl;
}

bool Sudoku::fill(size_t r, size_t c) {
  std::set<size_t> candidate = get_candidate(r, c);
  std::pair<int, int> next;
  for(auto it : candidate) {
    grid_[r * GRID_SIZE + c] = it;
    // sleep(1);
    // std::cout << "(" << r << ", " << c<< ") ";
    // std::cout << "candidate: " << it << '\n';
    // this->Grid::show();
    next = get_next_space(r, c);
    if (next.first == -1 && next.second == -1)
      return true;
    else {
      if (fill(next.first, next.second))
        return true;
      else
        grid_[r * GRID_SIZE + c] = space;
    }
  }
  return false;
}

bool Sudoku::solve() {
  if(!valid())
    return false;
  std::pair<int, int> rc = get_first_space();
  bool res = fill(rc.first, rc.second);
  // std::cout << "res: " << res << '\n';
  // std::cout << "valid: " << valid() << '\n';
  if(res && valid()){
    std::cout << "Solve!\n";
    return true;
  }
  else {
    std::cout << "Fail\n";
    return false;
  }
}

