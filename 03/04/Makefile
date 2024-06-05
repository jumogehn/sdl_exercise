
NAME = 04

CXXFLAGS = $(shell pkg-config --cflags sdl2)
LDFLAGS = $(shell pkg-config --libs sdl2)

all:
	g++ $(CXXFLAGS) $(NAME).cpp -o $(NAME) $(LDFLAGS)

clean:
	rm -rf *.o $(NAME)

