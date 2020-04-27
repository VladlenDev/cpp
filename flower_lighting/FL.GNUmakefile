SRC_DIR = src
OBJ_DIR = obj
CC = g++
CFLAGS = -c -Wall -I"./include"
LDFLAGS =
SOURCES = $(SRC_DIR)/main.cpp
OBJECTS = $(OBJ_DIR)/main.o
EXECUTABLE = flowerLighting

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)