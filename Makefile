all:
	g++ src/gamescene.cpp src/stage.cpp src/make_map.cpp src/startscene.cpp src/function.cpp src/main.cpp -lncurses -o /tmp/a.out && /tmp/a.out
