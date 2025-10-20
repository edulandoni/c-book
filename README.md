# C Programming: A Modern Approach (2nd Edition) — Exercises

Practice repository for exercises from K. N. King’s *C Programming: A Modern Approach* (2nd ed.). Goals: disciplined C17 practice, reproducible builds with make, strict warnings, and basic tooling.

## Quick Setup

- **Toolchain:** Clang or GCC, make. Optional: gdb and valgrind.
- **Fedora**
    
        sudo dnf groupinstall -y "Development Tools"
        sudo dnf install -y clang gcc make gdb valgrind

- **Verify**
    
        clang --version || gcc --version
        make --version

## Repository Layout

        .
        ├── c01/
        │   ├── e01/
        │   │   ├── main.c
        │   │   └── Makefile
        │   └── e02/
        │       ├── main.c
        │       └── Makefile
        ├── common.mk        # shared flags
        ├── Makefile         # convenience targets to run any exercise
        └── README.md

## Building and Running

Each exercise folder is standalone with its own Makefile.

- **From repo root** (replace `c01/e01` with the target):
    
        make DIR=c01/e01 run

- **Inside an exercise folder**:
    
        make run     # build and execute
        make clean   # remove build artifacts

## Compiler Flags

Strict by default.

- Warnings: `-Wall -Wextra -Wpedantic -Werror`
- Standard: `-std=c17`
- Debug: `-O0 -g`
- Sanitizers (Clang/GCC): `-fsanitize=address,undefined` (when available)

These are centralized in `common.mk`.

## Debugging and Analysis

- **GDB**
    
        make DIR=c01/e01 debug     # starts gdb ./build/main

- **Valgrind**
    
        make DIR=c01/e01 memcheck  # valgrind --leak-check=full ./build/main

## Style

- One exercise per folder named `cNN/eMM`.
- Single entry point `main.c` per exercise unless the book suggests more files.
- No global state unless required by the exercise.
- Short functions, clear names, and consistent formatting (`clang-format` optional).

## Common Makefile (`common.mk`)

Put this file at repo root.

        # common.mk
        CC ?= clang
        CSTD ?= c17
        WARN := -Wall -Wextra -Wpedantic -Werror
        DBG  := -O0 -g
        SAN  := -fsanitize=address,undefined
        CFLAGS ?= -std=$(CSTD) $(WARN) $(DBG) $(SAN)
        LDFLAGS ?= $(SAN)

        BUILD_DIR ?= build
        TARGET ?= $(BUILD_DIR)/main
        SRC ?= main.c

        $(BUILD_DIR):
        	@mkdir -p $(BUILD_DIR)

        $(TARGET): $(SRC) | $(BUILD_DIR)
        	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

        .PHONY: run clean debug memcheck
        run: $(TARGET)
        	./$(TARGET)

        debug: $(TARGET)
        	gdb ./$(TARGET)

        memcheck: $(TARGET)
        	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

        clean:
        	@rm -rf $(BUILD_DIR)

## Exercise Makefile (template)

Put this file inside each `cNN/eMM/` folder.

        # cNN/eMM/Makefile
        include ../../common.mk
        SRC := main.c

## Root Makefile (convenience)

Allows running any exercise from repo root with `DIR=...`.

        # Makefile (root)
        .PHONY: run clean debug memcheck
        run:
        	@$(MAKE) -C $(DIR) -f Makefile run
        clean:
        	@$(MAKE) -C $(DIR) -f Makefile clean
        debug:
        	@$(MAKE) -C $(DIR) -f Makefile debug
        memcheck:
        	@$(MAKE) -C $(DIR) -f Makefile memcheck

## Troubleshooting

- Missing headers: install “Development Tools”.
- Sanitizer not supported: remove `-fsanitize=...` in `common.mk`.
- Prefer GCC: set `CC=gcc`.

## License

MIT. See `LICENSE`.

## Credits

Exercises from K. N. King’s book. For personal study and notes.

