#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
FILE *inp;
void insertionsort(float[],float);
void main(){
        inp=fopen("input.txt","r");
        int i,j;
        float n;
        fscanf(inp,"%f",&n);
        float arr[(int)n];
        for(i=0;i<n;i++){
                fscanf(inp,"%f",&arr[i]);
        }
        insertionsort(arr,n);
}
void insertionsort(float arr[],float n){
	int element,j,i;
	float temp;
	for(i=1; i<n; i++){
		element=arr[i];
		j=i;
		while((j>0) && (arr[j-1] > element)){
			arr[j]=arr[j-1];
			j=j-1;
			}
		arr[j]=element;
	}
	for(i=0;i<n;i++){
		printf("%d\t",(int)arr[i]);
	}
	printf("\n");
}

