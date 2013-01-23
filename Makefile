DIRS = src

all: compile gtkfraktal.o



compile: $(DIRS)
	for i in $(DIRS); do make -C $$i; done
	
gtkfraktal.o: src/gtkfraktal.o
	cp src/gtkfraktal.o gtkfraktal

.PHONY: clean
clean:
	rm -rf gtkfraktal
	for i in $(DIRS); do make -C $$i clean; done
