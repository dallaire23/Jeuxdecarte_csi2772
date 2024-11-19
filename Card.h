#ifndef CARD_H
#define CARD_H

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

// Classe dérivée les types d'haricots
class Blue : public Card
{
public:
    int getcardcount() const override
    {
        return 20; // nombre de cartes pour les cartes Blue
    }
    int getCardsPerCoin(int coins) const override
    {

        return coins == 1 ? 4 : coins == 2 ? 6
                                           : (coins == 3 ? 8 : 10);
    }

    std::string getName() const override
    {
        return "Blue";
    }

    void print(std::ostream &out) const override
    {
        out << 'B';
    }
};

// classes pour Chili
class Chili : public Card
{
public:
    int getcardcount() const override
    {
        return 18; // nombre de cartes pour les cartes Blue
    }
    int getCardsPerCoin(int coins) const override
    {

        return coins == 1 ? 2 : coins == 2 ? 6
                            : coins == 3   ? 8
                                           : (coins == 4 ? 9 : -1);
    }

    std::string getName() const override
    {
        return "Chili";
    }

    void print(std::ostream &out) const override
    {
        out << 'c';
    }
};

// classes pour Stink
class Stink : public Card
{
public:
    int getcardcount() const override
    {
        return 16; // nombre de cartes pour les cartes Blue
    }
    int getCardsPerCoin(int coins) const override
    {

        return coins == 1 ? 3 : coins == 2 ? 5
                            : coins == 3   ? 7
                                           : (coins == 4 ? 8 : -1);
    }

    std::string getName() const override
    {
        return "Stink";
    }

    void print(std::ostream &out) const override
    {
        out << 's';
    }
};
// classes pour green
class Green : public Card
{
public:
    int getcardcount() const override
    {
        return 14; // nombre de cartes pour les cartes Blue
    }
    int getCardsPerCoin(int coins) const override
    {

        return coins == 1 ? 3 : coins == 2 ? 5
                            : coins == 3   ? 6
                                           : (coins == 4 ? 7 : -1);
    }

    std::string getName() const override
    {
        return "Green";
    }

    void print(std::ostream &out) const override
    {
        out << 'g';
    }
};

// classes pour soy
class Soy : public Card
{
public:
    int getcardcount() const override
    {
        return 12; // nombre de cartes pour les cartes Blue
    }
    int getCardsPerCoin(int coins) const override
    {

        return coins == 1 ? 2 : coins == 2 ? 4
                            : coins == 3   ? 6
                                           : (coins == 4 ? 7 : -1);
    }

    std::string getName() const override
    {
        return "Soy";
    }

    void print(std::ostream &out) const override
    {
        out << 's';
    }
};
// classes pour black
class Black : public Card
{
public:
    int getcardcount() const override
    {
        return 10; // nombre de cartes pour les cartes Blue
    }
    int getCardsPerCoin(int coins) const override
    {

        return coins == 1 ? 2 : coins == 2 ? 4
                            : coins == 3   ? 5
                                           : (coins == 4 ? 6 : -1);
    }

    std::string getName() const override
    {
        return "Black";
    }

    void print(std::ostream &out) const override
    {
        out << "bk";
    }
};
// classes pour Red
class Red : public Card
{
public:
    int getcardcount() const override
    {
        return 8; // nombre de cartes pour les cartes Blue
    }
    int getCardsPerCoin(int coins) const override
    {

        return coins == 1 ? 2 : coins == 2 ? 3
                            : coins == 3   ? 4
                                           : (coins == 4 ? 5 : -1);
    }

    std::string getName() const override
    {
        return "Red";
    }

    void print(std::ostream &out) const override
    {
        out << 'R';
    }
};

// classes pour Garden
class Garden : public Card
{
public:
    int getcardcount() const override
    {
        return 6; // nombre de cartes pour les cartes Blue
    }
    int getCardsPerCoin(int coins) const override
    {

        return coins == 1 ? -1 : coins == 2 ? 2
                                            : (coins == 3 ? 3 : -1);
    }

    std::string getName() const override
    {
        return "Garden";
    }

    void print(std::ostream &out) const override
    {
        out << 'G';
    }
};

#endif // CARD_H