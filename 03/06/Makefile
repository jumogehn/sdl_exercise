
NAME = 06

CXXFLAGS = $(shell pkg-config --cflags sdl2 SDL2_image)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image)

all:
	g++ $(CXXFLAGS) $(NAME).cpp -o $(NAME) $(LDFLAGS)

clean:
	rm -rf *.o $(NAME)

