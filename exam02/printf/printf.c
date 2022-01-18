#include <stdarg.h>
#include <unistd.h>

#define BASE "0123456789"
#define BASEX "0123456789abcdef"

#define max(a, b) (((a) < (b)) ? (b) : (a))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int print_size;

int numlen(long long num, int base)
{
    int i = 1;
    while ((num /= base) > 0)
        ++i;
    return (i);
}
int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        ++i;
    return (i);
}
void ft_putnbr(long long num, int base, char *bs )
{
    if(num >= base)
        ft_putnbr(num / base, base, bs);
    print_size += write(1, &bs[num % base], 1);
}
int ft_printf(char *format, ...)
{
    va_list ap;
    int i = 0;
    int sign = 0;
    print_size = 0;
    va_start(ap, format);
    while (format[i])
    {
        int wid = 0;
        int dot = 0;
        int pre = 0;
        if (format[i] == '%')
        {
            ++i;
            while (format[i] != 's' && format[i] != 'd' && format[i] != 'x' && format[i] != '\0')
            {
                if (format[i] == '.')
                {
                    dot = 1;
                    ++i;
                }
                for ( ; dot == 0 && format[i] >= '0' && format[i] <= '9' ; i++)
                    wid = wid * 10 + (format[i] - '0');
                for ( ; dot == 1 && format[i] >= '0' && format[i] <= '9' ; i++)
                    pre = pre * 10 + (format[i] - '0');
            }
            if (format[i] == 's')
            {
                char *s = va_arg(ap, char *);
                if (!s)
                    s = "(null)";
                if (dot == 1 && pre == 0)
                    s = "";
                if (dot == 0)
                    pre = ft_strlen(s);
                for (int j = 0 ; j < wid - min(ft_strlen(s), pre) ; j++)
                    print_size += write(1, " ", 1);
                for (int j = 0 ; j < min(ft_strlen(s), pre) ; j++)
                    print_size += write(1, &s[j], 1);
            }
            else if(format[i] == 'd')
            {
                long long num = va_arg(ap, int);
                if (num < 0)
                {
                    num *= -1;
                    sign = 1;
                }
                if (num == 0 && dot == 1 && pre == 0)
                    ++wid;
                for (int j = 0 ; j < wid - sign - max(pre, numlen(num, 10)) ; j++)
                    print_size += write(1, " ", 1);
                print_size += write(1, "-", sign);
                for (int j = 0 ; j < pre - numlen(num, 10) ; j++)
                    print_size += write(1, "0", 1);
                if (num != 0 || dot != 1 || pre != 0)
                    ft_putnbr(num, 10, BASE);
            }
            else if(format[i] == 'x')
            {
                long long num = va_arg(ap, unsigned int);
                if (num == 0 && dot == 1 && pre == 0)
                    ++wid;
                for (int j = 0 ; j < wid - max(pre, numlen(num, 16)) ; j++)
                    print_size += write(1, " ", 1);
                for (int j = 0 ; j < pre - numlen(num, 16) ; j++)
                    print_size += write(1, "0", 1);
                if (num != 0 || dot != 1 || pre != 0)
                    ft_putnbr(num, 16, BASEX);
            }
            else
                --i;
        }
        else
            print_size += write(1, &format[i], 1);
        ++i;
    }
    return (print_size);
}


int main(void)
{
	ft_printf("%10.2s\n", "toto");
	ft_printf("Magic %s is %5d", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("%d\n", -4200);

	return(0);

}
