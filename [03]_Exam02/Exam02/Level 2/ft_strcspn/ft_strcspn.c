#include <stdio.h>
#include <stddef.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    int     i = 0;
    int     j;

    while (s[i] != '\0')
    {
		j = 0;
        while (reject[j] != '\0')
        {
            if(s[i] == reject[j])
                return (i);      
            j++;                 
        }
        i++;
    }
    return (i);
}

// for testing
int main()
{
    printf("%ld", ft_strcspn("hello", "o"));
    /* "o" is on position 4 in "hello" */
                             /* ^^^^^ */
                             /* 01234 */
    /* so the result is 4 */
                        
}