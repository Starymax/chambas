#include <iostream>
using namespace std;

void merge(int arr[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[medio + 1 + j];
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]){
            arr[k] = L[i];
            i++;
        }  else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;
        mergeSort(arr, inicio, mitad);
        mergeSort(arr, mitad + 1, fin);
        merge(arr, inicio, mitad, fin);
    }
}

void imprimeArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    cout << "Arreglo ordenado: "<<endl;
    imprimeArr(arr, size);
    getchar();
    return 0;
}