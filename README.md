# Hangman Game

## Introduction

Welcome to the Hangman Game, a classic word-guessing game where you try to uncover a hidden word by guessing individual letters. This C program is designed to offer a challenging and entertaining experience, allowing users to choose difficulty levels and test their vocabulary.

## Features

### 1. Difficulty Levels

Choose your difficulty level:
- **Easy (1):** Guess words from a simple vocabulary.
- **Medium (2):** Increase the challenge with a more diverse set of words.
- **Hard (3):** Test your skills with complex words.

### 2. Gameplay

- **Random Word Selection:** A word is randomly chosen from the respective text file based on the selected difficulty level.
- **Hangman Structure:** A visual representation of the hangman structure is displayed to indicate incorrect guesses.
- **Input Letters:** Enter letters to guess the hidden word. Incorrect guesses contribute to the hangman's structure.
- **Used Letters:** Track the letters you've already guessed.
- **Win or Lose:** Successfully guess the word within six incorrect attempts to win, or reach six incorrect attempts to lose.

### 3. Session Score

- **Games Won:** Track the number of games won during a session.
- **Total Games Played:** Keep a count of the total games played in a session.
  
After each play session, the program displays a session score:

```plaintext
****************************
*  Session score:   X/Y    *
****************************
```

Here, `X` represents the number of games won, and `Y` represents the total games played in that session.

### 4. Level Files

- **Easy Level (easy.txt):** Simple words suitable for beginners.
- **Medium Level (medium.txt):** A mix of common and more challenging words.
- **Hard Level (hard.txt):** Complex words for advanced players.

## How to Play

1. Run the program and choose a difficulty level (1 for easy, 2 for medium, 3 for hard).
2. Guess letters to uncover the hidden word.
3. Observe the hangman structure for incorrect guesses.
4. Track used letters to avoid repetition.
5. Win by guessing the word within six incorrect attempts.
6. Optionally play multiple games in one session.

## Code Overview

The code is organized into functions, making it modular and easy to understand. Key functions include:

- `play_session(int level)`: Manages the gameplay for a selected difficulty level.
- `load_file(int level)`: Loads the appropriate word file based on the difficulty level.
- `sessions_score(int Won, int Total)`: Prints the session score with the number of games won and total games played.
- `print_init_hangman(void)`: Prints the initial hangman structure.

## How to Run

1. Compile the code using a C compiler.
2. Run the executable.
3. Follow on-screen instructions to choose the difficulty level and play.

## Game Structure
The game presents a hangman structure with each incorrect guess.
Visual feedback includes used letters, remaining guesses, and the partially revealed word.
