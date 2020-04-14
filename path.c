#include "libs.h"

void(*builds(char **aCmd))(char **aCmd)
{
	if (!(_strcmp("exit",aCmd[0])))
		return (shellExit);
	else if (!(_strcmp("env",aCmd[0])))
		return (shellEnv);
	else if (!aCmd[0])
		return (NULL);
	return (0);
}

char *getEnv(char *name)
{
	int i = 0;
	char *res;

	if (!name)
		return (NULL);
	while (environ[i])
	{
		if (!(_strcmp(environ[i],name)))
		{
			res = (environ[i] + 1 + _strlen(name) );
			return (res);
		}
		i++;
	}
	return (0);
}

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

void shellExit(char **array)
{
    int ext = 0;

    if (array[1])
        ext = _atoi(array[1]);
    exit(ext);
}

void shellEnv()
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, (const char *) environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 2);
	}	
}