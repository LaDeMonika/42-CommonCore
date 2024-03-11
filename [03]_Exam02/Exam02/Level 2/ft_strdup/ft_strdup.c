#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int len = 0;
    int i = 0;
    char *cpy;

    if (src == NULL)
        return (NULL);
    while (src[len])
        len++;
    cpy = malloc(sizeof(char) * len  + 1);
    if (cpy == NULL) /* zaboravljam osigurati cpy i str */
        return (NULL);
    while (src[i])
    {
        cpy[i] = src[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}