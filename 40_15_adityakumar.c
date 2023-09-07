#include <stdio.h>
#include <stdlib.h>


int x,p;

struct node {

	int info;
	struct node *next;
	
};

struct node *getnode(void) {

	return ((struct node *) malloc(sizeof(struct node))); // struct node * --> to allocate memory to structure pointer   ---> return malloc(sizeof(struct node));
	
};

void freenode(struct node *p){

	free(p);

}



void insertbeg(int x){

	struct node *node;
	newnode = getnode();
	newnode->info=x;
	newnode->next=list;
	list=newnode;

}


void insertend(int x){

	if(list==NULL){
	
		insertbeg(x); // call insertbeg()
	
	}
	else{
	
		struct node *nn,*temp;
		nn=getnode();	// memory allocation
		nn->info=x;	// value insertion at nn
		nn->next=NULL;	// nn starts pointing to NULL
		
		temp=list;	// temp copies the address in list
		
		while(temp->next !=NULL){
		
			temp->next=temp;	// address is added
		
		}
		
		temp->next=nn;
	
	}
	
}

void insertatlocation(int p, int x){

	if(list==NULL || p == 1){ // If user wants to add at first location
	
		insertbeg(x); // call insertbeg()
	
	}
	else{
	
		struct node *nn,*temp;
		
		temp=list;	// temp copies the address in list
		
		for(int i=1;i<p-1;i++){
		
			temp=temp->next;
		
		}
		nn=getnode();	// memory allocation
		nn->info=x;	// value insertion at nn
		nn->next = temp->next;	// nn starts pointing to NULL
		
		temp->next=nn;
	
	}
	
}


void delbeg(){

	struct node *temp;
	if(list  == NULL){
	
		printf("Empty);
	
	}
	else{
	
		temp =list;
		list = temp->next;
		freenode(temp);
	
	}

}

void delend(){

	if(list == NULL){
	
		printf("List Is Empty");
	
	}
	else{
		
		struct node,*temp,*t2;
		temp=list;
		while(temp->next != NULL){
			
			t2=temp;
			temp=temp->next;
		
		}
		t2->next=NULL;
		freenode(temp);
			
	
	}

}

void delatlocation(p){

	struct node,*temp,*t2,*t3;
	if(list == NULL){
	
		printf("List Is Empty");
	
	}
	else{
		if(p==1){
			
			t3=list;
			list=list->next;
			freenode(t3);
		}
		else{
		
			temp=list;
			for(int i=1;i<p-1;i++){
				
				temp=temp->next;
			
			}
			t2=temp->next;
			temp->next=t2->next;
			freenode(t2);
		}	
	
	}

}
