
# ♟️ Chess Game in C++

### C++ | Console Application | Game Logic | File Handling

A two-player, console-based Chess Game developed in C++ as a programming fundamentals project.

The application provides an interactive 8×8 chessboard where two players can take turns moving chess pieces, capturing opponents' pieces, promoting pawns, saving and loading games, resigning, or agreeing to a draw.

The project demonstrates fundamental programming concepts, including **multidimensional arrays, functions, conditional logic, loops, input validation, and file handling**.

---

## Features

### Two-Player Gameplay

- Local two-player chess
- Alternating white and black turns
- Interactive console-based board
- Selection of pieces using row and column coordinates
- Move validation based on piece type
- Piece capture handling

### Chess Piece Movement

The application includes dedicated movement functions for all six chess piece types.

| Piece | Function | Implemented Movement |
|---|---|---|
| Pawn | `swapP()` | Forward movement and promotion logic |
| Rook | `swapR()` | Horizontal and vertical movement |
| Knight | `swapN()` | L-shaped movement |
| Bishop | `swapB()` | Diagonal movement |
| Queen | `swapQ()` | Combined rook and bishop logic |
| King | `swapK()` | Single-square movement |

**Note:** These are custom movement-validation implementations and are not fully compliant with official chess rules.

### Pawn Promotion

When a pawn reaches the opposite end of the board, the program provides promotion options:

- Queen
- Bishop
- Knight
- Rook

The existing implementation contains some promotion-symbol issues that require correction.

### Save and Load Games

The application supports three local save slots:

```text
saved1.txt
saved2.txt
saved3.txt
```

Players can save a game and attempt to restore it later.

The saved data includes the chessboard representation and, for some save slots, the current player's turn.

### Resignation and Draw Agreement

During gameplay, players can:

- Resign from the match
- Offer a draw through a handshake
- Accept a draw
- Continue playing if the draw is not accepted
- Save and quit

### Experimental Timer Modes

The source contains experimental timer functions for:

- Classic
- Rapid
- Blitz
- Lightning

These functions are commented out in the main implementation and are **not currently active gameplay features**.

---

## Technology Stack

| Category | Technology |
|---|---|
| Language | C++ |
| Interface | Console / Command Line |
| Board Representation | 2D Character Array |
| File Handling | `ifstream`, `ofstream` |
| Game Logic | Functions and Conditional Statements |
| Platform | Windows |
| Libraries | iostream, fstream, cstring, windows.h, conio.h |

---

## Game Architecture

```text
                Chess Game
                    |
              Welcome Screen
                    |
          +---------+---------+
          |                   |
       New Game            Load Game
          |                   |
          +---------+---------+
                    |
               Chessboard
                    |
             Current Player
                    |
              Select Piece
                    |
           Select Destination
                    |
           Validate Movement
                    |
          +---------+---------+
          |                   |
       Valid Move         Invalid Move
          |                   |
       Update Board       Retry Selection
          |
       Switch Turn
          |
       Next Player
```

---

## Project Structure

The three supplied source files are:

```text
Chess-Game-CPP/
|
|-- PfProject.cpp
|-- Source.cpp
|-- time.cpp
|-- README.md
```

### `PfProject.cpp`

The main chess application.

Contains:

- Board initialization and display
- Player turn management
- Chess piece movement functions
- Move selection and validation
- Pawn promotion logic
- Save/load functionality
- Resignation and draw handling
- Main game loop

### `Source.cpp`

An earlier, smaller chess implementation demonstrating:

- Board creation
- Coordinate selection
- Basic pawn movement
- Console board updates

This file contains a separate `main()` function and should be compiled independently.

### `time.cpp`

A small experimental program demonstrating C++ time functions.

This file also contains its own `main()` function and should be compiled independently.

---

## Installation and Setup

### Prerequisites

- Windows operating system
- C++ compiler
- Visual Studio or MinGW-w64

The main application uses Windows-specific headers:

```cpp
#include <windows.h>
#include <conio.h>
```

### Clone the Repository

```bash
git clone https://github.com/Emaan-Munib/Chess-Game-CPP.git
cd Chess-Game-CPP
```

### Compile the Main Game

Using a compatible Windows C++ compiler:

```bash
g++ PfProject.cpp -o ChessGame.exe
```

### Run the Game

```bash
ChessGame.exe
```

**Important:** Compile `PfProject.cpp` separately. The other source files contain independent `main()` functions.

Compilation and execution have not been verified in this repository package.

---

## How to Play

### 1. Start or Load a Game

When the program starts, choose whether to begin a new game or load an existing save.

### 2. Understand the Board

The program displays an 8×8 chessboard with numbered rows and lettered columns.

Pieces are represented by characters.

| Piece | White | Black |
|---|---|---|
| Pawn | P | p |
| Rook | R | r |
| Knight | N | n |
| Bishop | B | b |
| Queen | Q | q |
| King | K | k |

Uppercase letters represent white pieces, and lowercase letters represent black pieces.

### 3. Select a Piece

Enter the row and column of the piece you want to move.

For example:

```text
Select Row and column: 2 a
```

### 4. Select a Destination

Enter the destination row and column.

```text
Enter destination Row and column: 3 a
```

The program evaluates the movement using the selected piece's corresponding function.

### 5. Continue Playing

After a move, the turn switches to the other player.

Players can also resign, offer a draw, or save and quit.

---

## Core Implementation

### Chessboard Representation

The game uses a two-dimensional character array:

```cpp
char board[8][8];
```

Each position represents one square on the chessboard.

Uppercase and lowercase characters distinguish the two players.

### Turn Management

A Boolean variable tracks the current player:

```cpp
bool turn = 0;
```

The value switches after a move.

### Piece Movement

Each chess piece has its own movement function.

For example, knight movement is implemented using coordinate differences corresponding to an L-shaped move.

### File Handling

The game uses file streams to save and load board data.

Example:

```cpp
ofstream saveFile;
saveFile.open("saved1.txt");
```

Saved games are stored locally in text files.

---

## Programming Concepts Demonstrated

- Multidimensional arrays
- Functions and parameter passing
- Pass-by-reference
- Conditional statements
- Nested loops
- Input validation
- Character manipulation
- File input/output
- Global state management
- Turn-based game logic
- Console interaction
- Modular movement functions

---

## Known Limitations

This is an academic programming project rather than a complete chess engine.

### Movement Validation

Some movement functions contain logic errors, including assignment operators used where comparisons are intended.

This can cause incorrect board updates or invalid moves.

### Check and Checkmate

The current implementation does not perform complete chess check/checkmate detection.

Its game-ending logic is based primarily on identifying a king as a capture target.

### Missing Official Chess Rules

The project does not fully implement:

- Castling
- En passant
- Stalemate
- Threefold repetition
- Fifty-move rule
- Full king-safety validation

### Save/Load Reliability

The save and load logic is inconsistent between slots, and empty board squares may not be restored correctly.

### Pawn Promotion

Some promotion options use piece symbols incorrectly, potentially resulting in invalid board states.

### Platform Support

The application is designed for Windows and uses Windows-specific functions.

### Computer Opponent

The application supports two local players. It does not implement a computer-controlled opponent or chess AI.

---

## Future Improvements

- Fix piece movement validation
- Implement complete legal move detection
- Add proper check and checkmate detection
- Implement castling and en passant
- Improve pawn promotion
- Add stalemate and draw detection
- Improve save/load serialization
- Implement chess clocks
- Add an AI opponent
- Add move history and undo functionality
- Refactor the application into classes
- Develop a graphical chessboard
- Add automated tests for movement rules
- Improve cross-platform compatibility

---

## Project Status

**Academic C++ Programming Fundamentals Project**

This project demonstrates a two-player chess application built with procedural C++ programming techniques.

It serves as a foundation for exploring game development, board representation, movement algorithms, file handling, and interactive console applications.

Further debugging and rule validation are needed before the game can be considered a complete chess implementation.
