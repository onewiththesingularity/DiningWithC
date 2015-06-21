/* okay is this good so far */
/* here is a sample struct in C: */

//once selected, press M-; // sorry...
/* struct Books */
/* { */
/*     char  title[50];    // this is a title field with a max length of 50 */
/*     char  author[50];   // same for author */
/*     char  subject[100]; */
/*     int   book_id;      // we might have to use a "float" instead of "int" */
/* } book; <--? necessary? nope; <-- semicolon doe*/


/* int main( ) */
/* { */
/*     struct Books book1;        /\* Declare Book1 of type Book *\/ */
/*     strcpy( book1.title, "C Programming"); */
/*     Book1.book_id = 6495407; */

/*     /\* print Book1 info *\/ */
/*     printf( "Book 1 title : %s\n", Book1.title); */
/*     printf( "Book 1 author : %s\n", Book1.author); */
/*     printf( "Book 1 subject : %s\n", Book1.subject); */
/*     printf( "Book 1 book_id : %d\n", Book1.book_id); */
/* } */

/* int myArray[3] = {20, 40, 60}; */
/* printf("myArray[1] + myArray[2] = %d", */
/*        *(myArray+1) + *(myArray+2)); */

# include "stdio.h"
# include "string.h"

struct Entry {
    char mealName[100];
    float price;
};


// takes the parameters for the item and returns a struct

struct Entry createEntry (char*name, float price) {
    struct Entry item;
    strcpy( item.mealName, name);
    item.price = price;
    return item;
} 

// Prompt for user input. Will accept numbers separated by comma

void userInput (struct Entry *menu) {
    // storage object for user input:
    char stringCache[100];
    char *token;
    long selection;
    float yourTotal = 0;

    // Read in user input
    printf("Enter your choices as numbers: ");
    scanf ("%s", stringCache);

    token = strtok (stringCache, ",");
    while (token != NULL) {
        // Do something with the token
        selection = strtol(token, NULL, 10);
        printf("Selected [%lu]: %s\n", selection, menu[selection-1].mealName);
        yourTotal += menu[selection-1].price;
        token = strtok (NULL, ",");
    }
    printf("Your total is: %.2f\n", yourTotal);
}

//  MAIN MAIN MAIN

int main ( ) {

    struct Entry menuArray[2] = {
        createEntry("Shrimp Alfredo", 14.99),
        createEntry("Beef Tacos", 9.99)
    };


    // Well, you now have an array. We need to iterate through it somehow.
    // Consider using a for loop
    
    int i;
        
    for (i = 0 ; i < (sizeof(menuArray)/sizeof(struct Entry)); ++i) {    
        printf("[%d]: %s \t $%.2f \n", i + 1, menuArray[i].mealName, menuArray[i].price);
    }

    userInput(menuArray);
    return 0;
}
    
    











