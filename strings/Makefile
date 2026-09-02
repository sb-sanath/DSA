CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
OUTDIR = out
TARGET = $(OUTDIR)/app

SRC = main.c src/reverse_string.c lib/libstrings.c
OBJ = $(patsubst %.c,$(OUTDIR)/%.o,$(SRC))

all: $(TARGET)

$(OUTDIR):
	mkdir -p $(OUTDIR) $(OUTDIR)/src $(OUTDIR)/lib

$(TARGET): $(OBJ) | $(OUTDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OUTDIR)/%.o: %.c | $(OUTDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTDIR)

.PHONY: all clean
