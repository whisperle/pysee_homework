
BIN=./bin/
INC=./include/

SRCS=./sortspeed.c \
	./src/bubble_sort.c \
	./src/merge_sort.c\
	./src/insertion_sort.c\
	./src/quick_sort.c\
	./src/utils.c  

OUTFILE=$(BIN)sortspeed

all: $(OUTFILE)
	$(OUTFILE)

$(OUTFILE): $(SRCS)  
	gcc -O3 -o $@ $^ -I$(INC) 

run:
	$(OUTFILE)

