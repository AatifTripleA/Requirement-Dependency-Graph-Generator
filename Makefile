CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
SRC = src/main.c src/parse.c src/graph.c src/report.c
OBJ = $(SRC:.c=.o)
TARGET = req_dep_graph

all: $(TARGET)

$(TARGET): $(SRC)
    $(CC) $(CFLAGS) -o $@ $(SRC)

clean:
    rm -f $(TARGET) src/*.o

run: $(TARGET)
    ./$(TARGET)
