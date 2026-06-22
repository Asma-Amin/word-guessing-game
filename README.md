# Word Guessing Game 🎯

A CLI-based word guessing game built in **C++** using Object-Oriented Programming principles.

---

## About

This game challenges players to guess a hidden word letter by letter before running out of attempts. The difficulty level controls word complexity and the number of allowed attempts, making it suitable for different skill levels.

Built as part of my C++ and OOP coursework at Lahore Garrison University.

---

## Features

- 3 difficulty levels — Easy, Medium, and Hard
- Dynamic word bank with 100+ words across all levels
- Letter-by-letter guessing with duplicate detection
- Live scoring system (earn points for correct guesses, lose for wrong ones)
- Replay option with round counter
- Clean CLI interface

## Difficulty Levels

| Level | Word Length | Attempts |
|-------|------------|----------|
| Easy | Short (3–4 letters) | 10 |
| Medium | Medium (5–7 letters) | 7 |
| Hard | Long (8+ letters) | 5 |

---

## OOP Concepts Used

- **Classes** — `WordBank` and `WordGame`
- **Inheritance** — `WordGame` extends `WordBank`
- **Encapsulation** — private game state, public methods
- **Static methods** — for difficulty configuration

---

## How to Run

**Requirements:** A C++ compiler (g++ recommended)

```bash
g++ word_guessing_game.cpp -o word_guessing_game
./word_guessing_game
```

On Windows:
```bash
g++ word_guessing_game.cpp -o word_guessing_game.exe
word_guessing_game.exe
```

---

## Tech Stack

- Language: C++
- Paradigm: Object-Oriented Programming
- Interface: Command Line (CLI)

---

---

## A Note on Development Process

This project was developed using **AI-assisted development** as part of my learning workflow. I used AI tools to help structure ideas, debug logic, and improve code quality — however, all core decisions, modifications, testing, and understanding of the code were done by me personally.

I believe using AI as a thinking partner is a real and valuable skill in modern software development. My approach involved:
- Forming the idea and game logic myself first
- Using AI to suggest improvements and catch bugs
- Critically reviewing every suggestion before applying it
- Making my own modifications to fit the actual requirements
- Testing and verifying the final output myself

This reflects how AI tools are actually used in real development environments — not as a replacement for thinking, but as a tool that makes thinking sharper.

---

## Author

**Asma Amin**
BSIT Student — Lahore Garrison University
