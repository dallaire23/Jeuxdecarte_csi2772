#include "CardFactory.h"
#include "Deck.h"
#include <algorithm>
#include <random>

using namespace std;

CardFactory *CardFactory::instance = nullptr;

CardFactory::CardFactory()
{
    for (int i = 0; i < 20; ++i)
        allCards.push_back(new Blue());
    for (int i = 0; i < 18; ++i)
        allCards.push_back(new Chili());
    for (int i = 0; i < 16; ++i)
        allCards.push_back(new Stink());
    for (int i = 0; i < 14; ++i)
        allCards.push_back(new Green());
    for (int i = 0; i < 12; ++i)
        allCards.push_back(new Soy());
    for (int i = 0; i < 10; ++i)
        allCards.push_back(new Black());
    for (int i = 0; i < 8; ++i)
        allCards.push_back(new Red());
    for (int i = 0; i < 6; ++i)
        allCards.push_back(new Garden());
}

CardFactory::~CardFactory()
{
    for (auto card : allCards)
        delete card;
}

CardFactory *CardFactory::getFactory()
{
    if (!instance)
        instance = new CardFactory();
    return instance;
}

Deck CardFactory::getDeck()
{
    Deck deck;
    for (auto card : allCards)
        deck.push_back(card);

    auto rng = default_random_engine(random_device{}());
    shuffle(deck.begin(), deck.end(), rng);
    return deck;
}
