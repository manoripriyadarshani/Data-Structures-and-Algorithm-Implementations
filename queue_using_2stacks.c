#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

//structure for stack
struct node{
   datatype info;
   struct node* link;

};


//structure for queue
struct queue
{
    struct node *stack1;
    struct node *stack2;
};



void createstack(struct node **start);
void pushstack(struct node **start,datatype num);
void displaystack(struct node* *start);
datatype popstack(struct node **start);
int isemptystack(struct node *start);
void peekstack(struct node *start);
void destroystack(struct node **start);

void queueCreate(   struct queue*q);
void  enqueue( struct queue*q,datatype a);
void display( struct queue *q);
void dequeue( struct queue *q);
void  isemptyqueue(struct queue *q);
void peekqueue(struct queue *q);
void destroyqueue(struct queue *q);



main(){
	
            int choice;
            datatype num; 
			struct node* stack2;
	
			struct queue *q = (struct queue*)malloc(sizeof(struct queue));
			
			
  while(1){
               printf(" 1. create  queue\n");
               printf(" 2. destroy  queue\n"); 
		        printf(" 3. add element to the  queue\n");
                printf(" 4. remove element from queue \n");
                printf(" 5. peek at  queue\n");
                printf(" 6. check is empty?  queue\n");
                printf(" 7. display  queue\n");
	            printf(" 8. exit  (enter your choice in number)    ");
 
		scanf("  %d",& choice);
        switch(choice)
		{
			case 1 :queueCreate(  q); break;
			case 2 : destroyqueue(q); break;
			case 3 :printf("enter the data to be insert  :");
			          	  scanf("  %d",& num);
		             	  enqueue(q,num); break;
		   case 4:dequeue(q);break;
			case 5:peekqueue(q);break;
			case 6: isemptyqueue(q);break;
		    case 7: display(q);break;
			case 8: exit(1);break;
           default:printf("invalid input\n");
                        
		}
                



}
}



//***************************************************************queue  methods create by stack methods*************************************************


void queueCreate(   struct queue*q){
	
    createstack(&q->stack1);
   createstack( &q->stack2);
  
	printf("queue is created\n");
	
	
}

void  enqueue( struct queue*q,datatype a){
	    
     pushstack( &q->stack1, a);
     printf("push done\n");
 }

	

 
 void display( struct queue *q){
	 
	datatype x;
	//all elements are fill to stack2
     if(q->stack1 != NULL)
		   while (q->stack1 != NULL) {
		   x=popstack(&q -> stack1);
			pushstack(&q -> stack2, x);
        }
	 q->stack1 == NULL;
	 
	 //display srtack 1
	 displaystack(&q->stack2);
}






void dequeue( struct queue *q){
	
	datatype x;
    if (q -> stack1 == NULL && q -> stack2 == NULL){
        printf("Queue is empty  Nothing to pop");
        return;
    }
    if (q -> stack2 == NULL) {
        while (q->stack1 != NULL) {
		   x=popstack(&q -> stack1);
			pushstack(&q -> stack2, x);
        }
    }
	
	
    x = popstack(&q -> stack2);
    printf("Poped element is %d\n", x);
	
	
	
}





void  isemptyqueue(struct queue *q){
	
	 if (q -> stack1 == NULL && q -> stack2 == NULL){
        printf("Queue is empty  \n");
        return;
    }
	else
			  printf("Queue is not empty \n");
	
}





void peekqueue(struct queue *q){
	
	datatype x;
	//all element are fill to stack 2
     if(q->stack1 != NULL)
		   while (q->stack1 != NULL) {
		   x=popstack(&q -> stack1);
			pushstack(&q -> stack2, x);
        }
	 q->stack1 == NULL;
	 
	 peekstack(q -> stack2);
	
	
}




void destroyqueue(struct queue *q){
	
	destroystack(&q -> stack2);
	destroystack(&q -> stack1);
	printf("queue is distroyed\n");
}




//*******************************************************************used stack methods *********************************************


void createstack(struct node **start){
	
		* start=NULL;
			
			
	}

	
void pushstack(struct node **start,datatype num){  

                           struct node *temp;
					       temp=(struct node*)malloc(sizeof(struct node));
						   temp->info=num;
						   temp->link=*start;
						   *start=temp;
					


	}	
	
	
	
datatype popstack(struct node **start){ 
                     datatype x;
                    struct node *temp;
					if(*start==NULL)printf("stack is empty.nothing to pop\n");
					else{temp=*start;
					       x=temp->info;
							*start=temp->link;
							free(temp);
							return x;
							}

						}
	
	
							
						
void displaystack(struct node* *start){     
                  if(start==NULL)printf("stack is empty can't print\n");
				  else{ struct node *temp;
				           temp=*start;
				                           while(temp!=NULL)
                                           { printf("%d\n",temp->info);
					                         temp=temp->link;
					                        }
			        	 }						
}




int isemptystack(struct node *start){ 
                if(start==NULL) return 1;
				

}




void peekstack(struct node *start){  
					if(start==NULL)return;
					else{
						    printf("%d\n",start->info);

						  }
				
          
}
        


void destroystack(struct node **start){  
                   struct node *temp = *start ;
                   while(*start)
				   { 
					temp=*start;
					*start=temp->link;
					free(temp);
					}

					
					}  		