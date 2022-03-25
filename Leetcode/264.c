struct heap {
    int size;
    long long *elements;
};
typedef struct heap Heap;

Heap* createEmptyHeap(int size) {
    Heap *h = (Heap *) malloc(sizeof(Heap));
    h->size = 0;
    h->elements = (long long *) malloc(sizeof(long long) * size);
    return h;
}

void deleteHeap(Heap *h) {
    free(h->elements);
    free(h);
    h = NULL;
}

void insertHeap(Heap *h, long long val) {
    int hole = h->size;
    int parent = (hole - 1) / 2;
    
    while (hole > 0 && (val < h->elements[parent])) {
        h->elements[hole] = h->elements[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    h->elements[hole] = val;
    h->size++;
}

int deleteMin(Heap *h) {
    long long output = h->elements[0];
    long long last = h->elements[h->size - 1];
    int hole = 0;
    int child = 1;
    
    
    
    while (child + 1 < h->size) {
        if (h->elements[child] > h->elements[child + 1]) {
            child++;
        }
        if (last < h->elements[child]) {
            break;
        }
        
        h->elements[hole] = h->elements[child];
        hole = child;
        child = hole * 2 + 1;
    }
    
    h->elements[hole] = last;
    h->size--;
    return output;
}

int nthUglyNumber(int n){
    Heap *h = createEmptyHeap(n * 3 + 1);
    
    insertHeap(h, 1);
    long long cur;
    long long last = -1;
    while (n > 0) {
        cur = deleteMin(h);
        if (last != cur) {
            insertHeap(h, cur * 2);
            insertHeap(h, cur * 3);
            insertHeap(h, cur * 5);
            n--;  
            last = cur;
        }
    }
    
    deleteHeap(h);
    return cur;
}