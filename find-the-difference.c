/* Solution to Leetcode Problem 389 with unique characters in strings s and t */

char findTheDifference(char* s, char* t) {
    char hashS[256];
    char hashT[256];

    int i;
    for(i = 0; i < strlen(t); i++){
        int hashkeyS = (int)s[i];
        int hashkeyT = (int)t[i];
        printf("hashkeyS = %d hashkeyT = %d\n",hashkeyS,hashkeyT);
        if(i>strlen(s)||strlen(s)==0)
        {
            return t[i];

        }

        hashS[hashkeyS] = s[i];
        hashT[hashkeyT] = t[i];
        if(hashS[hashkeyT]!=0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return t[i];
}
