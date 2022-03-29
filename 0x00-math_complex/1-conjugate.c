#include "holberton.h"
#include <stdio.h>
/**
 * conjugate - returns the conjugate of a given complex number.
 * @c: struct with the real number plus imaginary number.
 * Return: nothing. 
 */
complex conjugate(complex c)
{
	c.im = -c.im;
	return (c);
}
