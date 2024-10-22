#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Date {
    int day;
    int month;
    int year;
}Date;

struct Cell {
    unsigned char horizontal;
    char vertical;
};

typedef struct Vertex {
    long double x;
    long double y;
}Vertex;

typedef struct Rectangle {
    Vertex v1;
    Vertex v2;
}Rectangle;

typedef struct Poly {
    unsigned n;
    double* a;
}Poly;

void output_date(Date d) {
    printf("%d %d %d", d.day, d.month, d.year);
}

void output_cell(struct Cell c) {
    printf("%c%ssh\n", c.vertical, c.horizontal);
}

void output_vertex(struct Vertex v) {
    printf("(%lg, %lg)", v.x, v.y);
}

void output_rectangle(const Rectangle* r) {
    output_vertex(r->v1);
    printf("\t\n");
    output_vertex(r->v2);
}

void output_poly(Poly p) {
    for(int i = 0; i < p.n; i++) {
        printf("%lf*x^%d + ", p.a[i], i);
    }
    printf("%lf*x^%d", p.a[p.n], p.n);
}

Vertex input_vertex() {
    Vertex v;
    printf("x, y = \n");
    scanf("%lg %lg", &v.x, &v.y);
    return v;
}


int input_poly(Poly* p) {
    printf("Enter n: \n");
    scanf("%d", &p->n);
    p->a = (double*) calloc(p->n + 1, sizeof(*(p->a)));
    for(int i = 0; i < (p->n + 1); i++) {
        printf("a[%d] = \n", i);
        scanf("%lf", &(p->a[i]));
    }
    return 0;
}

void delete_poly(Poly* p) {
    if(p->a) {
        free(p->a);
    }
}

int input_rectangle(Rectangle* r) {
    r->v1 = input_vertex();
    r->v2 = input_vertex();
    return 0;
}

int input_cell(struct Cell* c) {
    printf("Enter vertical: \n");

    scanf("%c", &c->vertical);
    printf("Enter horizontal: \n");
    scanf("%ssh", &c->horizontal);

    if (c->vertical >= 'a'&&
        c->vertical <= 'h'||
        c->vertical >= 'A'&&
        c->vertical <= 'H'&&
        c->horizontal >= 1&&
        c->horizontal<= 8) {
        return 1;
    }
    return 0;
}

int input_date(Date* d) {
    printf("Input date: \n");
    int n = scanf("%d %d %d", &d -> day, &d -> month, &d -> year);
    return n;
}

int task2_hit_queen(struct Cell f1, struct Cell f2) {
    if((f1.horizontal == f2.horizontal)||
        (f1.vertical == f2.vertical)||
        (fabs(f1.vertical - f2.vertical) == fabs(f2.horizontal - f2.vertical))) {
        return 1;
    }
    return 0;
}


int main() {
    Poly p;
    input_poly(&p);
    output_poly(p);
    delete_poly(&p);
}