#include <iostream>
#include <stack>

using namespace std;

// Nó da lista encadeada
struct Node {
    int data;
    Node* next;
};

// Pilha implementada como lista encadeada
class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cerr << "Pilha vazia! Não é possível desempilhar." << endl;
            return -1; // Valor inválido para indicar erro
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

// Pilha implementada como vetor
class ArrayStack {
private:
    static const int MAX_SIZE = 30;
    int arr[MAX_SIZE];
    int top;

public:
    ArrayStack() : top(-1) {}

    void push(int value) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = value;
        } else {
            cerr << "Pilha cheia! Não é possível empilhar." << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cerr << "Pilha vazia! Não é possível desempilhar." << endl;
            return -1; // Valor inválido para indicar erro
        }
        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    LinkedListStack parStack; // Pilha para números pares
    LinkedListStack imparStack; // Pilha para números ímpares
    ArrayStack mergedStack; // Pilha para a sequência decrescente

    cout << "Digite 30 números inteiros (em ordem crescente):" << endl;
    for (int i = 0; i < 30; ++i) {
        int num;
        cin >> num;

        if (i > 0 && num <= mergedStack.pop()) {
            cerr << "Número inválido! Deve ser maior do que o anterior." << endl;
            return 1;
        }

        if (num % 2 == 0) {
            parStack.push(num);
        } else {
            imparStack.push(num);
        }

        mergedStack.push(num);
    }

    cout << "\nNúmeros desempilhados (sequência decrescente):" << endl;
    while (!parStack.isEmpty()) {
        cout << parStack.pop() << " ";
    }
    while (!imparStack.isEmpty()) {
        cout << imparStack.pop() << " ";
    }
    cout << endl;

    return 0;
}