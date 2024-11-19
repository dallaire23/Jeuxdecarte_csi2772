#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H
#include <iostream>
#include <vector>
#include "Card.h"

// Déclaration anticipée de Deck
class Deck;

using namespace std;

class CardFactory
{
private:
    static CardFactory *instance; // Instance singleton
    vector<Card *> allCards;      // Toutes les cartes disponibles

    CardFactory();                                        // Constructeur privé
    CardFactory(const CardFactory &) = delete;            // Suppression du constructeur par copie
    CardFactory &operator=(const CardFactory &) = delete; // Suppression de l'opérateur d'affectation

public:
    ~CardFactory();                   // Destructeur
    static CardFactory *getFactory(); // Méthode pour obtenir l'instance singleton
    Deck getDeck();                   // Méthode pour obtenir un Deck
};

#endif // CARD_FACTORY_H