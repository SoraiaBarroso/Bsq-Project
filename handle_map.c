#include <unistd.h>
#include "my_bsq.h"

// check the real size of the map in case first line is not showing real size
int ParseMap(char* file_name) 
{
    int size = 0, count_line = 0;
    char* str = NULL;
    int fd = open(file_name, O_RDONLY);

    str = get_line(fd);
    for (int i = 0; str[i] != '\0'; i++) {
        size = size * 10 + (str[i] - '0');
    }

    while ((str = get_line(fd)) != NULL) {
        count_line++;
        free(str);
    }

    close(fd);
    init_my_readline();
    return size == count_line ? size : count_line;
}

// store map in a 2D integer-based map
integer_map* StoreMap(char* file_name) {

    char *str = NULL;
    int fd = open(file_name, O_RDONLY);

    if (fd == -1) {
        printf("Error: Error opening file\n");
        return NULL;
    }

    integer_map *int_map;
    int_map = malloc(sizeof(integer_map));

    int_map->size = ParseMap(file_name);
    int_map->map = malloc(sizeof(int *) * int_map->size); 

    for (int i = 0; i < int_map->size; i++) {
        int_map->map[i] = (int *)malloc(int_map->size * sizeof(int)); 
        int index = 0;
        
        str = get_line(fd);
        // skip first line
        if (str[0] >= '0' && str[0] <= '9') {
            free(str);
            i--;
            continue;
        }

        if (int_map->map[i] == NULL) {
            printf("Error: Memory allocation failed\n");
            exit(1);
        }
    
        for (int j = 0; j < int_map->size; j++) {
            if (str[index] == 'o') {
                int_map->map[i][j] = 0;
            } else {
                int_map->map[i][j] = 1;
            }

            index++;
        }
        free(str);
    }   

    close(fd);
    init_my_readline();
    return int_map;
}