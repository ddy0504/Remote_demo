
CC = g++

CPPFLAGS = -std=c++11

SRCS+= \
       lambda_test.cpp\

OBJS = $(SRCS:.cpp=.o)

TARGET=lambda 

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
