all:
	mkdir -p build
	cd build && cmake ../ && cmake --build .

Xcode:
	mkdir -p buildXcode
	cd buildXcode && cmake ../ -G "Xcode" && cmake --build .

run:
	mkdir -p build
	cd build && cmake ../ && cmake --build . && ./BeatThemAll

clean:
	rm -rf build
