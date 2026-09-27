#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
class Brain
{
private:
    std::string _ideas[100];
protected:
public:
    Brain();
    Brain(const std::string ideas[]); // array cant be ref
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    virtual ~Brain(); // must be virtual bc dont have leaks when using delete

    const std::string &getIdea(int index) const;//send index and get idea from the array
    void setIdea(int index, const std::string &idea);//set idea inside the array
};
#endif