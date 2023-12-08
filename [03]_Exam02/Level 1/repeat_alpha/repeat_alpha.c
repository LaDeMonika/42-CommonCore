#include <unistd.h>

int    repeat_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return(c - 'a' + 1);
    /* char (b --> 98 - 'a' --> 97 + 1 = 2 [bb]) */
    else if (c >= 'A' && c <= 'Z')
        return(c - 'A' + 1);
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    int count;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            count = repeat_alpha(argv[1][i]);
            while(count--)
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}