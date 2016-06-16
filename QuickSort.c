//
//  main.c
//  Quick-Sort
//
//  Created by Dewang Lahariya on 6/16/16.
//  Copyright © 2016 Dewang Lahariya. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void quicksort(int*,int,int);
int partition(int*,int,int);

int main(int argc, const char * argv[]) {
    int n;
    printf("How many numbers are you wanting to sort ?");
    scanf("%d",&n);
    int *A = (int *)malloc(n * sizeof(int));
    printf("Enter the numbers: ");
    for(int i = 0;i<n;i++)
    {
        scanf("%d ",&A[i]);
    }
    int p = 0, r = sizeof(A)/sizeof(A[0]);
    quicksort(A, p, r);
    for(int i = 0; i<n;i++)
        printf("%d",A[i]);
    free(A);
    return 0;
}

void quicksort(int* A,int p,int r){
    int q;
    if(p<r)
        q = partition(A,p,r);
    
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);

}

int partition(int* A,int p,int r){
    int x = A[r], i = p-1;
    int j;
    for(j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i = i + 1;
            A[i]^=A[j];
            A[j]^=A[i];
            A[i]^=A[j];
        }
   
    }
    A[i+1]^=A[r];
    A[r]^=A[i+1];
    A[i+1]^=A[r];
    return i + 1;

}
