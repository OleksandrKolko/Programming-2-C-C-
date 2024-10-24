#include <stdio.h>
#include <math.h>
int main() {
    const char* fname = "file_1";
    FILE * f = fopen(fname, "wb");
    if (f==NULL) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }

    int n;
    printf("n = \n");
    scanf("%d", &n);
    double x;
    for (int i = 0; i < n; i++) {
        printf("x = \n");
        scanf("%lf", &x);
        fwrite(&x, sizeof(x), 1, f);
    }
    fclose(f);

    double a;
    printf("a = \n");
    scanf("%lf", &a);
    f = fopen(fname, "rb");
    double mas[10];
    const char * fname2 = "file2";
    FILE * g = fopen(fname2, "wb");
    int i = 0;
    int k = 0;

    while(1) {
        if(feof(f)) {
            break;
        }
        fread(&x, sizeof(double), 1, f);
        if (fabs(x) < a) {
            fwrite(&x, sizeof(double), 1, g);
        }
        else {
            mas[k++] = x;
        }
        i++;
    }
    fclose(f);
    fclose(g);

    g = fopen(fname2, "rb");
    i = 0;
    while(1) {
        if(feof(g)) {break;}
        fread(&x, sizeof(double), 1, g);
        printf("x%d = %lf\n", i++, x);
    }
    fclose(g);

    f = fopen(fname, "wb");
    fwrite(mas, sizeof(double), k, f);
    f = freopen(fname, "rb", f);
    i = 0;
    while(1) {
        if(feof(f)) {break;}
        fread(&x, sizeof(double), 1, f);
        printf("x%d = %lf\n", i++, x);
    }
    fclose(f);
}