int printf(char const *format, ...);

int main(){
    int x = 0;
    label: {
        x = x+1;
    }
    if (x<10) {
        goto label;
    }
    printf("%d\n",x);
    return x;
}