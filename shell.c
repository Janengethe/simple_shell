#include "holberton.h"

/**
 *main - Displays a prompt and waits for the user to enter a command
 *Return: 0 on success
 */
int main(void)
{
	char **tokens;
	char *line;
	int status;
	struct stat st;

	signal(SIGINT, ctrl_c);
	if (fstat(0, &st) == -1)
		perror("fstat");
	status = 1;
	do {
/*print prompt if command is not piped*/
		print_prompt();
/*read input from stdin*/
		line = read_line();
		if (_strcmp(line, "\n") == 0)
		{
			tokens = NULL;
			free(line);
			continue;
		}
/*split the line into tokens*/
		tokens = _strtotokens(line);
		if (tokens[0] == NULL)
		{
			free(tokens);
			free(line);
			continue;
		}
/*handle exit invokation*/
		if (_strcmp(tokens[0], "exit") == 0)
		{
			shell_exit(tokens, line);
		}
		else
		{
/*execute commands*/
			status = _execute(tokens, line);
		}
/*free memory*/
		free(line);
		free(tokens);
	} while (status == 1);
	return (status);
}
