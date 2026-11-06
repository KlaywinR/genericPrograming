#ifndef FILA_HPP
#define FILA_HPP

#include <cstddef>
#include <stdexcept>
#include <utility>
#include "no.hpp"


template <typename T, typename U>
class Fila {
    No<T, U>* inicio_;
    No<T, U>* fim_;
    std::size_t tam_;

public:
    Fila() : inicio_(nullptr), fim_(nullptr), tam_(0) {}
    Fila(const Fila&) = delete;
    Fila& operator=(const Fila&) = delete;
    ~Fila() { while (!vazia()) desenfileirar(); }

    bool vazia() const { return tam_ == 0; }
    std::size_t tamanho() const { return tam_; }

    void enfileirar(const T& chave, const U& valor) {
        No<T, U>* n = new No<T, U>(chave, valor);
        if (fim_) fim_->prox = n;
        else inicio_ = n;
        fim_ = n;
        ++tam_;
    }

    void desenfileirar() {
        if (vazia()) throw std::underflow_error("Fila vazia");
        No<T, U>* aux = inicio_;
        inicio_ = inicio_->prox;
        if (!inicio_) fim_ = nullptr;
        delete aux;
        --tam_;
    }

    std::pair<T, U> frente() const {
        if (vazia()) throw std::underflow_error("Fila vazia");
        return std::make_pair(inicio_->chave, inicio_->valor);
    }
};

#endif
