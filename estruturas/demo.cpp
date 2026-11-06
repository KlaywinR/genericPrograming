#include <iostream>
#include <string>
#include <utility>
#include "pilha.hpp"
#include "fila.hpp"
#include "lista.hpp"
#include "demo.hpp"

void demo_estruturas() {
    using std::cout;
    using std::string;
    using std::pair;

    cout << "===== PILHA<string, int> =====\n";
    Pilha<string, int> pilha;
    pilha.empilhar("A", 1);
    pilha.empilhar("B", 2);
    pilha.empilhar("C", 3);
    cout << "Desempilhando:";
    while (!pilha.vazia()) {
        pair<string, int> t = pilha.topo();
        cout << " (" << t.first << "," << t.second << ")";
        pilha.desempilhar();
    }
    cout << "\n\n";

    cout << "-- FILA<int, double> --\n";
    Fila<int, double> fila;
    fila.enfileirar(1, 1.5);
    fila.enfileirar(2, 2.5);
    fila.enfileirar(3, 3.5);
    cout << "Desenfileirando:";
    while (!fila.vazia()) {
        pair<int, double> f = fila.frente();
        cout << " (" << f.first << "," << f.second << ")";
        fila.desenfileirar();
    }
    cout << "\n\n";

    cout << "-- LISTA<string, double> --\n";
    Lista<string, double> lista;
    lista.inserir_fim("pi", 3.14);
    lista.inserir_fim("e", 2.71);
    lista.inserir_inicio("zero", 0.0);
    lista.imprimir();
    double* v = lista.buscar("e");
    cout << "buscar(\"e\") -> " << (v ? *v : -1) << "\n";
    cout << "remover(\"pi\") -> " << (lista.remover("pi") ? "ok" : "nao encontrado") << "\n";
    lista.imprimir();
    cout << "\n";
}
