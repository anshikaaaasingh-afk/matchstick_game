# Matchstick Game (Nim) 🔥

A terminal-based Matchstick game written in C — classic Nim, played against
an unbeatable computer opponent.

## Rules

- The game starts with a random pile of matchsticks.
- Players take turns removing **1, 2, or 3** matchsticks from the pile.
- Whoever is forced to take the **last** matchstick **loses**.
- You go first, then the computer.

## Demo

```
=== Matchstick Game (Nim) ===
Whoever takes the LAST matchstick LOSES.
Starting matches: 21

Matches left: 21
Take 1 to 3 matchsticks: 2
You took 2 matchstick(s).

Computer takes 3 matchstick(s).

Matches left: 16
Take 1 to 3 matchsticks: ...
```

## How the Computer Plays

The computer uses simple Nim strategy: it always tries to leave a
**multiple of 4** matchsticks for you after its turn. Once it can maintain
that pattern, it's mathematically guaranteed to win — so play carefully!

## Getting Started

### Prerequisites

- A C compiler (`gcc` or similar)

### Compile

```bash
gcc -o matchstick_game matchstick_game.c
```

### Run

```bash
./matchstick_game
```

## Features

- Clean, single-file implementation (~90 lines)
- Random starting pile size for replayability
- Input validation (rejects invalid or out-of-range moves)
- Simple, unbeatable computer AI based on Nim theory

## Customize

Change the range of starting matchsticks by editing these constants at the
top of `matchstick_game.c`:

```c
#define MIN_MATCHES 10
#define MAX_MATCHES 30
```

You could also extend the game to let players choose the max pick per turn,
or add a two-player mode.

## Project Structure

```
matchstick-game/
├── matchstick_game.c   # Game logic
└── README.md           # This file
```

## License

Free to use and modify for personal or educational purposes.
