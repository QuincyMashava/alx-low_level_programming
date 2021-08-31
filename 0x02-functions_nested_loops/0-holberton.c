#include "main.h"

/**
* main - print Holberton, followed by new line
* Return: 0
*/

int main(void)
{
char c[10] = "Holberton";
int i;
for(i =0; i < 10; i++){
_putchar(c[i]);
}
_putchar("\n");
return (0);
}
