#include "item.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("");
    }
    
    return 0;
}

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    Item *item_list;
    item_list = (Item *)malloc(sizeof(Item));
    item_list->category = (char *)malloc(sizeof(char));
    item_list->category = *category;
    item_list->name = (char *)malloc(sizeof(char));
    item_list->name = *name;
    item_list->sku = (char *)malloc(sizeof(char));
    item_list->sku = *sku;
    item_list->price = price; 
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
    return average;
}

void print_items(Item *item_list, int size)
{

}