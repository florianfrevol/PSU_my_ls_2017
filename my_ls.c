/*
** EPITECH PROJECT, 2017
** my_ls.c
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
#include <fcntl.h>
#include <sys/stat.h>



int number_files(char **list_name)
{	
	int i = 0;
	int a = 0;
	char *name_file;
	DIR *dir;
	struct dirent *entry;

	dir = opendir("./");
	entry = readdir(dir);
	while (entry != NULL) {
		name_file = entry->d_name;
		list_name[i] = name_file;
		if (list_name[i][0] != '.')
			a = a + 1;
		i = i + 1;
		entry = readdir(dir);
		entry->d_name;
	}
	return (a);
}

int number_all_files(char **list_name)
{	
	int i = 0;
	char *name_file;
	DIR *dir;
	struct dirent *entry;

	dir = opendir("./");
	entry = readdir(dir);
	while (entry != NULL) {
		name_file = entry->d_name;
		list_name[i] = name_file;
		i = i + 1;
		entry = readdir(dir);
		entry->d_name;
	}
	return (i);
}

char *modif_time(char *str)
{
	int i = 4;
	int a = 0;
	char *chaine = malloc(sizeof(char *) + my_strlen(str));

	while (str[i] != '\0' && i != 16) {
		chaine[i - 4] = str[i];
		i = i + 1;
	}
	chaine[i - 4] = '\0';
	return (chaine);
}

void print_name_size(char **list, int e)
{
	struct stat s;
	unsigned char *ptr;
	char *str;

	stat(list[e], &s);
	str = ctime(&s.st_ctime);
	str = modif_time(str);
	printf("%lu %s %s\n", s.st_size, str, list[e]);
}

void print_owner(char **list_name, int e)
{
	struct group *owner;
	struct stat s;
	struct passwd *owner2;

	stat(list_name[e], &s);
	owner2 = getpwuid(s.st_uid);
	printf("%s ", owner2->pw_name);
	owner = getgrgid(s.st_gid);
	printf("%s ", owner->gr_name);
}

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

void ls_option_l(char **list_name, int e, int b)
{
	int i = 0;
	struct stat s;

	while (e != b) {
		if (list_name[e][0] != '.') {
			print_right2(list_name, e);
			print_right(list_name, e);
			stat(list_name[e], &s);
			my_put_nbr(s.st_nlink);
			my_putchar(' ');
			print_owner(list_name, e);
			print_name_size(list_name, e);
		}
		e = e + 1;
	}
}

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

char **find_name(char **list)
{
	int i = 0;
	char *name_file;
	DIR *dir;
	struct dirent *entry;

	dir = opendir("./");
	entry = readdir(dir);
	while (entry != NULL) {
		name_file = entry->d_name;
		list[i] = name_file;
		i = i + 1;		
		entry = readdir(dir);
		entry->d_name;
	}
	return (list);
}

int main(int argc, char **argv)
{
	char *list_name[255];
	int a = 0;
	int e = 0;
	int b = 0;
	
	find_name(list_name);
	a = number_files(list_name);
	b = number_all_files(list_name);

	if (argc == 1) {
		print_name(list_name, b);
		return (0);
	}
	if (argc > 1)
		option_ls(list_name, e, b, argv);
	else
		return (0);
	return (0);
}