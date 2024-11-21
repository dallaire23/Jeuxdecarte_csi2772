#ifndef chain_h
#define chain_h
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Chain_base.h"
#include "CardFactory.h"
#include "CardFactory.cpp"

template <typename T>
class Chain : public Chain_Base {
private:
    std::vector<T*> cards; // Les cartes de type T

public:
    //Constructeurs
    Chain() = default;
    Chain(std::istream& in, const CardFactory* cardFactory);

    // Ajout d'une carte
    Chain<T>& operator+=(Card* card) override;

    // Vente des cartes
    int sell() const override;

    // Afficher la chaîne
    void print(std::ostream& out) const override;
};

// Constructeur à partir d'un flux d'entrée
template <typename T>
Chain<T>::Chain(std::istream& in, const CardFactory* cardFactory) {
    std::string type;
    size_t numCards;

    in >> type >> numCards;
    if (type != T().getName()) {
        throw std::invalid_argument("Type incompatible lors de la reprise !");
    }

    for (size_t i = 0; i < numCards; ++i) {
        cards.push_back(static_cast<T*>(cardFactory->createCard(type)));
    }
}

// Ajout d'une carte
template <typename T>
Chain<T>& Chain<T>::operator+=(Card* card) {
    if (T* specificCard = dynamic_cast<T*>(card)) {
        cards.push_back(specificCard);
    } else {
        throw std::invalid_argument("IllegalType : carte incompatible !");
    }
    return *this;
}

// Vente des cartes
template <typename T>
int Chain<T>::sell() const {
    if (cards.empty()) return 0;
    return cards.front()->getCardsPerCoin(cards.size());
}

// Affichage
template <typename T>
void Chain<T>::print(std::ostream& out) const {
    out << T().getName() << ": ";
    for (const T* card : cards) {
        out << card->getName() << " ";
    }
    out << std::endl;
}


#endif