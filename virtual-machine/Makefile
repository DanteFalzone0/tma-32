CC := g++
objects := bin/obj/tma32.o
tma-32-sources := src/tma32.cpp
tma-32-headers := src/tma32.h
main := src/main.cpp

tma32: $(main) $(tma-32-headers) $(objects)
	$(CC) $(main) $(objects) -o bin/tma32

$(objects): $(tma-32-sources)
	$(CC) src/tma32.cpp -c -o bin/obj/tma32.o

clean:
	rm -f bin/obj/*.o
	rm -f bin/tma32
