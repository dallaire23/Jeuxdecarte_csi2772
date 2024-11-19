#include "Deck.h"
#include "CardFactory.h"

Deck::Deck(istream &in, const cardFactory *factory)
{
    string cardName;
    while (in >> cardName)
    {
        // Utilisation de la CardFactory pour créer une carte correspondante au nom
        Card *card = nullptr;

        if (cardName == "Blue")
            card = new Blue();
        else if (cardName == "Chili")
            card = new Chili();
        else if (cardName == "Stink")
            card = new Stink();
        else if (cardName == "Green")
            card = new Green();
        else if (cardName == "Soy")
            card = new Soy();
        else if (cardName == "Black")
            card = new Black();
        else if (cardName == "Red")
            card = new Red();
        else if (cardName == "Garden")
            card = new Garden();

        if (card)
            this->push_back(card);
    }
}

Card *Deck::draw()
{
    // Implémentation de la méthode draw
    Card *superieur = this->front();
    this->erase(this->begin());
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