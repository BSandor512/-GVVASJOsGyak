#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int child;

    mkfifo("GVVASJ", S_IRUSR | S_IWUSR);

    child=fork();
    if(child>0){
        char s[1024];
        int fd;

        fd=open("GVVASJ", O_RDONLY);
        read(fd, s, sizeof(s));
        printf(" %s ", s);

        close(fd);
        unlink("GVVASJ");
    }
    else if(child == 0){
        int fd;

        fd=open("GVVASJ", O_WRONLY);
        write(fd, "GVVASJ!\n", 12);
        close(fd);
    }

}
