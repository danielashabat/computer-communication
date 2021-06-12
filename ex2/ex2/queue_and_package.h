#ifndef	QUEUE_AND_PACKAGE_H
#define	QUEUE_AND_PACKAGE_H


typedef struct Package {
	int time;
	char Sadd[20];
	int Sport;
	char Dadd[20];
	int Dport;
	int length;
	float weight;//optional
	float last;
	struct Package* next;
	struct Package* prev;

} Package;


/*this struct defines the queue data structure*/
typedef struct Queue {
	int size;//the size of queue
	Package* head;//pointer to the first package in queue
	Package* tail;//pointer to the last package in queue
	struct Queue* next;
}QUEUE;


// Function Declarations -------------------------------------------------------


//this function creats a new package 
//if succeed it return pointer to new node, otherwise it return NULL
Package* CreatePackage(int time, char* Sadd, int Sport, char* Dadd, int Dport, int length, float weight, float last);


/*this function search for the right queue for the new package and insert it to the  queue, if no queue found it will create new queue and insert the package*/
void InsertNewPackage(QUEUE ** ptr_head, Package* new_package);

/*this function returns the package with minimum last*/
Package* GetPackageWithMinimumLast(QUEUE* head);

/*this function returns the package with minimum last,pop it from the queue and updates all the linked queues*/
Package* PopPackageWithMinimumLast(QUEUE** ptr_head);

void PrintQueues(QUEUE* head);

//returns the sum of all active links
float SumActiveLinksWeights(QUEUE* head);

//returns the 'last' of the previous package in queue
int GetPreviousPackageLast(Package* package);

//the function searchs for last==-1 in all packages, and update it.
void UpdateLast(QUEUE* head, float round_t);

#endif