/*
** EPITECH PROJECT, 2017
** my_ls4.c
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

void print_name(char **list, int b)
{
	int i = 0;

	while (i != b) {
		if (list[i][0] != '.') {
			my_putstr(list[i]);
			my_putchar('\n');
		}
		i = i + 1;
	}
}

void ls_option_a(char **list, int b)
{
	int i = 0;

	while (i != b) {
		my_putstr(list[i]);
		my_putchar('\n');
		i = i + 1;
	}
}

int option_ls(char **list_name, int e, int b, char **argv)
{
	if (argv[1][0] == '-') {
		switch (argv[1][1]) {
			case 'l':
				ls_option_l(list_name, e, b);
				return (0);
			case 'a':
				ls_option_a(list_name, b);
				return (0);
		}
	}
	else if (argv[1][0] != '-') {
	}
}