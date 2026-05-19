#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
struct Hash{
	char abjad;
	int count;
	int keyIndex;
}*ht[MAX];


int hash(char abjad){
	return abjad%MAX;

}

void insert(char abjad) {
    int index = hash(abjad);
    int originalIndex = index;

    // 1. Look for existing character or an empty slot
    while (ht[index] != NULL) {
        if (ht[index]->abjad == abjad) {
            ht[index]->count++; // Already exists, just increment
            return; 
        }
        index = (index + 1) % MAX; // Linear Probing
        
        if (index == originalIndex) {
            printf("Table is full!\n");
            return;
        }
    }

    // 2. If we reach here, we found a NULL slot (new character)
    struct Hash *newHash = (struct Hash*)malloc(sizeof(struct Hash));
    newHash->abjad = abjad;
    newHash->count = 1;
    newHash->keyIndex = index;
    ht[index] = newHash;
}
int main(){
	

	
	return 0;
	
}
