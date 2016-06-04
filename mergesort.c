//
//  main.c
//  Merge_Sort
//
//  Created by Dewang Lahariya on 4/8/16.
//  Copyright © 2016 Dewang Lahariya. All rights reserved.
//
#define INFINITE 99999999

#include <stdio.h>

void merge(int A[], int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int i,j,k;
    int L[n1+1], R[n2+1];
    for(i=1;i<=n1;i++){
        L[i]=A[p+i-1];
    }
    for(j=1;j<=n2;j++){
        R[j]=A[q+j];
    }
    L[n1+1] = INFINITE;
    R[n2+1] = INFINITE;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        if (L[i]<=R[j])
        {
            A[k]=L[i];
            i=i+1;
        }
        //printf(" %d ",);
        else
        {
            A[k]=R[j];
            j=j+1;
        }
    }
}//End of Merge

void printarray(int A[], int p, int r)
{
    for (int z=0; z<=r; z++) {
        printf(" %d ", A[z]);
    }
}
void merge_sort(int A[], int p, int r)
{
    
    if (p<r) {
        int q = p + (r-p)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
        
    }
   // printarray(A, p, r);
    //printf("\n");
    
}//End of Merge Sort




int main(int argc, const char * argv[]) {
    int A[] = {9,7,13,5,1,74,45,8935,2345,2124};
    //int p = 0,r = 4;
    merge_sort(A,0,9);
    for (int i=0; i<=9; i++) {
        printf(" %d ", A[i]);
   }
    return 0;
    
}//End of Main

