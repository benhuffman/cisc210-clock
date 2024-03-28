INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: sigma
sigma: main.o display.o
	cc -o sigma main.o display.o $(LDFLAGS)

clean:
	rm -f *.o sigma
main.o: main.c display.h
	cc -c main.c -I ~/include
display.o: display.c display.h
	cc -c display.c -I ~/include
