run: obj/main.o obj/hockey_server.o obj/steam.o obj/smallet.o obj/spuck.o
	g++ -Wall obj/main.o -o run

obj/main.o: src/main.cpp
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/hockey_server.o: src/hockey_server.cpp
	g++ -Wall -c src/hockey_server.cpp -o obj/hockey_server.o

obj/steam.o: src/steam.cpp
	g++ -Wall -c src/steam.cpp -o obj/steam.o

obj/smallet.o: src/smallet.cpp
	g++ -Wall -c src/smallet.cpp -o obj/smallet.o

obj/spuck.o: src/spuck.cpp
	g++ -Wall -c src/spuck.cpp -o obj/spuck.o



clean:
	rm run obj/main.o obj/hockey_server.o obj/steam.o obj/smallet.o obj/spuck.o

