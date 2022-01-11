# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int ft_strlen(char *str)
{
	int i=0;

	while (*str && str[i])
		i++;
	return (i);
}

char *itoa_base(long long num, int base)
{
	int i = 1;
	char *ret;
	int minus = 0;

	if (num == 0)
		return ("0");
	if (num < 0)
	{
		i++;
		minus = -1;
		num *= -1;
	}
	long long temp = num;
	while ((temp /= base) > 0)
		i++;
	ret = malloc(i + 1);
	ret[i] = 0;
	//while (0 <= --i)
	while(--i >= 0)
	{
		if (i == 0 && minus == -1)
		{
			ret[i] = '-';
			break;
		}
		if (num % base < 10)
			ret[i] = num % base + '0';
		else
			ret[i] = (num % base - 10) + 'a';
		num /= base;
	}
	return (ret);
}

int ft_printf(const char *input, ...)
{
	va_list	ap;
	va_start(ap, input);
	char* res;

	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 's')
				write(1, input, 1);
			else if (*input == 'd')
				res = itoa_base((long long)va_arg(ap, int), 10);
			else if (*input == 'x')
				res = itoa_base((long long)va_arg(ap, unsigned int), 16);
			write(1, res, ft_strlen(res));
			if (*input != 's')
				free(res);
		}
		else
			write(1, input, 1);
		input++;
	}
	return (0);
}
