#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int rand(){
	int fd = open("/dev/random", O_RDONLY);
	int *randn = (int *)malloc(sizeof(int));
	
	int n = read(fd, &randn, sizeof(int));

    if (n == -1) { //the code still returns negative numbers idk why
		printf("error: %d, strerror: %s\n", errno, strerror(errno));
	}	
	
	close(fd);
	return randn;
}

int main(){
	
	printf("Generating random numbers:\n");
	int rand_nums[10];
	for(int i=0; i<10; i++){
		rand_nums[i] = rand();
		printf("  random %d: %d\n", i, rand_nums[i]);
	}

	printf("Writing numbers to file...\n");
	int f = open("rand.txt", O_RDWR);
	int w= write(f, rand_nums, sizeof(int) * 10);
	
	if (w==-1){
		printf("error: %d, strerror: %s\n", errno, strerror(errno));
	}
	close (f);
	
	printf("Reading numbers from a file...\n");
	int r= open("rand.txt", O_RDWR);
	int *randd = (int *) malloc (sizeof(int) * 10);
	int rr= read( f, &randd, sizeof(int));
	
	printf("Verification that written values were the same:\n");
	for (int i = 0; i < 10; i++){
		printf("  random %d: %d\n", i, randd[i]);
		}
		close(f); //IT JUST RETURNS 0
	}