#include <iostream>

namespace Our {
    template <class T = int>
    struct Node {
        T data;
        Node* prt;
    };

    template <typename T = int>
    class Stack {
        size_t n;
        Node<T>* current;
    public:
        Stack() : n(0), current(nullptr) {}

        void push(T x);
        void pop();
        size_t len() { return n; }
        T top();
        bool is_empty() { return current == nullptr; }

        void show() {
            while (!is_empty()) {
                std::cout << top() << " ";
                pop();
            }
            std::cout << "\n\n";
        }
    };

    template <typename T>
    void Stack<T>::push(T x) {
        Node<T>* z = new Node<T>();
        z->data = x;
        z->prt = current;
        current = z;
        n++;
    }

    template <typename T>
    void Stack<T>::pop() {
        if (is_empty()) return;
        Node<T>* temp = current;
        current = current->prt;
        delete temp;
        n--;
    }

    template <typename T>
    T Stack<T>::top() {
        if (is_empty()) throw std::runtime_error("Stack is empty");
        return current->data;
    }
}

int main() {
    Our::Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack elements: ";
    s.show();

    return 0;
}
