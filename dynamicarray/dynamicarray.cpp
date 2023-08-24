#include <iostream>
#include <cstdlib> // Include this header for malloc function

struct DynArrayStack {
    int capacity;
    int top;
    int* array;
};

struct DynArrayStack* CreateStack() {
    struct DynArrayStack* S = (struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
    // Check if memory allocation was successful
    if (S == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        exit(EXIT_FAILURE);
    }
    S->capacity = 1;
    S->top = -1;
    S->array = (int*)malloc(S->capacity * sizeof(int));
    return S;
}

int IsFullStack(struct DynArrayStack* S) {
    return(S->top == S->capacity - 1);
}

void DoubleStack(struct DynArrayStack* S) {
    S->capacity *= 2;
    S->array =(int*) realloc(S->array, S->capacity * sizeof(int));
}

void Push(struct DynArrayStack* S, int x) {
    if (IsFullStack(S)) {
        DoubleStack(S);
    }
    S->array[++S->top] = x;
}

int IsEmptyStack(struct DynArrayStack* S) {
    return S->top == -1;
}

int Top(struct DynArrayStack* S) {
    if (IsEmptyStack(S)) {
        return INT_MIN;
    }
    return S->array[S->top];
}

int Pop(struct DynArrayStack* S) {
    if (IsEmptyStack(S)) {
        return INT_MIN;
    }
    return S->array[S->top--];
}

void DeleteStack(struct DynArrayStack* S) {
    if (S && S->array) {
        free(S->array);
    }
    free(S);
}



int main() {
    struct DynArrayStack* stack = CreateStack();
    std::cout << "Stack created successfully." << std::endl;

    // Don't forget to free the memory when you're done
    free(stack);

    return 0;
}
