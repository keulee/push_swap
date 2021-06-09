#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char			*s1;
	char			*s2;
	unsigned int	i;

	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	if (n == 0 || src == dst)
		return (s1);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}