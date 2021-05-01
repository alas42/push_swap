#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#define RAND_TIME 32000

char		*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	int		tmp;

	len = (n < 0) ? 2 : 1;
	tmp = n;
	while ((tmp /= 10) != 0)
		len++;
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (n == -2147483648)
		result[1] = '2';
	n = (n == -2147483648) ? 147483648 : n;
	n = (n < 0) ? n * -1 : n;
	result[len] = '\0';
	while (len--)
	{
		result[len] = ((n % 10) + '0');
		n /= 10;
		if (n == 0)
			return (result);
	}
	return (result);
}

int main(int argc, char *argv[])
{
	int num[501];
	int i;
	int j;
	int numbers;
	char *s;
	int fd;

	if (argc > 1)
		numbers = atoi(argv[1]);
	else
		numbers = 500;
	i = 0;
	srand(time(NULL));
	while (i < numbers)
		num[i++] = rand();
	num[i] = -1;
	i = 0;
	while (num[i] != -1)
	{
		j = 0;
		while (num[j] != -1)
		{
			if (j != i)
			{
				if (num[i] == num[j])
				{
					i = -1;
					num[i] = rand();
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	fd = open("rand.txt", O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (i < numbers)
	{
		s = ft_itoa(num[i]);
		write(fd, s, strlen(s));
		write(fd, " ", 1);
		i++;
	}
	close(fd);
}
