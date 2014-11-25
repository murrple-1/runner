#ifndef MAIN_H_
#define MAIN_H_

/*
 * Various methods used in the main() method's menu. Allows the user to create
 * and simulate a race, with emphasis on the odds given to the runners
 *
 * Created by Murray Christopherson 2009. Last Updated April 2010.
 */

#include <list>
#include "Runner.h"

void addRunner(std::list<Runner *> &);

void printRunnerList(std::list<Runner *> &);

void runRace(std::list<Runner *> &);

void emptyList(std::list<Runner *> &);

void quit(bool *);

unsigned int getTotalOdds(std::list<Runner *> &);

#endif
