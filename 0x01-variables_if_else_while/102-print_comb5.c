#include <stdio.h>

/**
 *main - print all possible different combination of two two-digits
 *Return: Always 0 sucess
 */

int main(void)
{
int i, j;
for (i = 0; i < 100; i++)
{
for (j = 0; j < 100; j++)
{
if (i < j)
{
putchar ((i / 10) + 48);
putchar ((i % 10) + 48);
putchar(' ');
putchar((j / 10) + 48);
putchar((j % 10) + 48);
if (i != 98 || j != 98)
{
putchar(',');
putchar(' ');
}
}
}
}
putchar ('\n');
return (0);
}
