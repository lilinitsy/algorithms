CC = g++ 
CFLAGS = -O3 -Wall -Wextra -march=native -std=c++20
LDFLAGS = 
OBJ = main.o
DEPS = leaderboard.h

all: leaderboard

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

leaderboard: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o leaderboard

