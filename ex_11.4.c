#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int id;
    double x1, y1;
    double x2, y2;
} Rectangle;


double rectangle_area(Rectangle rect) {
    return fabs((rect.x2 - rect.x1) * (rect.y2 - rect.y1));
}


void write_rectangles_to_file(char *file_name, int n) {
    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        Rectangle rect;
        printf("Enter rectangle %d ID: ", i + 1);
        scanf("%d", &rect.id);
        printf("Enter coordinates (x1, y1) of the top-left corner: ");
        scanf("%lf %lf", &rect.x1, &rect.y1);
        printf("Enter coordinates (x2, y2) of the bottom-right corner: ");
        scanf("%lf %lf", &rect.x2, &rect.y2);

        fwrite(&rect, sizeof(Rectangle), 1, fp);
    }

    fclose(fp);
}


void find_largest_area(char *file_name) {
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    Rectangle rect;
    Rectangle largest_rect;
    double max_area = -1;

    while (fread(&rect, sizeof(Rectangle), 1, fp)) {
        double area = rectangle_area(rect);
        if (area > max_area) {
            max_area = area;
            largest_rect = rect;
        }
    }

    if (max_area != -1) {
        printf("Rectangle with the largest area:\n");
        printf("ID: %d, Area: %.2lf\n", largest_rect.id, max_area);
        printf("Top-left corner: (%.2lf, %.2lf), Bottom-right corner: (%.2lf, %.2lf)\n",
               largest_rect.x1, largest_rect.y1, largest_rect.x2, largest_rect.y2);
    } else {
        printf("No rectangles in the file.\n");
    }

    fclose(fp);
}


void delete_rectangle_by_id(char *file_name, int id_to_delete) {
    FILE *fp = fopen(file_name, "rb");
    FILE *temp_fp = fopen("temp.bin", "wb");
    if (fp == NULL || temp_fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Rectangle rect;
    int found = 0;

    while (fread(&rect, sizeof(Rectangle), 1, fp)) {
        if (rect.id != id_to_delete) {
            fwrite(&rect, sizeof(Rectangle), 1, temp_fp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp_fp);


    remove(file_name);
    rename("temp.bin", file_name);

    if (found) {
        printf("Rectangle with ID %d deleted.\n", id_to_delete);
    } else {
        printf("Rectangle with ID %d not found.\n", id_to_delete);
    }
}


void replace_rectangle_by_index(char *file_name, int index) {
    FILE *fp = fopen(file_name, "rb+");
    if (fp == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }

    fseek(fp, sizeof(Rectangle) * index, SEEK_SET);

    Rectangle new_rect;
    printf("Enter new rectangle ID: ");
    scanf("%d", &new_rect.id);
    printf("Enter new coordinates (x1, y1) of the top-left corner: ");
    scanf("%lf %lf", &new_rect.x1, &new_rect.y1);
    printf("Enter new coordinates (x2, y2) of the bottom-right corner: ");
    scanf("%lf %lf", &new_rect.x2, &new_rect.y2);

    fwrite(&new_rect, sizeof(Rectangle), 1, fp);

    fclose(fp);
}

int main() {
    char *file_name = "rectangles.bin";

    int n;
    printf("Enter number of rectangles: ");
    scanf("%d", &n);


    write_rectangles_to_file(file_name, n);


    find_largest_area(file_name);

    int id_to_delete;
    printf("Enter rectangle ID to delete: ");
    scanf("%d", &id_to_delete);
    delete_rectangle_by_id(file_name, id_to_delete);

    int index_to_replace;
    printf("Enter the index of the rectangle to replace (0-based): ");
    scanf("%d", &index_to_replace);
    replace_rectangle_by_index(file_name, index_to_replace);

    return 0;
}
