# ft_printf
A remake of printf in C.

ft_printf takes a format string
	%[flags][width][.precision][length]type
and a variable list of arguments to be printed to the standard output.

ft_printf handles:

• Flags: #0-+ and space
• Width
• Precision
• Length: hh, h, l, ll, j, and z.
• Types: sSpdDioOuUxXcC
