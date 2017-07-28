#include "../includes/ft_printf.h"

int print_buffer(t_plist *list)
{
	t_plist *ptr;
	ptr = list;
	while (ptr != NULL)
	{
		ft_putstr(ptr->data->str);
		ptr = ptr->next;
	}
	return 1;
}