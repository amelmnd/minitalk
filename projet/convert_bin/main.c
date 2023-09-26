#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	bin_to_char(int **ptr)
{
	static char	c;
	int			byte_idx;
	int			bit_idx;
	int			val;

	byte_idx = 0;
	printf("\nValue per 8 bit -> ");
	while (ptr[byte_idx])
	{
		bit_idx = 0;
		while (bit_idx < 8)
		{
			val = ptr[byte_idx][bit_idx];
			if (val == 1)
				c = (c << 1) | 1;
			else if (val == 0)
				c <<= 1;
			bit_idx++;
		}
		printf("%d", c);
		byte_idx++;
	}
	return (c);
}

int	**char_to_bin(char *str)
{
	int	**ptr;
	int	byte_index;
	int	bit_index;
	int	i;

	byte_index = 0;
	while (str[++byte_index])
		;
	ptr = calloc(byte_index + 1, sizeof(int *));
	if (!ptr)
		return (NULL);
	byte_index = 0;
	printf("Binary value -> ");
	while (str[byte_index])
	{
		ptr[byte_index] = calloc(sizeof(int), 8);
		if (!ptr[byte_index])
			return (NULL);
		bit_index = 7;
		i = 0;
		while (bit_index >= 0)
		{
			ptr[byte_index][i++] = (str[byte_index] >> bit_index) & 1;
			if ((str[byte_index] >> bit_index) & 1)
				printf("SIGUSR1 => %d -> %d\n", str[byte_index] >> bit_index,
						(str[byte_index] >> bit_index) & 1);
				// kill(pid, SIGUSR1);
			else
				printf("SIGUSR2 => %d -> %d\n", str[byte_index] >> bit_index,
						(str[byte_index] >> bit_index) & 1);
				// kill(pid, SIGUSR2);
			bit_index--;
		}
		byte_index++;
	}
	return (ptr);
}

int	main(int argc, char **argv)
{
	// char str[5] = "🌍";
	// -16:-97:-116:-115 or 11110000 : 10011111 : 10001100 : 10001101
	// char str[2] = "H"; // 72 01001000
	int **ptr;

	if (argc != 2)
	{
		printf("Usage: ./client [message]\n");
		return (0);
	}

	ptr = char_to_bin(argv[1]);
	bin_to_char(ptr);
	return (0);
}