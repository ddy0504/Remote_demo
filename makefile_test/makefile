
CC = g++

SRCS+= \
       test1.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET=prog1 

$(TARGET):$(OBJS)
	@echo "正在编译 $(TARGET).$$$$..."
	$(CC) $(OBJS) -o $(TARGET)

%.o:%.cpp
	@echo "======>>Makeing $(CC) -c -o $<"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(TARGET)

exec:
	@cd /home
	@pwd

exe:
	@cd /home;pwd
