/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 18:15:55 by svoort         #+#    #+#                */
/*   Updated: 2019/07/24 13:57:59 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <wctype.h>
# include <stdint.h>
# include <locale.h>

# define FLSIZ(x) x == 'j' || x == 'z' || x == '#' || x == 'l' || x == 'h'
# define FL2(x) x == ' ' || (x != 44 && x != 47 && x > 41 && x < 58) || x == 'L'
# define DEVAL(x) x == 'D' || x == 'd' || x == 'x' || x == 'O' || x == 'b'
# define DEVA2(x) x == 'i' || x == 'o' || x == 'X' || x == 'u' || x == 'U'
# define OPER(x) (x < 96 || x > 103) && x != 105 && x != 120 && x != 114
# define OPE2(x) x != 115 && (x < 110 || x > 112) && x != 117  && x != 83
# define OPE3(x) (x < 65 || x > 71) && x != 85 && x != 88 && x != 79

# define RED			\e[0;31m
# define BOLDRED		\e[1;31m
# define GREEN			\e[0;32m
# define BOLDGREEN		\e[1;32m
# define YELLOW			\e[0;33m
# define BOLDYELLOW		\e[1;33m
# define BLUE			\e[0;34m
# define BOLDBLUE		\e[1;34m
# define MAGENTA		\e[0;35m
# define BOLDMAGENTA	\e[1;35m
# define CYAN			\e[0;36m
# define BOLDCYAN		\e[1;36m

int					ft_atoi(const char *str);
int					ft_nbrlen(intmax_t c, int a);
int					ft_printf(const char *format, ...);
void				ft_prfoper(char *s, va_list *ar, int *i);
void				ft_prfnbr(char c, int *i, va_list *ar, char *ito);
char				*ft_itoabase(uintmax_t c, int l, int y);
size_t				ft_strlen(const char *s);
char				*unistr(wchar_t *s, int *j);
char				*unicd(wint_t c);
void				ft_prfdbl(char c, int *i, va_list *ar);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
uintmax_t			ft_basetoint(char *s, int base);
char				*ft_joinfree(char *s1, char *s2, int j);
void				ft_dblhex(long double c, int *i, int y);
size_t				ft_wcharlen(const wchar_t *s);
void				ft_precforp(char *s, int *i);
void				ft_outun(char *s, int *i, int j, int c);
char				*ft_qstr(char *s, int *i);
void				strendf(char s, int *i);
char				*ft_rotnb(char *s, int i);
void				prfsec(char c, int *i, va_list *ar, char *ito);
int					flbax(char *s, va_list *ar2, int *i);
int					justfree(char **ito, int a, char c);

/*
**	helper1.c
*/

void				ft_binary_magic(long double *c, int **i);
void				terminate_b(char ***s, int *j);
void				ft_ifupper(int *reg, int *tmp);
void				convert_pos(int *i, char **res, intmax_t *c);
void				check_char(char **s, uintmax_t *l, int j, uintmax_t i);

/*
**	helper2.c
*/

void				prec_helper(int *j, long double *y);
void				read_arg(int *i, long double *o, va_list *ar);
void				memalloc_ito(int *l, char ***ito);
void				check_sign(char **ito, int **i, char **s);
void				cpy_while_second_i(char **ito, int **i, char **s);

/*
**	helper3.c
*/

void				if_prfsec(int **i, char c, va_list *ar, char *ito);
void				prfstr_if_c(char s, int **i, char **un, va_list *ar);
void				prfsec_check_r(char *s, int **i);
void				prfoper_readarg(int *i, va_list *ar);
void				if_ar2(int **i, char *s, va_list *ar2);

/*
**	helper4.c
*/

void				if_dot(char *s, int **i, va_list *ar2);
void				ft_qstr_help(char **res, int *i, int *j, char *s);
void				ft_rotng_loop(int *a, int i, char **s, char **r);
void				ft_rotnb_loop(int *a, int i, char **s, char **r);
void				ft_outun_loop(char **s, int *c, int *b);

/*
**	helper5.c
*/

void				transcode_loops(int *c, char (*cd)[9], int *j, char *s);
void				unistr_loop(char **str, char *tmp, int **j, int *i);
void				enddbl_check(int **i, char *s);
void				dbltoa_loop(int *i, long double *c, int *j, intmax_t *x);
void				prfdbl_check(int **i, int l, char **ito, char c);

/*
**	helper6.c
*/

int					checkshar_check(int **i, char c, char **res, char *ito);
void				endprf_help(int **i, char *s, int r);
void				prfsec_help(int *i, char **ito, va_list *ar, char c);
void				prfnbr_help(int *i, char **ito, va_list *ar, char c);
void				strendf_help(int **i, char s);

/*
**	helper7.c
*/

int					flg_sec_check(int **i, char *s);
void				read_width(int **i, char *str, va_list tmp[2], \
					va_list varg);
void				read_args(int **i, va_list tmp[2]);
void				set_args_to_zero(int (*i)[19]);

#endif
