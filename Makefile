all:
	mkdir -p build
	cd build && cmake ../ && cmake --build .

Xcode:
	mkdir -p buildXcode
	cd buildXcode && cmake ../ -G "Xcode" && cmake --build .

clean:
	rm -rf build
