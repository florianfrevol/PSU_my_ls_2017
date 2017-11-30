/*
** EPITECH PROJECT, 2017
** my_ls.c
** File description:
** 
*/

#include <dirent.h>
#include <stdio.h>
#include "include/my.h"
#include "printf.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <fcntl.h>
#include <sys/stat.h>

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

int count_links(char **list_name, int b)
{
	struct stat s;
	int i = 0;
	int result = 0;

	while (i != b) {
		if (list_name[i][0] != '.') {
			stat(list_name[i], &s);
			if (result < s.st_nlink)
				result = s.st_nlink;
		}
		i = i + 1;
	}
	return (result);
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

 	//count_links(list_name, b);
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