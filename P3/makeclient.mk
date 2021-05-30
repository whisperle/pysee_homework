
BIN=./bin/
INC=./include/
OBJ=./obj/

SRCS=./sortspeed.c 
LIB=sort
OBJS= $(OBJ)sortspeed_shared.o
OUTFILE= $(BIN)sortspeed_shared

all: $(OUTFILE)
	$(OUTFILE)

$(OUTFILE):$(OBJS)   
	gcc -o $@ $^ -l$(LIB) -L$(BIN) 
$(OBJS):$(SRCS)
	gcc -o $(OBJ)sortspeed_shared.o -c $(SRCS) -I$(INC)
run:
	$(OUTFILE)

