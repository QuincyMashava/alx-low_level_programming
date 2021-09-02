#include "main.h"
#include <stdio.h>
/**
 * _isupper - checks for uppercase character
 * @c: character to be checked
 * Return: 1 if true, 0 if false
 */

int _isupper(char c)
{
 if (c >= 'A' && c <= 'Z')
   {
     return (1);
   }else if (c >= 'a' && c <= 'z')
   {
     return (0);
   }

}
