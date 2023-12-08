#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)  
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;         
		++i;
	}
	return (i);
}
/* #include <stdio.h>
int main()
{
    char s1[] = "i am Mo";
    char s2[] = "i am I";
    printf("%i\n", ft_strspn(s1, s2));
} */
