#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *rev_print(char *str)
{
    int i = ft_strlen(str) - 1;

    while (i > -1) {
        write(1, &str[i], 1);
        i--;
    }
    return(0); /* bez return 0 ne radi*/
}

/*
int main()
{
    rev_print("ab");
}
*/