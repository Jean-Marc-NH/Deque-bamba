#include <iostream>
using namespace std;

template<class T>
struct nodo {
    T valor[5];
    nodo<T>* next;
    T* p;

    nodo(T v, nodo<T>* n = nullptr) {
        valor[0] = v;
        next = n;
        p = valor;
    }
};

template<class T>
struct deque
{
    T* top;
    int count;
    nodo<T>* top2;

    deque() {
        top = nullptr;
        count = 0;
        top2 = nullptr;
    }

    void push(int v) {
        if (!top) {
            top2 = new nodo<T>(v, top2);
            top = top2->p;
        }
        else {
            if (count % 5 != 0) {
                top++;
                *top = v;
            }
            else {
                top2 = new nodo<T>(v, top2);
                top = top2->p;
                *top = v;
            }
        }

        count++;
    }

    void print() {

        nodo<T>* aux2 = top2;
        T* aux = top;
        int size = count;

        cout << " TOP -> ";

        while (size) {
            cout << *aux << " ";

            aux--;

            if (size > 1 &&(size % 5 == 1)) {
                aux2 = aux2->next;
                aux = aux2->p;
                aux += 4;
                cout << "-> ";

            }
            size--;



            
        }

        cout << "-> NULL";
    }

    int size() {
        return count;
    }

    void pop() {
        nodo<T>* aux;
        if ((count % 5) != 1) {
            top = top - 1;
        }
        else {
            aux = top2;
            top2 = top2->next;
            if (top2) {
                top = top2->p;
            }
            else {
                top = nullptr;
            }
            top += 4;

            delete aux;
        }
        count -= 1;
    }
};

int main()
{
    deque<int> a;

    a.push(1);
    a.push(12);
    a.push(1);
    a.push(14);
    a.push(1);
    a.push(15);
    a.push(1);
    a.push(19);

    a.print();

    a.pop();
    a.pop();

    a.print();
}
