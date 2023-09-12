#ifndef LIBFT_H
#define LIBFT_H

#define FT_INT_MIN -2147483648
#define FT_INT_MAX 2147483647

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct    s_list
{
    void    *content;
    struct  s_list  *next;
}                           t_list;

size_t    ft_strlcat(char *dest, const char *src, size_t destsize);
size_t   ft_strlcpy(char *dest, const char *src, size_t destsize);
int ft_atoi(const char *str);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size);
int ft_isalnum(int c);
int	ft_isalpha(int c);
int ft_isascii(int  c);
int ft_isdigit(int c);
int ft_isprint(int c);
void    *ft_memchr(const void *str, int c, size_t len);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t len);
void    *ft_memmove(void *dest, const void *src, size_t len);
void    *ft_memset(void *s, int c, size_t len);
char *ft_strchr(const char *str, int c);
char    *ft_strdup(const char *s);
size_t ft_strlen(const char *s);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char    *ft_strnstr(const char  *haystack, const char *needle, size_t len);
char    *ft_strrchr(const char *s, int   c);
char    *ft_tolower(char *str);
char    *ft_toupper(char *str);

#endif
