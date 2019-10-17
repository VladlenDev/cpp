SRC_DIR = src
OBJ_DIR = obj
CC = g++
CFLAGS = -c -Wall -I"./include"
LDFLAGS =
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Ball.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/Base.cpp $(SRC_DIR)/Game.cpp
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/Ball.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Base.o $(OBJ_DIR)/Game.o
EXECUTABLE = task_3

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)