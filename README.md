# Tile-Movement-Game

### Overview  
This project is an implementation of a **Tile Movement Game** using **C++**. The goal of this assignment is to practice working with **2D matrices** using a `vector<vector<char>>` data structure. The program reads an initial matrix from a file and then allows the user to move tiles based on specific rules.  

### Game Rules  
- The matrix contains **four directional characters** (`r`, `l`, `u`, `d`) and an **empty cell** (`-`).  
- Tiles move in the direction they point to until they are blocked or fall off the edge.  
- The user inputs row and column indices to select a tile to move.  
- The game continues until **no moves are possible** or **all tiles are removed**.  

### Input Format  
#### File Input  
The game reads a **text file** containing a **2D character matrix**.  
- Each row must have the same number of columns.  
- Only the following characters are allowed:  
  - `r` → Right  
  - `l` → Left  
  - `u` → Up  
  - `d` → Down  
  - `-` → Empty Cell  

Example file content (`matrix.txt`):  
```
r - u u d u r  
l u - u - - l  
- u d r d u -  
```

#### Keyboard Input  
After loading the matrix, the user **inputs row and column indices** to move a tile.  
- Invalid indices will prompt an error message.  
- The game runs **until all moves are exhausted**.  

### Program Flow  
1. **Prompt for a filename** and load the matrix.  
2. **Validate file content** (check for correct characters and uniform row lengths).  
3. **Display the matrix** before starting the game.  
4. **Process user moves** based on the tile's direction.  
5. **Update the matrix** and display it after each move.  
6. End the game when **no moves are possible** or **all tiles are removed**.  

### Compilation & Execution  
#### Compile the program:  
```bash
g++ -std=c++11 -o tile_game main.cpp
```
#### Run the program:  
```bash
./tile_game
```

### Example Run  
```
Please enter the file name:  
matrix.txt  

The matrix file contains:  
r - u u d u r  
l u - u - - l  
- u d r d u -  

Please enter the row and column of the tile that you want to move:  
0 6  

Tile at (0,6) has been moved.  
r - u u d u -  
l u - u - - l  
- u d r d u -  
```

### Restrictions  
- **No global variables** allowed.  
- **No `break` or `continue` statements**.  
- **Only standard C++ libraries** can be used.  
- The program must follow proper **modularization** and **coding standards**. 

---

Good luck! 🚀  
