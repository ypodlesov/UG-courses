void 
swap(int *a, int *b) 
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int 
unique(int *a, int size) 
{
    int src = 1;
    int dst = 1;
    
    while (src < size) {
        if (a[src] == a[src - 1]) {
            ++src;
        } else {
            a[dst++] = a[src++];
        }
    }
    return dst;
}
