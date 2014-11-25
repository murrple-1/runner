#include "../include/Runner.h"

Runner::Runner(const std::string &aName, const unsigned int bib, const unsigned int oddsWeight) {
    setBibNumber(bib);
    setName(aName);
    setOdds(oddsWeight);
}

unsigned int Runner::getBibNumber(void) const {
    return bibNum;
}

std::string Runner::getName(void) const {
    return name;
}

unsigned int Runner::getOdds(void) const {
    return odds;
}

void Runner::setBibNumber(const unsigned int bib) {
    bibNum = bib;
}

void Runner::setName(const std::string &n) {
    name = n;
}

void Runner::setOdds(const unsigned int o) {
    odds = o;
}
