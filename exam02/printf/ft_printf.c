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
	char* ret;

	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 's')
				write(1, input, 1);
			else if (*input == 'd')
				ret = itoa_base((long long)va_arg(ap, int), 10);
			else if (*input == 'x')
				ret = itoa_base((long long)va_arg(ap, unsigned int), 16);
			write(1, ret, ft_strlen(ret));
			if (*input != 's')
				free(ret);
		}
		else
			write(1, input, 1);
		input++;
	}
	return (0);
}

int main(void)
{
	//ft_printf("%10.2s\n", "toto");
	//ft_printf("Magic %s is %5d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("%d\n", -4200);

	return(0);

}
