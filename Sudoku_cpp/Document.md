Document
========

Detail explaination of Library Sudoku.

Grid
========

| Data | Description |
| :----: | :----: |
| GRID_SIZE | size of Grid |
| BOX_SIZE | size of Box |
| grid_| Two-dimensional square matrix |

| Method | Description |
| :----: | :----: |
| Grid() | constructor |
| Grid(size_t grid_size, size_t box_size) | constructor |
| Grid(size_t grid_size, size_t box_size, std::string grid) | constructor |
| int* get_row(size_t r) | return row data according to row |
| int* get_column(size_t c) | return column data according to column |
| int* get_box(size_t r, size_t c) | return box data according to row and column |
| int* parse_str(std::string grid_str) | parse string grid and return int* grid |
| std::string str() | return grid in string |

Sudoku
========

Sudoku inherits from its parent class Grid.

| Data | Description |
| :----: | :----: |
| GRID_SIZE | inherits from Grid |
| Box_SIZE | inherits from Grid |
| grid | inherits from Grid |
| min_num | minimum of valid number in Sudoku |
| max_num | maximum of valid number in Sudoku |
| space | sapce of Sudoku |

| Method | Description |
| :----: | :----: |
| Sudoku() | constructor |
| Sudoku(size_t grid_size, size_t box_size, int min_num, int max_num, int space) | constructor |
| Sudoku(size_t grid_size, size_t box_size, std::string grid, int min_num, int max_num, int space) | constructor |
| Sudoku(const Sudoku& s) | copy constructor |
| bool write(size_t r, size_t c, int num) | write number to given cell if it's valid |
| void reset(size_t grid_size, size_t box_size, std::string grid, int min_num, int max_num, int space) | reset rule and data of sudoku |
| void show() | show sudoku information |
| bool check_repeat(int* array) | check whether the array contains repeated nonzero values |
| bool valid() | check the validity of the sudoku |
| std::pair<int, int> get_first_space() | return the first space of the Sudoku |
| std::pair<int, int> get_next_space(size_t r, size_t c) | return the next space from given current space |
| std::set<size_t> get_candidate(size_t r, size_t c) | return all candidates of given space |
| void inference() | infer and show the candidates for all spaces |
| bool fill(size_t r, size_t c) | fill space according to the candidates recursively |
| bool solve() | solve sudoku |

