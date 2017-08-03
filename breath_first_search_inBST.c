#include<stdio.h>
#include<stdlib.h>

//create the structure for BST
struct node {
int data;
struct node * right, * left;
};
typedef struct node node;


//create the structure for Queue
struct Qnode{
   node* info;
   struct Qnode* link;

};typedef struct Qnode Qnode;



//method of BST
void createBST(node ** tree);
node* findBST(node ** tree, int val);
void addBST(node ** tree, int val);
void OrderedListBST	(node * tree);
void print_inorder(node * tree);
void bFS(node ** tree,int val);

//method of Queue
void queueCreate( Qnode **front, Qnode **rear);
void enqueue( Qnode **front, Qnode **rear,node* addr);
node* dequeue( Qnode **front, Qnode **rear);
int queueIsempty( Qnode *front, Qnode *rear);
void display( Qnode *front, Qnode *rear);



node *root;

void main(){
  
         //node *tmp;
		 
		 //building binary search tree
		 createBST(&root);
		 addBST(&root,50);
		 addBST(&root,25);
		 addBST(&root,90);
		 addBST(&root,22);
		 addBST(&root,27);
		 addBST(&root,85);
		 addBST(&root,108);
		 addBST(&root,65);
		 addBST(&root,67);
		 addBST(&root,60);
		 addBST(&root,55);
		
		 print_inorder(root);
		 printf("\n");
		 
		 //doing breath first search
		 bFS(&root,50);
		 bFS(&root,27);
		 bFS(&root,55);
		 bFS(&root,0);
		 
		 


}

void bFS(node ** tree,int val){
	
	node *temp ;
	if(!(*tree))
    {
       printf("tree is empty");
    }
	
	struct Qnode* front;
	struct Qnode* rear;
	queueCreate(&front,&rear);
	enqueue(&front,&rear,(*tree));
	
	while(!queueIsempty(front,rear)) 	
	{
        temp = dequeue(&front,&rear);
		
		
		if((temp)->data == val)
		{ printf("data value %d is found \n",temp->data);
			return;
		}
        if(temp->right!=NULL)
			enqueue(&front,&rear,temp->right);
                
        if(temp->left!=NULL)  // not else if(temp->left); there can be right node and left node as well.. no semicolon
            enqueue(&front,&rear,temp->left);
		
		
		
        }
	
	
	if(queueIsempty(front,rear)==1){printf("data not found\n");}
}


//creating the BST
void createBST(node ** tree){
			    *tree = NULL;
}


//add new element to bst
void  addBST(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
         addBST(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
         addBST(&(*tree)->right, val);
    }

}
						


void print_inorder(node * tree)
{ if ((tree) != NULL){
        print_inorder(tree->left);
        printf("%d , ",tree->data);
        print_inorder(tree->right);
}
}






//#################################################Queue methods #####################################################


//creating the Queue
void queueCreate( Qnode **front, Qnode **rear){
	* front=NULL;
	* rear=NULL;
	//printf("Queue is created\n");
	}


//add new element to Queue(add new Qnode in the begining of the link list)			
void enqueue( Qnode **front, Qnode **rear,node* addr){  
                         
	//create new Qnode 
	struct Qnode *temp;
	temp=(struct Qnode*)malloc(sizeof(struct Qnode));
	temp->info=addr;
	temp->link=NULL;
						   
	//the situation adding the element to empty queue
	if(*front==NULL && *rear==NULL)
		{ * front=*rear=temp;
			return;
		}
					   	  
	( * rear)->link=temp;
		 * rear=temp;
						  
}
						
			
			
//remove the element to front of the link list 
 node* dequeue( Qnode **front, Qnode **rear){ 
 
     Qnode *temp=*front;
	 node* val=(temp)->info;
	 if(*front==NULL) 
		{	printf("Queue is Empty\n");
			return;
		}
					
	 if(*front==*rear) 
		*front=*rear=NULL;
					
	 else
		{	( *front)=(*front)->link;
		}
	 free(temp);
	 return (val);
						
 }				


//check whether queue is empty or not
int queueIsempty( Qnode *front, Qnode *rear){ 

	if(front==NULL  )
		return 1;			
	else 
		return 0;


                                }
								

//print the queue top to bottom
void display( Qnode *front, Qnode *rear){    

	if(front==NULL   )
		printf("queue is empty nothing to print\n");
				  			  
	else{		
		struct Qnode *temp=front;
		while(temp!=NULL)
		{ printf("%d\n",temp->info);
		temp=temp->link;
		}
		}
}

