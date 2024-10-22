#include <stdio.h>
#include <string.h>
#define LEN 255

typedef struct Mountain {
    char name[LEN];
    int height;
} Mountain;

Mountain highest(const Mountain* m, int n) {
    Mountain highest_mountain = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i].height > highest_mountain.height) {
            highest_mountain = m[i];
        }
    }

    return highest_mountain;
}

int main() {
    int n;


    printf("Enter the number of mountains: \n");
    scanf("%d", &n);

    Mountain mountains[n];


    for (int i = 0; i < n; i++) {
        printf("Enter the name of mountain %d: \n", i + 1);
        scanf("%s", mountains[i].name);
        printf("Enter the height of mountain %d (in meters): \n", i + 1);
        scanf("%d", &mountains[i].height);
    }

    Mountain highest_mountain = highest(mountains, n);

    printf("The highest mountain is %s with a height of %d meters.\n", highest_mountain.name, highest_mountain.height);

}
