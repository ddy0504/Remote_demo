
GCC = g++
SRCDIR = ./
OBJDIR = 
TARGET_DIR = ./
CPPFLAGS = -std=c++11 -w -g

SRCS+= \
       sqlite_test.cpp

OBJS = $(SRCS:.cpp=.o)
LIBOBJS = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))
API_PATH = ./lib
#INCLDIR = -I./oci
LD_LIB_PATH = -L$(API_PATH)
LD_SYS_LIBS = -lpthread -ldl

#LD_APP_LIBS = $(API_PATH)/oci.lib
LD_APP_LIBS = -lsqlite3

TARGET = $(TARGET_DIR)/Sqlite_test
all: $(TARGET)

$(TARGET):$(LIBOBJS)
	@echo ""
	@echo "___Compile________ $@"
	$(GCC) -o $@ $(LIBOBJS) $(CPPFLAGS) $(LD_LIB_PATH) $(LD_SYS_LIBS) $(LD_APP_LIBS)

$(OBJDIR)/%.o: %.cpp
	$(GCC) $(CPPFLAGS) $(INCLDIR) -c -o $@ $< 

clean:
	rm -f $(LIBOBJS) $(TARGET)    
