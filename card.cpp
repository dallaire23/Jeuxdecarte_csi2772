#include <iostream>
#include <string>

class Card {
public:
    virtual int getCardsPerCoin(int coins) const = 0;  // Méthode virtuelle pure pour obtenir le nombre de cartes nécessaires pour des pièces
    virtual std::string getName() const = 0;           // Méthode virtuelle pure pour obtenir le nom de la carte
    virtual void print(std::ostream& out) const = 0;   // Méthode virtuelle pure pour l'affichage du caractère initial

    virtual ~Card() = default;  // Destructeur virtuel pour garantir la destruction correcte des objets dérivés

    // Opérateur d'insertion pour faciliter l'affichage
    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        card.print(out);
        return out;
    }
};

// Classe dérivée Blue, comme exemple. Répétez la même structure pour les autres types de haricots
class Blue : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        // Implémentez la logique spécifique pour "Blue" ici
        // Par exemple : 4 cartes pour 1 pièce, 6 pour 2 pièces, etc.
        return coins == 1 ? 4 : coins == 2 ? 6 : (coins == 3?:10);
    }

    std::string getName() const override {
        return "Blue";
    }

    void print(std::ostream& out) const override {
        out << 'B';  // Le caractère initial pour le type "Blue"
    }
};

// Ajoutez des classes pour Chili, Stink, Green, etc., en suivant la même structure
