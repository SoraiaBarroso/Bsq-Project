#include "my_bsq.h"

int main(int argc, char** argv) {

    char* file_name;
    integer_map *int_map;
    save_positions square_pos;

    if (argc < 2) {
        printf("Error: Usage: ./my_bsq 'map_file'\n");
        return 1;
    } else {
        file_name = argv[1];
    }

    // convert map into integer-based map
    int_map = StoreMap(file_name);

    // find biggest square
    square_pos = FindSquare(int_map);
    
    // print result 
    PrintResult(square_pos, int_map);

    return 0;
}