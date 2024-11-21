#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int *counter)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		++(*counter);
		++i;
	}
	return (1);
}

void	ft_format(va_list str, char c, int *counter)
{
	if (c == 'c')
		*counter += ft_putchar(va_arg(str, int));
	else if (c == 's')
		ft_putstr(va_arg(str, char *), counter);
	else if (c == 'd' || c == 'i')
		ft_putnum(va_arg(str, int), counter);
	else if (c == 'p')
		ft_printp(va_arg(str, unsigned long long), counter);
	else if (c == 'u')
		ft_putun(va_arg(str, unsigned int), counter);
	else if (c == 'x' || c == 'X')
		ft_printhex(va_arg(str, unsigned int), c, counter);
	else if (c != 0)
	{
		++(*counter);
		ft_putchar(c);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			counter += ft_putchar(*format);
		}
		else
		{
			ft_format(args, (*(++format)), &counter);
		}
		++(format);
	}
	va_end(args);
	return (counter);
}
/*
int	main(void)
{
	int				num;
	unsigned int	u_num;
	char			c;
	char			*str;
	char			*null_str;
	int				*ptr;
	int				zero;
	int				neg_num;
	int				ft_res;
	int				std_res;

	ft_res = 0, std_res = 0;
	num = 12345;
	u_num = 4294967295;
	c = 'A';
	str = "Hello, World!";
	null_str = NULL;
	ptr = &num;
	zero = 0;
	neg_num = -42;
	ft_res = ft_printf("Custom: Char: %c\n", c);
	std_res = printf("Standard: Char: %c\n", c);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: String: %s\n", str);
	std_res = printf("Standard: String: %s\n", str);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: Null String: %s\n", null_str);
	std_res = printf("Standard: Null String: %s\n", null_str);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: Integer: %d\n", num);
	std_res = printf("Standard: Integer: %d\n", num);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: Negative Integer: %d\n", neg_num);
	std_res = printf("Standard: Negative Integer: %d\n", neg_num);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: Unsigned: %u\n", u_num);
	std_res = printf("Standard: Unsigned: %u\n", u_num);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: Hex (lower): %x\n", num);
	std_res = printf("Standard: Hex (lower): %x\n", num);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: Hex (upper): %X\n", num);
	std_res = printf("Standard: Hex (upper): %X\n", num);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: Pointer: %p\n", ptr);
	std_res = printf("Standard: Pointer: %p\n", ptr);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
	ft_res = ft_printf("Custom: Zero: %d %x %u\n", zero, zero, zero);
	std_res = printf("Standard: Zero: %d %x %u\n", zero, zero, zero);
	printf("Return values - Custom: %d, Standard: %d\n\n", ft_res, std_res);
}*/
