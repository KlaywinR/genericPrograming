#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <utility>
#include "pilha.hpp"
#include "fila.hpp"
#include "lista.hpp"
#include "benchmark.hpp"
#include "comparacao.hpp"

void comparar_com_stl(int n) {
    using std::cout;
    using std::make_pair;
    using std::pair;

    cout << "---   COMPARACAO COM A STL (" << n << " elementos) ---\n";
    long long soma = 0; 
    {
        Pilha<int, int> p;
        double t1 = medir_ms([&] {
            for (int i = 0; i < n; ++i) p.empilhar(i, i);
            while (!p.vazia()) { soma += p.topo().first; p.desempilhar(); }
        });
        std::stack<pair<int, int> > s;
        double t2 = medir_ms([&] {
            for (int i = 0; i < n; ++i) s.push(make_pair(i, i));
            while (!s.empty()) { soma += s.top().first; s.pop(); }
        });
        cout << "Pilha: propria = " << t1 << " ms | std::stack = " << t2 << " ms\n";
    }
    {
        Fila<int, int> f;
        double t1 = medir_ms([&] {
            for (int i = 0; i < n; ++i) f.enfileirar(i, i);
            while (!f.vazia()) { soma += f.frente().first; f.desenfileirar(); }
        });
        std::queue<pair<int, int> > q;
        double t2 = medir_ms([&] {
            for (int i = 0; i < n; ++i) q.push(make_pair(i, i));
            while (!q.empty()) { soma += q.front().first; q.pop(); }
        });
        cout << "Fila:  propria = " << t1 << " ms | std::queue = " << t2 << " ms\n";
    }
    {
        Lista<int, int> l;
        double t1 = medir_ms([&] {
            for (int i = 0; i < n; ++i) l.inserir_fim(i, i);
            l.limpar();
        });
        std::list<pair<int, int> > sl;
        double t2 = medir_ms([&] {
            for (int i = 0; i < n; ++i) sl.push_back(make_pair(i, i));
            sl.clear();
        });
        cout << "Lista: propria = " << t1 << " ms | std::list =- " << t2 << " ms\n";
    }
    cout << "(checksum: " << soma << ")\n";
}
