deadlock-detector: main.o bfs.o knot-detector.o
	g++ -o deadlock-detector main.o bfs.o knot-detector.o

main.o: main.cpp 
	g++ -c main.cpp

bfs.o: bfs.cpp
	g++ -c bfs.cpp

knot-detector.o: knot-detector.cpp
	g++ -c knot-detector.cpp