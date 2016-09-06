
/* 
  

*/



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
