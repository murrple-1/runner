#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "../include/main.h"

int main() {
    srand((unsigned int) time(NULL));
    std::list<Runner *> runners;
    bool cont = true;
    int select = 0;
    while (cont) {
        while (select < 1 || select > 5) {
            std::cout
                    << "\n1.  Add New Runner\n"
                    << "2.  Run Race\n"
                    << "3.  Print Current List\n"
                    << "4.  Empty List\n"
                    << "5.  Quit\n"
                    << "Enter Selection:" << std::endl;
            if (!(std::cin >> select)) {
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (select) {
            case(1) :
                        addRunner(runners);
                break;
            case(2) :
                        runRace(runners);
                break;
            case(3) :
                        printRunnerList(runners);
                break;
            case(4) :
                        emptyList(runners);
                break;
            case(5) :
                        quit(&cont);
                break;
            default:
                break;
        }
        select = 0;
    }
    emptyList(runners);
    return EXIT_SUCCESS;
}

void addRunner(std::list<Runner *> &l) {
    std::string s;
    unsigned int bib;
    float odds;
    std::cout << "Name?" << std::endl;
    getline(std::cin, s);
    std::cout << "Bib Number? Please input a positive integer" << std::endl;
    if (!(std::cin >> bib)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "ERROR: Please input positive integer" << std::endl;
        return;
    }
    std::cout << "Race Odds? Please input positive integer as relative weight" << std::endl;
    if (!(std::cin >> odds)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "ERROR: Please input positive integer" << std::endl;
        return;
    }
    Runner *r = new Runner(s, bib, odds);
    l.push_front(r);
    std::cout << "Runner " << r->getName() << " has been created" << std::endl;

}

void printRunnerList(std::list<Runner *> &l) {
    std::list<Runner *>::iterator iter;
    for (iter = l.begin(); iter != l.end(); ++iter) {
        Runner *r = *iter;
        std::cout << '#' << r->getBibNumber() << ' ' << r->getName()
                << ", Weighted Odds: " << r->getOdds() << std::endl;
    }
}

void runRace(std::list<Runner *> &l) {
    std::list<Runner *> results, holder(l);
    while(holder.size() > 0)
    {
        unsigned int beginChunk = 0, endChunk = beginChunk;
        unsigned int random = rand() % getTotalOdds(holder);
        std::list<Runner *>::iterator iter;
        for(iter = holder.begin(); iter != holder.end(); ++iter)
        {
            endChunk += (*iter)->getOdds();
            if(random >= beginChunk && random <= endChunk)
            {
                break;
            }
            beginChunk = endChunk;
        }
        results.push_back(*iter);
        holder.erase(iter);
    }
    std::cout << "After Race:" << std::endl;
    printRunnerList(results);
}

void emptyList(std::list<Runner *> &l) {
    std::list<Runner *>::iterator iter;
    for (iter = l.begin(); iter != l.end(); ++iter) {
        delete *iter;
    }
    l.clear();
}

void quit(bool *q) {
    *q = false;
}

unsigned int getTotalOdds(std::list<Runner *> &l) {
    unsigned int total = 0u;
    std::list<Runner *>::iterator iter;
    for (iter = l.begin(); iter != l.end(); ++iter) {
        total += (*iter)->getOdds();
    }
    return total;
}
