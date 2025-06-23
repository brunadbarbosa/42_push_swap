#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list 
{
	struct s_list	*next;
	int				content;
	int				index;
}					t_list;

#endif