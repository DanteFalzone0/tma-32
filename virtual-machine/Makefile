CC := g++
objects := bin/obj/tma32.o

test: src/test.cpp $(objects)
	$(CC) src/test.cpp $(objects) -o bin/test

$(objects): src/tma32.cpp src/tma32.h
	$(CC) src/tma32.cpp -c -o bin/obj/tma32.o

clean:
	rm -f bin/obj/*.o
	rm -f bin/test
	rm -f bin/tma32
