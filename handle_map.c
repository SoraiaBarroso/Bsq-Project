#include "my_bsq.h"

off_t FileSize(char* file_name) {

    off_t size = 0;
    char* buf[MAX_SIZE];
    int fd;

    fd = open(file_name, O_RDONLY);

    if (fd == -1) {
        printf("Error: Error opening file\n");
        return 1;
    }

    while ((read(fd, buf, 1)) > 0) {
        size++;
    }

    close(fd);

    return size;
}

// store map in a string
char* StoreMap(char* file_name) {

    off_t size;
    char* map;
    int fd;

    size = FileSize(file_name);
    map = malloc(sizeof(char) * (size + 1));

    if (map == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    fd = open(file_name, O_RDONLY);

    if (fd == -1) {
        printf("Error: Error opening file\n");
        return NULL;
    }
    
    // read the file and store it in the map variable
    if (read(fd, map, size) == -1) {
        printf("Error: error opening file\n");
        close(fd);
        return NULL;
    }

    map[size] = '\0';
    close(fd);

    return map;
}

// convert string map into an integer-based map with 0s and 1s
integer_map* CreateIntegerMap(char* map) {   

    // start aftern the new line character
    int map_index = 0, index = 0;
    integer_map *int_map;

    int_map = malloc(sizeof(integer_map));

    // get size of the map from the first line
    for (index = 0; map[index] != '\n'; index++) {
        int_map->size = int_map->size * 10 + (map[index] - '0');
    }

    map_index = index + 1;
    int_map->map = malloc(sizeof(int *) * int_map->size);

    if (int_map->map == NULL) {
        printf("Error: Memory allocation failed\n");
    }
    
    // convert str map into arr map of numbers 0s 1s
    for (int i = 0; i < int_map->size; i++)
    {
        int_map->map[i] = (int *)malloc(int_map->size * sizeof(int)); 

        if (int_map->map[i] == NULL) {
            printf("Error: Memory allocation failed\n");
            exit(1);
        }
        
        for (int j = 0; j < int_map->size ; j++)
        {            
            if (map[map_index] == 'o') {
                int_map->map[i][j] = 0;
            }
            else {
                int_map->map[i][j] = 1;
            }
            map_index++;
        }
        map_index++;
    }

    return int_map;
}