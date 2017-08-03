#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 100

	typedef int datatype;

	typedef struct{

	datatype*array;
	int maxSize;
	int topIndex;

	}stack;




	void stackCreate(    stack *s){
		
		s->array=(datatype*)malloc(ARRAY_SIZE*sizeof(datatype));
		if(s->array==NULL)printf("memory allocation faild\n");

		s->maxSize=ARRAY_SIZE;
		s->topIndex=-1;
		
	}




	void stackDestroy( stack *s){

		 free(s->array);
		s->maxSize=-1;
		s->topIndex=-1;
		
	}





	 void  stackPush( stack* s,datatype a){
		if(s->topIndex==s->maxSize-1)  printf("stack over flow\n");
		   s->topIndex++;
			s->array[s->topIndex]=a;
			
	}
	
	
	
	
	
	int stackPop(stack *s){
		if(s->topIndex==-1)  printf("stack under ********flow\n");
		datatype b=s->array[s->topIndex];
			s->topIndex--;
		return b;
		

	}





	//I used severel methods of my stack implimentation.un used methods are commented.

	/*
	void stackPeek (stack *s){
		if(s->topIndex==-1)  printf("stack under flow\n");
		printf("%d",s->array[s->topIndex]);


	}

	void stackIsFull (stack* s){
		if(s->topIndex==(s->maxSize-1))  printf("stack is full\n");
		else   printf("stack is not full\n");

	}


	void stackIsEmpty ( stack* s){
		if(s->topIndex==-1)  printf("stack is empty\n");
		else   printf("stack is not empty\n");

	}

	void display( stack* s){
		if(s->topIndex==-1)  printf("there is no element in stack to print\n");
	   int i=s->topIndex;
	   while(i>=0){
		printf("%c",s->array[i]);
			i--;
		}


	}


	*/




main(){   

							int string_arraysize=30;
							char yourString[string_arraysize];
							
						   //get input the string from user to a char array

							
							printf("enter your string :\n");
							fgets(yourString,string_arraysize,stdin);


							//create the stack
							 stack s;
							stackCreate(&s); 


							//the elements in the char array push in to stack 
							int i=0;
							while(yourString[i]!='\0'){
							stackPush(&s,yourString[i]);
							 
							i++;
							}


							//the elements are poped and repalce the array named yourString
							int j=0;
							while(j<i){
							 yourString[j] =stackPop(&s);

							j++;
							}
								


							// print the element of the modified array	
							int k=0;
							while(k<i){
							 printf("%c",yourString[k] );
							k++;
							}
							  

							//now array is reversed order.destroy the stack
							stackDestroy(&s);

}



