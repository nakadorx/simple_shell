#include "libs.h"

list_t *add_node_end(list_t **head, char *str)
{
	list_t *nouveau = malloc(sizeof(list_t));
	list_t *tmp = *head;

	if (nouveau == NULL)
		return (NULL);
	nouveau->next = NULL;
	if (!str)
		return (NULL);
	nouveau->dName = strdup(str);
	if (tmp == NULL)
		*head = nouveau;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nouveau;
	}
	return (*head);
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nouveau;
	char *old_p;
	unsigned int i = 0;

	if (ptr == NULL)
	{
		nouveau = malloc(new_size);
		return (nouveau);
	}
	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	old_p = ptr;
	nouveau = malloc(new_size);
	if (nouveau == NULL)
		return (NULL);
	if (new_size > old_size)
	{
		while (i < old_size)
		{
			nouveau[i] = old_p[i];
			i++;
		}
		free(ptr);
	}
	return (nouveau);
}

void free_list(list_t *head)
{
	list_t *l;

	while (head != NULL)
	{
		l = head;
		head = head->next;
		free(l);
	}
}

void free_array(char **array)
{
    int i = 0;

    if (!array)
        exit(0);
    for (;array[i];i++)
    {
        free(array[i]);
    }
    free(array);
}

void frees(list_t *head, char **aCmd, char * cmd)
{
	free_list(head);
	free_array(aCmd);
	free(cmd);
}