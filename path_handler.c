#include "holberton.h"
/**
 *get_path - gets the absolute path of a command
 *@args:pointer to an array of strings
 *Return:address of the path
 */
char *get_path(char **args)
{
	int i = 0;
	char *path = NULL, **token = NULL, *slash_token = NULL, *cmd_token = NULL;

	if (args == NULL)
		return (NULL);
	if(check_file_status(argv[0]) == 0)
		return (argv[0]);
	path = get_env("PATH");
	token = strtok(path, ":");
	i = 0;
	while (token[i])
	{
		slash_token = str_concat(token[i], "/");
		cmd_token = str_concat(slash_token, args[0]);
		free(slash_token);
		if (check_file_status(cmd_token) == 0)
		{
			_strcpy(args[0], cmd_token);
			free(path);
			free(cmd_token);
			return(args[0]);
		}
		free(cmd_token);
	}
	free(path);
	return (NULL);
}
