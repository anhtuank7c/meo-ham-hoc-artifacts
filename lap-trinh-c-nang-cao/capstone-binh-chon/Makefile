CC      = cc
CFLAGS  = -Wall -Wextra -std=c11 -g
BIN     = binh-chon
OBJ     = main.o candidate.o

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

main.o: main.c candidate.h
	$(CC) $(CFLAGS) -c main.c

candidate.o: candidate.c candidate.h
	$(CC) $(CFLAGS) -c candidate.c

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJ) binh-chon.dat

.PHONY: run clean
