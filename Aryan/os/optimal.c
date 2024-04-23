/* 
Name : WAGH ARYAN ANIL
Class : SE AIML 
RollNO :- 53
Problem Statement:  Implement the C program for Page Replacement Algorithms: FCFS, LRU, and Optimal for 
frame size as minimum three.
*/
#include <stdio.h>

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1 = 0, flag2 = 0, flag3 = 0, i, j, k, pos, max, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");

    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j) {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k) {
                    if (frames[j] == pages[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j) {
                if (temp[j] == -1) {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0) {
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j) {
                    if (temp[j] > max) {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for (j = 0; j < no_of_frames; ++j) {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
/*
error@DESKTOP-OFL03QL:~$ cd 'OS code'
error@DESKTOP-OFL03QL:~/OS code$ gcc optimal.c -o abc
error@DESKTOP-OFL03QL:~/OS code$ ./abc
Enter number of frames: 3
Enter number of pages: 10
Enter page reference string: 1 2 3 5 6 2 3 4 7 2

1       -1      -1
1       2       -1
1       2       3
5       2       3
6       2       3
6       2       3
6       2       3
4       2       3
7       2       3
7       2       3

Total Page Faults = 7
*/