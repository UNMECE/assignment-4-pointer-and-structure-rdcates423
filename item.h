#ifndef item_h
#define item_h

typedef struct {
	double price;
	char *sku;
	char *name;
	char *catagory;
}item;

void addItem(item *item_list, double price, char *sku, char *catagory, char *name, int index);
void free_items(item *item_list, int size);
double averagePrice(item *item_list, int size);
void print_items(item *item_list, int size);


#endif


