# ft_printf
**A remake of printf in C.**
``int printf(const char *format, ...);``


The format string is specified as follows:
``%[flags][width][.precision][length]type``

followed by a variable list of arguments to be printed to the standard output.

ft_printf handles:

<ul>
<li>Flags: #0-+ and space</li>
<li>Width</li>
<li>Precision</li>
<li>Length: hh, h, l, ll, j, and z.</li>
<li>Types: sSpdDioOuUxXcC</li>
</ul>
