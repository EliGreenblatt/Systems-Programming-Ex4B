#ifndef COWBOY_
#define COWBOY_

#include "Character.hpp"
namespace ariel
{
    class Cowboy : public Character
    {
        public:

            Cowboy(std::string name , Point spawnLocation);
            ~Cowboy();
            void shoot(Character * enemy);
            bool hasboolets();
            void reload();
            std::string print() override;

            int numberOfBullets;
            int damage;
    };
}


#endif