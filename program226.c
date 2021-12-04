#include<stdio.h>

void DisplayR()
{
	static int icnt = 1;
	
	if(icnt <= 4)
	{
		printf("Hello\n");
		icnt++;
		DisplayR();
	}
}

 int main()
 {
	DisplayR();
	 
	return 0;
 }