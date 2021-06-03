#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find(char c, char *str, size_t start)
{
    int i;

    if (!str || start > strlen(str))
        return -1;
    i = start;
    while (str[i] && str[i] != c)
        i++;
    if (!str[i])
        return -1;
    return i;
}

int main(int argc, char **argv)
{
    char *str = argv[1];
    char c = argv[2][0];
    size_t start = atoi(argv[3]);
    int index = find(c, str, start);
    printf("%d\n", index);
}
