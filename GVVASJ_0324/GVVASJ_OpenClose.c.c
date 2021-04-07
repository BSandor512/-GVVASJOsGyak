#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>



int main()
{
    int fajl, b;
    char buffer[100];

    buffer[0] = 0;

    fajl = open("GVVASJ.txt", O_RDWR);

    if (fajl == -1) {
        perror("Fajl megnyitas [open()] hiba! \n");
        exit(-1);
    }

    b = read(fajl, buffer, 100);
    printf("A read() %d byteot olvasott.\n\n", b);
    strcpy(buffer, "GVVASJ");


    b = lseek(fajl, 0, SEEK_SET);
    printf("Az lseek()  %d.  ", b);

    b = write(fajl, buffer, 6);
    printf("a write() %d byteot irt: %s\n\n", b, buffer);

    close(fajl);

    return 0;
}
