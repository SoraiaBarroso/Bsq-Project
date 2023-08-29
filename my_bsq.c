#include "my_bsq.h"

int GetMinimum(int first, int second, int third)
{
    if (first <= second && first <= third) 
        return first;
    else if (second <= third && second <= first)
        return second;
    else
        return third;
}

save_positions FindSquare(integer_map* int_map) 
{
    int x, y, min;

    integer_map *save_map;
    save_map = malloc(sizeof(integer_map));

    save_map->size = int_map->size;
    save_map->map = malloc(sizeof(int *) * int_map->size);

    for (int i = 0; i < int_map->size; i++) {
        save_map->map[i] = malloc(int_map->size * sizeof(int)); 
        if (save_map->map[i] == NULL) {
            printf("Error: Memory allocation failed\n");
            exit(1);
        }
        for (int j = 0; j < int_map->size; j++) {
            save_map->map[i][j] = int_map->map[i][j];
        }
    }

    save_positions square_pos;
    square_pos.largest = 0;
    square_pos.largest_x = -1;
    square_pos.largest_y = -1;

    for (x = 1; x < save_map->size; x++) 
    {
        for (y = 1; y < save_map->size; y++) 
        {
            if (save_map->map[x][y] != 0 && 
                save_map->map[x - 1][y] != 0 && 
                save_map->map[x - 1][y - 1] && 
                save_map->map[x][y - 1] != 0) 
            {
                min = GetMinimum(save_map->map[x- 1][y],save_map->map[x][y - 1],save_map->map[x - 1][y - 1]);
                save_map->map[x][y] += min;

                if (save_map->map[x][y] > square_pos.largest)
                {
                    square_pos.largest = save_map->map[x][y];
                    square_pos.largest_x = x;
                    square_pos.largest_y = y;
                }
            }
        }
    }

    for (int i = 0; i < save_map->size; i++) {
        free(save_map->map[i]);
    }

    free(save_map->map);

    return square_pos;
}

void PrintResult(save_positions square_pos, integer_map* int_map)
{
    for (int x = 0; x < int_map->size; x++)
    {
        for (int y = 0; y < int_map->size; y++)
        {
            if (x >= square_pos.largest_x - square_pos.largest + 1 &&
                x <= square_pos.largest_x &&
                y >= square_pos.largest_y - square_pos.largest + 1 &&
                y <= square_pos.largest_y)
                {
                    printf("x");
                }
            else {
                printf("%c", int_map->map[x][y] == 0 ? 'o' : '.');
            }
        }
        printf("\n");
    }
}