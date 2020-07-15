#include <stdio.h>
#include<time.h>
int b[50000];
void Merge(int a[], int low, int mid, int high){
int i, j, k;
i=low; j=mid+1; k=low;
while ( i<=mid && j<=high ) {
if( a[i] <= a[j] )
b[k++] = a[i++] ;
else
b[k++] = a[j++] ;
}
while (i<=mid)
b[k++] = a[i++] ;
while (j<=high)
b[k++] = a[j++] ;
for(k=low; k<=high; k++)
a[k] = b[k];
}
18 | P a g e
voidMergeSort(int a[], int low, int high){
int mid;
if(low >= high)
return;
mid = (low+high)/2 ;
MergeSort(a, low, mid);
MergeSort(a, mid+1, high);
Merge(a, low, mid, high);
}
void main(){
int n, a[50000],k;
clock_tst,et;
doublets;
printf("\n Enter How many Numbers:");
scanf("%d", &n);
printf("\nThe Random Numbers are:\n");
for(k=1; k<=n; k++) {
a[k]=rand();
printf("%d\t", a[k]);
}
st=clock();
MergeSort(a, 1, n);
et=clock();
ts=(double)(et-st)/CLOCKS_PER_SEC;
printf("\n Sorted Numbers are : \n ");
for(k=1; k<=n; k++)
printf("%d\t", a[k]);
printf("\nThe time taken is %e",ts);
}
