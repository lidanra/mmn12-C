#include<stdio.h>
#include<stdlib.h>
#include"header.h"

/*we let the user to choose whitch method to use 1.buffer 2.linked list after that we read the user text and saved it n memory allocation
after the user finished to text we print the text in rows of 60 chars free the memory and exit*/
int main()
{
	int option=0;
	int r=0;
	int *p = NULL;
	ptr q = NULL;
	ptr q1 = NULL;
	
	/* loop to get from the user the method he choose 1.buffer 2.linked list after he choose we initialize the first memory allocation*/
	while((option==0))
	{
		printf("please choose \n1.write to a buffer \n2.write to linked list\n\n");
		option = getchar();
		
		if(option=='1')
		{
			p =  (int*) calloc(BUFFERSIZE,sizeof(int));
				
			if(!p)
		      	{
			     	printf("First memory allocation failed");
			      	exit(0);
		      	}
		 }
		else if(option=='2')
		{
			q = (ptr) calloc(1,sizeof(item));
			
			if(!q)
			{
				printf("First memory allocation failed");
				exit(0);
			}
			p =  (int*) calloc(BUFFERSIZE,sizeof(int));
				
			if(!p)
		      	{
			     	printf("First memory allocation failed");
			      	exit(0);
		      	}
		      	q->data = p;
		      	

		}
		else 
		{
			option = 0;
		}
	}
	/*read, print and free for each method*/
	if(option == '1')
	{
		r = readText(option,(void*) p);
		printText(option, (void*) p);
		free(p);
	}
	
	else if(option == '2')
	{
		r = readText(option,(void*) q);
		printText(option, (void*) q);
		while(!q)
		{
			if(!(q->next))
			{
				q1 = (ptr) (q->next);
			}
			free((q->data));
			free(q);
			q=q1;
		}
	}
	
	/*if we get error from one of the realloctions we print that we had error*/
	if(r!=SUCCESS)
	{
		printf("ERROR memory reallocation failed\n");
		
	}
	printf("\nit was fun and the allocation released so goodbye\n");
	return SUCCESS;
} 

/*we read the user text according to the user choice we keep index i to keep track the alloction and reallocte when need to resized
end when we get EOF or get error realloction. */ 
int readText(int option, void *p)
{
	int i = 0;
	int buffer=BUFFERSIZE;
	int index = 0;	
	int *q1 = (int*)p;
	ptr q2 = (ptr) p;
	printf("Please write your text\n\n");
			
	while(i != ENDFILE)
	{	
		if(option == '1')
		{	
			i = read((q1+index),index);
				
			if(i==RESIZED)
			{ 	
				int *q2 = NULL;
				q2 = (int*)addToBuffer(buffer,(int*)p);
				if (!q2)
				{
					return FAILED;
				}
				q1=q2;
				p=q2;
				index = buffer;
				buffer +=BUFFERSIZE;
				i = 0;
			}
		}
		else if(option == '2')
		{
			int* q3 = (int*)(q2->data);
			i = read(q3,index);
				
			if(i==RESIZED)
			{ 
				q2->next = (ptr)addToList((ptr)q2);
				if (!(q2->next))
				{
					return FAILED;
				}
				index = 0;
				i=0;
				q2 = q2->next;
			}
		}
	}		      
	return SUCCESS;
}

/* sent to print function print if the method is linked list we point to the next after 60 chars*/
void printText(int option, void *p)
{
	int* data = NULL;
	printf("let's print!\n\n");
	if(option == '1')
	{
		data = (int*)p;
		print (option,data);
	}
	if(option == '2')
	{
		ptr q = (ptr)p;
		while(q != NULL)
		{
			data = (int*)q->data;
			print (option,data);
			q = q->next;
			
		}
	}

}
/*read the text from the user after 60 chars the function ask for realloction*/
int read (int *p, int i)
{
	int ch=getchar();
	int *q = (int*)p;
	int j = 0;
	for(; j<BUFFERSIZE; j++)
	{
		ch = getchar();
		if(ch != '\n' && ch!=EOF)
		{
			*q = ch;
			q++;
		}
		if(ch == '\n')
		{
			j--;
		}
			
		if(ch==EOF)
		{
			*q = ch;
			return ENDFILE;
		}

	}
	return RESIZED;
}
/*print rows of 60 chars*/
void print (int option, int *p)
{
	int i = 0;
	int end_node = 0;
	int *q = (int*)p;
	while(*q!=EOF && end_node==0)
	{
		while(i<BUFFERSIZE && *q!=EOF && end_node==0)
		{
			if(*q!=EOF)
			{
				printf("%c",*q);
				q++;
			}
			i++;
			if(i==(BUFFERSIZE))
			{
				if(option == '2')
				{
					end_node = 1;	
				}
				if(option == '1')
				{
					i=0;
					printf("\n");	
				}
			}

		}
		
		printf("\n");
	}
	
	
}
/*realloction for the buffer*/
int * addToBuffer(int buffer , int *p)
{
	int *q = NULL;
	q = (int*) realloc(p,(buffer+BUFFERSIZE)*sizeof(int));
	if(!q)
	{
		return NULL;
	}
	return q;
}
/*add new node for the linked list*/
ptr addToList(ptr p)
{
	ptr q = NULL;
	int *q1 = NULL;
	
	q = (ptr) calloc(1,sizeof(item));
		      
	if(!q)
	{
		return NULL;
	}
	q1 =  (int*) calloc(BUFFERSIZE,sizeof(int));
	
	if(!q1)
	{
		return NULL;
	}
	q->data = q1;
	p=q;
	return q;
}













