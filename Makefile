CC = clang
CFLAGS = -Wall -O2
BIN_DIR = ./bin

tree: 
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c tree.c list.c -o $(BIN_DIR)/tree.o
	$(CC) -o $(BIN_DIR)/tree $(BIN_DIR)/tree.o

list: 
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c list.c -o $(BIN_DIR)/list.o
	$(CC) -o $(BIN_DIR)/list $(BIN_DIR)/list.o

run_tree: tree
	./bin/tree

run_list: list
	./bin/list

debug_tree: tree
	valgrind ./bin/tree --track-origins=yes --leak-check=full

debug_list: list
	valgrind ./bin/list --track-origins=yes --leak-check=full

clean:
	rm -rf $(BIN_DIR)

.PHONY: clean $(BIN_DIR)
