CC = gcc
CFLAGS = -Wall -lpng
DEPS = testOutput/pipeline.h
OBJ = ./testOutput/blurry.o builder.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

builder: $(OBJ)
	gcc $(CFLAGS) -o $@ $^


very_blurred: $(OBJ)
	gcc $(CFLAGS) -o $@ $^


