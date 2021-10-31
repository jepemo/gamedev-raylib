all: build exec

build:
	make -C tests

exec:
	ls bin | fzf | awk '{print "./bin/"$$1}' | sh
