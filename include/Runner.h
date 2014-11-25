#ifndef RUNNER_H_
#define RUNNER_H_

/*
 * A Model class for a Runner, containing a name, bib number and weighted odds.
 * The various methods are just get/set methods.
 *
 * Weighted odds can be thought of as arbitrary percentages, except they mean
 * nothing unless compared with other odds. For example, the number 37 is
 * entirely abitrary, though when compared to 56, we can say this is just
 * slightly more than 2 times as likely as 37. When both of these are compared
 * to 41, we can say this more likely than 37 but less than 56.
 * To be precise, the probability of each of the above examples is
 * 37 / (37 + 41 + 56) = 37 / 136, 56 / 136 and 41 / 136 respectively.
 *
 * Created by Murray Christopherson 2009. Last Updated April 2010.
 */

#include <string>

class Runner {
public:
    /**
     * Constructor, sets the data members of the Runner
     */
    Runner(const std::string & = "Undefined", const unsigned int = 0u, const unsigned int = 100u);
    /**
     * Returns the runner's name
     * @pre no requirements
     * @post no change
     * @return string of Runner's name
     */
    std::string getName(void) const;
    /**
     * Returns the bib number of the runner
     * @pre no requirement
     * @post no change
     * @return unsigned int of bib number
     */
    unsigned int getBibNumber(void) const;
    /**
     * Returns the weighted odds of the runner
     * @pre no requirement
     * @post no change
     * @return unsigned int of weighted probability
     */
    unsigned int getOdds(void) const;
    /**
     * Sets the runner's name
     * @pre no requirement
     * @post the runner's name is now the supplied string
     */
    void setName(const std::string &);
    /**
     * Sets the runner's bib number
     * @pre no requirement. Number may be 0
     * @post the runner's bib number is now the supplied number
     */
    void setBibNumber(const unsigned int);
    /**
     * Sets the weighted odds
     * @pre no requirement. Number may be 0
     * @post the weight of the runner's odds are now the supplied number
     */
    void setOdds(const unsigned int);
private:
    std::string name;
    unsigned int bibNum;
    unsigned int odds;
};
#endif
