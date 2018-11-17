CC=g++

OBJS=create_ppm x 

all: create_ppm.cc

%: %.c
	$(CC) $< -o $@

clean:
	rm -rf *.ppm $(OBJS)
