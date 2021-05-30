
CC=gcc
CFLAGS=-O3 -Wall -fPIC 

SRCDIR=./src/
OBJDIR=./obj/
BINDIR=./bin/
INCDIR=./include/

objects=$(OBJDIR)bubble_sort.o $(OBJDIR)insertion_sort.o $(OBJDIR)merge_sort.o $(OBJDIR)utils.o

# Windows
LIB=libsort.dll

all:  $(LIB)

$(LIB): sortobj
	$(CC) -shared -o $(BINDIR)$@ $(OBJDIR)bubble_sort.o $(OBJDIR)insertion_sort.o $(OBJDIR)merge_sort.o $(OBJDIR)quick_sort.o

sortobj: 
	$(CC) -c $(CFLAGS)  -o $(OBJDIR)bubble_sort.o $(SRCDIR)bubble_sort.c -I$(INCDIR)
	$(CC) -c $(CFLAGS)  -o $(OBJDIR)insertion_sort.o $(SRCDIR)insertion_sort.c -I$(INCDIR)
	$(CC) -c $(CFLAGS)  -o $(OBJDIR)merge_sort.o $(SRCDIR)merge_sort.c -I$(INCDIR)
	$(CC) -c $(CFLAGS)  -o $(OBJDIR)quick_sort.o $(SRCDIR)quick_sort.c -I$(INCDIR)
	$(CC) -c $(CFLAGS)  -o $(OBJDIR)utils.o $(SRCDIR)utils.c -I$(INCDIR)