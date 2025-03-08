CC = gcc
CFLAGS = -Wall -std=c99 -Os -s -Isrc
SRCFILES = src/main.o src/pokemon_file_type.o src/data/tables.o src/saves/read_rb_international.o src/pokemon/read_pk1.o src/pokemon/print_pk1.o src/pokemon/read_pk2.o
TARGET = bin/read_pokemon

all: $(TARGET)

$(TARGET): $(SRCFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCFILES)

clean:
	rm -f $(SRCFILES)
