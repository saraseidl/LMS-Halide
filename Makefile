CC = gcc
CFLAGS = -Wall -lpng
DEPS = testOutput/pipeline.h
OBJ = ./testOutput/blurry.o builder.o
OBJ1 = ./testOutput/blur_split_y_inner.o builder.o
OBJ2 = ./testOutput/blur_split_y_outer.o builder.o
OBJ3 = ./testOutput/blur_split_storeCompute.o builder.o
OBJ4 = ./testOutput/blur_tile_splitCompute.o builder.o
OBJ5 = ./testOutput/blur_tile_y_outer.o builder.o
OBJ6 = ./testOutput/blur_tile_y_inner.o builder.o


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

builder: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

blur_split_inner: $(OBJ1)
	gcc $(CFLAGS) -o $@ $^

blur_split_outer: $(OBJ2)
	gcc $(CFLAGS) -o $@ $^

blur_split_store: $(OBJ3)
	gcc $(CFLAGS) -o $@ $^

blur_tile_inner: $(OBJ6)
	gcc $(CFLAGS) -o $@ $^

blur_tile_outer: $(OBJ5)
	gcc $(CFLAGS) -o $@ $^

blur_tile_store: $(OBJ4)
	gcc $(CFLAGS) -o $@ $^
