#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, "8", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
	}
	else
		c = n + '0';
	write(fd, &c, 1);
}
int main()
{
	ft_putnbr_fd(2147483647, 1);
}
