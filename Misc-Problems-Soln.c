#define MAXROW 3
#define MAXCOL 4
#define MAX 1000
#define PRINT(var) printf(#var "=%d", var)



int check_strong_number(int n)
{
    int x,i,sum=0,fact,n1=n;
   
    int s;
    if(n1<1)
    {
        s = 0;
        
    }
    else if(n1==1)
    {
        s = 1;
        
    }
    else if(n1>1)
    {
        while(n1)
        {
            i=1,fact=1;
            x = n1 % 10;
            while(i<=x)
            {
                fact = fact * i;
                i++;
            }
            sum+=fact;
            n1/=10;
        }
        if(sum==n)
            s = 1;
        else
            s = 0;
        
    }
    

   return s;

}

//Print all Prime Factors

void primefactor(int num){
    int i=1,j,k;
    while(i<=num){
        k=0;
        if(num%i==0){
            j=1;
            while(j<=i){
                if(i%j==0)
                    k++;
                j++;
            }
            if(k==2)
                printf("%d is a prime factor\n",i);
        }
        i++;
    }
    
}


// A function to print all prime factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
    
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
    
    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2)
        printf ("%d ", n);
}


/* Decimal to Hexadecimal conversion */
long int deciTohex(void){
    long int decimalNumber,remainder,quotient;
    int i=1,j,temp;
    char hexadecimalNumber[100];
    
    printf("Enter any decimal number: ");
    scanf("%ld",&decimalNumber);
    
    quotient = decimalNumber;
    
    while(quotient!=0){
        temp = quotient % 16;
        
        //To convert integer into character
        if( temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        
        hexadecimalNumber[i++]= temp;
        quotient = quotient / 16;
    }
    
    printf("Equivalent hexadecimal value of decimal number %d: ",decimalNumber);
    for(j = i -1 ;j> 0;j--)
        printf("%c",hexadecimalNumber[j]);
    printf("\n");
    return 0;
}






/* Octal to binary */
int octTobin(void){

    
        char octalNumber[MAX];
        long int i=0;
        
        printf("Enter any octal number: ");
        scanf("%s",octalNumber);
        
        printf("Equivalent binary value: ");
        while(octalNumber[i]){
            switch(octalNumber[i]){
                case '0': printf("000"); break;
                case '1': printf("001"); break;
                case '2': printf("010"); break;
                case '3': printf("011"); break;
                case '4': printf("100"); break;
                case '5': printf("101"); break;
                case '6': printf("110"); break;
                case '7': printf("111"); break;
                default:  printf("\nInvalid octal digit %c ",octalNumber[i]); return 0;
            }
            i++;
        }
    printf("\n");
    return 1;
    

}



/* Program to count different characters in the string */
int count_char(char *str)
{
    int i,count=0;
    for(i=0;i<strlen(str);i++)
        count++;
    return count;

}



/* Compare function for qsort to sort characters in string */
int compare (const void* p1, const void *p2){
    
    return ( *(char *)p1 - *(char *)p2 );

}


/* Concatenate 2 strings without using string.h functions */
char *new_str (char *str1, char *str2){
    int j=0,i=0,k,l;
    while(str1[i]!='\0'){
        i++;
    }
    while(str2[j]!='\0'){
        str1[i++]=str2[j++];
    }
    str1[i]='\0';
    
    return str1;


}



void *fptr (int s)
{
    
    
    return 0;
}

union u
{
    short int no;
    char ch[2];
};
void slogan(void)
{
    printf("\n Only He men use C!");
}
void convert(void)
{
    char *str = "234";
    int a;
   // a = atof(str);
   // sscanf(str, "%d", &a);
    
    printf("%d",a);
}
void func ( int i )
{
    if ( i != 4 )
        main ( ++i ) ;
}

float myflt(){

    return 2.0;
}


const char * fun( )
{
    return "Rain";
}


int display( ) ;



/* Binary to Octal */
int binToOct (int x){
    printf("bin=  %d\n",x);
     int binaryNumber,octalNumber=0,j=1,remainder;
    binaryNumber=x;
    
       while(binaryNumber!=0){
        remainder=binaryNumber%10;
        octalNumber=octalNumber+remainder*j;
        j=j*2;
        binaryNumber=binaryNumber/10;
    }
    printf("my octal num = %o\n",octalNumber);
    
    return octalNumber;

}



/*    Inverse of 3x3 matrix      --      Don't trust its functionality    */
void inv_matrix (void){

    int i,j;
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int determinant=0;
    
//    printf("Enter the 9 elements of matrix: ");
//    for(i=0;i<3;i++)
//        for(j=0;j<3;j++)
//            scanf("%d",&a[i][j]);

    
        
    printf("\nThe matrix is\n");
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++)
            printf("%d\t",a[i][j]);
    }
    
    for(i=0;i<3;i++)
        determinant = determinant + (a[0][i]*((a[1][(i+1)%3]*a[2][(i+2)%3]) - (a[1][(i+2)%3]*a[2][(i+1)%3])));
    
    printf("\nDeterminant of matrix is: %d\n", determinant);
    printf("\nInverse of matrix is: \n\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%.2f\t",((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/ determinant);
        printf("\n");
    }



}


/* Find detereminant of a matrix --> Bad code - refine it */
void find_det(void){

    int a[3][3],i,j;
    int determinant=0;
    
    printf("Enter the 9 elements of matrix: ");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    
    printf("\nThe First matrix is\n");
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++)
            printf("%d\t",a[i][j]);
    }
    
    for(i=0;i<3;i++)
        determinant = determinant + (a[0][i]*((a[1][(i+1)%3]*a[2][(i+2)%3]) - (a[1][(i+2)%3]*a[2][(i+1)%3])));
    
    printf("\nDeterminant of matrix is: %d",determinant);


}




/* Write to a file from a C program */
void writeToFile (void){
    FILE *fp;
    char ch;
    fp = fopen("/Users/dewanglahariya/Documents/C_coding_brushup_2/Cquestions/CQuestions/file.txt ","w");
    printf("Enter the data puny human!\n");
    while((ch=getchar())!=EOF)
        putc(ch,fp);
    fclose(fp);
    //char *filename = "/Users/dewanglahariya/Documents/C_coding_brushup_2/Cquestions/CQuestions/file.txt";
    remove("/Users/dewanglahariya/Documents/C_coding_brushup_2/Cquestions/CQuestions/file.txt");
    int ret;
    if(ret == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error: unable to delete the file");
    }

    
}

/* Delete a file from */
void deleteFile (void){
    char *filename = "/Users/dewanglahariya/Documents/C_coding_brushup_2/Cquestions/CQuestions/file.txt";
//    FILE *fp;
//    fp = fopen(filename,"r");
//    fclose(fp);
    remove(filename);
    int ret;
    if(ret == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error: unable to delete the file");
    }
}


/* Copy a file from one place to another  */
void copyFile(void){
    char *source = "/Users/dewanglahariya/Documents/C_coding_brushup_2/Cquestions/CQuestions/file.txt";
    char *target = "/Users/dewanglahariya/Documents/C_coding_brushup_2/Cquestions/CQuestions/fileCopy.txt";
    
    FILE *fp_source, *fp_target;
    fp_source = (source,"r");
    fp_target = (target,"w");
    errno_t err1, err2;
    

}
