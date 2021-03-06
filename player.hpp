#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
protected:
    char _mark;
    std::string _name;
public:
    Player(char mark, std::string name): _mark(mark), _name(name){}

    char get_mark()const {return _mark;}
    std::string get_name()const {return _name;}
};

#endif // PLAYER_HPP
