#include<stdio.h>
#include<stdlib.h>



//create the structure
struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;



//method prototype
void createBST(node ** tree);
node* findBST(node ** tree, int val);
void addBST(node ** tree, int val);
void destroyBST(node **tree);
void print_preorder(node * tree);
void print_inorder(node * tree);
void print_postorder(node * tree);
int maxBST(node * tree);
int minBST(node * tree);
void OrderedListBST	(node * tree);
void deleteBST	(node** tree,int val);
node* CopyBST(node ** tree);

int max;
int min;
struct bin_tree *t3;
 node *root;

void main(){
         int choice;
         int  num;
  
         node *tmp;
   

    while(1){
             printf(" \n 1. create BST\n");
             printf(" 2. destroy BST\n"); 
             printf(" 3. add element to the BST\n");
             printf(" 4. delete element from BST \n");
             printf(" 5. Find element from BST\n");
             printf(" 6.print pre order\n");
             printf(" 7.print in order\n");
		     printf(" 8.print post order\n");
			 printf(" 9.maximun elenent ?\n");
			 printf(" 10.minimum elenent ?\n");
			 printf(" 11.Ordered list of BSt ?\n");
			 printf(" 12. create copy of bst    (enter your choice in number)\n");


		scanf("%d",& choice);
                switch(choice)
		{
			case 1 :createBST(&root); break;
		    case 2 : destroyBST(&root);
					 printf("\nBST is destroyed\n");	
					 break;
			case 3 :printf("enter the data to be insert   :");
					scanf("%d",& num);
					addBST(&root,num); break;
						
		    case 4: printf("enter the data to be delete   :");
					scanf("%d",& num);
					deleteBST(&root,num); break;
					
			case 5:printf("enter the data to be find  :");
				   scanf("%d",& num);
				   tmp =findBST(&root, num);	
				   if (tmp) { 	printf("Searched node=%d\n", tmp->data);  }
                   else  {   	printf("Data Not found in tree.\n"); }   
				   break;		
							
					   		
			case 6: print_preorder(root);break;
			case 7: print_inorder(root);break;
			case 8: print_postorder(root);break;
			case 9: max = maxBST(root);
					 printf("max is =%d\n", max);
					 break;
			 
			case 10: min = minBST(root);
					 printf("min is =%d\n", min);
					 break;
			 
			case 11: OrderedListBST(root);break;
		    case 12:printf("\nCreate Copy of the tree:\n");
				   node *copy;
				   createBST(&copy);
				   copy = CopyBST(&root);
				   print_preorder(copy);
				break;
            default:printf("invalid input\n");
		}
                



}

}


//creating the BST
void createBST(node ** tree){
			    *tree = NULL;
				printf("BST is created\n");
			
				}
				
//destroy whole bst				
void destroyBST(node** tree)
{   if((*tree)==NULL)
		return;
	
        destroyBST(&((*tree)->left));
        destroyBST(&((*tree)->right));
		
	if ((((*tree) -> right) == NULL) && (((*tree) -> left) == NULL)){
		free(*tree);
		*tree = NULL;
	}
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
						

						
//find given valu in BST
node* findBST(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        findBST(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        findBST(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}


//print pre order
void print_preorder(node * tree)
 {  
     if (tree != NULL)
    {
		 printf("\n%d\n",tree->data);
         print_preorder(tree->left);
         print_preorder(tree->right);
		
    }
 
}


//print in order
void print_inorder(node * tree)
{ if ((tree) != NULL){
        print_inorder(tree->left);
        printf("\n%d\n",tree->data);
        print_inorder(tree->right);
}
    
}


//print post order
void print_postorder(node * tree)
{   if (tree != NULL)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("\n%d\n",tree->data);
    }
}



//print largest value of bst
int maxBST(node * tree){
	 t3 = tree;
	 
	 if (tree == NULL)
		printf("\nTree is empty.\n");
	
	
     else if (tree->right!= NULL)
     {
        t3 = tree;
        return(maxBST(tree->right));
     }
    else    
        return (tree->data);
	
}


//print minimum value of bst
int minBST(node * tree){
	
	  t3 = tree;
    if (tree->left != NULL)
    {
        t3 = tree;
        return(minBST(tree->left));
    }
    else    
        return (tree->data);
	
}


//print bst element as increasing order
void OrderedListBST	(node * tree){
	  if (tree == NULL)
		printf("\nTree is empty.nothig to display \n");
	
        print_inorder(tree);
	   
		
}	


//delete given element from bst
void deleteBST	(node ** tree,int val){
	
				if(* tree == NULL)
		printf("\nValue does not exist in tree!");
	
	else if (val< ((* tree) -> data))
		deleteBST( &((* tree) -> left),val);
	
	else if (val > ((* tree) -> data))
		deleteBST( &((* tree) -> right),val);
	
	else{
		// when deleted node have no child
		if((((* tree) -> right) == NULL) && (((* tree) -> left) == NULL)){
			free(* tree);
			* tree = NULL;
		}
		// when deleted node have one child
		else if (((* tree) -> left) == NULL){
			node* temp = * tree;
			* tree = (* tree) -> right;
			free(temp);
		}
		else if (((*tree) -> right) == NULL){
			node* temp = * tree;
			* tree = (* tree) ->left;
			free(temp);
		}
		// when deleted node have two children
		else{
			node* temp = (* tree) -> right;
			
			// Loop down to find the leftmost leaf
			while (temp -> left != NULL){
				temp = temp -> left;
			}
			
			(* tree) -> data = temp -> data;
			deleteBST( &((* tree) -> right),temp -> data);
		}
	}
			 
}	


// create same copy of the bst
node* CopyBST(node ** tree){
	
	if(* tree == NULL)
		return NULL;
	
	node* copy = (node*)malloc(sizeof(node));
	copy -> data = (* tree) -> data;
	copy ->left = CopyBST(&((* tree) -> left));
	copy -> right = CopyBST(&((* tree) -> right));
	
	return copy;
}

