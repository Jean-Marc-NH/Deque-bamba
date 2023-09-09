#include <iostream>
using namespace std;

template<class T>
struct nodo{
	T valor[5];
	nodo* next;
	T* end

	nodo(T v, nodo* n = nullptr, T* p = nullptr) {
		valor[0] = v;
		next = n;
		end = p;
	}
};

template<class T>
struct pila
{
	T* top = nullptr;
	int count = 0;
	nodo* top2 = nullptr;

	pila() {

	}

	void push(int v) {
		if (!top) {
			top2 = new nodo<T>(v, top2);
			top = top2->valor[0];
		}
		else {
			if (count % 5 != 0) {
				top++;
				*top = v;
			}
			else {
				top2 = new nodo<T>(v, top2, top2->valor[5]);
				top = top2->valor[0];
				*top = v;
			}
		}

		count++;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
