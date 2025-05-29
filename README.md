<h1>Chess clone</h1>

<h3> Launch</h3>

```bash

g++ main.cpp board.cpp path_size.cpp -o chess-app -lsfml-graphics -lsfml-window -lsfml-system
./chess-app

```

---

<h2>Total to_do_list:</h2>

- [] get_possible_moves for each figure
- [] split method Game::run() into some another methods
- [] add state pattern 
- [] makefile

---
<h2>Diary to_do_list:</h2> 

## Thursday - 01.05.25
- [x]  make assets
- [x]  draw base board
- [x] started making class "Board" for drawing chess board by cells



## Friday - 02.05.25
- [x] finish class Board
- [x] start making new class "Figures"


## Thursday - 08.05.25

- [x] class "Figure"
- [x] class "Pawn"


## Friday - 09.05.25

- [] finish class "Pawn"
- [x] try to start class "Game"

## Monday - 12.05.25

- [x] finish class "Pawn"
- [x] try to start class "Game"

## Tuesday - 13.05.25
- [x] finish class "Pawn" for print
- [x] correct class "Figure"
- [x] print Pawns

![13.05.25 result](temp/screenshots/130525.png)

## Thursday - 15.05.25
- [] make makefile
- [x] do interact with figures
- [x] display another figures

![15.05.25](temp/screenshots/150525.png)

## Tuesday - 20.05.25
- [x] bug fixing Game::run()
- [x] method is_current_move for Pawns
- [x] method get_possible_moves for Pawns

## Tuesday - 27.05.25
- [x] fix class board
- [x] method Game::run() optimization
- [x] move pawns correctly

## Wednesday - 28.05.25 General refactoring
- [] State pattern  
- [] refactoring class Game 
- [x] refactoring class Board

## Wednesday - 29.05.25 General refactoring done
- [x] State pattern  
- [x] refactoring class Game 

Added enum class Action, which used for different game conditions. Refactored class Game(splited method Game::run() into some new methods)
code became more readable
---

