CC = gcc
CFLAGS += -Wall -Werror -Wextra
SOURCES = main.c my_bsq.c handle_map.c readline.c helper_fun.c my_bsq.h
TARGET = my_bsq

all: $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all