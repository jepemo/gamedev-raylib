all: build exec

build:
	mkdir -p bin
	make -C tests

exec:
	ls bin | fzf | awk '{print "./bin/"$$1}' | sh
