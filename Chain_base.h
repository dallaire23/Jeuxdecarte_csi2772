#ifndef CHAIN_BASE_H
#define CHAIN_BASE_H

#include <iostream>
#include "Card.h"

class Chain_Base {
public:
    virtual ~Chain_Base() = default;

    // Ajoute une carte à la chaîne
    virtual Chain_Base& operator+=(Card* card) = 0;

    // Vend la chaîne et retourne les pièces gagnées
    virtual int sell() const = 0;

    // Affiche la chaîne dans un flux de sortie
    virtual void print(std::ostream& out) const = 0;
};

// Opérateur d'insertion pour les chaînes abstraites
inline std::ostream& operator<<(std::ostream& out, const Chain_Base& chain) {
    chain.print(out);
    return out;
}

#endif

