#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class CardFactory;

class Deck : public vector<Card *>
{
public:
    // Constructeur qui accepte un flux d'entrée et un pointeur vers une fabrique de cartes
    Deck(istream &in, const CardFactory *factory);

    // Fonction pour tirer une carte (retire et retourne la carte supérieure du Deck)
    Card *draw();

    // Surcharge de l'opérateur d'insertion pour insérer toutes les cartes du deck dans un flux
    friend ostream &operator<<(ostream &out, const Deck &deck);
};