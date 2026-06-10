#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    char name[1005];
    struct Node *next;

}*head = NULL, *tail = NULL;

void pushSorted(char name[]){
    struct Node *baru= (struct Node*)malloc(sizeof(struct Node));
    strcpy(baru->name, name);
    baru->next = NULL;
    
    if(head == NULL){
        head = tail = baru;
    }else if(strcmp(name, head->name)<0){
        baru->next =head;
        head = baru;
    }
    //kalo sama bakal dimasukin ke paling belakang
    else if(strcmp(name, tail->name)>=0){
        tail->next= baru;
        tail = baru;
    }
    else{
        struct Node *curr = head;
    
        //biar dia jadi palign akhir
        while(curr->next != NULL && strcmp(name, curr->name)>=0){
            curr = curr->next;
        }
        baru->next = curr->next;
        curr->next= baru;
    }
}

void print(){
    struct Node *pos = head;
    while(pos!= NULL){

        printf("%s ", pos->name);
        pos = pos->next;
    }
}

int main(){

	pushSorted("andi");
	pushSorted("deni");
	pushSorted("charlie");
	pushSorted("budi");
	print();
	





    return 0;

}
