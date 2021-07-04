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

int main()
{
    char buff[10000000];

    buff[0] = '\0';
}
