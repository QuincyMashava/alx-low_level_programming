#include "main.h"

/**
* main - Prints _putchar as a message using putchar.
*
* Return: Always 0 (Success)
*/

int main(void)
{

char *c = "_putchar";
int i;
for (i = 0; i < 8; i++)
{
_putchar(c[i]);
}
_putchar('\n');
return (0);
}
