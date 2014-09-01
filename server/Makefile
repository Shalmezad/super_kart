
build:
	make prep
	g++ src/*.cpp -o bin/super_kart_server `sdl-config --cflags --libs` -lSDL_image -lSDL_net
prep:
	mkdir -p bin
clean:
	rm -rf bin/
run:
	bin/super_kart_server
