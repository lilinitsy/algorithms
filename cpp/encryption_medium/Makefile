CC = g++ 
CFLAGS = -O3 -Wall -Wextra -march=native -std=c++20
LDFLAGS = 
OBJ = main.o
DEPS = encryption_medium.h

all: encryption_medium

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

encryption_medium: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o encryption_medium

