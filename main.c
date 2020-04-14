#include "libs.h"

/**
 * main - shell main
 * @argc : int
 * @argv : **char
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int patata = argc - 1;
	ssize_t tol = 0;
	size_t size = 0;
	char *cmd = NULL, **aCmd = NULL;
	list_t *head = '\0';

	signal(SIGINT, handler);
	while (1)
	{
		patata++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell $ ", 9);
		tol = getline(&cmd, &size, stdin);
		if (cmd[0] == '\n')
		{
			free(cmd);
			main(patata + 1, argv);
		}
		if (tol == -1)
		{
			free(cmd);
			write(STDOUT_FILENO, "\n", 2);
			exit(0);
		}
		aCmd = cmdArray(cmd);
		if (!aCmd)
			exec(aCmd, patata, argv[0]);
		else
			envs(aCmd, patata, argv[0]);
	}
	frees(head, aCmd, cmd);
	return (0);
}
