#include "my_bsq.h"

/*Number os characters read and global storage*/
int READLINE_READ_SIZE = 20;
char storage[MAX_LINE];

void init_my_readline() {
    READLINE_READ_SIZE = 20;
    storage[0] = '\0';
}

char *get_line(int fd)
{
    int bytes_read = 0;
    char buf[READLINE_READ_SIZE + 1];
    char *line = NULL;
    int i = 0;

    if (strlen(storage) > 0) {
        while (storage[i] != '\n' && storage[i] != '\0') 
            i++;

        if (storage[i] == '\n') {
            line = (char*)malloc(i + 1);

            if (line == NULL) {
                printf("Error: Memory allocation failed\n");
                return NULL;
            }

            my_strncpy(line, storage, i);
            line[i] = '\0';

            my_strcpy(storage, storage + i + 1);
            return line;
        }
    }

    while ((bytes_read = read(fd, buf, READLINE_READ_SIZE)) > 0)
    {
        buf[bytes_read] = '\0';

        my_strcat(storage, buf);

        //loop until there is a new line character to get first line
        while (storage[i] != '\n' && storage[i] != '\0') 
            i++;

        //copy the first line
        if (storage[i] == '\n')
        {   
            line = (char*)malloc(sizeof(storage));

            if (line == NULL) {
                printf("Error: Memory allocation failed\n");
                return NULL;
            }

            my_strncpy(line, storage, i);
            line[i] = '\0';

            // Remove the processed line from storage
            int len = strlen(storage + i + 1);
            for (int j = 0; j <= len; j++) {
                storage[j] = storage[i + 1 + j];
            }

            return line;
        }

        // allocate more memory for bigger files
        if (strlen(storage) + bytes_read >= MAX_LINE)
        {
            READLINE_READ_SIZE += MAX_LINE;
            line = my_realloc(line, READLINE_READ_SIZE);
        }
    }

    if (bytes_read == 0 && strlen(storage) > 0) {

        line = (char*)malloc(strlen(storage) + 1);

        if (line == NULL) {
            printf("Error: Memory allocation failed\n");
            return NULL;
        }

        my_strcpy(line, storage);
        storage[0] = '\0';

        return line;
    }

    return NULL;
}
