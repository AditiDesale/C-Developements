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
	//0 starting point
	//1 current point
	//2 end of file
	
	lseek(fd,5,0);
	
	read(fd,Arr,5);
	write(1,Arr,5); 
	printf("\n");
	
	
	lseek(fd,5,1);
	
	read(fd,Arr,5);
	write(1,Arr,5);  
	printf("\n");
	
	close(fd);
	
    return 0;
}

