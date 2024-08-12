#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a union to store either an integer or a floating-point number
union Data {
    int intVal;
    float floatVal;
};

// Define a struct to store the product information
struct Product {
    int id;
    char name[50];
    char category[50];
    union Data price;
};

// Function prototypes
void addProduct(struct Product *products, int *numProducts);
void viewProduct(struct Product *products, int numProducts);
void deleteProduct(struct Product *products, int *numProducts);
void searchProduct(struct Product *products, int numProducts);

int main() {
    struct Product products[100];
    int numProducts = 0;
    int choice;

    while (1) {
        printf("\nProduct Catalog Management\n");
        printf("1. Add Product\n");
        printf("2. View Product\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                viewProduct(products, numProducts);
                break;
            case 3:
                deleteProduct(products, &numProducts);
                break;
            case 4:
                searchProduct(products, numProducts);
                break;
            case 5:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addProduct(struct Product *products, int *numProducts) {
    printf("Enter the product ID: ");
    scanf("%d", &products[*numProducts].id);

    printf("Enter the product name: ");
    scanf("%s", products[*numProducts].name);

    printf("Enter the product category: ");
    scanf("%s", products[*numProducts].category);

    printf("Enter the product price: ");
    scanf("%f", &products[*numProducts].price.floatVal);

    (*numProducts)++;
}

void viewProduct(struct Product *products, int numProducts) {
    int i;
    printf("Products:\n");
    for (i = 0; i < numProducts; i++) {
        printf("%d. %s (%s): $%.2f\n", products[i].id, products[i].name, products[i].category, products[i].price.floatVal);
    }
}

void deleteProduct(struct Product *products, int *numProducts) {
    int i, index;
    printf("Enter the index of the product to delete: ");
    scanf("%d", &index);

    for (i = index-1; i < *numProducts-1; i++) {
        products[i] = products[i+1];
    }
    (*numProducts)--;
}

void searchProduct(struct Product *products, int numProducts) {
    int i;
    char searchTerm[50];
    printf("Enter the search term: ");
    scanf("%s", searchTerm);

    printf("Products matching the search term:\n");
    for (i = 0; i < numProducts; i++) {
        if (strstr(products[i].name, searchTerm)!= NULL || strstr(products[i].category, searchTerm)!= NULL) {
            printf("%d. %s (%s): $%.2f\n", products[i].id, products[i].name, products[i].category, products[i].price.floatVal);
        }
    }
}
