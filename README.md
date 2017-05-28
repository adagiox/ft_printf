# ft_printf
**A remake of printf in C.**
<p><code>int printf(const char *format, ...);</code></p>


The format string is specified as follows:
<p><code>%[flags][width][.precision][length]type</code></p>

and is followed by a variable list of arguments to be printed to the standard output.

ft_printf is implemented very similar to glibc's implementation by calling ft_vprintf.

ft_printf handles:

<ul>
<li>Flags: #0-+ and space</li>
<li>Width</li>
<li>Precision</li>
<li>Length: hh, h, l, ll, j, and z.</li>
<li>Types: sSpdDioOuUxXcC</li>
</ul>
