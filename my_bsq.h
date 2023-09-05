#ifndef MY_BSQ_H_
#define MY_BSQ_H_

#include <string.h>
#include <stdio.h> // printf()
#include <unistd.h> // read() write()
#include <fcntl.h> // open() close()
#include <stdlib.h> // malloc() free()
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
    save positions of the largest square
    largest: size of largest square
    largest_x: x-coordinate of the bottom-right corner of the largest square.
    largest_y: y-coordinate of the bottom-right corner of the largest square.
*/ 
typedef struct positions{
    unsigned short largest_x;
    unsigned short largest_y;
    unsigned short largest;
} save_positions;

typedef struct int_map{
    int **map;
    int size;
} integer_map;
#define MAX_LINE 1024

// helper functions
void *my_realloc(void *ptr, size_t size);
char* my_strcat(char* dest, const char* src);
char* my_strcpy(char* dest, const char* src);
char* my_strncpy(char* dest, const char* src, size_t n);

// read lines from file
char *get_line(int fd);
void init_my_readline();

// handle map
void PrintMap(integer_map* map) ;
int ParseMap(char* file_name);
integer_map* StoreMap(char* file_name);

// algorithm functions
int GetMinimum(int first, int second, int third);
save_positions FindSquare(integer_map* map);
void PrintResult(save_positions square_pos, integer_map* int_map);

#endif