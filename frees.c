#include "libs.h"
/**
 * add_node_end - adding a node to the list
 * @head: the pointer for the lsit
 * @str: char
 * Return: added node.
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *nouveau = malloc(sizeof(list_t));
	list_t *tmp = *head;

	if (nouveau == NULL)
		return (NULL);
	nouveau->next = NULL;
	if (!str)
		return (NULL);
	nouveau->dName = _strdup(str);
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

/**
 * _realloc - realocate a memory
 * @ptr: the pointer for the memory
 * @old_size: int
 * @new_size: int
 * Return: void.
 */

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
/**
 * free_list - freeing list
 * @head: the pointer for the lsit
 */

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
/**
 * free_array - freeing array
 * @array: the pointer for the array
 */

void free_array(char **array)
{
	int i = 0;

	if (!array)
		exit(0);

	free(array);
}
/**
 * frees - freeing array
 * @head: the pointer for the lsit
 * @aCmd: pointer for the array
 * @cmd : char
 */

void frees(list_t *head, char **aCmd, char *cmd)
{
	free_list(head);
	free_array(aCmd);
	free(cmd);
}
