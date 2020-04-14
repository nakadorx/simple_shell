#ifndef LIBS_H
#define LIBS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
typedef struct list_t
{
	struct list_t *next;
	char *dName;
} list_t;

extern char **environ;

int _strlen(char *s);
char *_strdup(char *str);
char *concat3(char *s1, char *s2, char *s3);
char **cmdArray(char *str);
void exec(char **aCmd,int patata, char *pName);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *getEnv(char *name);
list_t *add_node_end(list_t **head, char *str);
char *_path(char *links, char *name);
void(*builds(char **arv))(char **arv);
int _atoi(char *s);
void shellExit(char **array);
void shellEnv();
void freearv(char **arv);
void free_list(list_t *head);
int _strcmp(char *s1, char *s2);
char *string_nconcat(char *s1, char *s2);
char *string_concat(char *s1, char *s2);
void free_array(char **array);
void frees(list_t *head, char **aCmd, char * cmd);
void handler(int sig);
void envs(char **aCmd,int patata, char *pName);
char *_itoa(int x);

#endif
