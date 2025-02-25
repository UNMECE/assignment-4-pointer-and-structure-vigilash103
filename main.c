#include "item.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    item_list[index].category = (char *)malloc(sizeof(char));
    item_list[index].category = category;

    item_list[index].name = (char *)malloc(sizeof(char));
    item_list[index].name = name;

    item_list[index].sku = (char *)malloc(sizeof(char));
    item_list[index].sku = sku;

    item_list[index].price = price; 
}

void free_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(item_list);
    }
}

double average_price(Item *item_list, int size)
{
    double average = 0;
    for (int i = 0; i < size; i++)
    {
        average += item_list[i].price;
    }
    average /= size;
    
    return average;
}

void print_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("*******************************\n");
        printf("            Item %d            \n", i+1);
        printf("*******************************\n");
        printf("Name: %s", item_list[i].name);
        printf("Price: %f", item_list[i].price);
        printf("Catagory: %s", item_list[i].category);
        printf("SKU: %s", item_list[i].sku);
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s<size>", argv[1]);
    }

    char *searchSku = argv[1];

    int size = 5;
    Item *itemList;

    itemList = (Item *)malloc(sizeof(Item) * size);

    if(size < 0) 
    {
        printf("size to small");
    }
    
    add_item(&itemList[size], 5, "19282", "breakfast", "reese\'s cereal", 0);
    print_items(&itemList[size], 1);
    free_items(&itemList[size], size);

    return 0;
}