current_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

all:
	@echo "make <option>"
	@echo "  setup: Download and compiles raylib"
	@echo "  build: Compiles all tests and minigames"
	@echo "  exec: Show and execute a build"
	@echo "  clean: Cleans the bin directory" 

.PHONY: setup
setup:
	rm -Rf raylib
	git clone https://github.com/raysan5/raylib.git raylib
	cd raylib/src/
	make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED
	sudo make install RAYLIB_LIBTYPE=SHARED
	cd $(current_dir)
	mkdir -p bin

.PHONY: build
build:
	make -C tests
	make -C games

.PHONY: exec
exec:
	ls bin | fzf | awk '{print "./bin/"$$1}' | sh

.PHONY: clean
clean:
	rm -Rf bin/*
