#include <Sudoku.hpp>

void menu() {
  Sudoku sudoku;
  std::string input;
  while (true) {
    std::cout << "\nSudoku Menu:" << std::endl;
    std::cout << "1. Initialize Sudoku" << std::endl;
    std::cout << "2. Reset Sudoku" << std::endl;
    std::cout << "3. Show" << std::endl;
    std::cout << "4. Write" << std::endl;
    std::cout << "5. Inference" << std::endl;
    std::cout << "6. Solve" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    if (input == "1") {
      int grid_size, box_size, min_num, max_num, space;
      std::string sudoku_str;
      std::cout << "Enter grid size (default 9): " << std::endl;
      std::cin >> grid_size;
      std::cout << "Enter box size (default 3): " << std::endl;
      std::cin >> box_size;
      std::cout << "Enter min number (default 1): " << std::endl;
      std::cin >> min_num;
      std::cout << "Enter max number (default 9): " << std::endl;
      std::cin >> max_num;
      std::cout << "Enter space number (default 0): " << std::endl;
      std::cin >> space;
      std::cout << "Enter sudoku string(e.g., '017903600000080000900000507072010430000402070064370250701000065000030000005601720'): " << std::endl;
      std::cin >> sudoku_str;
      sudoku =Sudoku(grid_size, box_size, sudoku_str, min_num, max_num, space);
      if (sudoku_str.length() != grid_size * grid_size &&
          sudoku.valid()) {
        std::cout << "Invalid Input. Please try again." << std::endl;
        continue;
      }

    } else if (input == "2") {
      int grid_size, box_size, min_num, max_num, space;
      std::string sudoku_str;
      std::cout << "Enter grid size (default 9): " << std::endl;
      std::cin >> grid_size;
      std::cout << "Enter box size (default 3): " << std::endl;
      std::cin >> box_size;
      std::cout << "Enter min number (default 1): " << std::endl;
      std::cin >> min_num;
      std::cout << "Enter max number (default 9): " << std::endl;
      std::cin >> max_num;
      std::cout << "Enter space number (default 0): " << std::endl;
      std::cin >> space;
      std::cout << "Enter sudoku string(e.g., '017903600000080000900000507072010430000402070064370250701000065000030000005601720'): " << std::endl;
      std::cin >> sudoku_str;
      sudoku.reset(grid_size, box_size, sudoku_str, min_num, max_num, space);
      if (sudoku_str.length() != grid_size * grid_size &&
          sudoku.valid()) {
        std::cout << "Invalid Input. Please try again." << std::endl;
        continue;
      }
      
    } else if (input == "3") {
      sudoku.show();

    } else if (input == "4") {
      int row, col, num;
      std::cout << "Enter row (index starts at 0): ";
      std::cin >> row;
      std::cout << "Enter column (index starts at 0): ";
      std::cin >> col;
      std::cout << "Enter your number: ";
      std::cin >> num;
      if (sudoku.write(row, col, num))
        std::cout << "Write complete" << std::endl;
      else 
        std::cout << "Write fail" << std::endl;

    } else if (input == "5") {
      sudoku.inference();

    } else if (input == "6") {
      sudoku.solve();

    } else if (input == "7") {
      std::cout << "Exiting..." << std::endl;
      break;
      
    } else {
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  }
}

int main() {
    menu();
    return 0;
}