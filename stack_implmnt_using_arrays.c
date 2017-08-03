#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 30

typedef int datatype;

//create the structure
typedef struct{

datatype*array;
int maxSize;
int topIndex;

}stack;



//the stack creating function
void stackCreate(    stack *s){
    
 	s->array=(datatype*)malloc(ARRAY_SIZE*sizeof(datatype));
  	if(s->array==NULL)printf("memory allocation faild\n");
   else{
 	s->maxSize=ARRAY_SIZE;
 	s->topIndex=-1;
 	printf("stack is created\n");
   }

}


//stack distroying function
void stackDestroy( stack *s){

 	 free(s->array);
  	s->maxSize=-1;
	s->topIndex=-1;
  	printf("stack distroyed\n");


}



// Insert data in to the stack
 void  stackPush( stack* s,datatype a){
	if(s->topIndex==s->maxSize-1)  printf("stack over flow\n");
     else{  s->topIndex++;
	 s->array[s->topIndex]=a;}
        

}


//poping where we only reduce topIndex by 1 .when each time we push data will be replace
void stackPop(stack *s){
	if(s->topIndex==-1)  printf("stack under flow\n");
	else{datatype b=s->array[s->topIndex];
        s->topIndex--;
	printf("the element %d is poped\n",b);}
	

}


//print the top of the stack
void stackPeek (stack *s){
	if(s->topIndex==-1)  printf("stack under flow\n");
   else{	printf("%d\n",s->array[s->topIndex]);
  }

}



//check whether stack is full or not
void stackIsFull (stack* s){
	if(s->topIndex==(s->maxSize-1))  printf("stack is full\n");
	else   printf("stack is not full\n");

}


//check whether stack is empty or not
void stackIsEmpty ( stack* s){
	if(s->topIndex==-1)  printf("stack is empty\n");
	else   printf("stack is not empty\n");

}

//display the stack
void display( stack* s){
    if(s->topIndex==-1)  printf("there is no element in stack to print\n");
	else{
			int i=s->topIndex;
			while(i>=0)
			{
			printf("%d\n",s->array[i]);
			i--;
			}

	     }
}







main(){
         int choice;
         datatype num;
        
    stack s;


  while(1){
              printf(" 1. create stack\n");
              printf(" 2. destroy stack\n"); 
              printf(" 3. push to the stack\n");
              printf(" 4. pop stack \n");
              printf(" 5. peek at stack\n");
              printf(" 6. check is empty? stack\n");
              printf(" 7. check is full? stack\n");
              printf(" 8. display stack\n");
	          printf(" 9. exit  (enter your choice in number)    ");

		scanf("  %d",& choice);
                switch(choice)
		{
			case 1 : stackCreate(&s); break;
			case 2 : stackDestroy(&s); break;
			case 3 :printf("enter the character to be insert  :");
			         	scanf("  %d",& num);
			        	stackPush(&s,num); break;
			case 4: stackPop(&s);break;
			case 5: stackPeek (&s);break;
			case 6: stackIsEmpty(&s);break;
			case 7: stackIsFull(&s);break;
			case 8: display(&s);break;
			case 9: exit(1);break;
           default:printf("invalid input\n");
                        
		}
                



}

}



