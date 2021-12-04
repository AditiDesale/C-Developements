#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
	char Arr[10];
	
	fd = open("LB17.txt",O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	lseek(fd,10,2);
	
	write(fd,"*",1);        //hole in the file
	
	close(fd);
	
    return 0;
}

