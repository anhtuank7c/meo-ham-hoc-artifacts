CC      = cc
CFLAGS  = -Wall -Wextra -std=c11 -g
BIN     = chi-tieu
OBJ     = main.o expense.o

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

main.o: main.c expense.h
	$(CC) $(CFLAGS) -c main.c

expense.o: expense.c expense.h
	$(CC) $(CFLAGS) -c expense.c

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJ) chi-tieu.dat

.PHONY: run clean
