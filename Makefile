CC = gcc
CFLAGS = -Wall -lpng
DEPS = testOutput/pipeline.h
OBJ = ./testOutput/blurry.o builder.o
OBJ1 = ./testOutput/bsi.o builder.o
OBJ2 = ./testOutput/bso.o builder.o
OBJ3 = ./testOutput/bss.o builder.o
OBJ4 = ./testOutput/bts.o builder.o
OBJ5 = ./testOutput/bto.o builder.o
OBJ6 = ./testOutput/bti.o builder.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: test bsi bso bss bti bto bts

test: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

builder: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

bsi: $(OBJ1)
	gcc $(CFLAGS) -o $@ $^

bso: $(OBJ2)
	gcc $(CFLAGS) -o $@ $^

bss: $(OBJ3)
	gcc $(CFLAGS) -o $@ $^

bti: $(OBJ6)
	gcc $(CFLAGS) -o $@ $^

bto: $(OBJ5)
	gcc $(CFLAGS) -o $@ $^

bts: $(OBJ4)
	gcc $(CFLAGS) -o $@ $^