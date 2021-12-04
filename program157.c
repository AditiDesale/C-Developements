#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#include<io.h>

int main()
{
	int fd = 0;
	char Fname[30];
	
	printf("Enter the file name\n");
	scanf("%s",Fname);
	
	fd = creat(Fname,0777);
	
	if(fd == -1)
	{
		printf("Unable to create the file\n");
	}
	else
	{
		printf("File successfully created\n");
	}
	
	return 0;
}