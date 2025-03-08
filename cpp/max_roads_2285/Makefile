CC = g++ 
CFLAGS = -O3 -Wall -Wextra -march=native -std=c++20
LDFLAGS = 
OBJ = main.o
DEPS = max_roads_2285.h

all: max_roads_2285

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

max_roads_2285: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o max_roads_2285

