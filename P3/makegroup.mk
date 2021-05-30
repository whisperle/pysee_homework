
BIN=./bin/
INC=./include/

SRCS=./sortspeed_group.c \
	./src/bubble_sort.c \
	./src/insertion_sort.c\
	./src/merge_sort.c\
	./src/quick_sort.c\
	./src/utils.c

EXENAME=sortspeed_group
DATNAME=speedvalue.csv

OUTFILE=$(BIN)$(EXENAME)

all: $(OUTFILE)
	
$(OUTFILE): $(SRCS)  
	gcc -O3  -o $@ $^ -I$(INC) 

run:
	.\bin\$(EXENAME) > ./result/$(DATNAME) 
	type .\result\$(DATNAME) 
	python plot_speed.py .\result\$(DATNAME)

