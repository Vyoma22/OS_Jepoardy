# Jeopardy Game - SOFE 3950U 

## Project Overview
This is a command-line implementation of the classic Jeopardy game, developed as part of the Operating Systems course (SOFE 3950U). The game supports up to four players and follows the traditional Jeopardy format, where players take turns selecting questions from different categories, answering them in the correct format, and tracking their scores.

## Features
- Command-line interface for seamless gameplay
- Supports four players with dynamic name input
- Randomized question selection from predefined categories
- Answer validation using string tokenization
- Score tracking and final ranking display
- Modular design with separate source files for better maintainability

## File Structure
- **jeopardy.c** - Main game loop and core logic
- **jeopardy.h** - Header file containing function declarations
- **questions.c / questions.h** - Stores categories, questions, and answer validation functions
- **players.c / players.h** - Manages player data and scoring
- **Makefile** - Automates compilation and builds the executable

## Installation & Setup
### Prerequisites
Ensure you have the following installed:
- GCC compiler
- Make utility
- Git (optional, for version control)

### Cloning the Repository

$ git clone <repository_url>
$ cd jeopardy_game


### Compilation
To compile the program, run:

$ make

This will generate the `jeopardy.exe` executable.

To clean up object files and binaries:

$ make clean


## How to Play
1. Run the executable:
   
   $ ./jeopardy.exe
   
2. Enter the names of the four players.
3. Players take turns selecting a category and question value.
4. Answer the question using the format **"What is"** or **"Who is"**.
5. If correct, the player's score updates; if incorrect, the correct answer is displayed.
6. The game ends when all questions have been answered, and the final scores are displayed.

## Debugging & Known Issues
- Loop Adjustments in `jeopardy.c`: We encountered issues where the game logic caused infinite loops or premature exits. These were resolved by refining loop conditions and properly handling user inputs.
- String Handling: Input validation and tokenization were extensively tested to ensure correct parsing of answers.


## Contributors
Vyoma Shah
Wang-Ying Su
Maisha Zarrin Subha
Marwan Alam

## License
This project is for educational purposes only.



