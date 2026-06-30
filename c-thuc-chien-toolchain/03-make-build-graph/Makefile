CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -MMD -MP
OBJ = main.o util.o

app: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o app

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean
all: app

clean:
	rm -f $(OBJ) app *.d

-include $(OBJ:.o=.d)
