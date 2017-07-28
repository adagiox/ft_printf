#include "ft_printf.h"

// Create a new t_plist node from a t_printf struct

t_plist *lstnew(t_printf data)
{
	t_plist *new;
	new = (t_plist *)malloc(sizeof(t_plist));
	new->data = data;
	new->next = NULL;
	return new;
}

t_plist *lstadd(t_plist *head, t_printf data)
{
	t_plist *ptr;
	if (head == NULL)
	{
		ptr = lstnew(data);
		return ptr;
	}
	ptr = head;
	if (ptr->next == NULL)
	{
		ptr->next = lstnew(data);
		return head;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = lstnew(data);
	return head;
}
