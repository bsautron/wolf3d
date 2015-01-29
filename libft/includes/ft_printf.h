/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 09:16:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/20 23:19:47 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define NONE	0
# define LLEFT	1
# define ZERO	2
# define SIGNE	3
# define TAG	4

# define OCT	3
# define HEX	4

typedef unsigned long long int	t_ullong;

struct			s_flag
{
	char	left;
	char	zero;
	char	signe;
	char	blank;
	char	tag;
};

struct			s_over
{
	char	l_short;
	char	l_long;
	char	l_double;
	char	l_intmax_t;
	char	l_z;
};

typedef struct	s_format
{
	struct s_flag	*flag;
	struct s_over	*over_flag;
	int				width;
	int				precision;
	char			did_p;
	char			my_god;
	char			conversion;
}				t_format;

void			ft_pputchar(char c);
void			ft_pputstr(char *s);
void			ft_putstr_c(char *s, int len);
int				ft_pstrlen(const char *s);
int				ft_strlen_per(const char *s);
char			*ft_pitoa(int n);
int				ft_onlyesp(char *str);
char			*ft_pstrnew(unsigned int size);
char			*ft_long_itoa(long long int n);
char			*ft_unsigned_itoa(t_ullong n);
void			*ft_pmemalloc(unsigned int size);
void			ft_pbzero(void *s, unsigned int n);
void			*ft_pmemset(void *s, int c, unsigned int n);
char			*ft_pstrdup(const char *s1);
char			*ft_pstrncpy(char *dst, const char *src, unsigned int n);
char			*ft_pstrncat(char *s1, const char *s2, unsigned int n);
int				ft_charcheck_in_str(char let, char *str);
int				ft_pisdigit(int c);
long long int	ft_patoi(const char *str);
int				ft_pintlen(int n);
char			*ft_transfo_int(char *str, t_format *fg, int *tab_b, int len_b);
char			*ft_transfo_hexoct(char *str, t_format *fg);
char			*ft_pstrjoin(const char *s1, const char *s2);
char			*ft_strjoin_per(const char *s1, const char *s2);
char			*ft_strjoin_per_aux(const char *s1, const char *s2);
char			*ft_strjoin_per_aux2(const char *s1, const char *s2);
char			*ft_strjoin_etoile(const char *s1, const char *s2);
char			*ft_pstrnjoin(const char *s1, const char *s2, int s, int len);
int				ft_ppow(int base, int pow);
int				ft_pstrequ(char const *s1, char const *s2);
void			ft_initflags(t_format **fg);
int				ft_printf(const char *format, ...);
char			*ft_putarg(const char *f, va_list ap, t_format *fg);
int				ft_check_flags(const char *str, t_format **fg, va_list ap);
void			ft_putflags(char flg, t_format **fg);
char			*ft_binary(unsigned long long int nb, t_format *fg);
char			*ft_bin_to_hexoct(char *str, int conv, t_format *fg);
char			*ft_putwidth(char *str, int width, t_format *fg);
char			*ft_split_bytes(char *bin, int *nb_bytes);
char			*ft_putprecision(char *str, char *dst, int prec, t_format *fg);
char			*ft_putprecision_ho(char *s, char *d, int prec, t_format *fg);
char			*ft_long_str(va_list ap, const char *f,
		char *dst, int **tab_b, int *bn_bytes, t_format *fg);
int				ft_nbesp(char *str);

#endif
