CC      = cc
CFLAGS  = -Wall -Wextra -std=c11 -g
BIN     = todo
OBJ     = main.o store.o

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

main.o: main.c task.h
	$(CC) $(CFLAGS) -c main.c

store.o: store.c task.h
	$(CC) $(CFLAGS) -c store.c

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJ) todo.dat

.PHONY: run clean
