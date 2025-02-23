CC = g++ 
CFLAGS = -O3 -Wall -Wextra -march=native -std=c++20
LDFLAGS = 
OBJ = main.o
DEPS = segment_tree.h

all: segment_tree

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

segment_tree: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o segment_tree

