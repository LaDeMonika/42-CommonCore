#include <unistd.h>
#include <stdio.h>

int ft_strchr(char *s, int c)
{
    int i = 0;

	if (c == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return write(1, "\n", 1);
    char    *s1 = argv[1];
    char    *s2 = argv[2];
    char    arr[500];
    arr[0] = 0;

    int     i = 0;
    int     j = 0;
    int     a = 0;

    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                if (ft_strchr(arr, s1[i]) == 0)
                    write(1, &s1[i], 1);
                arr[a] = s1[i];
                a++;
                arr[a] = 0;
            }
            j++;
        }
        i++;
    }
    write(1, "\n", 1);
}