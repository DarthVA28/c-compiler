int printf(char const *format, ...);

int bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i = i + 1) {
        for (j = 0; j < n - i - 1; j = j + 1) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }   
        }
    }   
    return 0;
}

int main() {
    int x[10] = {6,7,8,2,3,4,5,1,2,3};
    bubbleSort(x,10);
    int i;
    for (i = 0; i < 10; i = i + 1) {
        printf("%d\n",x[i]);
    }
    return 0;
}