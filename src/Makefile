CC 		= /usr/bin/gcc
CFLAGS	= -Wall -O2 
LDFLAGS	= `pkg-config --libs --cflags gtk+-3.0 gmodule-2.0`

# module fraktal
FMOD = \
		fraktal \
		fraktalimage \
		fraktalimageprofiles \
		fraktalinit \
		fraktalprofiles

FHDR = $(FMOD:%=%.h)
FSRC = $(FMOD:%=%.c)

# gtkfraktal
GFMOD = \
		gtkfraktal \
		gtkfraktalsignals \
		gtkfraktalinit \
		gtkfraktaldraw

GFOBJ = $(GFMOD:%=%.o)
GFHDR = $(GFMOD:%=%.h)
GFSRC = $(GFMOD:%=%.c) $(FSRC)

all: gtkfraktal.o

gtkfraktal.o: $(GFSRC) $(GFHDR) $(FHDR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(GFSRC) -o gtkfraktal.o

mandel.o: mandel.c $(FSRC)
	$(CC) $(CFLAGS) $(FSRC) mandel.c -o mandel.o
	
.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.bmp
