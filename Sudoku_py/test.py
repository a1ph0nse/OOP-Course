from Sudoku import Sudoku


class TestSuduku:
  def setup_class(self):
    self.sudoku_str = ["017903600000080000900000507072010430000402070064370250701000065000030000005601720",
                       "600100708000800200238050100000040092004308600370010000003070526002004000907006004"]

    self.result_str = ["417953682256187943983246517872519436539462871164378259791824365628735194345691728",
                      "695123748741869253238457169816745392524398671379612485483971526162584937957236814"]

    # sudoku rule
    self.grid_size = 9
    self.box_size = 3
    self.min_num = 1
    self.max_num = 9
    self.space = 0

  # test clone
  def test_clone(self):
    print("---------->test clone")
    s1 = Sudoku(self.grid_size, 
                self.box_size,
                self.sudoku_str[0],
                self.min_num,
                self.max_num,
                self.space)
    s2 = s1.clone()
    s2.GRID_SIZE = 19
    assert s1.GRID_SIZE == 9 and s2.GRID_SIZE == 19

  # test inference a space
  def test_inference1(self):
    print("---------->test inference a space")
    s1 = Sudoku(self.grid_size, 
                self.box_size,
                self.sudoku_str[0],
                self.min_num,
                self.max_num,
                self.space)
    assert s1.get_candidate(0, 0) == {2, 4, 5, 8}

  # test solve  
  def test_solve(self):
    for i in range(2):
      print("---------->test solve{}".format(i + 1))
      su = Sudoku(self.grid_size, 
                  self.box_size,
                  self.sudoku_str[i],
                  self.min_num,
                  self.max_num,
                  self.space)
      su.solve()
      assert str(su) == self.result_str[i]
    



if __name__ == '__main__':
  # su = Sudoku(9, 
  #             3,
  #             "017903600000080000900000507072010430000402070064370250701000065000030000005601720",
  #             1,
  #             9,
  #             0)
  # su.inference()
  import pytest
  pytest.main([__file__])