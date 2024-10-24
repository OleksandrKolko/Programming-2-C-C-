#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char surname[30];
    char name[30];
    char middle[30];
    char sex[10];
    int age;
    int course;
}Student;

Student input_student(Student* student) {
    printf("Enter surname: \n");
    scanf("%s", student->surname);
    printf("Enter name: \n");
    scanf("%s", student->name);
    printf("Enter middle name: \n");
    scanf("%s", student->middle);
    printf("Enter sex (male/female): \n");
    scanf("%s", student->sex);
    printf("Enter age: \n");
    scanf("%d", &student->age);
    printf("Enter course: \n");
    scanf("%d", &student->course);

    return *student;
}

void output_student(const Student* student) {
    printf("Student: %s %s %s, Sex: %s, Age: %d, Course: %d\n",
           student->surname, student->name, student->middle, student->sex, student->age, student->course);
}

void find_most_common_names(Student students[], int n) {
    int male_count[100] = {0}, female_count[100] = {0};
    char male_names[100][30], female_names[100][30];
    int male_total = 0, female_total = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].sex, "male") == 0) {
            int found = 0;
            for (int j = 0; j < male_total; j++) {
                if (strcmp(students[i].name, male_names[j]) == 0) {
                    male_count[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(male_names[male_total], students[i].name);
                male_count[male_total++] = 1;
            }
        } else if (strcmp(students[i].sex, "female") == 0) {
            int found = 0;
            for (int j = 0; j < female_total; j++) {
                if (strcmp(students[i].name, female_names[j]) == 0) {
                    female_count[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(female_names[female_total], students[i].name);
                female_count[female_total++] = 1;
            }
        }
    }

    int max_male_idx = 0, max_female_idx = 0;
    for (int i = 1; i < male_total; i++) {
        if (male_count[i] > male_count[max_male_idx]) {
            max_male_idx = i;
        }
    }
    for (int i = 1; i < female_total; i++) {
        if (female_count[i] > female_count[max_female_idx]) {
            max_female_idx = i;
        }
    }

    printf("Most common male name: %s\n", male_names[max_male_idx]);
    printf("Most common female name: %s\n", female_names[max_female_idx]);
}

void find_most_common_age(Student students[], int n) {
    int age_count[100] = {0};
    int ages[100];
    int age_total = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < age_total; j++) {
            if (students[i].age == ages[j]) {
                age_count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            ages[age_total] = students[i].age;
            age_count[age_total++] = 1;
        }
    }

    int max_age_idx = 0;
    for (int i = 1; i < age_total; i++) {
        if (age_count[i] > age_count[max_age_idx]) {
            max_age_idx = i;
        }
    }

    printf("Most common age: %d\n", ages[max_age_idx]);
    printf("Students with age %d:\n", ages[max_age_idx]);

    for (int i = 0; i < n; i++) {
        if (students[i].age == ages[max_age_idx]) {
            printf("%s %s, age %d, course %d\n", students[i].surname, students[i].name, students[i].age, students[i].course);
        }
    }
}
int main() {
    int n;
    printf("Enter number of students: \n");
    scanf("%d", &n);

    Student students[n];

    for (int i = 0; i < n; i++) {
        printf("\nEntering details for student %d:\n", i + 1);
        input_student(&students[i]);
    }

    find_most_common_names(students, n);
    find_most_common_age(students, n);
}
