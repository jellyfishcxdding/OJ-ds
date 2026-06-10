#include <stdio.h>
#include <stdlib.h>


struct DLL{
    int data;
    struct DLL *next, *prev;
}*head = NULL, *tail = NULL;

void pushT(int val){
    struct DLL *nn = (struct DLL*)malloc(sizeof(struct DLL));
    nn->data = val;
    nn->next = NULL;
    nn->prev = NULL;
    
    if(head == NULL){
        head= tail  = nn;
    }
    else{
        tail->next = nn;
        nn->prev=  tail;
        tail= nn;
    }
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

void pop(int val) {
    if (head == NULL) return;

    struct DLL *p = head;
    while (p != NULL && p->data != val) {
        p = p->next;
    }

    if (p == NULL) return; // Value not found

    if (p == head) {
        popHead();
    } else if (p == tail) {
        popTail();
    } else {
        // This is effectively "popMid"
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}

void print(){
    struct DLL *c = head;
    while(c){
        printf("%d", c->data);
        if(c->next != NULL) {
            printf(" ");
        }
        c = c->next;
        
    }
    printf("\n");
}

int main(){

    int N, i;
    scanf("%d", &N);
    for( i = 1; i<=N; i++){
        pushT(i);
    }
    int queries;
    scanf("%d", &queries);
    for( i = 0; i<queries; i++){
        int valToPop;
        scanf("%d", &valToPop);
        pop(valToPop);
        pushT(valToPop);
        print();
    }
    return 0;
}
