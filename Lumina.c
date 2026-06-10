#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct DLL {
    int p;
    char name[1004];
    struct DLL *next, *prev;

}*head = NULL, *tail= NULL;

void push(int p, char name[]){
    struct DLL *n = (struct DLL*)malloc(sizeof(struct DLL));
    n->p = p;
    strcpy(n->name, name);
    n->next=  NULL;
    n->prev = NULL;

    if(head == NULL){
        head = tail = n;
        return;

    }
    if(p<head->p){
        n->next = head;
        head->prev = n;
        head = n;
    }
    else if(p>=tail->p){
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    else {
        //push mid
        struct DLL *t = head;
        while(t!= NULL && p>= t->next->p){
            t = t->next;

        }
        n->next = t->next;
        n->prev = t;
        t->next->prev = n;
        t->next = n;


    }

}

void serve(){
    if(head == NULL){
        return;
    }
    else if(head == tail){
        printf("Served Customer: %s (%d)\n", head->name, head->p);
        free(head);
        head = tail = NULL;

    }
    else{
        struct DLL *temp = head;
        head = head->next;
        printf("Served Customer: %s (%d)\n", temp->name, temp->p);
        free(temp);
        head->prev = NULL;
    }
}

void showHead(){
    if(head == NULL){
        printf("DOUBLE LINKED-LIST EMPTY.\n");
    }
    else{
        printf("Served Customer: %s (%d)\n", head->name, head->p);
    }
}

void display(){
    if(head ==NULL){
    	printf("DOUBLE LINKED-LIST EMPTY.\n");
        return;
    }
    else{
        struct DLL *temp =head;
        printf("Waiting List:\n");
        while(temp){
            printf("%s (%d)\n", temp->name, temp->p);
            temp = temp->next;
        }
    }
}

int jumlah(){
    int t = 0;
    struct DLL *temp =head;
        while(temp){
            printf("%s (%d)\n", temp->name, temp->p);
            t++;
            temp = temp->next;
        }
    return t;
}

void popHead() {
    if (head == NULL) return;
    struct DLL *t = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(t);
}

void popTail() {
    if (tail == NULL) return;
    struct DLL *t = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(t);
}

void hapus(char name[]){
    if(head == NULL){
        return;
    }
    struct DLL *pos = head;
    
    while(pos!= NULL && strcmp(pos->name, name)!= 0){
        pos = pos->next;
    } 
    if(pos == NULL){
        return;
    }
    if(pos == head){
        popHead();
    }
    else if(pos== tail){
        popTail();
    }
    else{
        pos->next->prev = pos->prev;
        pos->prev->next = pos->next;
        free(pos);
    }
}

int main(){

    int N ,i, ps;
    scanf("%d", &N);
    char name[1004];
    for( i = 0;i<N; i++){
        char command[1004];
        scanf("%s", command);
        if(strcmp(command,"SERVE" )==0){
            serve();
        }
        else if((strcmp(command,"NEXT" )==0)){
            showHead();
        }
        else if((strcmp(command, "DISPLAY")==0)){
            display();
        }
        else if((strcmp(command, "DELETE")==0)){
            char target[1004];   
        scanf("%s", target); 
            hapus(target);
        }
        else if((strcmp(command, "COUNT")==0)){
            int count = jumlah();
            printf("Number of customers: %d\n", count);
        }
        else if(strcmp(command, "ADD")==0){
        scanf("%s %d", name, &p);
        push(p, name);
        }
    }
    return 0;
}
