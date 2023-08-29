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

#define MAX_SIZE 1000

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

// handle map
off_t FileSize(char* file_name);
char* StoreMap(char* file_name);
integer_map* CreateIntegerMap(char* map);

// algorithm functions
int GetMinimum(int first, int second, int third);
save_positions FindSquare(integer_map* map);
void PrintResult(save_positions square_pos, integer_map* int_map);

#endif