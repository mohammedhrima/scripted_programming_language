#ifndef HEADER_H
#define HEADER_H

#define STDIN STDIN_FILENO
#define STDOUT STDOUT_FILENO
#define STDERR STDERR_FILENO

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <math.h>
#include <stdbool.h>

typedef enum
{
    characters_,
    integer_,
    float_,
    boolean_,
    none_
} data;

typedef struct
{
    char *name;
    union
    {
        long integer;
        double number;
        char *string;
        bool boolean;
    } value;
    data type;
} var;

int pos;
int line;
char *text;

char *readline(int fd);
void ft_printf(int fd, char *fmt, ...);
int ft_strlen(char *str);
void handle_signal(int signum);
void ft_strcpy(char *dest, char *src);
void ft_strncpy(char *dest, char *src, int size);
void print_space(int fd, int line_long);
int ft_isalpha(int c);
int ft_isdigit(int c);
char *ft_strchr(char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
double ft_atof(char *str);
void ft_putfloat(int fd, double num, int decimal_places);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
#endif