#ifndef __MY_H__
#define __MY_H__

char find_symb(int fig, char *base);
int find_weight(char nbr, char *base);
int my_char_isalnum(char c);
int my_find_prime_sup(int nbr);
int my_getnbr(char *str);
int my_getnbr_base(char *nbr, char *base);
int my_is_prime(int nbr);
void my_isneg(int n);
int my_power_rec(int nbr, int power);
void my_putchar(char c);
void my_putnbr(int nombre);
int my_putnbr_base(int nbr, char *base);
void my_putstr(char *str);
char *my_revstr(char *str);
int my_showstr(char *str);
void my_sort_int_tab(int tab[], int size);
int my_square_root(int nbr);
int my_square_root_int(int nbr);
int my_str_isalpha(char *str);
int my_str_islower(char *str);
int my_str_isnum(char *str);
int my_str_isprintable(char *str);
int my_str_isupper(char *str);
char **my_str_to_wordtab(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *str1, char *str2);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *str);
int my_strlcat(char *str1, char *str2, int l);
int my_strlen(char *str);
char *my_strlowcase(char *str);
char *my_strncat(char *str1, char *str2, int n);
int my_strncmp(char *s1, char *s2, int n);
char *my_strncpy(char *dest, char *src, int n_cpy);
char *my_strndup(char *str, int n);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char my_tabsize(char *str);

#endif