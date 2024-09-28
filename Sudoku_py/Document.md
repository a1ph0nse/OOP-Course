Document
========

Detail explaination of Library Sudoku.

Grid
========

| Data | Description |
| :----: | :----: |
| GRID_SIZE | size of Grid |
| BOX_SIZE | size of Box |
| grid | Two-dimensional square matrix |

| Method | Description |
| :----: | :----: |
| \_\_init\_\_(self, grid_size, box_size, grid) | construct and initialize |
| get_row(self, r) | return row data according to row |
| get_column(self, c) | return column data according to column |
| get_box(self, r, c) | return box data according to row and column |

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
| \_\_init\_\_(self, grid_size, box_size, sudoku_str, min_num, max_num, space) | construct and initialize |
| \_\_str\_\_(self) | transform sudoku into str |
| parse_str(self, grid_size, sudo_str) | parse str sudoku |
| clone(self) | return a deep copy instance |
| serialize(self) | return object in the format of serial data |
| write(self, r, c, num) | write number to given cell if it's valid |
| reset_sudoku(self, grid_size, box_size, sudoku_str, min_num, max_num, space) | reset rule and data of sudoku |
| show(self) | show sudoku information |
| check_repeat(self, array) | check whether the array contains repeated nonzero values |
| valid(self) | check the validity of the sudoku |
| get_first_space(self) | return the first space of the Sudoku |
| get_next_space(self, r, c) | return the next space from given current space |
| get_candidate(self, r, c) | return all candidates of given space |
| get_space_with_one_candidate(self) | return the spaces with only one candidate and their candidate value |
| inference(self) | infer and show the candidates for all spaces |
| ez_fill(self) | fill space with only one candidate iterately |
| fill(self, r, c) | fill space according to the candidates recursively |
| solve(self) | solve sudoku |

