#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Пункт e)

typedef struct Book {
    char cypher[50];
    char author[50];
    char title[50];
}Book;

typedef struct Reader {
    int num_ticket;
    char surname[50];
}Reader;

typedef struct Date {
    int day;
    int month;
    int year;
}Date;

typedef struct Form {
    Book book;
    Reader reader;
    Date date;
}Form;


void output_book(Book book) {
    printf("Information of book: \n");
    printf("Cypher name: %s\n", book.cypher);
    printf("Author: %s\n", book.author);
    printf("Title: %s\n", book.title);
}

Book input_book(Book* book) {
    printf("Information of book: \n");
    printf("Please enter a cypher: \n");
    scanf("%s", book->cypher);
    printf("Please enter a author: \n");
    scanf("%s", book->author);
    printf("Please enter a title: \n");
    scanf("%s", book->title);
}

void output_reader(Reader reader) {
    printf("Information of reader: \n");
    printf("Number of ticket: %d\n", reader.num_ticket);
    printf("Surname: %s\n", reader.surname);
}

Reader input_reader(Reader* reader) {
    printf("Please enter a number of ticket: \n");
    scanf("%d", &reader->num_ticket);
    printf("Please enter your surname: \n");
    scanf("%s", reader->surname);
}

void output_date(Date date) {
    printf("Information of date: \n");
    printf("%d.%d.%d", date.day, date.month, date.year);
}

Date input_date(Date* date) {
    printf("Please enter a date: \n");
    scanf("%d %d %d", &date->day, &date->month, &date->year);
}

void output_form(Form form) {
    printf("Information of form: \n");
    output_book(form.book);
    output_reader(form.reader);
    output_date(form.date);
}

Form input_form(Form* form) {
    printf("Please enter an information of your form: \n");
    input_book(&form->book);
    input_reader(&form->reader);
    input_date(&form->date);
}

int main() {
    Form form;
    input_form(&form);
    output_form(form);
}