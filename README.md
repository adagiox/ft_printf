# ft_printf
A remake of printf in C.


The protoype is:
	int printf(const char *format, ...);

Where the format string is specefied as follows:
	%[flags][width][.precision][length]type

followed by a variable list of arguments to be printed to the standard output.

ft_printf handles:

<ul>
<li>Flags: #0-+ and space</li>
<li>Width</li>
<li>Precision</li>
<li>Length: hh, h, l, ll, j, and z.</li>
<li>Types: sSpdDioOuUxXcC</li>
</ul>
