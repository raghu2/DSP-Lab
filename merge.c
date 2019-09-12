#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
FILE *inp;
void mergesort(float[],int,int);
void merge(float[],int,int,int);
float n;
void main(){
        inp=fopen("input.txt","r");
        int i,j;
        fscanf(inp,"%f",&n);
        float arr[(int)n];
        for(i=0;i<n;i++){
                fscanf(inp,"%f",&arr[i]);
        }
        mergesort(arr,0,n-1);
	for(i=0;i<n;i++){
		printf("%d\t",(int)arr[i]);
	}
	printf("\n");
}
void mergesort(float arr[],int low,int high){
	int m=0;
	if(low<high){
		m=(low+high)/2;
		mergesort(arr,low,m);
		mergesort(arr,m+1,high);
		merge(arr,low,m,high);
	}
}
void merge(float arr[],int low,int mid,int high){
	int i,j,k,t;
	i=low;
	j=mid+1;
	k=low;
	float c[(int)n];
	while((i<=mid) && (j<=high)){
		if(arr[i]<=arr[j]){
			c[k]=arr[i];
			i++;
		}
		else{
			c[k]=arr[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		for(t=j;t<=high;t++){
			c[k]=arr[t];
			k++;
		}
	}
	else{
		for(t=i;t<=mid;t++){
			c[k]=arr[t];
			k++;
		}
	}
	for(t=low;t<=high;t++){
		arr[t]=c[t];
	}
}

