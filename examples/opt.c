int printf(char const *format, ...);

int main() {
    int x = 0;
    int y = 3+6+x;
    int z = 0;
    // This will be cleaned up
    if (0 && y) {
        z = 100;
    } else {
        z = 50;
    }
    printf("%d\n",z);
    return z;
    // This deadcode will be removed
    for(x = 0; x < z; x = x+1) {
        printf("%d\n",x);
    }
}