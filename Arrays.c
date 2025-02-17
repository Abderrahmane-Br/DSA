#include "stdlib.h"
#include "stdio.h"

int max(int line[], int size);
int min(int line[], int size);


int main() {
    // const int N = 5;
    int arr[][] = {{9, 5, 7, 5},
                    {4,2,2,3},{4,3,3,2},{8,5,6,5},{7,4,10,4}};

    int i,j;
    for (i=0; i<4; i++) {
        int mini = min(arr[i][], 4);
        for (j=0; j<5; j++) {
            int maxi = max(arr[][j], 5);
            if(arr[i][j] == mini && arr[i][j] == maxi)
                print("col %d at %d %d", mini, i, j);
        }
    }
}

max(int line[], int size) {
    int index = 0;
    int i;
    for (i=0; i<size; i++) {
        if(line[index]<line[i])
            index = i;
    }
    return line[index];
}

min(int line[], int size) {
    int index = 0;
    int i;
    for (i=0; i<size; i++) {
        if(line[index]>line[i])
            index = i;
    }
    return line[index];
}