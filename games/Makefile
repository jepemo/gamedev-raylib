bins := $(patsubst %.c,%.bin,$(wildcard *.c))
CC := cc
CFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: $(bins)

%.bin : %.c
	cc $< $(CFLAGS) -o ../bin/$@	