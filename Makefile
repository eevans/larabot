
all: findFace

all:

findFace:
	g++ -Wall -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc findFace.cpp -o findFace

clean:
	-rm findFace
