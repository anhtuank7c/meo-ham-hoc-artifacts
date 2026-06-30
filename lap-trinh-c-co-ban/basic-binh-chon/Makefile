CC      = cc
CFLAGS  = -Wall -Wextra -std=c11
BIN     = binh-chon

$(BIN): main.c
	$(CC) $(CFLAGS) -o $@ main.c

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: run clean
