#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t	ft_strlen(char *str)
{
	size_t	len = 0;

	if (!str)
		return (0);
	while (str[len])
		len++;
	if (str[len] == '\n')
		return (len + 1);
	return (len);
}

size_t	clean_line(char *buffer)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	res = 0;

	while (buffer[i])
	{
		if (res)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			res = 1;
		buffer[i] = 0;
		i++;
	}
	return (res);
}

char	*strjoin_line(char *s1, char *s2)
{
	size_t	i = 0;
	size_t	j = 0;
	char	*s3;

	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s3))
		return (NULL);
	while (s1 && s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		s3[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	s3[j] = '\0';
	free(s1);
	return (s3);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = strjoin_line(line, buffer);
		if (clean_line(buffer) == 1)
			break ;
		if (read(fd, buffer, BUFFER_SIZE) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}

//to test
int main() {
    int fd;
    char *line;

    fd = open("files/long_file", O_RDONLY);
    if (fd < 0) 
    {
        perror("Error");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL) 
    {
        printf("> %s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}