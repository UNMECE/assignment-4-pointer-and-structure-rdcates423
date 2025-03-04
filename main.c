#include "item.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void addItem(item *item_list, double price, char *sku, char *catagory, char *name, int index) {
	item_list[index].price = price;
	item_list[index].sku = strdup(sku);
	item_list[index].name = strdup(name);
	item_list[index].catagory = strdup(catagory);

}

void free_items(item *item_list, int size) {
int i;
for (i = 0; i < size; i++) {
	free(item_list[i].sku);
	free(item_list[i].name);
	free(item_list[i].catagory);
}
	free(item_list);
}


double averagePrice(item *item_list, int size) {
double total = 0.0;
int i;
for (i = 0; i < size; i++) {
	total += item_list[i].price;
}
return total / size;
}

void print(item *item_list, int size) {
int i;
for (i = 0; i < size; i++) {
	printf("name: %s\n", item_list[i].name);
	printf("sku: %s\n", item_list[i].sku);
	printf("catagory: %s\n", item_list[i].catagory);
	printf("price: %.2f\n", item_list[i].price);
}
}

int main(int argc, char *argv[]) {
int size = 5;

item *items = malloc(size * sizeof(item));

addItem(items, 299.99, "12345", "gaming", "xbox series s", 0);
addItem(items, 5.98, "12346", "kitchen", "coffee mug", 1);
addItem(items, 1199.99, "12347", "phones", "iphone 16 pro max", 2);
addItem(items, 119.99, "12348", "office", "printer", 3);
addItem(items, 99.99, "12349", "fitness", "fitbit inspire", 4);

print(items, size);
printf("Average price: %f\n", averagePrice(items, size));

if (argc > 1) {
char *search_sku = argv[1];
int ct = 0;
while (ct < size && strcmp(items[ct].sku, search_sku) != 0){
ct++;
}
if (ct < size) {
printf("found item!");
printf("name: %s\n", items[ct].name);
printf("catagory: %s\n", items[ct].catagory);
printf("sku: %s\n", items[ct].sku);
printf("price: %.2f\n", items[ct].price);
}else {
printf("not a valid item\n");
}
}
free_items(items, size);
return 0;
}





