#include <stdio.h>
#include <stdlib.h>

#include "Str.h"

//-----------------------------------------------------------------------------

int main()
{
    char* s = NULL;
    int lim = 6;

    printf ("%p\n", s);
    int len = get_line (stdin, &s, &lim);

    printf ("%d %s", len, s);
}
