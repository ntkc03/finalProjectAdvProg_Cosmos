all:
	g++ -ID:\libraries\sources\include -LD:\libraries\sources\lib -o main-sfml main-sfml.cpp -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window -lsfml-network
