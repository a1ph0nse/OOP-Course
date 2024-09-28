from Sudoku import Sudoku

def menu():
  sudoku = ''
  while True:
    print("\nSudoku Menu:")
    print("1. Initialize Sudoku")
    print("2. Reset Sudoku")
    print("3. Show")
    print("4. Write")
    print("5. Inference")
    print("6. Solve")
    print("7. Exit")
    choice = input("Enter your choice: ")

    if choice == '1':
      grid_size = int(input("Enter grid size (default 9): ") or 9)
      box_size = int(input("Enter box size (default 3): ") or 3)
      min_num = int(input("Enter min number (default 1): ") or 1)
      max_num = int(input("Enter max number (default 9): ") or 9)
      space = int(input("Enter space number (default 0): ") or 0)
      sudoku_str = input("Enter sudoku string (e.g., '017903600000080000900000507072010430000402070064370250701000065000030000005601720')")
      print(sudoku)
      if (len(sudoku_str) != grid_size * grid_size and
          sudoku.valid()):
        print("Invalid Input. Please try again.")
        continue
      sudoku = Sudoku(grid_size, box_size, sudoku_str, min_num, max_num, space)

    elif choice == '2':
      if sudoku == '':
        print("Please initialize sudoku first")
        continue
      grid_size = int(input("Enter grid size (default 9): ") or 9)
      box_size = int(input("Enter box size (default 3): ") or 3)
      min_num = int(input("Enter min number (default 1): ") or 1)
      max_num = int(input("Enter max number (default 9): ") or 9)
      space = int(input("Enter space number (default 0): ") or 0)
      sudoku_str = input("Enter sudoku string (e.g., '017903600000080000900000507072010430000402070064370250701000065000030000005601720')\n")
      if (len(sudoku_str) != grid_size * grid_size and
          sudoku.valid()):
        print("Invalid Input. Please try again.")
        continue
      sudoku.reset_sudoku(grid_size, box_size, sudoku_str, min_num, max_num, space)

    elif choice == '3':
      if sudoku == '':
        print("Please initialize sudoku first")
        continue
      sudoku.show()
    elif choice == '4':
      if sudoku == '':
        print("Please initialize sudoku first")
        continue
      row = int(input("Enter row (index starts at 0): "))
      col = int(input("Enter column (index starts at 0): "))
      num = int(input("Enter your number: "))
      if sudoku.write(row, col, num):
        print("write complete")
      else:
        print("write fail")

    elif choice == '5':
      if sudoku == '':
        print("Please initialize sudoku first")
        continue
      sudoku.inference()

    elif choice == '6':
      if sudoku == '':
        print("Please initialize sudoku first")
        continue
      sudoku.solve()

    elif choice == '7':
      print("Exiting...")
      break

    else:
        print("Invalid choice. Please try again.")

if __name__ == "__main__":
    menu()