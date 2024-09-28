import numpy as np

class Grid:
  '''
  function:
    construct and initialzie
  '''
  def __init__(self, grid_size, box_size, grid):
    self.GRID_SIZE = grid_size
    self.BOX_SIZE = box_size
    self.grid = grid
  
  '''
  function:
    return row data according to row
  Output:
    np.array(dtype = int, shape = (GRID_SIZE,))
  '''
  def get_row(self, r):
    return self.grid[r, :]

  '''
  function:
    return column data according to column
  Output:
    np.array(dtype = int, shape = (GRID_SIZE,))
  '''
  def get_column(self, c):
    return self.grid[:, c]

  '''
  function:
    return box data according to row and column
  Output:
    np.array(dtype = int, shape = (BOX_SIZE, BOX_SIZE))
  '''
  def get_box(self, r, c):
    r = r // self.BOX_SIZE
    c = c // self.BOX_SIZE
    return self.grid[3 * r : 3 * r + 3, 3 * c : 3 * c + 3]
  