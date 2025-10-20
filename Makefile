# Uso: make DIR=cap01/ej01 run
DIR ?= c01/e01
run: ; $(MAKE) -C $(DIR) run
build: ; $(MAKE) -C $(DIR)
clean: ; $(MAKE) -C $(DIR) clean
.PHONY: run build clean
