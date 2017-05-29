/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:13:43 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 15:51:22 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 128
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "rgb.h"
# include "keys.h"

size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *s);
int				ft_isalpha(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_lstprint(t_list *lst);

typedef struct	s_buf
{
	char	buf[BUFF_SIZE + 1];
	size_t	cursor;
}				t_buf;

int				get_next_line(const int fd, char **line);

typedef struct	s_quadratic_equation
{
	double		a;
	double		b;
	double		c;
	double		x1;
	double		x2;
	int			has_solutions;
}				t_quadratic_equation;

void			solve_quadratic_equation(t_quadratic_equation *eq);

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

t_vec			vec(double x, double y, double z);
t_vec			vec_plus(t_vec a, t_vec b);
t_vec			vec_minus(t_vec a, t_vec b);
t_vec			vec_mult_num(t_vec a, double num);
double			vec_mult_scal(t_vec a, t_vec b);
double			vec_len(t_vec a);
double			vec_cos_angle(t_vec a, t_vec b);
t_vec			vec_normed(t_vec a);

void			split_res_free(char ***split_res);
int				ft_is_int(char *s);

char			*ft_uintmax_to_str_base(uintmax_t a, unsigned char base,
					int is_uppercase, size_t min_width);
char			*ft_intmax_to_str_base(intmax_t a, unsigned char base,
					int is_uppercase, size_t min_width);
char			*ft_longdouble_to_str_base(long double a, unsigned char base,
					int is_uppercase, unsigned char precision);
intmax_t		ft_i_pow_n(intmax_t i, unsigned char n);

# define PRINTF_LEN_L	1
# define PRINTF_LEN_H	2
# define PRINTF_LEN_J	3
# define PRINTF_LEN_Z	4
# define PRINTF_LEN_LL	5
# define PRINTF_LEN_HH	6

typedef struct	s_printf_conversion_vars
{
	int			reshetka;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	char		conv_char;
	int			conv_len;
	int			len_modifier;
	int			precision;
	char		sign;
	int			was_p;
	int			conv_printed;
}				t_pcv;

typedef struct	s_printf_arg_vars
{
	char		**pstr;
	const char	*fmt;
	va_list		args;
	size_t		i;
	size_t		fmt_len;
	int			res;
	t_pcv		pcv;
}				t_pav;

int				ft_printf(const char *fmt, ...);
int				ft_sprintf(char **pstr, const char *fmt, ...);
int				ft_vsprintf(char **pstr, const char *fmt, va_list args);

void			parse_arg(t_pav *pav);
void			init_pav(t_pav *pav, char **pstr, const char *fmt,
					va_list args);
void			init_pcv(t_pcv *pcv);
int				ft_printf_add_str_to_pav(t_pav *pav, const char *s,
					size_t s_len);
int				ft_printf_add_str_using_width(t_pav *pav, char *s,
					size_t s_len);

void			ft_printf_c(t_pav *pav);
void			ft_printf_s(t_pav *pav);
void			ft_printf_di(t_pav *pav);
void			ft_printf_boux(t_pav *pav);
void			ft_printf_p(t_pav *pav);
void			ft_printf_uppercase_doucs(t_pav *pav);
void			ft_printf_f(t_pav *pav);
void			ft_printf_percent(t_pav *pav);
void			ft_printf_v(t_pav *pav);
void			ft_printf_default(t_pav *pav);

void			ft_wctomb(wchar_t c, char *s, int *s_len);
size_t			ft_wstrlen(const wchar_t *ws);
void			ft_wcstombs(wchar_t *s, char **s1,
					size_t *s1_len, int ws_len);
void			ft_printf_print_pav(t_pav *pav);
#endif
