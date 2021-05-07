/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marty <Marty@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 15:22:57 by Marty         #+#    #+#                 */
/*   Updated: 2020/05/25 13:35:37 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);

void		test_strlen(void)
{
	printf("\n	-----  FT_STRLEN  -----\n\n");
	printf("1) <string> : %zu\n", strlen(""));
	printf("1) <libasm> : %zu\n", ft_strlen(""));
	printf("2) <string> : %zu\n", strlen("Hello"));
	printf("2) <libasm> : %zu\n", ft_strlen("Hello"));
	printf("3) <string> : %zu\n", strlen("\t"));
	printf("3) <libasm> : %zu\n", ft_strlen("\t"));
	printf("\n");
}

void		test_strcmp(void)
{
	printf("\n	-----  FT_STRCMP  -----\n\n");
	printf("3) <string> : %d\n", strcmp("", ""));
	printf("3) <libasm> : %d\n", ft_strcmp("", ""));
	printf("4) <string> : %d\n", strcmp("Hello", "Hello"));
	printf("4) <libasm> : %d\n", ft_strcmp("Hello", "Hello"));
	printf("5) <string> : %d\n", strcmp("Assembly", ""));
	printf("5) <libasm> : %d\n", ft_strcmp("Assembly", ""));
	printf("6) <string> : %d\n", strcmp("", "Assembly"));
	printf("6) <libasm> : %d\n", ft_strcmp("", "Assembly"));
	printf("7) <string> : %d\n", strcmp("Nasm", "Assembly"));
	printf("7) <libasm> : %d\n", ft_strcmp("Nasm", "Assembly"));
	printf("\n");
}

void		test_strcpy(void)
{
	char d[50];

	printf("\n	-----  FT_STRCPY  -----\n\n");
	printf("1) <string> : %s\n", strcpy(d, ""));
	printf("1) <libasm> : %s\n", ft_strcpy(d, ""));
	printf("2) <string> : %s\n", strcpy(d, "Hello"));
	printf("2) <libasm> : %s\n", ft_strcpy(d, "Hello"));
	printf("3) <string> : %s\n", strcpy(d, "Assembly"));
	printf("3) <libasm> : %s\n", ft_strcpy(d, "Assembly"));
	printf("\n");
}

void		test_strdup(void)
{
	printf("\n	-----  FT_STRDUP  -----\n\n");
	printf("1) <stdlib> : %s\n", strdup(""));
	printf("1) <libasm> : %s\n", ft_strdup(""));
	printf("2) <stdlib> : %s\n", strdup("Hello"));
	printf("2) <libasm> : %s\n", ft_strdup("Hello"));
	printf("3) <stdlib> : %s\n", strdup("Assembly"));
	printf("3) <libasm> : %s\n", ft_strdup("Assembly"));
	printf("\n");
}

void		test_write(void)
{
	int a;
	int b;

	printf("\n	-----  FT_WRITE  -----\n\n");
	a = write(-40 + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	perror("1) <unistd> errno ");
	errno = 100;
	b = ft_write(-40 + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	perror("1) <libasm> errno ");
	printf("1) <unistd> return : %d\n1) <libasm> return : %d\n", a, b);
	a = write(1, 0, 9);
	perror("2) <unistd> errno ");
	errno = 100;
	b = ft_write(1, 0, 9);
	perror("2) <libasm> errno ");
	printf("2) <unistd> return : %d\n2) <libasm> return : %d\n", a, b);
	a = write(1, 0, 10);
	perror("3) <unistd> errno ");
	errno = 100;
	b = ft_write(-1, "test", 5);
	perror("3) <libasm> errno ");
	printf("3) <unistd> return : %d\n3) <libasm> return : %d\n", a, b);
	a = write(103, "hello", 5);
	perror("4) <unistd> errno ");
	errno = 100;
	b = ft_write(103, "hello", 5);
	perror("4) <libasm> errno ");
	printf("4) <unistd> return : %d\n4) <libasm> return : %d\n", a, b);
}

void		test_read(void)
{
	int fd;
	char uni_buf[50];
	char lib_buf[50];
	ssize_t ret;

	printf("\n	-----  FT_READ    -----\n\n");

	fd = open("Makefile", O_RDONLY);
	ret = read(fd, uni_buf, 5);
	printf("1) <unistd> : %zd\n", ret);
	close(fd);

	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, lib_buf, 5);
	printf("1) <libasm> : %zd\n", ret);
	close(fd);

	fd = open("emptyFile", O_RDONLY | O_CREAT | O_TRUNC, 0777);
	ret = read(fd, uni_buf, 5);
	printf("2) <unistd> : %zd\n", ret);
	close(fd);

	fd = open("emptyFile", O_RDONLY | O_CREAT | O_TRUNC, 0777);
	ret = ft_read(fd, lib_buf, 5);
	printf("2) <libasm> : %zd\n", ret);
	close(fd);
	remove("emptyFile");
	printf("\n");

	errno = 100;
	fd = open("I don't exist", O_RDONLY);
	ret = read(fd, uni_buf, 5);
	printf("3) <unistd> return : %zd\n", ret);
	perror("3) <unistd> errno ");
	close(fd);

	errno = 100;
	fd = open("I don't exist", O_RDONLY);
	ret = ft_read(fd, lib_buf, 5);
	printf("3) <libasm> return : %zd\n", ret);
	perror("3) <libasm> errno ");
	close(fd);

	errno = 100;
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, NULL, 5);
	printf("4) <unistd> return : %zd\n", ret);
	perror("4) <unistd> errno ");
	close(fd);

	errno = 100;
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, NULL, 5);
	printf("4) <libasm> return : %zd\n", ret);
	perror("4) <libasm> errno ");
	close(fd);
}

int			main(void)
{
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_strdup();
	test_write();
	test_read();
	return (0);
}
