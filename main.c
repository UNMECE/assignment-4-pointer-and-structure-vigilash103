#include "item.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    item_list[index].category = (char *)malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);

    item_list[index].name = (char *)malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);

    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);

    item_list[index].price = price; 
}

void free_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(item_list[i].category);
        free(item_list[i].name);
        free(item_list[i].sku);
    }
    free(item_list);
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
        printf("Name: %s\n", item_list[i].name);
        printf("Price: $%0.2f\n", item_list[i].price);
        printf("Catagory: %s\n", item_list[i].category);
        printf("SKU: %s\n", item_list[i].sku);
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s <SKU>\n", argv[0]);
        exit(1);
    }
    char *searchSku = argv[1];
    
    int size = 5;
    Item *itemList;
    itemList = (Item *)malloc(sizeof(Item) * size);
    add_item(itemList, 5, "19282", "breakfast", "reese's cereal", 0);
    add_item(itemList, 3.95, "79862", "dairy", "milk", 1);
    add_item(itemList, 2.50, "12345", "snack", "chips", 2);
    add_item(itemList, 1.25, "67890", "beverage", "soda", 3);
    add_item(itemList, 4.75, "54321", "produce", "apples", 4);

    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(itemList[i].sku, searchSku) == 0)
        {
            print_items(&itemList[i], 1);
            printf("Average price: $%0.2f\n", average_price(&itemList[i], 1));
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Item with SKU %s not found.\n", searchSku);
    }

    free_items(itemList, size);

    return 0;
}