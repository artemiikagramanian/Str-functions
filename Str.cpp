#include <stdio.h>
#include <stdlib.h>

#include "Str.h"

//-----------------------------------------------------------------------------

void puts (char* str)
{
    while (*str != '\0')
    {
        putchar (*str);
        str++;
    }

    putchar ('\n');
}

//-----------------------------------------------------------------------------

int str_len (char* str)
{
    char* begin_pointer = str;

    while (*str != '\0') str++;

    return str - begin_pointer;
}

//-----------------------------------------------------------------------------

char* str_copy (char* str_dst, const char* str_src)
{
    char* begin_str_dst = str_dst;

    while (*str_src != '\0' && *str_dst != '\0')
    {
        *str_dst = *str_src;
        str_dst++;
        str_src++;
    }

    *str_dst = '\0';

    return begin_str_dst;
}

//-----------------------------------------------------------------------------

char* str_n_copy (char* str_dst, const char* str_src, int n)
{
    char* begin_str_dst = str_dst;
    int   copy_counter  = 0;

    while (*str_src != '\0' && *str_dst != '\0' && copy_counter < n)
    {
        *str_dst = *str_src;

        copy_counter++;
        str_dst++;
        str_src++;
    }

    while (*str_dst != '\0')
    {
        *str_dst = '\0';

        str_dst++;
    }

    return begin_str_dst;
}

//-----------------------------------------------------------------------------

char* str_cat (char* str_dst, const char* str_src)
{
    char* begin_str_dst = str_dst;

    str_dst += str_len (str_dst);

    while (*str_src != '\0')
    {
        *str_dst = *str_src;

        str_dst++;
        str_src++;
    }

    *str_dst = '\0';

    return begin_str_dst;
}

//-----------------------------------------------------------------------------

char* str_n_cat (char* str_dst, const char* str_src, int n)
{
    char* begin_str_dst = str_dst;

    str_dst += str_len (str_dst);

    int cat_counter = 0;

    while (*str_src != '\0' && cat_counter < n)
    {
        *str_dst = *str_src;

        str_dst++;
        str_src++;
    }

    *str_dst = '\0';

    return begin_str_dst;
}

//-----------------------------------------------------------------------------

char* str_chr (char* str, char sym)
{
    while (*str != '\0')
    {
        if (*str == sym) return str;
        str++;
    }

    return NULL;
}

//-----------------------------------------------------------------------------

int str_cmp (const char* str_dst, const char* str_src)
{
    int comp_flag = 0;

    while (*str_dst != '\0' && *str_src != '\0')
    {
        if (*str_dst != *str_src) return *str_dst - *str_src;

        str_dst++;
        str_src++;
    }

    return (*str_dst - *str_src == 0) ? 0 : *str_dst - *str_src;
}

//-----------------------------------------------------------------------------

int fgets (FILE* file, char* str, int lim)
{
    int len =  0;
    char c  = '\0';

    while (len < lim && c != '\n' && c != EOF)
    {
        c = fgetc(file);
        *str = c;

        len++;
        str++;
    }

    *str = '\0';
    return len;
}

//-----------------------------------------------------------------------------

int get_line (FILE* file, char** buf, int* lim)
{
    int len = 0;
    char c = fgetc (file);

    if (*buf == NULL) *buf = (char*) calloc (sizeof (char), *lim);
    char* pointer = *buf;

    while (c != '\n' && c != EOF)
    {
        len++;

        if (len >= *lim)
        {
            *buf = (char*) realloc (*buf, sizeof (char) * (*lim * 2));
            pointer = *buf + *lim - 1;
            *lim *= 2;
        }

        *pointer = c;
        pointer++;

        c = fgetc (file);
    }

    *pointer = '\0';

    return len;
}

char* str_dup (char* str_src)
{
    char* str_dst = (char*) calloc (sizeof (char), str_len(str_src));


    return str_copy (str_dst, str_src);
}
