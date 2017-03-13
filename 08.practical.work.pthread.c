#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define BUFFER_SIZE 10

typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
	}item;
	
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
	// do nothing -- no free buffer item
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume()	
 {
 	item *i = (item *)malloc(sizeof(item));
 	while(first == last)
 	{	
 	// do nothing -- no free buffer item
 	}
 	memcpy(i, &buffer[last], sizeof(item));
 	last = (last+1) % BUFFER_SIZE;
 	return i;
}

void *threadProduce(void *param) {
// do something in the background
	item a1;
	a1.type = '1';
	a1.amount = '0';
	a1.unit = '0';
	printf("Producing 1st item: type = %c, amount = %d, unit = %c", a1.type, a1.amount, a1.unit);

	item a2;
	a2.type = '0';
	a2.amount = '1';
	a2.unit = '0';
	printf("\nProducing 2nd item: type = %c, amount = %d, unit = %c", a2.type, a2.amount, a2.unit);

	item a3;
	a3.type = '0';
	a3.amount = '0';
	a3.unit = '1';
	printf("\nProducing 3rd item: type = %c, amount = %d, unit = %c", a3.type, a3.amount, a3.unit);

	printf("\n\tFirst: %d, Last: %d\n", first, last);
	produce(&a1);
	
	printf("\n\tFirst: %d, Last: %d\n", first, last);
	produce(&a2);

	printf("\n\tFirst: %d, Last: %d\n", first, last);
	produce(&a3);
}

void *threadConsume(void *param) {
	printf("Consuming an item!\n");
	consume();
	printf("'tFirst: %d, Last: %d\n", first, last);

	printf("Consuming an another item!\n");
	consume();
	printf("\tFirst: %d, Last: %d\n", first, last);
}
	
int main() {
// create a background thread to execute threadProduce, threadConsume
	pthread_t pro, con;
	pthread_create(
	&pro,		// get thread id
	NULL, 		// skip the attributes
	threadProduce,	// thread function name
	NULL);		// argument to thread function
	pthread_join(pro, NULL);
	pthread_create(
	&con,
	NULL,
	threadConsume,
	NULL);
	pthread_join(con, NULL);
}
