SRC_DIR = src
OBJ_DIR = obj
CC = g++
CFLAGS = -c -Wall -I"./include"
LDFLAGS =
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Gate.cpp $(SRC_DIR)/Tracklist.cpp
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/Gate.o $(OBJ_DIR)/Tracklist.o
EXECUTABLE = task_2

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)