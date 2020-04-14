#include "libs.h"
/**
 *builds - check the right function
 *@aCmd: char
 * Return: void.
 */
void(*builds(char **aCmd))(char **aCmd)
{
	if (!(_strcmp("exit", aCmd[0])))
		return (shellExit);
	else if (!(_strcmp("env", aCmd[0])))
		return (shellEnv);
	else if (!aCmd[0])
		return (NULL);
	return (0);
}
/**
 *getEnv - write the environ
 *@name: char
 * Return: char.
 */
char *getEnv(char *name)
{
	int i = 0;
	char *res;

	if (!name)
		return (NULL);
	while (environ[i])
	{
		if (!(_strcmp(environ[i], name)))
		{
			res = (environ[i] + 1 + _strlen(name));
			return (res);
		}
		i++;
	}
	return (0);
}
/**
 **_path - check the path
 *@links: char
 *@name: char
 * Return: char.
 */
char *_path(char *links, char *name)
{
	char *tok, *link;
	list_t *head, *l2;
	struct stat st;

	head = '\0';
	link = _strdup(links);
	tok = strtok(link, ":");
	while (tok)
	{
		head = add_node_end(&head, tok);
		tok = strtok(NULL, ":");
	}
	l2 = head;
	while (l2)
	{
		tok = concat3(l2->dName, "/", name);
		if (stat(tok, &st) == 0)
		{
			return (tok);
		}
		free(tok);
		l2 = l2->next;
	}
	return (NULL);
}
/**
 *shellExit - fonction of exit
 *@array: char
 *return: nothing(mean true)
 */
void shellExit(char **array)
{
	int ext = 0;

	if (array[1])
		ext = _atoi(array[1]);
	exit(ext);
}
/**
 *shellEnv - get the envrion
 *return: nothing(mean true)
 */
void shellEnv(char **array)
{
	int i;
	(void) array;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, (const char *) environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 2);
	}
}
