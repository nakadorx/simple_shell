#include "libs.h"

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


void exec(char **aCmd,int patata, char *pName)
{
	int frk, stat;
	char *str;

	if (!aCmd)
	{
		return;
	}
	frk = fork();
	if (frk == -1)
		perror(getEnv("_"));
	else if (frk == 0)
	{
		if ( 0 > execve(aCmd[0], aCmd, environ) )
		{
			str = concat3(pName,": ",_itoa(patata));
			str = concat3(str,": ","not found");	
			write(STDERR_FILENO,str, _strlen(pName)+ 14 +_strlen(_itoa(patata)));
			write(STDERR_FILENO,"\n",2);
		}		
		/**perror(aCmd[0]);**/
		exit(EXIT_FAILURE);
	}
	wait(&stat);
	free_array(aCmd);
}

void envs(char **aCmd,int patata, char *pName)
{

	void (*func)(char **);
	char *link, *path;

	link = getEnv("PATH");
	path = _path(link,aCmd[0]);
	func = builds(aCmd);
	if (func)
	{
		func(aCmd);
	}
	else if (path)
	{
		free(aCmd[0]);
		aCmd[0] = path;
		exec(aCmd,patata,pName);
	}
	else if (!path)
	{
		exec(aCmd,patata,pName);
	}

}

void handler(int sig)
{
    if (sig == SIGINT)
    {
		write(STDOUT_FILENO, "\nShell $ ", 10);
    }
}