CC := g++
objects := bin/obj/tma-32.o

test: src/test.cpp $(objects)
	$(CC) src/test.cpp $(objects) -o bin/test

$(objects): src/tma-32.cpp src/tma-32.h
	$(CC) src/tma-32.cpp -c -o bin/obj/tma-32.o

clean:
	rm -f bin/obj/*.o
	rm -f bin/test
	rm -f bin/tma32
