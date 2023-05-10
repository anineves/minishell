#include "libft.h" 

void  ft_putendl_fd(char *s, int fd)
{
    if (fd < 0)
      return;
    ft_putstr_fd(s, fd);
    write (fd, "\n", 1);
}

/* int main()
{
  ft_putendl_fd("Teste", 1);
  return (0);
 }
 */
