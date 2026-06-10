#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    char task[1004];
    int num;
    struct Node *next, *prev;
}*head = NULL, *tail =NULL;

void push(int num , char task[]){
    struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
    nn->num = num;
    strcpy(nn->task, task);
    nn->next = NULL;
    nn->prev = NULL;

    if(head == NULL && tail == NULL){
        head = tail =nn;
    }
    //push tail
    else{
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
}

void pop(){
    if(head == NULL){
        printf("Printer Idle\n");
        return;
    }
    if(head == tail){
        printf("%d %s\n", head->num, head->task);
        head = NULL;
        tail = NULL;
    }
    
    else{
            struct Node *t = head;
            printf("%d %s\n", head->num, head->task);
            head = head->next;
            free(t);
            head->prev = NULL;
        }
}
    



void peek(){
    if(head == NULL){
        printf("Printer Idle\n");
        return;
    }
    printf("%d %s\n", head->num, head->task);
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ;i<N; i++){
        int opsi;
        scanf("%d", &opsi);
        if(opsi == 1){
            char tugas[1004];
            int num;
            scanf("%d %s", &num, tugas);
            push(num, tugas);
        }
        else if(opsi == 2){
            pop();
        }
        else if(opsi == 3){
            peek();
        }
    }

    return 0;
}
