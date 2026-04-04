#include <stdio.h>
int main()
{
	int choice , pin , correctpin= 2565,i;
	float balance=1000,amount,deposit,withdraw;
	
	
	//transactionhistory
	char history[100][50];
	int count =0;
	
	printf("Enter the Pin :\n");
	scanf("%d",&pin);
	
	if(pin!=correctpin){
		printf("Entered Pin is wrong. \n");
		return 0;
	}
	
	do{
		printf("\n ----Atm Menu---- \n");
		printf("1. Check Balance\n");
		printf("2. Deposit\n");
		printf("3. Withdraw\n");
		printf("4. History\n");
		printf("5. Exit\n");
							
		printf("Enter the Choice\n");
		scanf("%d",&choice);
							
		switch(choice){
								
		case 1:
			   printf("Balance :%.2f\n",balance);
				sprintf(history[count++],"check Balance  %.2f",balance);
					break;
									
		case 2:
		       printf("Enter the amount of Deposit :\n");
		    	scanf("%f",&amount);
				balance+=amount;
				printf("Deposit Successfull!\n");
				sprintf(history[count++],"Deposited: %.2f",deposit);
				break;
									
	    case 3:
		       printf("Enter the Amount to withdraw :\n");
		       scanf("%f",&amount);
									
		if(amount<=balance){
		balance-=amount;
		printf("withdrawal Successful!\n");
		sprintf(history[count++],"Withdraw  %.2f",withdraw);
		}
		else{
               printf("Insufficient Balance!\n");
          }
              break;
                                       
		 case 4:
                 printf("\n--- Transaction History ---\n");
                   if(count == 0) {
                     printf("No transactions yet.\n");
                      }         
					  else {
                        for( i = 0; i < count; i++) {
                         printf("%d. %s\n", i+1, history[i]);
                              }
                             }
             break;	
                                 
          case 5:
                 printf("Thanku for using ATM !\n");
                break;
                                 	
                  default:
                  printf("Enter the invalid Choice!\n");
}							
}
	while(choice != 5);
	
	return 0;
}
