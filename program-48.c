#include <stdio.h>

void swap(int* a,int* b){ int t=*a; *a=*b; *b=t; }

int partition(int a[], int l, int r){
    int pivot=a[r], i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<=pivot){ i++; swap(&a[i],&a[j]); }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}

void quicksort(int a[], int l, int r){
    if(l<r){
        int p=partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}

void print(int a[],int n){ for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n"); }

int main(){
    int a[]={10,7,8,9,1,5};
    int n=sizeof(a)/sizeof(a[0]);
    printf("Before: "); print(a,n);
    quicksort(a,0,n-1);
    printf("After: "); print(a,n);
    return 0;
}
