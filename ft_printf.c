#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define	ABS(x) ((x < 0) -x : x)
#define	MIN(a,b) ((a < b) a : b)
#define	INT_MAX 2147483647
#define	INT_MIN -2147483648

typedef struct 	s_str
{
	char 		*content;
	struct s_str	*next;
}		t_str;

int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while(str[l])
		l++;
	return (l);
}

int	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (0);
}

int	add_str(t_str **str, char *content)
{
	t_str	*new;
	t_str	*tmp;

	if (!content)
		return (0);
	if (!(new = (t_str *)malloc(sizeof(t_str) * 1)))
		return (0);
	new->content = content;
	new->next = 0;
	if (!*str)
		*str = new;
	else
	{
		tmp = *str;
		while ((*str)->next)
			*str = (*str)->next;
		(*str)->next = new;
		*str = tmp;
	}
	return (1);
}

char	*ft_substr(const char *format, int start, int length)
{
	char	*new;
	int	i;

	if (!format)
		return (0);
	if (!(new = (char *)malloc(sizeof(char) * length + 1)))
		return (0);
	i = 0;
	while (i < length)
	{
		new[i] = format[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}

int	ft_in_set(char c, char *set)
{
	int	i;
	
	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	parse_flag(char *flag, int *with, int *precision)
{
	int	i;
	int	state;
	int	tmp;

	*precision  = -1;
	*with = -1;
	state = 0;
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '.')
		{
			*precision = 0;
			state = 1;
			i++;
		}
		else if (ft_isdigit(flag[i]))
		{
			tmp = 0;
			while (ft_isdigit(flag[i]))
				tmp = (tmp * 10) + (flag[i++] - '0');
			if (!state)
				*with  = tmp;
			else
				*precision = tmp;
			state = 0;
		}
		else
			return (0);
	}
	return (1);
}

char	*format_decimal(int l, int precision)
{
	char	*str;
	int	i;

	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	i = 0;
	while (i < l)
	{
		if (precision >= 0 && l - i <= precision)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*format_signed(int with, int precision, int val)
{
	char 	*str;
	long	ltmp;
	int	tmp;
	int	nb_l;
	int	l;
	int	i;

	ltmp = val;
	if (ltmp > INT_MAX)
		val = INT_MIN + (ltmp - INT_MAX);
	if (ltmp < INT_MIN)
		val = INT_MAX - (INT_MIN - ltmp);
	tmp = val;
	nb_l = 0;
	while (tmp % 10)
	{
		tmp /= 10;
		nb_l++;
	}
	l = nb_l + (val < 0);
	if (with > l)
		l = with;
	if (precision > l)
		l = precision;
	if (!(str = format_decimal(l, precision)))
		return (0);
	if (precision == 0 && val == 0)
		str[l - 1] = (with == l) ? ' ' : 0;
	else if (val == 0)
		str[l - 1] = '0';
	tmp = val;
	i = l - 1;
	while (tmp != 0)
	{
		ltmp = tmp;
		ltmp = (ltmp < 0) ? -ltmp : ltmp;
		str[i--] = "0123456789"[ltmp % 10];
		tmp /= 10;
	}
	if (val < 0)
		str[i] = '-';
	return (str);
}

char	*format_hex(int with, int precision, unsigned int val)
{
	unsigned int	tmp;
	int		nb_l;
	int		l;
	int		i;
	char		*str;

	nb_l = 1;
	tmp = val;
	while (tmp > 15)
	{
		nb_l++;
		tmp /= 16;
	}
	l = nb_l;
	if (with > nb_l)
		l = with;
	if (precision > l)
		l = precision;
	if (!(str = format_decimal(l, precision)))
		return (0);
	if (precision == 0 && val == 0)
		str[l - 1] = (with == l) ? ' ' : 0;
	else if (val == 0)
		str[l - 1] = '0';
	i = l - 1;
	tmp = val;
	while (tmp != 0)
	{
		str[i--] = "0123456789ABCDEF"[tmp % 16];
		tmp /= 16;
	}
	return (str);
}

char	*format_str(int with, int precision, char *str)
{
	char 	*new;
	int	l;
	int	nb_l;
	int	i;
	int	j;
	int	limit;
	
	if (!str)
		str = "(null)";
	nb_l = ft_strlen(str);
	l = nb_l;
	if (with > nb_l || (precision >= 0 && with > precision))
		l = with;
	if (!(new = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	i = 0;
	while (i < l)
		new[i++] = ' ';
	new[i] = 0;
	if (with > 0 && (precision == 0 || nb_l == 0))
	{
		new[with] = 0;
		return (new);
	}
	else if (precision == 0)
	{
		new[0] = 0;
		return (new);
	}
	if (precision > 0)
		limit = (nb_l < precision) ? nb_l : precision;
	else
		limit = nb_l;
	j = 0;
	if (with == l)
		i = l - limit;
	else
		i = 0;
	while (j < limit)
	{
		new[i++] = str[j++];
	}
	return (new);
}

char	*format_missing(char *flag, char format)
{
	char 	*str;
	int 	l;
	int	i;
	int	j;

	l = ft_strlen(flag) + 1 + 1;
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	i = 0;
	str[i++] = '%';
	j = 0;
	while (flag[j])
		str[i++] = flag[j++];
	str[i++] = format;
	str[i] = 0;
	return (str);
}

int	add_format(t_str **str, char *flag, char c, va_list *arg)
{
	char	*mat;
	int	with;
	int	precision;
	int	fla;

	if (!flag)
		return (0);
	fla = parse_flag(flag, &with, &precision);
	if (!fla)
		return (ft_free((void *)flag));
	mat = 0;
	if (c == 'd')
		mat = format_signed(with, precision, va_arg(*arg, int));
	else if (c == 'x')
		mat = format_hex(with, precision, va_arg(*arg, int));
	else if (c == 's')
		mat = format_str(with, precision, va_arg(*arg, char *));
	else
		mat = format_missing(flag, c);
	if (!mat)
		return (ft_free((void *)flag));
	if (!add_str(str, mat))
		return (ft_free((void *)flag));
	return (1);
}

int	str_write(t_str *str)
{
	t_str	*tmp;
	int	l;
	int	nb_l;

	l = 0;
	nb_l = 0;
	while (str)
	{
		l = ft_strlen(str->content);
		write (1, str->content, l);
		nb_l += l;
		str = str->next;
	}
	return (nb_l);
}

void	ft_free_str(t_str *str)
{
	if (str)
	{
		if (str->next)
			ft_free_str(str->next);
		if (str->content)
			free(str->content);
		free(str);
	}
}

int	clear_all(t_str *str, va_list *arg)
{
	ft_free_str(str);
	va_end(*arg);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int	length;
	int	i;
	int	start;
	t_str	*str;
	va_list	arg;

	if (!format)
		return (0);
	va_start(arg, format);
	length = ft_strlen(format);
	str = 0;
	i = 0;
	while (i < length)
	{
		start = i;
		while (i < length && format[i] != '%')
			i++;
		if (i - start > 0 && !add_str(&str, ft_substr(format, start, i - start)))
			return (clear_all(str, &arg));
		if (format[i] == '%' && (start = ++i) && i < length)
		{
			while (i < length && ft_in_set(format[i], ".0123456789"))
				i++;
			if (!add_format(&str, ft_substr(format, start, i - start), format[i], &arg))
				return (clear_all(str, &arg));
		}
		i++;
	}
	i = str_write(str);
	clear_all(str, &arg);
	return (i);
}

int	main()
{
	ft_printf("la chaine %1s\n%2.2x hi\n%d %234.45j%%%\n", 0, -15, -15);
	return (1);
}
