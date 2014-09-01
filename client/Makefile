
build:
	make prep
	g++ src/*.cpp src/*.c -o bin/super_kart_client `sdl-config --cflags --libs` -lSDL_image
prep:
	mkdir -p bin
clean:
	rm -rf bin/
run:
	bin/super_kart_client
