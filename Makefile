CC = clang
CFLAGS = -Wall -O2
BIN_DIR = ./bin

tree: 
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c tree.c -o $(BIN_DIR)/tree.o
	$(CC) -o $(BIN_DIR)/tree $(BIN_DIR)/tree.o

list: 
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c list.c -o $(BIN_DIR)/list.o
	$(CC) -o $(BIN_DIR)/list $(BIN_DIR)/list.o

run_tree: tree
	./bin/tree

run_list: list
	./bin/list

# Clean target to remove build artifacts
clean:
	rm -rf $(BIN_DIR)

# A phony target to ensure make runs even if files named 'clean' exist
.PHONY: clean $(BIN_DIR)
