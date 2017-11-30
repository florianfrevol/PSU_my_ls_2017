/*
** EPITECH PROJECT, 2017
** printf.h
** File description:
** 
*/

char **find_name(char **list);
int main(int argc, char **argv);
int count_links(char **list_name, int b);
void print_name(char **list, int b);
void ls_option_a(char **list, int b);
int option_ls(char **list_name, int e, int b, char **argv);
void print_right(char **list_name, int e);
int print_right2(char **list_name, int e);
void links(char **list_name, int e);
void print_total(char **list_name, int b);
void ls_option_l(char **list_name, int e, int b);
int number_files(char **list_name);
int number_all_files(char **list_name);
char *modif_time(char *str);
void print_name_size(char **list, int e);
void print_owner(char **list_name, int e);