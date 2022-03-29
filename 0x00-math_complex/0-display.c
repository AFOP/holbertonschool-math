#include "holberton.h"
#include <stdio.h>
/**
 * display_complex_number - show the complex number.
 * @c: struct with the real number plus imaginary number.
 * Return: nothing. 
 */
void display_complex_number(complex c)
{
	printf("%d", (int)c.re);
	if (c.im != 0)
	{
		if (c.im < 0)
		{
			printf(" - ");
			c.im = c.im * -1;
			printf("%d", (int)c.im);
		}
		else
		{
			printf(" + ");
			printf("%d", (int)c.im);
		}
		printf("i");
	}
	printf("\n");
}
