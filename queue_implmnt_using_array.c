#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 30

typedef int datatype;

//create the structure
typedef struct{

datatype*array;
int capacity;
int front;
int rear;
int size;

}queue;



//the stack creating function
void queueCreate(   queue *q){
    
 	q->array=(datatype*)malloc(ARRAY_SIZE*sizeof(datatype));
  	if(q->array==NULL)printf("memory allocation faild\n");
   else{
 	q->capacity=ARRAY_SIZE;
 	q->front=-1;
	q->rear=-1;
	q->size=0;
	
 	printf("stack is created\n");
   }

}


//queue distroying function
void queueDestroy( queue*q){

 	 free(q->array);
    q->front=-1;
	q->rear=-1;
	q->size=0;
	
  	printf("queue distroyed\n");


}



// Insert data in to the queue
 void  enqueue( queue* q,datatype a){
	 
	 if((q->rear+1)%q->capacity==q->rear) // the situation queue is full
		 printf("queue over flow\n");
		 
     else{    q->rear=(q->rear+1)%q->capacity;
				q->array[q->rear]=a;
				q->size++;
				if(q->front==-1)    // the situation queue que have one element
				q->front=q->rear;
			
        

}
 }


//poping where we only reduce topIndex by 1 .when each time we push data will be replace
void dequeue(queue *q){
	if(q->front==-1 && q->rear==-1)  //the situation array have not any element 
	printf("queue is underflow\n");

	else{ 
	   
			if(q->front==q->rear) //the situation array have only one element 
			{q->front=q->rear=-1;
			  q->size--;
			}
			
			else   // array have more than one element 
			{q->front=(q->front+1)%q->capacity;
			   q->size--;
			}
	

}

}
//print top(front) of the queue
void queuePeek (queue *q){
	if(q->front==-1 && q->rear==-1)  printf("queue is empty nothing to show\n");
   else{	printf("%d\n",q->array[q->front]);
  }

}



//check whether queue is full or not
void queueIsFull (queue* q){
 if((q->rear+1)%q->capacity==q->rear)  printf("queue is full\n");
else   printf("queue is not full\n");

}


//check whether queue is empty or not
void queueIsEmpty ( queue* q){
	if(q->front==-1&&q->rear==-1)  printf("queue is empty\n");
	else   printf("queue is not empty\n");

}

//display the queue
void display( queue* q){
 	if(q->front==-1&&q->rear==-1)  printf("queue is empty nothing to show\n");
	else{  
				int i=q->front;
				while( i != q->rear){
				printf("%d ", q->array[i]);	
				i = (i + 1) % ARRAY_SIZE;
                 }
				 printf("%d ",  q->array[i]);
	     }
}


main(){
         int choice;
         datatype num;
        
  queue q;


  while(1){
              printf(" 1. create  queue\n");
              printf(" 2. destroy  queue\n"); 
              printf(" 3. add element to the  queue\n");
              printf(" 4. remove element from queue \n");
              printf(" 5. peek at  queue\n");
              printf(" 6. check is empty?  queue\n");
              printf(" 7. check is full?  queue\n");
              printf(" 8. display  queue\n");
	          printf(" 9. exit  (enter your choice in number)    ");

		scanf("  %d",& choice);
                switch(choice)
		{
			case 1 :queueCreate(  &q); break;
			case 2 : queueDestroy(&q); break;
			case 3 :printf("enter the data to be insert  :");
			         	scanf("  %d",& num);
			        	enqueue(&q,num); break;
			case 4: dequeue(&q);break;
			case 5: queuePeek (&q);break;
			case 6: queueIsEmpty(&q);break;
			case 7: queueIsFull(&q);break;
			case 8: display(&q);break;
			case 9: exit(1);break;
           default:printf("invalid input\n");
                        
		}
                



}

}



