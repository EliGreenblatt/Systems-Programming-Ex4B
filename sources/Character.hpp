#ifndef CHARACTER_
#define CHARACTER_

#include <string>
#include "Point.hpp"
namespace ariel
{
    class Character
    {
        public:
            virtual ~Character();
            Character();
            Character(std::string otherName , Point spawnPoint);
            bool isAlive();
            double distance(Character * otherChar);
            Point getLocation();
            std::string getName();
            void hit(int damageTaken);
            virtual std::string print() = 0;

            int getHP();

            void setLeader();
            bool isLeader();

            void setTeam();
            bool isInTeam();

            Point location;
            int hitpoints;
            bool alive;
            bool leader;
            bool isTeam;
            std::string name;
            
    };
}


#endif