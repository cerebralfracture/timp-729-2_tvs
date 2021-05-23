#include <stdio.h>
#include <stdlib.h>
FILE *file_sort;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int quicksort(int *array, int left, int right, int size) {
    int l = left;
    int r = right;
    int pivot = array[(l + r)/ 2];
    while(l <= r) {
      while(array[l] < pivot) {
        l++;
      }
      while(array[r] > pivot) 
      r--;
      if(l <= r)
      swap(&array[l++], &array[r--]);
      for (int k = 0; k < size; k++) {
        if (k != 0)
        fprintf(file_sort, " "); 
        fprintf(file_sort, "%d", array[k]);
      }
      fprintf(file_sort, "\n");
    }
    if(left < r) {
      quicksort(array, left, r, size);
    }
    if(right > l) {
      quicksort(array, l, right, size);
    }
    return 0;
}


void heapify(int *numbers, int root, int bottom, int size) {
    int max; 
    int done = 0; 
    
    while ((root * 2 <= bottom) && (!done)) {
      if (root * 2 == bottom)    
      max = root * 2;    
      else if (numbers[root * 2] > numbers[root * 2 + 1])
      max = root * 2;
      else
      max = root * 2 + 1;
      if (numbers[root] < numbers[max]) {
      swap(&numbers[max], &numbers[root]);
      root = max;
      for (int k = 0; k < size; k++) {
          if (k != 0)
          fprintf(file_sort, " "); 
          fprintf(file_sort, "%d", numbers[k]);
      }
      fprintf(file_sort, "\n");
      }
      else 
      done = 1;
    }
}


void heapSort(int *numbers, int array_size, int n) {

  for (int i = (array_size / 2); i >= 0; i--)
    heapify(numbers, i, array_size - 1, n);

  for (int i = array_size - 1; i >= 1; i--) {
    swap(&numbers[0], &numbers[i]);
    heapify(numbers, 0, i - 1, n);
  }
}

void read_array(int *a, int *b, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i] = x;
        b[i] = x;
    }
}

void print_array(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n-1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);
    int *array_1 = malloc(size * sizeof(int));
    int *array_2 = malloc(size * sizeof(int));
    read_array(array_1, array_2, size);

    file_sort = fopen("quicksort.log", "w+");  
    fclose(file_sort);
    file_sort = fopen("quicksort.log", "w+");
    quicksort(array_1, 0, size - 1, size);
    for (int k = 0; k < size; k++) {
        if (k != 0)
        fprintf(file_sort, " "); 
        fprintf(file_sort, "%d", array_1[k]);
    }
    fclose(file_sort);
    file_sort = fopen("heapsort.log", "w+"); 
    fclose(file_sort);
    file_sort = fopen("heapsort.log", "w+");
    heapSort(array_2, size, size);
    for (int k = 0; k < size; k++) {
        if (k != 0)
        fprintf(file_sort, " "); 
        fprintf(file_sort, "%d", array_1[k]);
    }
    fclose(file_sort);
    print_array(array_1, size);
    return 0;
}
