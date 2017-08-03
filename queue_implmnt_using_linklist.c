#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

//create the structure
struct Qnode{
   datatype info;
   struct Qnode* link;

};

//method prototype
void queueCreate(struct Qnode **front,struct Qnode **rear);
void queueDestroy(struct Qnode **front,struct Qnode **rear);
 void enqueue(struct Qnode **front,struct Qnode **rear,datatype num);
void dequeue(struct Qnode **front,struct Qnode **rear);
void queuePeek(struct Qnode *front);
void queueIsempty(struct Qnode *front,struct Qnode *rear);
void display(struct Qnode *front,struct Qnode *rear);


main(){
         int choice;
         datatype num;
         struct Qnode* front;
		  struct Qnode* rear;

    while(1){
              printf(" 1. create queue\n");
              printf(" 2. destroy queue\n"); 
              printf(" 3. add element to the queue\n");
              printf(" 4. remove element from queue \n");
              printf(" 5. peek at queue\n");
              printf(" 6. check is empty? queue\n");
              printf(" 7. diaplay queue\n");
			  printf(" 8. exit    (enter your choice in number)\n  ");

		scanf("%d",& choice);
                switch(choice)
		{
			case 1 :queueCreate(&front,&rear); break;
			case 2 : queueDestroy(&front,&rear); break;
			case 3 :printf("enter the data to be insert   :");
						scanf("%d",& num);
						enqueue(&front,&rear,num); break;
			case 4: dequeue(&front,&rear);break;
			case 5:queuePeek(front);break;
			case 6:queueIsempty(front,rear);break;
			case 7: display(front,rear);break;
		    case 8:exit(1);break;
            default:printf("invalid input\n");
		}
                



}

}


//creating the stack
void queueCreate(struct Qnode **front,struct Qnode **rear){
			* front=NULL;
		    * rear=NULL;
				printf("stack is created\n");
			
				}


//distroying the stack,remove all Qnodes from front to end
 void queueDestroy(struct Qnode **front,struct Qnode **rear){  
 
                 
					if(*front==NULL) 
					{	printf("Queue is Empty\n");
						return;
						
					}
					
					else{        
					struct Qnode *temp ;
						while(*front)
				   { 
					temp=*front;
					(*front)=(*front)->link;
					free(temp);
					}
					*rear=NULL;
					printf("stack destroyed\n");
		   }	
					}  

//add new element to stack(add new Qnode in the begining of the link list)
			
   void enqueue(struct Qnode **front,struct Qnode **rear,datatype num){  
                         
						   
						   //create new Qnode 
						   struct Qnode *temp;
					       temp=(struct Qnode*)malloc(sizeof(struct Qnode));
						   temp->info=num;
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
 void dequeue(struct Qnode **front,struct Qnode **rear){ 
                    struct Qnode *temp=*front;
					
					
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
						
 }				
						
// look at the top of queue,where we don't want rear,therefore it dont want to pass it as a parameter
void queuePeek(struct Qnode *front){  

					if(front==NULL)
						printf("queue is empty.nothing to pop\n");
					else{
						    printf("%d\n",front->info);

						  }
				
                     }

//check whether queue is empty or not
void queueIsempty(struct Qnode *front,struct Qnode *rear){ 

                if(front==NULL  )
					printf("queue is empty\n");
				
				else 
					printf("queue is not empty\n");


                                }
								

//print the queue top to bottom
void display(struct Qnode *front,struct Qnode *rear){    
 
               
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


