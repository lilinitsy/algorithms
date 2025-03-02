CC = g++ 
CFLAGS = -O3 -Wall -Wextra -march=native -std=c++20
LDFLAGS = 
OBJ = main.o
DEPS = max_subarray.h

all: max_subarray

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

max_subarray: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o max_subarray

