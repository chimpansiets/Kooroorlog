#include "vm.h"
#include "op.h"

int	print_mem(int *mem)
{
	int	i;

	i = 0;
	ft_printf("[");
	while (i < MEM_SIZE)
	{
		ft_printf("0x%02X,", mem[i]);
		i++;
		if (i % 32 == 0 && i != MEM_SIZE)
			ft_printf("\n");
	}
	ft_printf("]\n");
	return (0);
}