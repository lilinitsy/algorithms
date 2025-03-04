CC = g++ 
CFLAGS = -O3 -Wall -Wextra -march=native -std=c++20
LDFLAGS = 
OBJ = main.o
DEPS = nondivisible_subset.h

all: nondivisible_subset

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

nondivisible_subset: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o nondivisible_subset

