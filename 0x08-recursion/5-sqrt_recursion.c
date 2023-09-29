#include "holberton.h"
/*this is bout squre recursion im writing this code 
 * finding the squre root of  a function 
 * If n does not have a natural square root, the function should return -1
 */
int _sqrt_recursion(int n)
{
	if (a == (b*b))
		return(b);
	else if ((b * b) >= a)
		return (-1);
	else
		return(my_sqrt_recursion(a, b + 1));
}
/*my first function 
 * this is the first value assign
 * this result of my fuctionmy_sqr_recursion
 */
int sqrt_recursion(int n)
{
	if (n <= 0)
		return (-n);
	return (my_sqrt_recursion(n, 0));
}
