#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int n;

    if (ac == 2)
    {
        i = 0;

        while (av[1][i])
        {
            n = 0;
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
            {
                n = av[1][i] - 'a' + 1;
                while(n--)
                {
                    write(1, &av[1][i], 1);
                }
            }
            else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                n = av[1][i] - 'A' + 1;
                while(n--)
                {
                    write(1, &av[1][i], 1);
                }
            }
            else
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}