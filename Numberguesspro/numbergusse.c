#include<stdio.h>   //For Input/output(printf,scanf)
#include<stdlib.h>  //For random nubers(rand())
#include<time.h>    //For time()

int main()
{
		
int number,guess,attempt=0;   //number stores random number,gusse stores user input
	
	srand(time(0));
	number=rand() % 100 + 1;
	
	printf("Guess the number (1 to 100):\n");
	
	do{
		scanf("%d",&guess);
		attempt++;
		
		if(guess>number)
		printf("too high!\n");
		
		else if(guess<number)
		printf("too less!\n");
		
 		else
		printf("Correct guess! the number in %d attempt.\n",attempt);
      }
       while(guess != number);

      return 0;

     }


