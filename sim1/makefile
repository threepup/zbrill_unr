OBJS = conNode.o metaNode.o configList.o metaQueue.o main.cpp
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Sim01: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o Sim01

conNode.o: conNode.h conNode.cpp
	$(CC) $(CFLAGS) conNode.cpp

metaNode.o: metaNode.h metaNode.cpp
	$(CC) $(CFLAGS) metaNode.cpp

configList.o: configList.h configList.cpp
	$(CC) $(CFLAGS) configList.cpp

metaQueue.o: metaQueue.h metaQueue.cpp
	$(CC) $(CFLAGS) metaQueue.cpp

clean:
	rm *.o Sim01

tar:
	tar cvf Sim01_BrillZachary.tar.gz conNode.h conNode.cpp metaNode.h metaNode.cpp configList.h configList.cpp metaQueue.h metaQueue.cpp main.cpp makefile
