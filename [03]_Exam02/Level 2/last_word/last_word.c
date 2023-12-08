#include <unistd.h>

size_t strlen(const char *s)
{
    size_t  i = 0;

    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}
int main(int argc, char **argv)
{
    if(argc != 2)
        return write(1, "\n", 1);
    
    char    *str = argv[1];
    int i = strlen(str) - 1; /* sa ili bez - 1 dobijam isti rezultat, zasto? */

    while (str[i] <= 32) // zaboravljam <= i moram pisati while statement ne if
    {
        i--;
    }
    while (str[i] > 32)
    {
        i--;
    }
    i++;
    while (str[i] > 32)
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}