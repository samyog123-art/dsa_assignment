#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Print array
void printArray(int a[], int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

// Bubble sort
void bubbleSort(int a[], int n, int *comp, int *swap){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            (*comp)++;
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                (*swap)++;
            }
        }
}

// Selection sort
void selectionSort(int a[], int n, int *comp, int *swap){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            (*comp)++;
            if(a[j]<a[min]) min=j;
        }
        if(min!=i){
            int t=a[i]; a[i]=a[min]; a[min]=t;
            (*swap)++;
        }
    }
}

// Insertion sort
void insertionSort(int a[], int n, int *comp, int *swap){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0){
            (*comp)++;
            if(a[j]>key){
                a[j+1]=a[j]; (*swap)++;
                j--;
            } else break;
        }
        a[j+1]=key;
    }
}

// Merge sort functions
void merge(int a[], int l, int m, int r, int *comp, int *swap){
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        (*comp)++;
        if(L[i]<=R[j]) a[k++]=L[i++];
        else { a[k++]=R[j++]; (*swap)++; }
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r, int *comp, int *swap){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(a,l,m,comp,swap);
        mergeSort(a,m+1,r,comp,swap);
        merge(a,l,m,r,comp,swap);
    }
}

int main(){
    int n;
    printf("Enter number of numbers: ");
    scanf("%d",&n);

    int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++) arr[i]=rand()%1000+1; // generate random numbers

    printf("Numbers before sorting:\n");
    printArray(arr,n);

    int choice, comp=0, swap=0;
    printf("\nChoose sorting method:\n1.Bubble 2.Selection 3.Insertion 4.Merge\n");
    scanf("%d",&choice);

    // Run chosen sort
    if(choice==1) bubbleSort(arr,n,&comp,&swap);
    else if(choice==2) selectionSort(arr,n,&comp,&swap);
    else if(choice==3) insertionSort(arr,n,&comp,&swap);
    else if(choice==4) mergeSort(arr,0,n-1,&comp,&swap);
    else { printf("Invalid choice\n"); return 0; }

    printf("Numbers after sorting:\n");
    printArray(arr,n);

    printf("Total comparisons: %d\nTotal swaps: %d\n",comp,swap);

    return 0;
}
