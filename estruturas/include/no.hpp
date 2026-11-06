#ifndef NO_HPP
#define NO_HPP

template <typename T, typename U>
struct No {
    T chave;
    U valor;
    No* prox;
    No(const T& c, const U& v) : chave(c), valor(v), prox(nullptr) {}
};

#endif 
