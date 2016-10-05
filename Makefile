
all: findFace

all:

findFace:
	g++ -O2 -Wall -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_imgproc findFace.cpp -o findFace

clean:
	-rm findFace

install:
	install -m 755 wifi_breakfix.sh /usr/local/bin/wifi_breakfix.sh
	install -m 644 wifi_breakfix.service /lib/systemd/system/wifi_breakfix.service
	systemctl enable wifi_breakfix.service 2>/dev/null
