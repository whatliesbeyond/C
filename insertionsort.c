//
//  main.c
//  InsertionSort
//
//  Created by Dewang Lahariya on 3/25/16.
//  Copyright © 2016 Dewang Lahariya. All rights reserved.
//

//Insertion sort to arrange elements of array in increasing order

#include <stdio.h>

void insertionsort (int A[], int n)
{
    int i,k,key;
    for (i = 1; i < n; i++) {
        key = A[i];
        k = i-1;
        while (k >= 0 && A[k] > key){
           /* A[k]   ^= A[k-1];
            A[k-1] ^= A[k];
            A[k]   ^= A[k-1];*/
            A[k+1] = A[k];
            k = k-1;
            
        }
        A[k+1] = key;
    }
    
}



int main(int argc, const char * argv[]) {
    int A[]={98,9,6,10,13};
    insertionsort(&A[0],5);
    for (int i=0; i<5; i++) {
        printf(" %d ", A[i]);
    }
    //printf(" %d ", A[5]);
    return 0;
}
