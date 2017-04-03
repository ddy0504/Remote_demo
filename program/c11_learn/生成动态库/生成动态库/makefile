
CC = gcc
OBJDIR = ./obj
TARGET_DIR = ./lib
SRCDIR = ./
INCLDIR = -I./
TARGET = libfunc
CFLAGS = -fpic -shared

SRCS+= \
       test_a.c\
       test_b.c\
       test_c.c

OBJS = $(SRCS:.c=.o)
LIBOBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all:mkdirs libfunc.a libfunc.so
#all:mkdirs libfunc.a 

mkdirs:
	mkdir -p $(OBJDIR) $(TARGET_DIR)

libfunc.a:$(OBJS)
	ar -rv $(TARGET_DIR)/libtemp.a $(LIBOBJS)
	ar xv $(TARGET_DIR)/libtemp.a
	rm $(TARGET_DIR)/libtemp.a
	ar rv $(TARGET_DIR)/$(TARGET).a *.o
	rm -f *.o *.obj

libfunc.so:$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET_DIR)/$(TARGET).so $(LIBOBJS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJDIR)/*
	rm -f $(TARGET_DIR)/$(TARGET).a
	rm -f $(TARGET_DIR)/$(TARGET).so
	
.SUFFIXES: .c .o
.c.o:
	$(CC) -c -w $(INCLDIR) $(CFLAGS) -o $(addprefix $(OBJDIR)/,$(notdir $*).o) $(notdir $*).c
