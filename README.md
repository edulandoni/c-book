C Programming: A Modern Approach — 2nd Edition (Exercises)

Exercises and notes for K. N. King’s book. 

Built with clang, standard C17, one Makefile per exercise. Layout uses cNN/eMM directories such as c01/e01, c01/e02, etc. 

Prerequisites: clang or gcc and make; optionally gdb and valgrind. 

On Fedora, install with: sudo dnf groupinstall "Development Tools" -y && sudo dnf install -y clang gdb valgrind. 

To run from the repo root use: make DIR=c01/e01 run. To run inside an exercise use: make run. 

Per-exercise Makefile template: CC:=clang; CFLAGS:=-std=c17 -Wall -Wextra -Wpedantic -O0 -g; SAN:=-fsanitize=address,undefined -fno-omit-frame-pointer; BIN:=app; SRC:=$(wildcard *.c); target all builds with $(CC) $(CFLAGS) $(SAN) $(SRC) -o $(BIN); target run depends on all and executes ./$(BIN); target clean removes $(BIN); declare .PHONY for all run clean. 

Conventions: directories are cNN/eMM (chapter NN, exercise MM); do not commit binaries like app or *.o; format code with clang-format. 

License: MIT for my code; no book content included.


