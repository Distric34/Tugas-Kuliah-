CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic
TARGET = program_sort
OBJS = main.o sort_basic.o sort_insertion.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c sorting.h
	$(CC) $(CFLAGS) -c main.c

sort_basic.o: sort_basic.c sorting.h
	$(CC) $(CFLAGS) -c sort_basic.c

sort_insertion.o: sort_insertion.c sorting.h
	$(CC) $(CFLAGS) -c sort_insertion.c

clean:
	rm -f *.o $(TARGET) $(TARGET).exe luaran.txt