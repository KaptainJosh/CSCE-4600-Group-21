deadlock-detector: main.o bfs.o knot-detector.o
	g++ -o deadlock-detector -Wc++11-extensions main.o bfs.o knot-detector.o

main.o: main.cpp 
	g++ -c -Wc++11-extensions main.cpp

bfs.o: bfs.cpp
	g++ -c -Wc++11-extensions bfs.cpp

knot-detector.o: knot-detector.cpp
	g++ -c -Wc++11-extensions knot-detector.cpp