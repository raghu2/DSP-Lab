#include<stdio.h>
#include<stdlib.h>
int count(int[],int,int);
void main(){
        int i,number,amount;
	printf("enter number of denominations\n");
	scanf("%d",&number);
        int denominations[number];
	printf("enter %d number of denominations\n",number);
	for(i=0;i<number;i++){
		scanf("%d",&denominations[i]);
	}
	printf("enter the amount\n");
	scanf("%d",&amount);
        printf("%d\n",count(denominations,amount,number));
}
int count(int s[],int amount,int number){
        if(number==0)
                return 1;
        if(number<0)
                return 0;
        if(amount<=0&&number>=1)
                return 0;
        return count(s,amount-1,number)+count(s,amount,number-s[amount-1]);
}

