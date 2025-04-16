# Compiler and flags
CC = gcc
CFLAGS = -c
OBJ = currency.o deck.o main.o hand.o actions.o player.o dealer.o round.o
TARGET = out

# Default target
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile each .c file into .o
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Clean up build files
clean:
	rm -f *.o $(TARGET)
