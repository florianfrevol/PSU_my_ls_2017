/*
** EPITECH PROJECT, 2017
** src.c
** File description:
** 
*/

#include "include/my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
	int mod = 0;
	
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		mod = nb % 10;
		nb = nb / 10;
		my_put_nbr(nb);
		my_putchar(mod + 48);
	}
	else
		my_putchar(nb + 48);
	return (0);
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char *str)
{
	int i = 0;
	
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}

char *my_revstr(char *str)
{
	int compt = 0;
	int i = 0;
	char a;

	while (str[compt] != '\0')
		compt = compt + 1;
	compt = compt - 1;
	while (i < compt) {
		a = str[i];
		str[i] = str[compt];
		str[compt] = a;
		i = i + 1;
		compt = compt - 1;
	}
	return (str);
}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}