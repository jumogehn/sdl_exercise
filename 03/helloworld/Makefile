
CXXFLAGS = $(shell pkg-config --cflags sdl2)
LDFLAGS = $(shell pkg-config --libs sdl2)

all:
	g++ $(CXXFLAGS) helloworld.cpp -o helloworld $(LDFLAGS)

clean:
	rm -rf *.o helloworld

