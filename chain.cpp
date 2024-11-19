template <typename T>
void chain<T>::addcard (T* card){
    card.push_back(card);
}
int chain<T>::sell()const{
    if(card.empty(()) return 0;
    int numcards = cards.size();
    return cards[0]->getcardpercoin(numcards);
    )
}
void chain<T>:: print (std::ostream& out) const{
    out << getType()<<":";
    for(const T* card: cards){
        out << card->getName()<<" ";
    }
    out <<std:endl;
}
std::string Chain<T>::getType() const {
    return cards.empty() ? "Empty" : cards[0]->getName();
}

std::ostream& operator<<(std::ostream& out, const Chain<T>& chain) {
    chain.print(out);
    return out;
}

