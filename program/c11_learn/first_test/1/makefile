
CC = g++

CPPFLAGS = -std=c++11

SRCS+= \
       Type.cpp\
       Type.h\
       Template_type.cpp\
       Template_type.h

OBJS = $(SRCS:.cpp=.o)

TARGET=prog1 

$(TARGET):$(OBJS)
	@echo "正在编译 $(TARGET).$$$$..."
	$(CC) $(CPPFLAGS) $(OBJS) -o $(TARGET)

%.o:%.cpp
	@echo "======>>Makeing $(CC) -c -o $<"
	@$(CC) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(TARGET)

exec:
	@cd /home
	@pwd

exe:
	@cd /home;pwd
