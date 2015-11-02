CC=gcc
CFLAGS=-c -Wall
SOURCES=aligned_arrays.c aligned_arrays_optimized.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLES=aligned_arrays aligned_arrays_optimized

all: $(EXECUTABLES)

aligned_arrays: $(OBJECTS)
	$(CC) aligned_arrays.o -o $@

aligned_arrays_optimized: $(OBJECTS)
	$(CC) aligned_arrays_optimized.o -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES) $(OBJECTS) 
