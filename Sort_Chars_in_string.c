#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Compare function for qsort to sort characters in string */

int compare (const void* p1, const void *p2){
    
    return ( *(char *)p1 - *(char *)p2 );


}

int main(int argc, const char * argv[]) {
    
    char str[100];
    printf("enter the string\n");
    scanf("%s",&str);
  
    qsort(str, strlen(str), sizeof(char), compare);
    printf("new string is %s\n",str);
    
    
    return 0;
}
