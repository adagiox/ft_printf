#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

// Enumeration of types returned by the format parser

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

// Function pointer typedef

typedef int (*t_func)(t_printf *print);

t_func g_func_arr[] = {};

// Calls the appropriate function for a chosen type

typedef struct	s_handler
{
	t_type htype;
	t_func hfunc;
}				t_handler;

typedef struct	s_printf
{
	//int prec; 	/* Precision. */
	//int width; 	/* Width. */
	char spec; 	/* Format letter. */
	//unsigned int is_long_double:1;	/* L flag. */
	//unsigned int is_short:1;	/* h flag. */
	//unsigned int is_long:1;	/* l flag. */
	//unsigned int alt:1;	/* # flag. */
	//unsigned int space:1;	/* Space flag. */
	//unsigned int left:1;	/* - flag. */
	//unsigned int showsign:1;	/* + flag. */
	//unsigned int group:1;	/* ' flag. */
	//unsigned int is_char:1;	/* hh flag. */
	//unsigned int wide:1;	/* Nonzero for wide character streams. */
	//unsigned int i18n:1;	/* I flag. */
	char *str;
}				t_printf;

// t_plist is a list of t_printf struct elemenents
// corresponding to the elements which need to be printed
// each node in t_plist contains the arg and associated t_printf struct

typedef struct	s_plist
{
	t_printf		*data;
	struct s_plist	*next;
}				t_plist;

int	ft_printf(const char *format, ...);
int parse_format(char *format, va_list args);
int str_size(char *str);
int print_buffer(t_plist *list);
char *parse_subfmt(char *format);
t_printf *parse_set(char **format, va_list args);
t_plist *lstnew(t_printf *data);
t_plist *lstadd(t_plist *head, t_printf *data);
