#include <unistd.h>

int		ft_stop(char *s, int max, char c)
{
	int	i;

	i = -1;
	while(++i < max)
		if (s[i] == c)
			return (0);
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	while (s1[++i])
		if (ft_stop(s1, i, s1[i]))
			write(1, &s1[i], 1);
	j = -1;
	while (s2[++j])
		if (ft_stop(s1, i, s2[j]) & ft_stop(s2, j, s2[j]))
			write(1, &s2[j], 1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}