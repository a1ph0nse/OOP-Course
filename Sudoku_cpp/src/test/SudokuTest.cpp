#include <SudokuTest.hpp>


TEST(SudokuTest, Construct) {
  size_t grid_size = 9;
  size_t box_size = 3;
  int min_num = 1;
  int max_num = 9;
  int space = 0;
  std::string sudoku_str1 = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";

  Sudoku s(grid_size, box_size, sudoku_str1, min_num, max_num, space);
  
  EXPECT_STREQ(sudoku_str1.c_str(), s.str().c_str());
}

TEST(SudokuTest, CopyConstruct) {
  size_t grid_size = 9;
  size_t box_size = 3;
  int min_num = 1;
  int max_num = 9;
  int space = 0;
  std::string sudoku_str1 = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
  Sudoku s(grid_size, box_size, sudoku_str1, min_num, max_num, space);

  Sudoku ss(s);
  
  EXPECT_STREQ(sudoku_str1.c_str(), ss.str().c_str());
}

TEST(SudokuTest, Reset) {
  size_t grid_size = 9;
  size_t box_size = 3;
  int min_num = 1;
  int max_num = 9;
  int space = 0;
  std::string sudoku_str1 = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
  std::string sudoku_str2 = "600100708000800200238050100000040092004308600370010000003070526002004000907006004";
  
  Sudoku s(grid_size, box_size, sudoku_str1, min_num, max_num, space);

  s.reset(grid_size, box_size, sudoku_str2, min_num, max_num, space);
  
  EXPECT_STREQ(sudoku_str2.c_str(), s.str().c_str());
}

TEST(SudokuTest, Write) {
  size_t grid_size = 9;
  size_t box_size = 3;
  int min_num = 1;
  int max_num = 9;
  int space = 0;
  std::string sudoku_str1 = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
  std::string sudoku_str1_modified = "217903600000080000900000507072010430000402070064370250701000065000030000005601720";
  
  Sudoku s(grid_size, box_size, sudoku_str1, min_num, max_num, space);

  s.write(0, 0, 2);
  
  EXPECT_STREQ(sudoku_str1_modified.c_str(), s.str().c_str());
}

TEST(SudokuTest, Solve) {
  size_t grid_size = 9;
  size_t box_size = 3;
  int min_num = 1;
  int max_num = 9;
  int space = 0;

  std::string sudoku_str1 = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
  std::string sudoku_str2 = "600100708000800200238050100000040092004308600370010000003070526002004000907006004";
  
  std::string result_str1 = "417953682256187943983246517872519436539462871164378259791824365628735194345691728";
  std::string result_str2 = "695123748741869253238457169816745392524398671379612485483971526162584937957236814";

  Sudoku s(grid_size, box_size, sudoku_str1, min_num, max_num, space);
  s.solve();
  EXPECT_STREQ(result_str1.c_str(), s.str().c_str());


  s.reset(grid_size, box_size, sudoku_str2, min_num, max_num, space);
  s.solve();
  EXPECT_STREQ(result_str2.c_str(), s.str().c_str());
}

int main() {
  RUN_ALL_TESTS();
  return 0;
}