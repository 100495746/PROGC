//
// Created by Raúl Armas Seriñá on 5/2/24.
//

#include <stdlib.h>
#include <printf.h>
#include <string.h>


int main() {
    int nums[3][2] = {
            {1, 2},
            {3, 4},
            {5, 6}
            //we need to declare the variable and specify  the total elements (as seen above)
    };
    printf("%d\n", nums[1][0]);
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }


    return 0;
}