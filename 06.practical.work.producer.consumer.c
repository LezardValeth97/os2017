#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main(){
	item a1;
	item b1;
	
	a1.type = '1';
	a1.amount = '4';
	a1.unit = '1';
	printf("Producing 1st item: type = %c, amount = %d, unit = %c", a1.type, a1.amount, a1.unit);
	
	b1.type = '0';
	b1.amount = '6';
	b1.unit = '1';
	printf("Producing 2nd item: type = %c, amount = %d, unit = %c", b1.type, b1.amount, b1.unit);	
	
	printf("\tFirst: %d, Last: %d\n", first, last);
	produce(&a1);
	
	printf("\tFirst: %d, Last: %d\n", first, last);
	produce(&b1);
	
	item* consumed = consume();
	printf("Item consumed:\n Type: %c, Amount: %d, Unit: %c\n", consumed->type, consumed->amount, consumed->unit);
	return 0;
}
