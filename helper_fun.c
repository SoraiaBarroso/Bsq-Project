#include "my_bsq.h"

char* my_strcat(char* dest, const char* src)
{
    char *ptr = dest + strlen(dest);

    while (*src != '\0') {
        *ptr++ = *src++;
    }

    *ptr = '\0';

    return dest;
}

char* my_strcpy(char* dest, const char* src) 
{
    if (dest == NULL) {
        return NULL;
    }

    char *ptr = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest++ = '\0';

    return ptr;
}

char* my_strncpy(char* dest, const char* src, size_t n) 
{
    if (dest == NULL) {
        return NULL;
    }

    char *ptr = dest;

    while(*src && n--) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest++ = '\0';

    return ptr;
}

void *my_realloc(void *ptr, size_t size)
{
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);

    if (new_ptr == NULL)
    {
        printf("Error: Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    if (ptr != NULL)
    {
        char *old_ptr = ptr;
        char *new_ptr_char = new_ptr;

        for (size_t i = 0; i < size; i++)
        {
            new_ptr_char[i] = old_ptr[i];
        }

        free(ptr);
    }

    return new_ptr;
}

