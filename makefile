CC = gcc
CFLAGS = -Wall -g
SRCFILES = src/main.o src/pokemon_file_type.o src/saves/read_rb_international.o src/pokemon/tables.o src/pokemon/read_pk1.o src/pokemon/read_pk2.o
TARGET = bin/read_pokemon

all: $(TARGET)

$(TARGET): $(SRCFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCFILES)

clean:
	rm -f $(SRCFILES)
