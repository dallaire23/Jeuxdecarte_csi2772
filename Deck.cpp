#include "Deck.h"

Deck::Deck(istream &in, const CardFactory *factory)
{
    // Implémentation du constructeur
}

Card *Deck::draw()
{
    // Implémentation de la méthode draw
    Card superieur = this->front();
    this.erase(this->begin());
    return superieur;
}

ostream &operator<<(ostream &out, const Deck &deck)
{
    // Implémentation de l'opérateur d'insertion
    for (int i = 0; i < deck.size(); i++)
    {
        out << *deck[i] << "\n";
    }
    return out;
}