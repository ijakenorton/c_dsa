CC = clang
CFLAGS = -Wall -O2
BIN_DIR = ./bin

tree: 
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c tree.c -o $(BIN_DIR)/tree.o
	$(CC) -o $(BIN_DIR)/tree $(BIN_DIR)/tree.o


run: tree
	./bin/tree

# Clean target to remove build artifacts
clean:
	rm -rf $(BIN_DIR)

# A phony target to ensure make runs even if files named 'clean' exist
.PHONY: clean $(BIN_DIR)
