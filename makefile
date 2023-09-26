CC = gcc
CFLAGS = -Wall
SRCFILES = src/read_pk1.o src/main.o
TARGET = bin/read_pokemon

all: $(TARGET)

$(TARGET): $(SRCFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCFILES)

clean:
	rm -f $(TARGET)
	rm -f $(SRCFILES)
