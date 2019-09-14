SRC_DIR = src
OBJ_DIR = obj
CC = g++
CFLAGS = -c -Wall -I"./include"
LDFLAGS =
SOURCES = $(SRC_DIR)/task_1_main.cpp $(SRC_DIR)/task_1_core.cpp
OBJECTS = $(OBJ_DIR)/task_1_main.o $(OBJ_DIR)/task_1_core.o
EXECUTABLE = task_1

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE) csv_out/*.csv