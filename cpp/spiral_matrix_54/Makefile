CC = g++ 
CFLAGS = -O3 -Wall -Wextra -march=native -std=c++20
LDFLAGS = 
OBJ = main.o
DEPS = spiral_matrix_54.h

all: spiral_matrix_54

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

spiral_matrix_54: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o spiral_matrix_54

