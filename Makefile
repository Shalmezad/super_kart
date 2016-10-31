build:
	make prep
	g++ client/src/*.cpp client/src/*.c -o bin/super_kart_client `sdl-config --cflags --libs` -lSDL_image
	g++ server/src/*.cpp -o bin/super_kart_server `sdl-config --cflags --libs` -lSDL_image -lSDL_net
prep:
	mkdir -p bin
clean:
	rm -rf bin/
run:
	bin/super_kart_client
	bin/super_kart_server