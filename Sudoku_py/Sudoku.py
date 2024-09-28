import pickle
import numpy as np
import copy

from Grid import Grid

class Sudoku(Grid):
  '''
  function:
    construct and initialize
  '''
  def __init__(self, grid_size, box_size, sudoku_str, min_num, max_num, space):
    grid = self.parse_str(grid_size, sudoku_str)

    super(Sudoku, self).__init__(grid_size, box_size, grid)
    self.min_num = min_num
    self.max_num = max_num
    self.space = space
    self.revisable_grid = (self.grid == self.space)

  '''
  function:
    parse str sudoku
  Output:
    np.array(dtype = int, shape = (grid_size, grid_size))
  '''
  def parse_str(self, grid_size, sudoku_str):
    sudoku_list = []
    for i in sudoku_str:
      sudoku_list.append(int(i))
    return np.array(sudoku_list).reshape(grid_size, grid_size)
  
  '''
  function:
    transform sudoku into str
  Output:
    str
  '''
  def __str__(self):
    sudoku_str = ''
    for i in self.grid.flatten():
      sudoku_str += str(i)
    return sudoku_str

  '''
  function:
    return a deep copy instance
  Output:
    sudokuku
  '''
  def clone(self):
    return copy.deepcopy(self)
  
  '''
  function:
    return object in the format of serial data
  Output:
    bytes
  '''
  def serialize(self):
    return pickle.dumps(self)

  '''
  function:
    write number to given cell if it's valid
  '''
  def write(self, r, c, num):
    if (self.revisable_grid[r][c] and
        (r >=0 and r < self.GRID_SIZE) and
        (c >=0 and c < self.GRID_SIZE) and
        ((num <= self.max_num and num >= self.min_num) or num == self.space)):
      self.grid[r][c] = num
      return True
    else:
      return False

  '''
  function:
    reset rule and data of sudoku
  '''
  def reset_sudoku(self, grid_size, box_size, sudoku_str, min_num, max_num, space):
    self.GRID_SIZE = grid_size
    self.BOX_SIZE = box_size
    self.grid = self.parse_str(sudoku_str)
    self.min_num = min_num
    self.max_num = max_num
    self.space = space
    self.revisable_grid = (self.grid == self.space)

  '''
  function:
    show sudoku information
  '''
  def show(self):
    print("Sudoku Information:")
    print("GRID_SIZE: {}".format(self.GRID_SIZE))
    print("BOX_SIZE: {}".format(self.BOX_SIZE))
    print("min_num: {}".format(self.min_num))
    print("max_num: {}".format(self.max_num))
    print("space: {}".format(self.space))
    print(self.grid)
  
  '''
  function:
    check whether the array contains repeated nonzero values
  Input:
    np.array
  Output:
    bool
  '''
  def check_repeat(self, array):
    unique_value, repeat = np.unique(array, return_counts = True)
    for i in range(len(repeat)):
      if (repeat[i] != 1 and 
          unique_value[i] != self.space):
        return False
    return True

  '''
  function:
    check the validity of the sudoku
  Output:
    bool: valid or not
  '''
  def valid(self):
    flag = True
    # for all row
    for r in range(self.GRID_SIZE):
      row = self.get_row(r)
      flag = flag and self.check_repeat(row)

    # for all column
    for c in range(self.GRID_SIZE):
      column = self.get_column(c)
      flag = flag and self.check_repeat(column)

    # for all block
    for r in range(self.GRID_SIZE // self.BOX_SIZE):
      for c in range(self.GRID_SIZE // self.BOX_SIZE):
        box = self.get_box(r * self.BOX_SIZE, c * self.BOX_SIZE).flatten()
        flag = flag and self.check_repeat(box)

    return flag

  '''
  function:
    return the first space of the Sudoku
  Output:
    (row, column)
    (-1, -1) means can't find the first space, sudoku has been solved
  '''
  def get_first_space(self):
    for i in range(self.GRID_SIZE):
      for j in range(self.GRID_SIZE):
        if self.grid[i][j] == self.space:
          return i, j
        
    # can't find space 
    return -1, -1

  '''
  function:
    return the next space from given current space
  Input:
    row: row of current space
    column: column of current space
  Output:
    (next_row, next_column)
    (-1, -1) means can't find next space, sudoku has been solved
  '''
  def get_next_space(self, r, c):
    # space in the same row
    for y in range(c + 1, self.GRID_SIZE):
      if self.grid[r][y] == self.space:
        return r, y

    # space in other row
    for x in range(r + 1, self.GRID_SIZE):
      for y in range(self.GRID_SIZE):
        if self.grid[x][y] == self.space:
          return x, y
    
    # can't find space 
    return -1, -1

  '''
  function:
    return all candidates of given space
  Input:
    row: row of space
    column: column of space
  Output:
    set{candidate1, candidate2, ...}
  '''
  def get_candidate(self, r, c):
    res = set([x for x in range(self.min_num, self.max_num + 1)])
    res -= set(self.get_row(r))
    res -= set(self.get_column(c))
    res -= set(self.get_box(r, c).flatten())
    return res

  '''
  function:
    return the spaces with only one candidate and their candidate value
  Output:
    dict{(space_row, space_column): candidate}
  '''
  def get_space_with_one_candidate(self):
    candidate_dict = {}

    space = self.get_first_space()
    while (space != (-1, -1)):
      candidate = self.get_candidate(space[0], space[1])
      if (len(candidate) == 1):
        for v in candidate:  
          candidate_dict[space] = v
      space = self.get_next_space(space[0], space[1])
    return candidate_dict
  
  '''
  function:
    infer and show the candidates for all spaces
  '''
  def inference(self):
    s = self.get_first_space()
    print("inference begin")
    while (s != (-1, -1)):
      candidate = self.get_candidate(s[0], s[1])
      if (len(candidate) != 0):
        print("candidates of {}: {}".format(s, candidate))
      s = self.get_next_space(s[0], s[1])
    print("inference end")

  '''
  function:
    fill space with only one candidate iterately,
    it can solve some easy sudoku and accelerate for difficult sudoku
  '''
  def ez_fill(self):
    candidate_dict = self.get_space_with_one_candidate()
    while(candidate_dict != {}):
      for k in candidate_dict.keys():
        self.grid[k[0]][k[1]] = candidate_dict[k]
      # print(self.grid)
      candidate_dict = self.get_space_with_one_candidate()

  '''
  function:
    fill space according to the candidates recursively,
    it can solve all sudoku
  '''
  def fill(self, r, c):
    for candidate in self.get_candidate(r, c):
      self.grid[r][c] = candidate
      next_r, next_c = self.get_next_space(r, c)
      if (next_r, next_c) == (-1, -1):
        return True
      elif self.fill(next_r, next_c):
        return True
      else:
        self.grid[r][c] = self.space
    return False
  
  '''
  function:
    solve sudoku
  Output:
    bool: solve or not
  '''
  def solve(self):
    if (not self.valid()):
      return False
    self.ez_fill()
    if (not self.valid()):
      return False
    r, c = self.get_first_space()
    if (self.fill(r, c) and self.valid()):
      print("Solve!")
      return True
    else: 
      print("Fail!")
      return False
