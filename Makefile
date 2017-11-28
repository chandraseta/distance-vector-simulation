CC=g++

make:
	$(CC) src/dv.cpp -o bin/dv

clean:
	rm bin/*

run:
	bin/dv.exe < data/input.txt