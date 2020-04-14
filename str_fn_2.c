#include "libs.h"
/**
 *rev_string - reversing a string
 *@s: char
 * Return: void.
 */
void rev_string(char *s)
{
	int i;
	char c;

	for (i = 0; i < (_strlen(s) / 2); i++)
	{
		c = s[i];
		s[i] = s[(_strlen(s)  - 1) - i];
		s[(_strlen(s)  - 1) - i] = c;
	}
}
/**
 *_itoa - fron int to char
 *@x: int
 * Return: char.
 */
char *_itoa(int x)
{
	int len = 0, i = 0, z = 0;
	char *str;

	z = x;
	while (z != 0)
	{
		len++;
		z = z / 10;
	}
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (x / 10)
	{
		str[i] = (x % 10) + '0';
		x = x / 10;
		i++;
	}
	str[i] = (x % 10) + '0';
	rev_string(str);
	str[i + 1] = '\0';
	return (str);
}