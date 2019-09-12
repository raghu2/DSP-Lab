#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
FILE *inp;
void selectionsort(float[],float);
void main(){
        inp=fopen("input.txt","r");
        int i,j;
        float n;
        fscanf(inp,"%f",&n);
        float arr[(int)n];
        for(i=0;i<n;i++){
                fscanf(inp,"%f",&arr[i]);
        }
        selectionsort(arr,n);
}
void selectionsort(float arr[],float n){
	int minpos,i,j;
	float temp;
	for(i=0; i<n-1; i++){
		minpos=i;
		for(j=i+1; j< n; j++){
			if(arr[j] < arr[minpos]){
				minpos=j;
			}
		}
		if(minpos!=i){
			temp=arr[i];
			arr[i]=arr[minpos];
			arr[minpos]=temp;
		}
	}
	for(i=0;i<n;i++){
		printf("%d\t",(int)arr[i]);
	}
	printf("\n");
}
