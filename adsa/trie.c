#include <stdio.h>
int main(int argc, char *argv[])
{
    char const *const file = argv[1];
    FILE *f = fopen(file, "r");
    char a[100000];
    while (fgets(a, sizeof(a), f))
    {
        printf("%s", a);
    }
    fclose(f);
    return 0;
}