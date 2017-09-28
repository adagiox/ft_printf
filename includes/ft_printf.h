#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int vprintf(const char *format, va_list args);
int set_flags(const char *format, va_list args);

typedef enum	e_type
{
	PA_INT,		/* int */
	PA_CHAR,	/* int, cast to char */
	PA_WCHAR,	/* wide char */
	PA_STRING,	/* const char *, a '\0'-terminated string */
	PA_WSTRING,	/* const wchar_t *, wide character string */
	PA_POINTER,	/* void * */
	PA_FLOAT,	/* float */
	PA_DOUBLE,	/* double */
	PA_LAST
}				t_type;

typedef struct	s_printf
{
	int prec; /* Precision. */
	int width; /* Width. */
	wchar_t spec; /* Format letter. */
	unsigned int is_long_double:1;/* L flag. */
	unsigned int is_short:1; /* h flag. */
	unsigned int is_long:1; /* l flag. */
	unsigned int alt:1; /* # flag. */
	unsigned int space:1; /* Space flag. */
	unsigned int left:1; /* - flag. */
	unsigned int showsign:1; /* + flag. */
	unsigned int group:1; /* ' flag. */
	unsigned int is_char:1; /* hh flag. */
	unsigned int wide:1; /* Nonzero for wide character streams. */
	unsigned int i18n:1; /* I flag. */
}				t_printf;
