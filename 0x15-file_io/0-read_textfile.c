#include "main.h"

/*
* read_textfile - read a certain size and prints to std output
* @filename: file to read from
* @letters: size to read
* Return: actual size read and printed
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
int filedes; /* file descriptor */
ssize_t new_read, new_wrote;
char *buffer;

  if (filename == NULL)
    return (0);

  /* open */
  filedes = open(filename, O_RDONLY);
  if (filedes == -1)
    return (0);

  /* malloc buffer */
  buffer = malloc(sizeof(char) * letters);
  if (buffer == NULL)
    return (0);

  /* read */
  new_read = read(filedes, buffer, letters);
  if (new_read == -1)
    {
      free(buffer);
      close(filedes);
      return (0);
    }

  /* write */
  new_wrote = write(STDOUT_FILENO, buffer, new_read);
  if (new_wrote == -1)
    {
      free(buffer);
      close(filedes);
      return (0);
    }

  close(filedes);
  return (new_read);

}
