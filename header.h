#define BUFFERSIZE 60
#define RESIZED 1
#define ENDFILE 2
#define SUCCESS 0
#define FAILED 1


typedef struct node *ptr;

typedef struct node {
	int * data;
	ptr next;
}item;



int readText(int, void *);
void printText(int, void *);
int * addToBuffer(int, int *);
int read (int*,int);
void print (int, int *);
ptr addToList(ptr );
