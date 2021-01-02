#include <stdio.h>
typedef unsigned char *byte_pointer;
void show(byte_pointer start, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
        printf("\n");
    }
}