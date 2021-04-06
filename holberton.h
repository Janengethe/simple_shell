#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv);

/*print string content*/
int _putchar(char c);
void _print(char *str);

/*helper functions*/
int _strlen(const char *s);
int _execute(char **argv);
unsigned int _occurence(char *s);
char **_strtotokens(char *str);
int _strcmp(char *s1, char *s2);

int check_file_status(char *filename);
char *read_line(void);
/*builtin implementation*/
int shell_exit(char **args);
int shell_cd(char **args);
int shell_help(char **args);
int shell_environ(void);

#endif /*HOLBERTON_H*/
