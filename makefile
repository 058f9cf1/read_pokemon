CC = gcc
CFLAGS = -Wall
SRCFILES = src/main.o src/tables.o src/read_pk1.o src/read_pk2.o
TARGET = bin/read_pokemon

all: $(TARGET)

$(TARGET): $(SRCFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCFILES)

clean:
	rm -f $(TARGET)
	rm -f $(SRCFILES)
