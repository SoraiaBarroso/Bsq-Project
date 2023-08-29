#include "my_bsq.h"

int main(int argc, char** argv) {

    char* map;
    char* file_name;
    integer_map *int_map;
    save_positions square_pos;

    if (argc < 2) {
        printf("Error: Usage: ./my_bsq 'map_file'\n");
        return 1;
    } else {
        file_name = argv[1];
    }

    // store the map into a string
    map = StoreMap(file_name);

    // convert map into integer-based map
    int_map = CreateIntegerMap(map);
    free(map);

    // find biggest square
    square_pos = FindSquare(int_map);

    // print result 
    PrintResult(square_pos, int_map);

    for (int i = 0; i < int_map->size; i++) {
        free(int_map->map[i]);
    }

    free(int_map->map);
    free(int_map);

    return 0;
}