#include "main.h"

/**
* __exit - prints error messages and exits with exit value
* @error: num is either exit value or file descriptor
* @s: str is a name, either of the two filenames
* @fd: file descriptor
* Return: 0 on success
**/
int __exit(int error, char *s, int filedes)
{
switch (error)
{
case 97:
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(error);
case 98:
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", s);
exit(error);
case 99:
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", s);
exit(error);
case 100:
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filedes);
exit(error);
default:
return (0);
}
}

/**
* main - copies one file to another
* @argc: should be 3 (./a.out copyfromfile copytofile)
* @argv: first is file to copy from (filedes_1), second is file to copy to (filedes_2)
* Return: 0 (success), 97-100 (exit value errors)
*/
int main(int argc, char *argv[])
{
int filedes_1, filedes_2, new_read, new_wrote;
char *buffer[1024];

if (argc != 3)
__exit(97, NULL, 0);

/*sets file descriptor for copy-to file*/
filedes_2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
if (filedes_2 == -1)
__exit(99, argv[2], 0);

/*sets file descriptor for copy-from file*/
filedes_1 = open(argv[1], O_RDONLY);
if (filedes_1 == -1)
__exit(98, argv[1], 0);

/*reads original file as long as there's more than 0 to read*/
/*copies/writes contents into new file */
while ((new_read = read(filedes_1, buffer, 1024)) != 0)
{
if (new_read == -1)
__exit(98, argv[1], 0);

new_wrote = write(filedes_2, buffer, new_read);
if (new_wrote == -1)
__exit(99, argv[2], 0);
}

close(filedes_2) == -1 ? (__exit(100, NULL, filedes_2)) : close(filedes_2);
close(filedes_1) == -1 ? (__exit(100, NULL, filedes_1)) : close(filedes_1);
return (0);
}
