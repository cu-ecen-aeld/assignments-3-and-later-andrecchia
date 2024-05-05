#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	const char *file = argv[1];
	const char *string = argv[2];
	if(argc < 3){
		printf("Use this script as '%s <file> <string>'", argv[0]);
		exit(1);
	}
	// file open
	int fd = open (file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1){
		// error occurred
		syslog (LOG_MAKEPRI(LOG_USER, LOG_ERR),
        		"Error occurred on file open");
		exit(1);
	} else {
		// file writing
		ssize_t nr = write (fd, string, strlen(string));
		syslog (LOG_MAKEPRI(LOG_USER, LOG_DEBUG),
        		"Writing '%s' to '%s'", string, file);
		// check err on file writing	
		if(nr == -1){
			syslog (LOG_MAKEPRI(LOG_USER, LOG_ERR),
	                	"Error occurred on file writing");
		} else if(nr != strlen(string)){
			syslog (LOG_MAKEPRI(LOG_USER, LOG_ERR),
	                	"Error occurred, partial writing");	
		}

		// file closing, check for errors
		if (close(fd) == -1){
			syslog (LOG_MAKEPRI(LOG_USER, LOG_ERR),
	                	"Error occurred on file closing");	
		}
	}

}
