#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    int rc = 0;
    int fd;
    char template[] = "/tmp/kcfg-XXXXXX";
    fd = mkstemp(template);
    if ( fd != -1 ) {
        printf("filename=%s\n", template);
    } else {
        printf("Creating temp file failed.");
    }

    char *buffer = "hello,temp file!";
    if(-1 == write(fd,buffer,strlen(buffer))) {
        printf("\n write failed with error [%s]\n",strerror(errno));
        rc = -1;
    }
    close(fd);
    
    unlink(template);
    return rc;
}

