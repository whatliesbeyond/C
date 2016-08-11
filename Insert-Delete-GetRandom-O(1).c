
/*===================================================================================================
 Problem 380 from leetcode.com: Insert Delete GetRandom O(1)
 
 Design a data structure that supports all following operations in average O(1) time.
 insert(val): Inserts an item val to the set if not already present.
 remove(val): Removes an item val from the set if present.
 getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 
 
 Revision                Comment                                                            Author
 1.0 (Initial Design)    Assumption item val's are distinct and lie in the range [1,997)    Dewang Lahariya
 
 
 ==================================================================================================*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


#define SIZE 997

typedef struct {
    int val;
} RandomizedSet;

RandomizedSet Data[SIZE];  //A Dictionary of type RandomizedSet that holds the item val
RandomizedSet hashTable[SIZE]; //A cache that stores the item vals of Dictionary and keeps track of latest insertion/removal

//hashcode to find key
int hashCode(int key){
    return key % SIZE;
}

static unsigned int hashcount;



/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val)
{
    
    obj->val = val;
    int hashindex = hashCode(val);
    if(Data[hashindex].val!=val && Data[hashindex].val==0)
    {
        Data[hashindex].val = obj->val;
        hashTable[hashcount++].val = Data[hashindex].val;
        return true;
    }
    return false;
    
}

/** Removes a value from the set. Returns true if the set contained the specified element. **/
bool randomizedSetRemove(RandomizedSet* obj, int val)
{
    obj->val = val;
    int hashindex = hashCode(val);
    if(Data[hashindex].val==val && Data[hashindex].val!=0)
    {
        Data[hashindex].val = NULL;
        hashTable[hashcount--].val = Data[hashindex].val;
        return true;
    }
    return false;
 
}



/** Get a random element from the set. **/
int randomizedSetGetRandom(RandomizedSet* obj)
{
    int hashindex = rand() % hashcount;
    int value = hashTable[hashindex].val;
    return value;
 
}

/** Free memory allocated to object **/
void randomizedSetFree(RandomizedSet* obj)
{
    free(obj);
}


int main(int argc, const char * argv[]) {
    
    
    //Allocate memory for objects
    RandomizedSet* obj1 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj2 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj3 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj4 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj5 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj6 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj7 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj8 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj9 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj10 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj11 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    RandomizedSet* obj12 = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    
    

    //initialize srand for rand function
    srand((unsigned)time(NULL));
    
    
    bool param_1 = randomizedSetInsert(obj1, 265);
    //Runtime check to see if randomizedSetInsert functions properly
    assert(param_1==true);
    
    randomizedSetInsert(obj2, 6);
    randomizedSetInsert(obj3, 2);
    randomizedSetInsert(obj4, 524);
    randomizedSetInsert(obj5, 245);
    randomizedSetInsert(obj6, 45);
    randomizedSetInsert(obj7, 5);
    randomizedSetInsert(obj8, 85);
    randomizedSetInsert(obj9, 83);
    randomizedSetInsert(obj10, 49);
    randomizedSetInsert(obj11, 19);
    randomizedSetInsert(obj12, 95);
    
    
    
    printf("Random value from Data: %d\n", randomizedSetGetRandom(hashTable));
    
    //Remove Obj1
    bool param_2 = randomizedSetRemove(obj1, 85);
    param_2 = randomizedSetRemove(obj2, 5);
    
    //Runtime check to see if randomizedSetRemove functions properly
    assert(param_2==true);
    
    //Print bunch of random values
    printf("Random value from Data: %d\n", randomizedSetGetRandom(hashTable));
    printf("Random value from Data: %d\n", randomizedSetGetRandom(hashTable));
    printf("Random value from Data: %d\n", randomizedSetGetRandom(hashTable));
    printf("Random value from Data: %d\n", randomizedSetGetRandom(hashTable));
    
    
    //Free objects
    randomizedSetFree(obj1);
    randomizedSetFree(obj2);
    randomizedSetFree(obj3);
    randomizedSetFree(obj4);
    randomizedSetFree(obj5);
    randomizedSetFree(obj6);
    randomizedSetFree(obj7);
    randomizedSetFree(obj8);
    randomizedSetFree(obj9);
    randomizedSetFree(obj10);
    randomizedSetFree(obj11);
    randomizedSetFree(obj12);
    
    
    
    
    
    return 0;
}
