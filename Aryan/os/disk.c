#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the absolute difference between two integers
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to simulate the SSTF (Shortest Seek Time First) disk scheduling algorithm
void SSTF(int cylinders[], int n, int initial_position) {
    int total_seek_time = 0;
    int current_position = initial_position;

    // Flag to keep track of whether a cylinder has been serviced
    int serviced[n];
    for (int i = 0; i < n; i++) {
        serviced[i] = 0;
    }

    // Repeat until all cylinders are serviced
    while (1) {
        int min_seek = INT_MAX;
        int next_cylinder = -1;

        // Find the nearest cylinder
        for (int i = 0; i < n; i++) {
            if (!serviced[i]) {
                int seek = absDiff(cylinders[i], current_position);
                if (seek < min_seek) {
                    min_seek = seek;
                    next_cylinder = cylinders[i];
                }
            }
        }

        // If no cylinder is found, break the loop
        if (next_cylinder == -1) {
            break;
        }

        // Update total seek time and current position
        total_seek_time += min_seek;
        current_position = next_cylinder;

        // Mark the serviced cylinder
        for (int i = 0; i < n; i++) {
            if (cylinders[i] == next_cylinder) {
                serviced[i] = 1;
                break;
            }
        }
    }

    printf("SSTF Total Seek Time: %d\n", total_seek_time);
}

// Function to simulate the SCAN disk scheduling algorithm
void SCAN(int cylinders[], int n, int initial_position, int direction) {
    int total_seek_time = 0;
    int current_position = initial_position;

    // Sort the cylinders array
    sort(cylinders, n);

    // Find the position of initial_position in the sorted array
    int initial_index = -1;
    for (int i = 0; i < n; i++) {
        if (cylinders[i] >= initial_position) {
            initial_index = i;
            break;
        }
    }

    // If initial_position is not found, set initial_index to 0
    if (initial_index == -1) {
        initial_index = 0;
    }

    // Perform SCAN algorithm
    for (int i = initial_index; i < n && i >= 0; i += direction) {
        total_seek_time += absDiff(cylinders[i], current_position);
        current_position = cylinders[i];
    }

    // If the direction is towards the lower cylinders, go to the lowest cylinder
    if (direction == -1) {
        total_seek_time += current_position;
        current_position = 0;
    }

    printf("SCAN Total Seek Time: %d\n", total_seek_time);
}

// Function to simulate the C-LOOK disk scheduling algorithm
void CLOOK(int cylinders[], int n, int initial_position) {
    int total_seek_time = 0;
    int current_position = initial_position;

    // Sort the cylinders array
    sort(cylinders, n);

    // Find the position of initial_position in the sorted array
    int initial_index = -1;
    for (int i = 0; i < n; i++) {
        if (cylinders[i] >= initial_position) {
            initial_index = i;
            break;
        }
    }

    // If initial_position is not found, set initial_index to 0
    if (initial_index == -1) {
        initial_index = 0;
    }

    // Perform C-LOOK algorithm
    for (int i = initial_index; i < n; i++) {
        total_seek_time += absDiff(cylinders[i], current_position);
        current_position = cylinders[i];
    }

    // Go to the lowest cylinder
    total_seek_time += absDiff(current_position, cylinders[0]);
    current_position = cylinders[0];

    printf("C-LOOK Total Seek Time: %d\n", total_seek_time);
}

int main() {
    int no_of_cylinders, initial_position, no_of_requests;

    printf("Enter the number of cylinders: ");
    scanf("%d", &no_of_cylinders);

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initial_position);

    printf("Enter the number of requests: ");
    scanf("%d", &no_of_requests);

    int cylinders[no_of_requests];

   
