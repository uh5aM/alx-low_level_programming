#include <stdio.h>
/*this is the how to rint the value of x and y 
 *
 * telling the system to print -i*/
int _pow_recursion(int x, int y)
{
	if (y == 0)
	{
		return (1);

	}

	if (y < 0)
	{
		return (-1);

	}
	return (x * _pow_recursion(x, y-1));

}
