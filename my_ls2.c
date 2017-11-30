/*
** EPITECH PROJECT, 2017
** my_ls2.c
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
#include "printf.h"
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
	int i;

	stat(list[e], &s);
	str = ctime(&s.st_ctime);
	str = modif_time(str);
	i = s.st_size;
	my_put_nbr(i);
	my_putchar(' ');
	my_putstr(str);
	my_putchar(' ');
	my_putstr(list[e]);
	my_putchar('\n');
}

void print_owner(char **list_name, int e)
{
	struct group *owner;
	struct stat s;
	struct passwd *owner2;
	char *owner4;
	char *owner3;

	stat(list_name[e], &s);
	owner2 = getpwuid(s.st_uid);
	owner = getgrgid(s.st_gid);
	owner4 = owner2->pw_name;
	owner3 = owner->gr_name;

	my_putstr(owner4);
	my_putchar(' ');
	my_putstr(owner3);
	my_putchar(' ');
}