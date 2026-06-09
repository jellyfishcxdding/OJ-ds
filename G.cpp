#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	int height;
	struct node *left, *right;
};

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int getHeight(struct node *curr)
{
	if(curr==NULL)
		return 0;
	return curr->height;
}

int getBFactor(struct node *curr)
{
	if(curr==NULL)
		return 0;
	return getHeight(curr->left)-getHeight(curr->right);
}

struct node *leftRotate(struct node *a)
{
	struct node *b=a->right;
	struct node *c=b->left;
	
	b->left=a;
	a->right=c;
	
	a->height=max(getHeight(a->left), getHeight(a->right))+1;
	b->height=max(getHeight(b->left), getHeight(b->right))+1;
	
	return b;
}

struct node *rightRotate(struct node *a)
{
	struct node *b=a->left;
	struct node *c=b->right;
	
	b->right=a;
	a->left=c;
	
	a->height=max(getHeight(a->left), getHeight(a->right))+1;
	b->height=max(getHeight(b->left), getHeight(b->right))+1;
	
	return b;
}

struct node *insertAVL(struct node *curr, int val)
{
	if(curr==NULL)
	{
		struct node *newNode=(struct node*)malloc(sizeof(struct node));
		newNode->val=val;
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->height=1;
		curr=newNode;
	}
	else if(val<curr->val)
		curr->left=insertAVL(curr->left, val);
	else if(val>curr->val)
		curr->right=insertAVL(curr->right, val);
		
	curr->height=max(getHeight(curr->left), getHeight(curr->right))+1;
	int bFactor=getBFactor(curr);
	
	if(bFactor<-1 && getBFactor(curr->right)<=0)//single left rotate
		return leftRotate(curr);
	else if(bFactor<-1 && getBFactor(curr->right)>0)//RL rotate
	{
		curr->right=rightRotate(curr->right);
		return leftRotate(curr);
	}
	else if(bFactor>1 && getBFactor(curr->left)>=0)//single right rotate
		return rightRotate(curr);
	else if(bFactor>1 && getBFactor(curr->left)<0)//LR rotate
	{
		curr->left=leftRotate(curr->left);
		return rightRotate(curr);
	}
	return curr;
}

struct node *findPredecessor(struct node *curr)
{
	while(curr->right!=NULL)
		curr=curr->right;
	return curr;
}

struct node *delAVL(struct node *curr, int val)
{
	struct node *temp;
	if(curr==NULL)
	{
		printf("data is not found\n");
		return curr;
	}
	else if(val<curr->val)
		curr->left=delAVL(curr->left, val);
	else if(val>curr->val)
		curr->right=delAVL(curr->right, val);
	else{
		if(curr->left==NULL && curr->right==NULL)
		{
			free(curr);
			curr=NULL;
			return curr;
		}
		else if(curr->left==NULL)
		{
			temp=curr;
			curr=curr->right;
			free(temp);
		}
		else if(curr->right==NULL)
		{
			temp=curr;
			curr=curr->left;
			free(temp);
		}
		else
		{
			temp=findPredecessor(curr->left);
			curr->val=temp->val;
			curr->left=delAVL(curr->left, temp->val);
		}
	}
		
	curr->height=max(getHeight(curr->left), getHeight(curr->right))+1;
	int bFactor=getBFactor(curr);
	
	if(bFactor<-1 && getBFactor(curr->right)<=0)//single left rotate
		return leftRotate(curr);
	else if(bFactor<-1 && getBFactor(curr->right)>0)//RL rotate
	{
		curr->right=rightRotate(curr->right);
		return leftRotate(curr);
	}
	else if(bFactor>1 && getBFactor(curr->left)>=0)//single right rotate
		return rightRotate(curr);
	else if(bFactor>1 && getBFactor(curr->left)<0)//LR rotate
	{
		curr->left=leftRotate(curr->left);
		return rightRotate(curr);
	}
	return curr;
}

void print(struct node *curr)
{
	if(curr!=NULL)
	{
		print(curr->left);
		printf("%d(%d) ", curr->val, curr->height);
		print(curr->right);
	}
}

int main()
{
	struct node *root=NULL;
    int N, Q, k;

    for(int i = 0; i<N; i++){
        int angka;
        scanf("%d", &angka);
        root = insertAVL(root, angka);
    }

    print(root);

	return 0;
}