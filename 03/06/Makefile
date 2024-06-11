
#NAME = 06
NAME = 06_1
#sudo apt install libsdl2-mixer-dev

CXXFLAGS = $(shell pkg-config --cflags sdl2 SDL2_image SDL2_mixer)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image SDL2_mixer)

all:
	g++ $(CXXFLAGS) $(NAME).cpp -o $(NAME) $(LDFLAGS)

clean:
	rm -rf *.o $(NAME)

