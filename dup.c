#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int file_fd;
	file_fd=open("output.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(file_fd<0)
	{
		perror("open");
		return 1;
	}
	if (dup2(file_fd,STDOUT_FILENO)<0)
	{
		printf("dup2 GIVES ERROR");
		close(file_fd);
		return 0;
	}
	close(file_fd);
	printf("I am a good person\n");
	return 0;
}
	
