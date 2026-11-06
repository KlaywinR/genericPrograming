#ifndef PILHA_HPP
#define PILHA_HPP

#include <cstddef>
#include <stdexcept>
#include <utility>
#include "no.hpp"


template <typename T, typename U>
class Pilha {
    No<T, U>* topo_;
    std::size_t tam_;

public:
    Pilha() : topo_(nullptr), tam_(0) {}
    Pilha(const Pilha&) = delete;
    Pilha& operator=(const Pilha&) = delete;
    ~Pilha() { while (!vazia()) desempilhar(); }

    bool vazia() const { return tam_ == 0; }
    std::size_t tamanho() const { return tam_; }

    void empilhar(const T& chave, const U& valor) {
        No<T, U>* n = new No<T, U>(chave, valor);
        n->prox = topo_;
        topo_ = n;
        ++tam_;
    }

    void desempilhar() {
        if (vazia()) throw std::underflow_error("Pilha vazia");
        No<T, U>* aux = topo_;
        topo_ = topo_->prox;
        delete aux;
        --tam_;
    }

    std::pair<T, U> topo() const {
        if (vazia()) throw std::underflow_error("Pilha vazia");
        return std::make_pair(topo_->chave, topo_->valor);
    }
};

#endif 
