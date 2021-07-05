#include <stdio.h>

#define SIZE 128

int main(int argc, char **argv)
{
    char buf[SIZE];
    FILE *fd = popen("./test", "r");
    fgets(buf, SIZE, fd);
    printf("OUTPUT : %s\n", buf);
    pclose(fd);
}
