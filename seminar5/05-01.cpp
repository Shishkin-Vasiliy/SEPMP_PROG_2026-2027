#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    int pages;
    float price;
};

struct BookDyn {
    char* title;
    int pages;
    float price;
};

struct Library {
    BookDyn* books;
    int number_of_books;
};

void library_create(Library* lib, int n);
void library_set(Library lib, int i, const char* title, int pages, float price);
BookDyn* library_get(Library lib, int i);
void library_print(Library lib);
void library_destroy(Library* lib);

int main(void)
{
    size_t* a = (size_t*)calloc(1, sizeof(size_t));
    *a = 123;
    printf("%zu\n", *a);
    free(a);

    char* b = (char*)calloc(9, sizeof(char)); 
    strcpy(b, "Elephant");
    printf("%s\n", b);
    free(b);

    char** c = (char**)calloc(1, sizeof(char*));
    *c = (char*)calloc(14, sizeof(char));
    strcpy(*c, "Cats and Dogs");
    printf("%s\n", *c);
    free(*c);
    free(c);

    Book* d = (Book*)calloc(1, sizeof(Book));
    strcpy(d -> title, "Don Quixote");
    d -> pages = 1000;
    d -> price = 750;
    print_book(d);
    free(d);

    Book e = {"Don Quixote", 1000, 750}; 
    Book** e = (Book**)calloc(1, sizeof(Book*)); 
    *e = &e; 
    print_book(*e);
    free(e);

    Book** f = (Book**)calloc(1, sizeof(Book*));
    *f = (Book*)calloc(1, sizeof(Book));
    strcpy((*f) -> title, "Don Quixote");
    (*f) -> pages = 1000;
    (*f) -> price = 750.0;
    print_book(*f);
    free(*f);
    free(f);

    Book* g = (Book*)calloc(1, 3 * sizeof(Book));
    strcpy(g[0].title, "Don Quixote"); g[0].pages = 1000; g[0].price = 750.0;
    strcpy(g[1].title, "Oblomov");     g[1].pages = 400;  g[1].price = 250.0;
    strcpy(g[2].title, "The Odyssey"); g[2].pages = 500;  g[2].price = 500.0;
    for (int i = 0; i < 3; i++) 
        print_book(&g[i]);
    free(g);

    BookDyn* h = (BookDyn*)calloc(1, sizeof(BookDyn));
    h -> title = (char*)calloc(12, sizeof(char)); 
    strcpy(h -> title, "Don Quixote");
    h -> pages = 1000;
    h -> price = 750;
    print_book_dyn(h);
    free(h -> title);
    free(h);

    Library a = {};
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);

    print_book_dyn(library_get(a, 1));
    
    library_destroy(&a);

    return 0;
}

void library_create(Library* lib, int n)
{
    lib -> books = (BookDyn*)calloc(n, sizeof(BookDyn));

    if (lib -> books == NULL) {
        return;
    }
    lib -> number_of_books = n;
}

void library_set(Library lib, int i, const char* title, int pages, float price)
{
    lib.books[i].title = (char*)calloc((strlen(title) + 1), sizeof(char));

    strcpy(lib.books[i].title, title);
    lib.books[i].pages = pages;
    lib.books[i].price = price;
}

BookDyn* library_get(Library lib, int i) 
{
    return &lib.books[i];
}

void library_print(Library lib) 
{
    printf("#--- Library ---\n");
    for (int i = 0; i < lib.number_of_books; i++) 
    {
        printf("title: %s  pages: %d  price: %d\n", lib.books[i].title, lib.books[i].pages, lib.books[i].price);
    }
    printf("#---------------\n");
}

void library_destroy(Library* lib) 
{
    for (int i = 0; i < lib -> number_of_books; i++) 
    {
        free(lib -> books[i].title);
    }
    free(lib -> books);
    
    lib -> books = NULL;
    lib -> number_of_books = 0;
}