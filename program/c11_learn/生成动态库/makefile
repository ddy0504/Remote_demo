
CC = gcc
OBJDIR = ./obj
TARGET_DIR = ./lib
SRCDIR = ./
TARGET = libfunc
CFLAGS = -fpic -shared

SRCS+= \
       func1.c\
       func2.c

OBJS = $(SRCS:.c=.o)
LIBOBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all:libfunc.a libfunc.so

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
	$(CC) -c -w $(INC) $(CFLAGS) -o $(addprefix $(OBJDIR)/,$(notdir $*).o) $(notdir $*).c
