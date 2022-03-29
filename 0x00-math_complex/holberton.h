#ifndef holberton_H
#define holberton_H
/**
 * struct complex - Struct format complex
 * @re: real numbers
 * @im: imaginary numbers
 * @f: Function to print
 */
typedef struct complex_number 
{
	double re;
	double im;
} complex;

void display_complex_number(complex c);

#endif
