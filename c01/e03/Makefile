CC:=clang
CFLAGS:=-std=c17 -Wall -Wextra -Wpedantic -O0 -g
SAN:=-fsanitize=address,undefined -fno-omit-frame-pointer
BIN:=dweight
SRC:=$(wildcard *.c)

all:
	$(CC) $(CFLAGS) $(SAN) $(SRC) -o $(BIN)

run: all
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: all run clean
