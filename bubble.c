#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
FILE *inp;
void bubblesort(float[],float);
void main(){
	inp=fopen("input.txt","r");
	int i,j;
	float n;
	fscanf(inp,"%f",&n);
	float arr[(int)n];
	for(i=0;i<n;i++){
		fscanf(inp,"%f",&arr[i]);
	}
	bubblesort(arr,n);
}
void bubblesort(float arr[],float n){
	float temp;
	int i,j;
	for(i=1; i<n; i++){
		for(j=0; j< n-i; j++){
			if(arr[j] > arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\t",(int)arr[i]);
	}
	printf("\n");
}
