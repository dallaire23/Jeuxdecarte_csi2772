#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
    virtual int getCardsPerCoin(int coins) const = 0; // Méthode virtuelle pure pour obtenir le nombre de cartes nécessaires pour des pièces
    virtual std::string getName() const = 0;          // Méthode virtuelle pure pour obtenir le nom de la carte
    virtual void print(std::ostream &out) const = 0;  // Méthode virtuelle pure pour l'affichage du caractère initial

    virtual ~Card() = default; // Destructeur virtuel pour garantir la destruction correcte des objets dérivés
    virtual int getcardcount() const = 0;
    // Opérateur d'insertion pour faciliter l'affichage
    friend std::ostream &operator<<(std::ostream &out, const Card &card)
    {
        card.print(out);
        return out;
    }
};