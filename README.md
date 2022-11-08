# Filler

#### **Introduction**

**Filler** is a project about algorithmic game, purpose of which is to fill a fixed sized grid with pieces of random size and shape. Pieces can’t be stacked more than one square above each other and they can’t exceed the grid. If these conditions are not met - the game ends.

The game is played between two players taking turns at placing a piece. Each successfully placed piece yields a number of points. The goal of the game is get the highest score possible. During the game each player attempts to place as many pieces as possible on the grid while attempting to prevent his or her opponent from doing the same. At the end of the game, the player with the most points wins the match.

The game itself is played on a host VM provided with the subject. Each turn VM gives the player in turn information about the grid, its size and current state. It also tells the player what kind of piece needs to be placed on the aforementioned grid. Player’s objective is to answer the MV with a set of coordinates after which it’s the other player’s turn to do the same with the next given piece.

**Usage**

Compile the executable with Makefile:

```bash
make && make clean
```

To run the program against another player, launch it from the root of the repository:

```bash
./resources/filler_vm -p1 ./tlahin.filler -p2 ./resources/players/carli.filler -f ./resources/maps/map02
```

Subject: [filler.en.pdf](https://cdn.intra.42.fr/pdf/pdf/6630/filler.en.pdf)
