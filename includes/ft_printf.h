#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_printf
{
	int prec; /* Precision. */
	int width; /* Width. */
	char spec; /* Conversion specifer. */
	int type; /* Argument type. */
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

int ft_atoi(const char *str);
int ft_isdigit(int c);
void ft_putchar(char c);
void ft_putnbr(int n);
void ft_putstr(char *s);

int	ft_printf(const char *f, ...);
int vprintf(const char *f, va_list args);
int print_info(t_printf *flags);
int print_s(char *s);
int print_c(char c);
int print_i(int n);
int print_u(unsigned int n);
int print_x(char *s);
int print_ud(unsigned int ud);
int convert_ud(t_printf *flags, va_list args);
int convert_p(t_printf *flags, va_list args);
int convert_x(t_printf *flags, va_list args);
int convert_c(t_printf *flags, va_list args);
int convert_s(t_printf *flags, va_list args);
int convert_i(t_printf *flags, va_list args);
int convert_u(t_printf *flags, va_list args);
int do_conversion(const char **f, t_printf *flags, va_list args);
int set_flags(const char **f, va_list args);
int set_spec(const char **f, t_printf *flags, va_list args);
int set_length(const char **f, t_printf *flags, va_list args);
int set_width(const char **f, t_printf *flags, va_list args);
int set_prec(const char **f, t_printf *flags, va_list args);
t_printf *init_flags();