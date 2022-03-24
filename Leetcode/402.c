struct stack {
    int size;
    int *elements;
};
typedef struct stack Stack;

Stack* createEmptyStack(int num) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->size = 0;
    s->elements = (int *) malloc(sizeof(int) * (num + 1));
    return s;
}

void push(Stack *s, int val) {
    s->elements[s->size] = val;
    s->size++;
    return ;
}

int pop(Stack *s) {
    int output = s->elements[s->size - 1];
    s->size--;
    return output;
}

int min(int a, int b) {
    return (a < b ? a : b);
}

void deleteStack(Stack *s) {
    free(s->elements);
    free(s);
    s = NULL;
    return;
}

char * removeKdigits(char * num, int k){
    Stack *s = createEmptyStack(strlen(num));
    for (int i = 0; num[i] != '\0'; ++i) {
        int val = num[i] - '0';
        if (s->size == 0 || k == 0) {
            push(s, val);
        }
        else {
            while (s->size > 0) {
                if (k == 0) {
                    push(s, val);
                    break;
                }
                int top = pop(s);
                if (val >= top) {
                    push(s, top);
                    push(s, val);
                    break;
                }
                else {
                    k--;
                }
            }
            if (s->size == 0) {
                push(s, val);
            }
        }
    }
    
    while (k > 0) {
        pop(s);
        k--;
    }
    
    if (s->size == 0) push(s, 0);
    
    char *res = (char *) malloc(sizeof(char) * (s->size + 10));
    res[s->size] = '\0';
    int idx = 0;
    while (s->size != 0) {
        int val = pop(s);
        char c = '0' + val;
        res[idx++] = c;
    }
    
    
    while (idx > 1 && res[idx - 1] == '0') {
        res[idx - 1] = '\0';
        idx--;
    }
    
    
    // reverse string
    for (int i = 0; i < idx / 2; ++i) {
        char temp = res[i];
        res[i] = res[idx - i - 1];
        res[idx - i - 1] = temp;
    }
    
    
    deleteStack(s);
    
    return res;
}