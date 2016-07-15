MAIN = flappy_bird
CC = g++
CFLAGS =
INCLUDE = -I/usr/include/SDL
LIBS = -lSDL -lSDL_image -lSDL_mixer
HEADER =
OBJS = main.o keyEvent.o draw.o init.o bird.o

all: $(MAIN)

.c.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) $<

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

clean:
	rm -f *.o a.out $(MAIN) core *~
