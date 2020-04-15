#include "libs.h"
/**
 *_strdup - duplicate the char
 *@str: char
 * Return: char.
 */
char *_strdup(char *str)
{
	unsigned int i = 0, j = 0;
	char *x;

	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	x = malloc((i + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		x[j] = str[j];
	x[j] = '\0';
	return (x);
}
/**
 *concat3 - concat 3 string
 *@s1: char
 *@s2: char
 *@s3: char
 * Return: char.
 */
char *concat3(char *s1, char *s2, char *s3)
{
	char *ch;
	int i = 0;

	ch = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + _strlen(s3) + 1));
	if (ch == '\0')
		{
		return (NULL);
		}
	else
	{
		while (i < _strlen(s1))
		{
			ch[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < _strlen(s2))
		{
			ch[i + _strlen(s1)] = s2[i];
			i++;
		}
		i = 0;
		while (i < _strlen(s3))
		{
			ch[i + _strlen(s1) + _strlen(s2)] = s3[i];
			i++;
		}
	}
	ch[_strlen(s1) + _strlen(s2) + _strlen(s3)] = '\0';
	return (ch);
}
/**
 *_strlen - give the lenght of string
 *@s: char
 * Return: char.
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
/**
 *_strcmp - compare tow strings
 *@s1: char
 *@s2: char
 * Return: char.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i + 1) != '\0' && *(s2 + i + 1) != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}


/**
 * _atoi - from string to number
 * @s: string
 * Return: int.
 */

int _atoi(char *s)
{
	int a;
	int res;
	int type = 1;

	a = 0;
	res = 0;
	while ((*(s + a) < '0' || *(s + a) > '9') && (*(s + a) != '\0'))
	{
		if (*(s + a) == '-')
		{
			type = type * (-1);
		}
		a++;
	}
	while ((*(s + a) >= '0') && (*(s + a) <= '9'))
	{
		res = res * 10 + type * (*(s + a) - '0');
		a++;
	}
	return (res);
}
