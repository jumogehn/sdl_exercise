
NAME = 08

#sudo apt install libghc-sdl2-ttf-dev

CXXFLAGS = $(shell pkg-config --cflags sdl2 SDL2_image SDL2_mixer SDL2_ttf)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image SDL2_mixer SDL2_ttf)

all:
	g++ $(CXXFLAGS) $(NAME).cpp -o $(NAME) $(LDFLAGS)

clean:
	rm -rf *.o $(NAME)

