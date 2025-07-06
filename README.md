

<h3> Launch</h3>

```bash

g++ game/main.cpp game/board/Board.cpp game/figures/King/King.cpp game/figures/Queen/Queen.cpp game/figures/Knight/Knight.cpp game/figures/Bishop/Bishop.cpp game/figures/Rook/Rook.cpp game/figures/Pawn/Pawn.cpp game/figures/Figure.cpp game/Hint/Hint.cpp game/Game.cpp -Igame -Igame/core -Igame/figures -Igame/figures/Pawn -Igame/figures/Bishop -Igame/figures/King -Igame/figures/Knight -Igame/figures/Queen -Igame/figures/Rook -Igame/board -Igame/Hint -o chess -lsfml-graphics -lsfml-window -lsfml-system

./chess

```

<h3>To-do list</h3>

- [] makefile
- [] board simulation simplifying
- [] strategy pattern
- [] command pattern
- [] dynamic_cast<> for vector with pieces
- [] menu
- [] en passant
- [] fix methods in class Game



