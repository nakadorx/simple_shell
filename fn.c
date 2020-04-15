#include "libs.h"
/**
 *cmdArray - splting the string
 *@str: char
* Return: void.
 */
char **cmdArray(char *str)
{
	int i = 1, x = 3;
	char **res, *tok, *text;
	const char *d = " \n";

	text = malloc(_strlen(str) + 1);
	if (text == NULL)
	{
		perror(getEnv("_"));
		return (NULL);
	}
	text = _strdup(str);
	tok = strtok(text, d);
	res = malloc((sizeof(char *) * 2));
	res[0] = _strdup(tok);
	while (tok)
	{
		tok = strtok(NULL, d);
		res = _realloc(res, (sizeof(char *) * (x - 1)), (sizeof(char *) * x));
		res[i] = _strdup(tok);
		x++;
		i++;
	}
	free(text);
	return (res);
}
/**
 *exec - execute the commande
 *@aCmd: char
 *@patata: int
 *@pName: char
 *return: nothing(mean true)
 */

void exec(char **aCmd, int patata, char *pName)
{
	int frk, stat;
	(void) patata;
	(void) pName;

	if (!aCmd)
	{
		return;
	}
	frk = fork();
	if (frk == -1)
		perror(getEnv("_"));
	else if (frk == 0)
	{
		execve(aCmd[0], aCmd, environ);
		perror(aCmd[0]);
		exit(0);
	}
	wait(&stat);
	free_array(aCmd);
}
/**
 *envs - get the environ
 *@aCmd: char
 *@patata: int
 *@pName: char
 *return: nothing(mean true)
 */

void envs(char **aCmd, int patata, char *pName)
{

	void (*func)(char **);
	char *link, *path;

	link = getEnv("PATH");
	path = _path(link, aCmd[0]);
	func = builds(aCmd);
	if (func)
	{
		func(aCmd);
	}
	else if (path)
	{
		free(aCmd[0]);
		aCmd[0] = path;
		exec(aCmd, patata, pName);
	}
	else if (!path)
	{
		exec(aCmd, patata, pName);
	}

}
/**
 *handler - initialisation dog
 *@sig: int
 *return: nothing(mean true)
 */
void handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
	}
}
