#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return write(1, "\n", 1);
    int i = 0;
    int flg = 0;
    char *str;
    str = argv[1];

    while (str[i] == ' ' || str[i] == '\t')
    {
        i++;
    }
    while (str[i])
    {
        if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flg = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flg)
					write(1, " ", 1);
				flg = 0;
				write(1, &argv[1][i], 1);
			}
        i++;
    }
    write(1, "\n", 1);
}