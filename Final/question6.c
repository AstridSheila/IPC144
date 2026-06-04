//Astrid Bailey
//IPC144N1F
//April 16, 2026

#include <stdio.h>
#include <stdbool.h>

struct Date{
    int year;
    int month;
    int day;

};

struct Dimension{
    unsigned int length;
    unsigned int width;
    unsigned int height;

};

struct Product{
    int productID;
    char productName[100];
    char description[300];
    float price;
    char sku[30];
    int categoryID;
    int stockQuantity;
    int weight;
    struct Dimension dimension;
    char manufacturer[100];
    struct Date dateAdded;
    struct Date lastModifiedDate;
    bool isActive;
};

//Function Prototypes
void addProduct(FILE *ptr);
void displayProducts(FILE *ptr);
void display(struct Product p);
void findRecord(FILE *ptr);
void updateProduct(FILE *ptr);
void deleteProduct(FILE *ptr);
unsigned int userOption(void);

int main(){

    //Create and open file
    FILE *fptr = fopen("products.dat", "wb+");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }


    //User menu
    unsigned int userChoice;
    
    while((userChoice) != 9){
        userChoice=userOption();
        switch(userChoice){
            case 1:
                addProduct(fptr);
                break;
            case 2:
                displayProducts(fptr);
                break;
            case 3:
                findRecord(fptr);
                break;
            case 4:
                updateProduct(fptr);
                break;
            case 5:
                deleteProduct(fptr);
                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;

        }

    }
    fclose(fptr);
    return 0;
}

//Read/write/delete functions
void addProduct(FILE *ptr){
    int productID = 0;
    printf("%s", "Enter the product ID number. Enter 0 to end input.\n");
    scanf("%d", &productID);
    struct Product newProduct = {0, "", "", 0.0, "", 0, 0, 0, {0, 0, 0}, "", {0, 0, 0}, {0, 0, 0}, false};

    if(productID != 0){
        printf("%s", "Enter the product name: \n");
        scanf("%s", &newProduct.productName);
        
        printf("%s", "Enter the product description: \n");
        scanf("%s", &newProduct.description);

        printf("%s", "Enter the product price: \n");
        scanf("%f", &newProduct.price);
        
        printf("%s", "Enter the product SKU: \n");
        scanf("%s", &newProduct.sku);

        printf("%s", "Enter the product category: \n");
        scanf("%d", &newProduct.categoryID);

        printf("%s", "Enter the product stock quantity: \n");
        scanf("%d", &newProduct.stockQuantity);

        printf("%s", "Enter the product weight: \n");
        scanf("%d", &newProduct.weight);

        printf("%s", "Enter the product dimensions(height, width, and length): \n");
        scanf("%d %d %d", &newProduct.dimension.height, &newProduct.dimension.width, &newProduct.dimension.length);
        
        printf("%s", "Enter the product manufacturer: \n");
        scanf("%s", &newProduct.manufacturer);

        printf("%s", "Enter the date added(day, month, year): \n");
        scanf("%d %d %d", &newProduct.dateAdded.day, &newProduct.dateAdded.month, &newProduct.dateAdded.year);

        printf("%s", "Enter the date modified(day, month, year): \n");
        scanf("%d %d %d", &newProduct.lastModifiedDate.day, &newProduct.lastModifiedDate.month, &newProduct.lastModifiedDate.year);

        printf("%s", "Is this product active (1: yes, 0: no): \n");
        scanf("%d", &newProduct.isActive);

        newProduct.productID = productID;
        

        fseek(ptr, (productID - 1) * sizeof(struct Product), SEEK_SET);

        fwrite(&newProduct, sizeof(struct Product), 1, ptr);

    }
    return;
}

void displayProducts(FILE *ptr){

    int recordFound = 0;
    struct Product readItem= {0, "", "", 0.0, "", 0, 0, 0, {0, 0, 0}, "", {0, 0, 0}, {0, 0, 0}, false};
    rewind(ptr);
    while(!feof(ptr))
    {
        int result=fread(&readItem,sizeof(struct Product),1,ptr);
        if(result!=0&&readItem.productID!=0)
        {
            printf("%d %s %s %f %s %d %d %d %dx%dx%d %s %d/%d/%d %d/%d/%d %d \n",readItem.productID,readItem.productName,readItem.description,readItem.price, readItem.sku, readItem.categoryID, readItem.stockQuantity, readItem.weight, readItem.dimension.height, readItem.dimension.length, readItem.dimension.width, readItem.manufacturer, readItem.dateAdded.day, readItem.dateAdded.month, readItem.dateAdded.year, readItem.lastModifiedDate.day, readItem.lastModifiedDate.month, readItem.lastModifiedDate.year, readItem.isActive);
            recordFound = 1;
        }
    }
    if (recordFound==0)printf("No record found in the file\n\n\n");
}

void findRecord(FILE *ptr){
    printf("Enter the product ID\n");
    int recordNum;
    scanf("%d",&recordNum);
    rewind(ptr);
    fseek(ptr,(recordNum-1)*sizeof(struct Product),SEEK_SET);
    struct Product item= {0, "", "", 0.0, "", 0, 0, 0, {0, 0, 0}, "", {0, 0, 0}, {0, 0, 0}, false};
    fread(&item,sizeof(struct Product),1,ptr);
    if(item.productID==0||item.productID!=recordNum)
    {
        printf("Record Does Not Exist\n");
    }
    else
    {
        display(item);
    }
}

void updateProduct(FILE *ptr) {
    printf("Please enter the product ID number: \n");
    int recordNum = 0;
    scanf("%d", &recordNum);
    fseek(ptr,(recordNum-1)*sizeof(struct Product),SEEK_SET);
    struct Product item= {0, "", "", 0.0, "", 0, 0, 0, {0, 0, 0}, "", {0, 0, 0}, {0, 0, 0}, false};
    fread(&item,sizeof(struct Product),1,ptr);

    if(item.productID==0||item.productID!=recordNum){
        printf("A record of this item does not exist\n");
    }else{
        printf("%s", "Please enter this item's new quantity and cost: \n");
        scanf("%d%lf", &item.stockQuantity, &item.price);
        fseek(ptr, (recordNum - 1) * sizeof(struct Product), SEEK_SET);
        fwrite(&item, sizeof(struct Product), 1, ptr);
    }

}

void deleteProduct(FILE *ptr){
    printf("%s", "Please enter the product ID to be deleted\n");
    int recordNum = 0;
    scanf("%d", &recordNum);
    fseek(ptr, (recordNum - 1) * sizeof(struct Product), SEEK_SET);
    struct Product item= {0, "", "", 0.0, "", 0, 0, 0, {0, 0, 0}, "", {0, 0, 0}, {0, 0, 0}, false};
    fread(&item,sizeof(struct Product),1,ptr);
    if(item.productID==0||item.productID!=recordNum){
        printf("This item does not exist");
    }else{
        struct Product blankItem = {0, "", "", 0.0, "", 0, 0, 0, {0, 0, 0}, "", {0, 0, 0}, {0, 0, 0}, false};
        fseek(ptr, (recordNum - 1) * sizeof(struct Product), SEEK_SET);
        fwrite(&blankItem, sizeof(struct Product), 1, ptr);
    }

}

void display(struct Product p) {

	printf("%d %s %s %f %s %d %d %d %dx%dx%d %s %d/%d/%d %d/%d/%d %d\n", p.productID,p.productName,p.description,p.price, p.sku, p.categoryID, p.stockQuantity, p.weight, p.dimension.height, p.dimension.length, p.dimension.width, p.manufacturer, p.dateAdded.day, p.dateAdded.month, p.dateAdded.year, p.lastModifiedDate.day, p.lastModifiedDate.month, p.lastModifiedDate.year, p.isActive);
    }

unsigned int userOption(void){
    unsigned int option=0;
    printf("Please enter your choice\n"
           "1. Add product\n"
           "2. Display product\n"
           "3. Find by product ID\n"
           "4. Update product\n"
           "5. Delete product\n"
           "6. Sort by price\n"
           "7. Filter products\n"
           "8. Export to CSV file\n"
           "9. Exit\n");
    scanf("%d",&option);

    return option;
}