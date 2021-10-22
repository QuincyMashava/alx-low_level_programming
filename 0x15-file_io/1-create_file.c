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
 * create_file - creates file with permissions rw------- and writes content in
 * if file already exists, don't change permissions and just truncate it
 * @filename: name to give to new file
 * @text_content: writes this content into file
 * Return: 1 on success, -1 on error
*/

int create_file(const char *filename, char *text_content)
{
  int filedes;
  int new_wrote;

  if (!filename)
    return (-1);

  /* create with permissions if file doesn't exist, else truncate */
  filedes = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
  if (filedes == -1)
    return (-1);

  /* if nothing to write, just return newly created file */
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
