CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: FileMaster

FileMaster: main.o file_manager.o utils.o
    $(CC) $(CFLAGS) -o FileMaster main.o file_manager.o utils.o

main.o: src/main.c
    $(CC) $(CFLAGS) -c src/main.c

file_manager.o: src/file_manager.c
    $(CC) $(CFLAGS) -c src/file_manager.c

utils.o: src/utils.c
    $(CC) $(CFLAGS) -c src/utils.c

clean:
    rm -f *.o FileMaster
