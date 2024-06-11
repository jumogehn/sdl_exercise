
NAME = aplayer
SRCS = helper.c main.c

CFLAGS = $(shell pkg-config --cflags sdl2 SDL2_image SDL2_mixer SDL2_ttf)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image SDL2_mixer SDL2_ttf)

all:
	g++ $(CFLAGS) $(SRCS) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf *.o $(NAME)

