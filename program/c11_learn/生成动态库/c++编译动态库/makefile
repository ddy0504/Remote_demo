
GCC = g++
OBJDIR = ./obj
TARGET_DIR = ./lib
SRCDIR = ./
TARGET = libfunc
CPPFLAGS = -std=c++11 -fpic -shared

SRCS+= \
       func1.cpp\
       func2.cpp

OBJS = $(SRCS:.cpp=.o)
LIBOBJS = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

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
	$(GCC) $(CPPFLAGS) -o $(TARGET_DIR)/$(TARGET).so $(LIBOBJS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJDIR)/*
	rm -f $(TARGET_DIR)/$(TARGET).a
	rm -f $(TARGET_DIR)/$(TARGET).so
	
.SUFFIXES: .cpp .o
.cpp.o:
	$(GCC) -c -w $(INC) $(CPPFLAGS) -o $(addprefix $(OBJDIR)/,$(notdir $*).o) $(notdir $*).cpp
