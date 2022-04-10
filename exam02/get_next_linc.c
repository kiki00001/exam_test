# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

void	ft_error(char *str, int len)
{
	write(1, str, len);
	exit(1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_init_molloc(char c, int i)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * 2);
	if (!tmp)
		return (0);
	tmp[i] = c;
	return (tmp);
}

int	ft_strcat(char **str, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if (*str == 0)
	{
		tmp = ft_init_molloc(c, i);
		i++;
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 2));
		if (!tmp)
			return (0);
		while ((*str)[i])
		{
			tmp[i] = (*str)[i];
			i++;
		}
		tmp[i++] = c;
	}
	tmp[i] = '\0';
	free(*str);
	*str = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int		read_byte;
	char	buffer;

	*line = 0;
	buffer = 0;
	read_byte = read(fd, &buffer, 1);
	while (read_byte)
	{
		if (read_byte < 0)
			return (-1);
		if (buffer == '\n')
			return (1);
		if (ft_strcat(line, buffer) == 0)
			ft_error("error", 5);
		read_byte = read(fd, &buffer, 1);
	}
	return (0);
}