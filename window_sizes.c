#include "so_long.h"

int handle_horizontal(char *buffer)
{
    int i = 0;
    while (buffer[i] && buffer[i] == '1')
        i++;
    return (i);
}

int handle_vertical(char *buffer)
{
    int i = 0;
    int count = 0;
    while (buffer[i])
    {
        if (buffer[i] && buffer[i] == '1')
            count++;
        while (buffer[i] && buffer[i] != '\n')
            i++; 
        if (buffer[i] && buffer[i] == '1')
            count++;
        i++;
    }
    return (count);
}

int get_walls(char type, char *path)
{
    char *buffer = (char *)malloc(sizeof(char) * 1024);
    int fd = open(path, O_RDONLY);
    if(!fd)
        return 0;
    int reading = read(fd, buffer, 1024);
    if (reading == -1)
        return 0;
    buffer[reading] = '\0';
    if (type == 'h')
        return (handle_horizontal(buffer));
    return handle_vertical(buffer);
}
