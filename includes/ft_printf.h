#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>

#define ONE_BYTE 128
#define TWO_BYTE 2048
#define THREE_BYTE 65536

typedef struct	s_printf
{
	int prec; /* Precision. */
	int prec_set:1;
	int width; /* Width. */
	char spec; /* Conversion specifer. */
	int type; /* Argument type. */
	char pad_char; /* Padding character. */
	unsigned int is_short:1; /* h flag. */
	unsigned int is_char:1; /* hh flag. */
	unsigned int is_long:1; /* l flag. */
	unsigned int is_longlong:1; /* ll flag. */
	unsigned int is_sizet:1; /* z flag. */
	unsigned int intmax:1; /* j flag. */
	unsigned int alt:1; /* # flag. */
	unsigned int space:1; /* Space flag. */
	unsigned int left:1; /* - flag. */
	unsigned int showsign:1; /* + flag. */
	unsigned int wide:1; /* Nonzero for wide character streams. */
	unsigned int pad:1; /* Padding flag. */
}				t_printf;

typedef int dispatcher(t_printf *flags, va_list args);

typedef struct	s_type
{
	char spec;
	dispatcher *func;
}				t_type;

int ft_printf(const char *f, ...);
int ft_atoi(const char *str);
int ft_isdigit(int c);
void ft_putchar(char c);
void ft_putnbr(int n);
void ft_putstr(char *s);
void ft_putnstr(char *s, int n);
int		ft_wstrlen(wchar_t *ws);
int		ft_wclen(wchar_t wc);
int		ft_wputstr(wchar_t *ws);
int		ft_wputchar(wchar_t wc);
size_t	ft_strlen(const char *str);

int	ft_printf(const char *f, ...);
int vprintf(const char *f, va_list args);
int print_info(t_printf *flags);
void pad_char(t_printf *flags);
int print_s(t_printf *flags, char *s);
int print_c(t_printf *flags, char c);
int print_i(int n);
int print_u(unsigned int n);
int print_x(char *s);
int print_ud(unsigned int ud);
int print_wc(t_printf *flags, wchar_t wc);
int convert_ud(t_printf *flags, va_list args);
int convert_p(t_printf *flags, va_list args);
int convert_x(t_printf *flags, va_list args);
int convert_c(t_printf *flags, va_list args);
int convert_s(t_printf *flags, va_list args);
int convert_i(t_printf *flags, va_list args);
int convert_u(t_printf *flags, va_list args);
int convert_wc(t_printf *flags, va_list args);
int convert_ws(t_printf *flags, va_list args);
int do_conversion(t_printf *flags, va_list args);
int set_flags(const char **f, va_list args);
int set_spec(const char **f, t_printf *flags, va_list args);
int set_length(const char **f, t_printf *flags, va_list args);
int set_width(const char **f, t_printf *flags, va_list args);
int set_prec(const char **f, t_printf *flags, va_list args);
t_printf *init_flags();

#endif