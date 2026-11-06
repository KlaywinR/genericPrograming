#ifndef LISTA_HPP
#define LISTA_HPP

#include <cstddef>
#include <iostream>
#include "no.hpp"


template <typename T, typename U>
class Lista {
    No<T, U>* inicio_;
    No<T, U>* fim_;
    std::size_t tam_;

public:
    Lista() : inicio_(nullptr), fim_(nullptr), tam_(0) {}
    Lista(const Lista&) = delete;
    Lista& operator=(const Lista&) = delete;
    ~Lista() { limpar(); }

    bool vazia() const { return tam_ == 0; }
    std::size_t tamanho() const { return tam_; }

    void inserir_inicio(const T& chave, const U& valor) {
        No<T, U>* n = new No<T, U>(chave, valor);
        n->prox = inicio_;
        inicio_ = n;
        if (!fim_) fim_ = n;
        ++tam_;
    }

    void inserir_fim(const T& chave, const U& valor) {
        No<T, U>* n = new No<T, U>(chave, valor);
        if (fim_) fim_->prox = n;
        else inicio_ = n;
        fim_ = n;
        ++tam_;
    }

    
    U* buscar(const T& chave) {
        for (No<T, U>* p = inicio_; p; p = p->prox)
            if (p->chave == chave) return &p->valor;
        return nullptr;
    }

    
    bool remover(const T& chave) {
        No<T, U>* ant = nullptr;
        No<T, U>* p = inicio_;
        while (p && !(p->chave == chave)) {
            ant = p;
            p = p->prox;
        }
        if (!p) return false;
        if (ant) ant->prox = p->prox;
        else inicio_ = p->prox;
        if (p == fim_) fim_ = ant;
        delete p;
        --tam_;
        return true;
    }

    void limpar() {
        while (inicio_) {
            No<T, U>* aux = inicio_;
            inicio_ = inicio_->prox;
            delete aux;
        }
        fim_ = nullptr;
        tam_ = 0;
    }

    void imprimir() const {
        std::cout << "[ ";
        for (No<T, U>* p = inicio_; p; p = p->prox)
            std::cout << "(" << p->chave << ": " << p->valor << ") ";
        std::cout << "]\n";
    }
};

#endif 
