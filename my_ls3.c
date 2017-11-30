/*
** EPITECH PROJECT, 2017
** my_ls3.c
** File description:
** 
*/

#include <dirent.h>
#include <stdio.h>
#include "include/my.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include "printf.h"
#include <fcntl.h>
#include <sys/stat.h>

void print_right(char **list_name, int e)
{
	struct stat s;
	int i = 0;
	int array[9] = {256, 128, 64, 32, 16, 8, 4, 2, 1};
	char str[9] = "rwxrwxrwx";
	stat(list_name[e], &s);

	while (i != 9) {
		if (s.st_mode & array[i])
			my_putchar(str[i]);
		else
			my_putchar('-');
		i = i + 1;
	}
	my_putchar('.');
	my_putstr(" ");
}

int print_right2(char **list_name, int e)
{
	int i = 0;
	struct stat s;

	stat(list_name[e], &s);
	switch (s.st_mode & S_IFMT) {
		case S_IFBLK:
			my_putstr("b");
			return (0);
		case S_IFCHR:
			my_putstr("c");
			return (0);
		case S_IFDIR:
			my_putstr("d");
			return (0);
		case S_IFIFO:
			my_putstr("p");
			return (0);
		case S_IFLNK:
			my_putstr("l");
			return (0);
		case S_IFSOCK:
			my_putstr("s");
			return (0);
		default:
			my_putstr("-");
			return (0);
	}
}

void links(char **list_name, int e)
{
	struct stat s;

	stat(list_name[e], &s);
	my_put_nbr(s.st_nlink);
	my_putchar(' ');
}

void print_total(char **list_name, int b)
{
	int i = 0;
	int result = 0;
	struct stat s;

	while (i != b) {
		if (list_name[i][0] != '.') {
			stat(list_name[i], &s);
			result = result + s.st_blocks;
		}
		i = i + 1;
	}
	my_putstr("total ");
	my_put_nbr(result/2);
	my_putchar('\n');

}

void ls_option_l(char **list_name, int e, int b)
{
	int i = 0;
	struct stat s;

	print_total(list_name, b);
	while (e != b) {
		if (list_name[e][0] != '.') {
			my_putchar(' ');
			print_right2(list_name, e);
			print_right(list_name, e);
			links(list_name, e);
			print_owner(list_name, e);
			print_name_size(list_name, e);
		}
		e = e + 1;
	}
}