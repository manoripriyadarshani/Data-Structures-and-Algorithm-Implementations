#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

//create the structure
struct node{
   datatype info;
   struct node* link;

};

//method prototype
void createstack(struct node **start);
void destroystack(struct node **start);
void push(struct node**start,datatype num);
void  pop(struct node* *start);
void peek(struct node *start);
void isempty(struct node *start);
void display(struct node *start);
void stackReverseIter(struct node **start);
void stackReverseRec(struct node **start);


main(){
         int choice;
         datatype num;
         struct node* start;

    while(1){
              printf(" 1. create stack\n");
              printf(" 2. destroy stack\n"); 
              printf(" 3. push to the stack\n");
              printf(" 4. pop stack \n");
              printf(" 5. peek at stack\n");
              printf(" 6. check is empty? stack\n");
              printf(" 7. diaplay stack\n");
			  printf(" 8. reverse stack iteratively\n");
			  printf(" 9. reverse stack recursively\n");
              printf(" 10. exit    (enter your choice in number)\n  ");

		scanf("%d",& choice);
                switch(choice)
		{
			case 1 :  createstack(&start); break;
			case 2 : destroystack(&start); break;
			case 3 :printf("enter the number to be insert   :");
						scanf("%d",& num);
						push(&start,num); break;
			case 4: pop(&start);break;
			case 5: peek(start);break;
			case 6: isempty(start);break;
			case 7: display(start);break;
			case 8:	stackReverseIter(&start);break;
			case 9:	stackReverseRec(&start);break;
            case 10:exit(1);break;
            default:printf("invalid input\n");
		}
                



}

}


//creating the stack
void createstack(struct node **start){
		* start=NULL;
				printf("stack is created\n");
			
				}


//distroying the stack
 void destroystack(struct node **start){  
                   struct node *temp = *start ;
                   while(*start)
				   { 
					temp=*start;
					*start=temp->link;
					free(temp);
					}

					printf("stack destroyed\n");
					
					}  

//add new element to stack(add new node in the begining of the link list)					
   void push(struct node **start,datatype num){  
                           struct node *temp;
					       temp=(struct node*)malloc(sizeof(struct node));
						   temp->info=num;
						   temp->link=*start;
						   *start=temp;
					


						}
						
						
//poping (remove the top element)
 void pop(struct node **start){ 
                    struct node *temp;
					if(*start==NULL)printf("stack is empty.nothing to pop\n");
					else{temp=*start;
							*start=temp->link;
							free(temp);
							}

						}
						
						
// look at the top of stack
void peek(struct node *start){  
					if(start==NULL)printf("stack is empty.nothing to pop\n");
					else{
						    printf("%d\n",start->info);

						  }
				
                     }

//check whether stack is empty or not
void isempty(struct node *start){ 
                if(start==NULL)printf("stack is empty\n");
				else  printf("stack is not empty\n");


                                }
								

//print the stack top to bottom
void display(struct node *start){     
                  if(start==NULL)printf("stack is empty can't print\n");
				  else{ struct node *temp;
				           temp=start;
				                           while(temp!=NULL)
                                           { printf("%d\n",temp->info);
					                         temp=temp->link;
					                        }
			        	 }
}


void stackReverseIter(struct node **start){
	        struct node *result=NULL;
	        struct node *current=*start;
		    struct node *next;
		   
		   while(current!=NULL){
			   next=current->link;
			   current->link=result;
			   result=current;
			   current=next;
			   *start=result;
		   }
	
	printf("stack is reversed iteratively");
}



void stackReverseRec(struct node **start){
	    struct node *first;
		struct node *next;
		if(*start==NULL)return;
			
		first=*start;
		next=first->link;
		
		if(next==NULL)return;
		stackReverseRec(&next);
		first->link->link=first;
		first->link=NULL;
		*start=next;
		
		printf("stack is reversed recursively");	
		}
	
	


