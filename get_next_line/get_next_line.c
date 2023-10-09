#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char *ft_new_rest_str(char *rest_str)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	if (!rest_str[i])
	{
		free(rest_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest_str[i])
		str[j++] = rest_str[i++];
	str[j] = '\0';
	free(rest_str);
	return (str);
}

char *ft_get_line(char *rest_str)
{
	int	i;
	char	*str;

	i = 0;
	if (!rest_str[i])
		return (NULL);
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	str = (char	*)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	if (rest_str[i] == '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_read_rest_str(fd, char	*rest_str)
{
	char	*buf;
	int	rd_bytes;

	but = malloc ((BUFFER_SIZE + 1) * sizeof(char))
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(rest_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			free(rest_str);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		rest_str = ft_strjoin(rest_str, buf);
	}
	free(buf);
	return (rest_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char		*rest_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest_str = ft_read_rest_str(fd, rest_str);
	if (!rest_str)
		return (NULL);
	line = ft_get_line(rest_str);
	rest_str = ft_new_rest_str(rest_str);
	return (line);
}

/* int main()
{
	int		fd;
	char	bla[10];

	fd = open("halla.txt", O_RDWR | O_CREAT);
	get_next_line(fd);
	get_next_line(fd);
	if (fd == -1)
		return (-1);
	write(fd, "hey", 3);
	close(fd);
	fd = open("halla.txt", O_RDWR);
	read(fd, bla, 10);
	printf("%s", bla);
	close(fd);
} */

