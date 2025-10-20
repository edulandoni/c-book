C Programming: A Modern Approach (2nd Edition) Exercises
Welcome to my collection of exercises and notes from K. N. King's C Programming: A Modern Approach (2nd Edition). This repo helps me practice C in a structured way using modern tools.
Quick Setup

Prerequisites: Clang or GCC, Make. Optional: GDB (debugger) and Valgrind (memory checker).
On Fedora: Run sudo dnf groupinstall "Development Tools" -y && sudo dnf install -y clang gdb valgrind.

Building and Running
Each exercise has its own Makefile for simplicity.

From repo root: make DIR=c01/e01 run (replace c01/e01 with the chapter/exercise).
Inside an exercise folder: make run to build and execute.
Clean up: make clean.

The Makefiles use C17 standard with warnings enabled (-Wall -Wextra -Wpedantic) and sanitizers for safer code.
Directory Structure
Organized by chapter and exercise:

cNN/eMM (e.g., c01/e01 for Chapter 1, Exercise 1).

Conventions

No binaries (like app or *.o) committed—keep the repo clean!
Code formatted with clang-format for consistency.

License
MIT for my code. No book content included here—buy the book for that! 📖
