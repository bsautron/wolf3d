/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 09:17:00 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:20:36 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FUCKDATSHIT		const char *format, va_list ap
#define FUCKDATSHITP	char *temp, int *len

static char	*ft_temp(int *i, FUCKDATSHITP, FUCKDATSHIT, t_format *fg)
{
	*i = ft_check_flags(format, &fg, ap);
	temp = ft_putarg(&format[*i], ap, fg);
	if (temp[0] == 0 && (fg->conversion == 'c' || fg->conversion == 'C'))
		(*len) += 1;
	else if (fg->my_god)
		(*len) += ft_pstrlen(temp) + 1;
	else
		(*len) += ft_pstrlen(temp);
	return (temp);
}

static char	*ft_makestr(char *dst, FUCKDATSHIT, int *len, t_format *fg)
{
	char		*temp;
	int			len_save;
	int			i;

	dst = ft_pstrdup("");
	while (*format)
	{
		len_save = *len;
		if (*format == '%')
		{
			temp = ft_temp(&i, temp, len, format, ap, fg);
			format += i;
		}
		else
		{
			temp = (char *)malloc(sizeof(char) * 2);
			temp[0] = *format;
			temp[1] = '\0';
			(*len)++;
		}
		if (ft_pstrlen(temp))
			dst = ft_pstrnjoin(dst, temp, len_save, *len);
		format++;
	}
	return (dst);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*fg;
	char		*dst;
	int			len;

	va_start(ap, format);
	len = 0;
	if (ft_pstrlen(format) == 1)
	{
		if (*format != '%')
		{
			dst = (char *)malloc(sizeof(char) * 2);
			dst[0] = *format;
			dst[1] = '\0';
			len++;
		}
	}
	else
		dst = ft_makestr(dst, format, ap, &len, fg);
	va_end(ap);
	ft_putstr_c(dst, len);
	return (len);
}
