#include "main.h"

/**
* _strlen - find length of string
* @str: string
* Return: length
*/
int _strlen(char *str)
{
int len;

for (len = 0; str[len] != '\0'; len++)
;

return (len);
}

/**
* append_text_to_file - append text and only if file exists
* @filename: file
* @text_content: appends this content into file
* Return: 1 on success, -1 on error
*/
int append_text_to_file(const char *filename, char *text_content)
{
int filedes;
int new_wrote;

if (!filename)
return (-1);

/* open file if it exists */
filedes = open(filename, O_WRONLY | O_APPEND);
if (filedes == -1)
return (-1);

/* if nothing to write, still successful */
if (!text_content)
{
close(filedes);
return (1);
}

/* write */
new_wrote = write(filedes, text_content, _strlen(text_content));
if (new_wrote == -1 || new_wrote != _strlen(text_content))
{
close(filedes);
return (-1);
}

close(filedes);
return (1);
}
