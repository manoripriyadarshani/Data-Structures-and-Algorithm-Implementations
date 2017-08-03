#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;	
};
typedef struct node node;


void add_node_beg(node** head, int num);
void add_node_end(node** head, int num);
void add_node_between(node** head, int position,int num);
void print(node** head);
void search(node** head, int val );
void delete(node**head,int posi);
void reverse(node** head);
void print_recursive(node* head);
void reverse_print_recursive(node* head);

int main(){
	
	node* head= NULL;
	add_node_beg(&head,3);
	add_node_end(&head,3);
	add_node_between(&head,2,5);
	add_node_between(&head,2,4);
	add_node_end(&head,8);
	//print(&head);
	//search(&head,8);
	//delete(&head,4);
	//print(&head);
	//reverse(&head);
	//print(&head);
	print_recursive(head);
	reverse_print_recursive(head);
	add_node_beg(&head,7);
	print(&head);
	
	
}



void add_node_beg(node** head, int num){
	
	node* temp;
	temp=(node*)malloc(sizeof (node));
	temp->data=num;
	temp->link=*head;
	*head= temp;
	printf("node added at beginning \n");
	
	
}


void add_node_end(node** head, int num){
	
	node*temp;
	node*p;
	
	temp= (node*)malloc(sizeof(node));
	temp->data=num;
	temp->link=NULL;
	
	p=*head;
	while(p->link!=NULL){
		p=p->link;	
	}
	p->link=temp;
	printf("node added at the end\n");
	
	
	
}


void add_node_between(node** head, int position,int num){
	
	node *temp=(node*)malloc(sizeof(node));
	temp->data=num;
	node*p=*head;
	int i;
	for(i=1;i<position-1;i++){
		p=p->link;
	}
	temp->link=p->link;
	p->link=temp;
	
}


void print(node** head){
	node*p=*head;
	while(p!=NULL){
		printf("%d  ",p->data);
		p=p->link;
		
	}
	printf("\n");
}

void search(node** head, int val ){
	node*p=*head;
	int posi=1;
	while(p!=NULL){
		if(p->data==val){
			printf("data found at %d\n",posi);
			return;
		}
	 p=p->link;	
	 posi++;
	}
	
}


void delete(node**head,int posi){
	node*p1=*head;
	
	if(posi==1){
		*head = p1->link;
		printf("%d  is deleted\n",p1->data);
		free(p1);	
		
		return;
	}
	
	
	int i;
	for(i=1;i<posi-1;i++){
		p1=p1->link;	
	}
	
	node*p2=p1->link;
	p1->link=p2->link;
	printf("%d deleted\n ",p2->data);
	free(p2);
	
	
	
}



void reverse(node** head){
	node* prev;
	node*current;
	node*next;
	current=*head;
	prev=NULL;
	while(current!=NULL){
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;	
	}
	*head=prev;
	
	
}




void print_recursive(node* head){
	
	
	if(head==NULL){
		return;
	}
	printf("%d",head->data);
	print_recursive(head->link);
	

	
}


void reverse_print_recursive(node* head){
	
	
	if(head==NULL){
		return;
	}
	print_recursive(head->link);
	printf("%d",head->data);
	
}



