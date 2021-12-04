#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = 0, iSum = 0, iRet = 0, i = 0;
	char fname[20];
	char Buffer[10];
	
	printf("Enter file name : \n");
	scanf("%s",fname);
	
	fd = open(fname, O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open the file");
		return -1;
	}
	
	while((iRet = read(fd,Buffer,10)) != 0)         
	{
		iSum = iSum + iRet;
	}
	
	printf("Size of file : %d\n",iSum);
	
	close(fd);
	
    return 0;
}
