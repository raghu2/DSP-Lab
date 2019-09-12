#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
FILE *inp;
void quicksort(float[],int,int);
int partition(float[],int,int);
void swap(float *a, float *b){
        float temp=*a;
        *a=*b;
        *b=temp;
}
float n;
void main(){
        inp=fopen("input.txt","r");
        int i,j;
        fscanf(inp,"%f",&n);
        float arr[(int)n];
        for(i=0;i<n;i++){
                fscanf(inp,"%f",&arr[i]);
        }
        quicksort(arr,0,n-1);
        for(i=0;i<n;i++){
                printf("%d\t",(int)arr[i]);
        }
        printf("\n");
}
int partition(float arr[],int low,int high){
	int pivot=arr[low];
	int i,j;
	i=low;
	j=low+1;
	while(j<=high){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
		j++;
	}
	swap(&arr[i],&arr[low]);
	return i;
}
void quicksort(float arr[],int low,int high){
	if(low>=high)
		return;
	int pivot=partition(arr,low,high);
	quicksort(arr,low,pivot-1);
	quicksort(arr,pivot+1,high);
}
