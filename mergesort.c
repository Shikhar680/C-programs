#include<stdio.h>
void merge(int ar[],int l,int m,int r){
    int ls = m-l;
    int rs = r-m;
    int l_ar[ls];
    int r_ar[rs];
    for(int i=0;i<ls;i++){
        l_ar[i] = ar[l+i];
    }
    for(int i=0;i<rs;i++){
        r_ar[i] = ar[m+i];
    }
    int i=0,j=0,k=0;
    while(i<ls && j<rs){
        if (l_ar[i]<=r_ar[j]){
            ar[l+k] = l_ar[i];
            i++;
            k++;
        }
        else{
            ar[l+k] = r_ar[j];
            j++;
            k++;
        }
    }
    while(i<ls){
        ar[l+k] = l_ar[i];
        i++;
        k++;
    }
    while(j<rs){
        ar[l+k] = r_ar[j];
        j++;
        k++;
    }
}
void mergesort(int ar[],int l,int r){
    if(l<r-1){
        int mid = (l+r)/2;        
        mergesort(ar,l,mid);        
        mergesort(ar,mid,r);
        merge(ar,l,mid,r);
    }
}
void printAr(int ar[],int s){
    printf("[ ");
    for(int i=0;i<s;i++)
        printf("%d, ",ar[i]);
    printf("\b ]");
}
void main(){
    int ar[] = {10,1,5,7,2,12,0,8,3};
    printf("Before Sorting: ");
    printAr(ar,9);
    mergesort(ar,0,9);
    printf("\nAfter Sorting: ");
    printAr(ar,9);
}