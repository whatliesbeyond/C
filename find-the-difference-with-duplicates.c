
/*===================================================================================================
 Problem 389 from leetcode.com: Insert Delete GetRandom O(1)
 
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
 
 Revision             Comment                                                            Author
 1.1 (Bug Release)    Need to Debug                                                      Dewang Lahariya
 
 
 ==================================================================================================*/



typedef struct dictionary
{
    char value[256];
    char key[256];
}charDictionary;

charDictionary sdict = {0};
charDictionary tdict = {0};


char findTheDifference(char* s, char* t) {

    int i;
    
    for(i = 0; i < strlen(t); i++){
        if(sdict.key[i])
        {
            sdict.value[i]++;
        }
        if(tdict.key[i])
        {
            tdict.value[i]++;
        }
        
        //Formula for hash key
        int hashkeyS = (int)s[i];
        int hashkeyT = (int)t[i];
        
        //key stores individual characters and their count
        sdict.key[hashkeyS] = s[i];
        tdict.key[hashkeyT] = t[i];
       
        
        if(i>strlen(s)||strlen(s)==0)
        {
            return t[i];

        }
        
        if((sdict.key[hashkeyS] == tdict.key[hashkeyT]) && (sdict.value[hashkeyS] == tdict.value[hashkeyT]))
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
