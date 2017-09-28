#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define AR_INT 0
#define AT_UINT 1
#define AR_CHAR 2
#define AR_WCHAR 3
#define AR_STRING 4
#define AR_WSTRING 5
#define AR_POINTER 6
#define AR_FLOAT 7
#define AR_DOUBLE 8


// typedef enum	e_type
// {
// 	AR_INT,		/* int */
// 	AR_CHAR,	/* int, cast to char */
// 	AR_WCHAR,	/* wide char */
// 	AR_STRING,	/*const char *, a '\0'-terminated string 
// 	AR_WSTRING,	/* const wchar_t *, wide character string */
// 	AR_POINTER,	/* void * */
// 	AR_FLOAT,	/* float */
// 	AR_DOUBLE,	/* double */
// }				t_type;

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

int	ft_printf(const char *f, ...);
int vprintf(const char *f, va_list args);
int print_info(t_printf *flags);
int print_string(char *s, va_list args);
int print_char(char c, va_list args);
int print_int(int n, va_list args);
int convert_char(t_printf *flags, va_list args);
int convert_string(t_printf *flags, va_list args);
int convert_int(t_printf *flags, va_list args);
int do_conversion(const char **f, t_printf *flags, va_list args);
int set_flags(const char **f, va_list args);
int set_spec(const char **f, t_printf *flags, va_list args);
int set_length(const char **f, t_printf *flags, va_list args);
int set_width(const char **f, t_printf *flags, va_list args);
int set_prec(const char **f, t_printf *flags, va_list args);
t_printf *init_flags();