#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000 
void Add_BST(int arr[],int data,int index);
void print_inorder_BST(int arr[],int index);
void print_reorder_BST(int arr[],int index);
void print_postorder_BST(int arr[],int index);
void Binary_search_BST(int arr[],int val,int index);

int level_count;



void main(){
	
	int a[SIZE],i,j;
	
	//fill all the elements of array(which is used to create BST) by -1
	for( i = 0; i < SIZE ; i++ ){
		a[ i]=-1;
    }
	
	
	//create a binary search tree by adding following elements
	int node[31]={100,50,200,25,75,150,250,10,35,60,80,125,175,225,275,5,15,30,40,55,65,78,85,110,140,160,180,210,230,265,300};
	for (j=0;j<sizeof(node)/sizeof(int);j++){
		Add_BST(a,node[j],1);
	}
	
	printf("print the BST in-order  :  ");
	print_inorder_BST(a,1);
	printf("\n\n");
	
	
	printf("print the BST re-order  :  ");
	print_reorder_BST(a,1);
	printf("\n\n");
	
	
	printf("print the BST post-order  :  ");
	print_postorder_BST(a,1);
	printf("\n\n");
	
	
	level_count=-1;
	Binary_search_BST(a,40,1);
	
	level_count=-1;
	Binary_search_BST(a,180,1);
	
}


// add elements to the binary search tree
void Add_BST(int arr[],int data,int index){
	
	if(index>SIZE){
		printf("No space available in the array");
	}
	
	else{	if(arr[index]==-1)
				arr[index]=data;
				
			else {
				if(data<arr[index])
					{Add_BST(arr,data,index*2);
				
					}
				else
					{Add_BST(arr,data,(index*2)+1);
					}
				
				}	
		}
}



//print Binary search tree in-order		
void print_inorder_BST(int arr[],int index){
	if(arr[index]!=-1){
		print_inorder_BST(arr, index*2);
		printf("%d   ",arr[index]);
		print_inorder_BST(arr, (index*2)+1);
	}
}



//print Binary search tree re-order		
void print_reorder_BST(int arr[],int index){
	if(arr[index]!=-1){
		printf("%d   ",arr[index]);
		print_reorder_BST(arr, index*2);
		print_reorder_BST(arr, (index*2)+1);
	}
}



//print Binary search tree post-order	
void print_postorder_BST(int arr[],int index){
	if(arr[index]!=-1){
		print_postorder_BST(arr, index*2);
		print_postorder_BST(arr, (index*2)+1);
		printf("%d   ",arr[index]);
	}
}



//search a element in BST using binary search
void Binary_search_BST(int arr[],int val,int index){
	
	if(index>SIZE)
	{	printf("value is not there");
		return;
	}
	
	level_count++;
	if(val < arr[index])
    {
        Binary_search_BST(arr,val,index*2);
		
    }
    else if(val > arr[index])
    {
        Binary_search_BST(arr,val,(index*2)+1);
		
    }
    else if(val == arr[index])
    {	printf("element %d found at level %d \n",val,level_count);
        return;
    }
	
}


