#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    t_list *bla = begin_list;
    
    while (bla != 0)
    {
        bla = bla->next;
        i++;
    }
    return (i);
}