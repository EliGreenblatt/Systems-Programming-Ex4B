#include "Team.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Team::Team(Character * otherLeader) 
{
    if(otherLeader->isLeader())
    {
        throw std::runtime_error("Character is already a leader");
    }
    otherLeader->setLeader();
    team.reserve(10);
    teamSize = 1;
    leader = otherLeader;
    team.push_back(otherLeader);
}

Team::~Team()
{
    for(auto character : team)
    {
        delete character;
    }
}
void Team::add(Character * newTeamMate)
{
    if(newTeamMate->isInTeam())
    {
        throw std::runtime_error("Character is already in a team");
    }
    if(teamSize < 10)
    {
        team.push_back(newTeamMate);
        teamSize++;
        newTeamMate->setTeam();
    }
    else
    {
        throw std::runtime_error("Can't add over 10 Team Members");
    }

}

int Team::stillAlive()
{
    int cnt = 0;
    for (std::vector<Character*>::size_type i = 0; i < teamSize; i++)
    {
        if(team[i]->isAlive())
        {
            cnt++;
        }
    }

    return cnt;
}

void Team::print()
{
    for (std::vector<Cowboy*>::size_type i = 0; i < teamSize; i++)
    {
        if (Cowboy* cowboyPtr = dynamic_cast<Cowboy*>(team[i]))
        {
            cowboyPtr->print();
        }
    }
        
    for (std::vector<Cowboy*>::size_type i = 0; i < teamSize; i++)
    {
        if (Ninja* ninjaPtr = dynamic_cast<Ninja*>(team[i]))
        {
            ninjaPtr->print();
        }
    }
    
}

void Team::attack(Team * enemyTeam)
{

    if(enemyTeam == nullptr)
    {
        throw std::invalid_argument("Enemy Team is null");
    }       

    if(enemyTeam->stillAlive() <= 0)
    {
        throw std::runtime_error("Enemy Team Has Already Lost");
    }

    if(leader == nullptr)
    {
        throw std::runtime_error("Leader is null");
    }

    if (!leader->isAlive())
    {
        Character* newLeader = closestMember(leader);
        if (newLeader != nullptr)
        {
            leader = newLeader;
        }
        else
        {
            // No living members available, so the team is defeated
            return;
        }
    }   

    Character * sacrifice = enemyTeam->closestMember(leader);
    if(sacrifice == nullptr)
    {
        return;
    }

    // first loop is for the cowboys to attack , second loop for ninjas
    for (std::vector<Cowboy*>::size_type i = 0; i < teamSize; i++)
    {
        if (Cowboy* cowboyPtr = dynamic_cast<Cowboy*>(team[i]))
        {
            if(!cowboyPtr->isAlive())
            {
                continue;
            }
            if (cowboyPtr->hasboolets())
            {
                cowboyPtr->shoot(sacrifice);
            }
            else
            {
                cowboyPtr->reload();
            }
        }
        if(!sacrifice->isAlive())
        {
            sacrifice = enemyTeam->closestMember(leader);
            if(sacrifice == nullptr)
            {
                printf("Enemy Team Defeated\n");
                return;
            }
        }
    }

    // now ninjas attack
    for (std::vector<Cowboy*>::size_type i = 0; i < teamSize; i++)
    {
        if (Ninja* ninjaPtr = dynamic_cast<Ninja*>(team[i]))
        {
            if(!ninjaPtr->isAlive())
            {
                continue;
            }
           if (ninjaPtr->distance(sacrifice) < 1)
           {
                ninjaPtr->slash(sacrifice);
           }
           else
           {
                ninjaPtr->move(sacrifice);
           }
        }

        if(!sacrifice->isAlive())
        {
            sacrifice = enemyTeam->closestMember(leader);
            if(sacrifice == nullptr)
            {
                printf("Enemy Team Defeated\n");
                return;
            }
        }

    }
    
    
}

Character* Team::closestMember(Character * teamLeader)
{

    double minimumDistance = 99999;
    std::vector<Character*>::size_type indexOfCharacter = 10;
    for (std::vector<Character*>::size_type i = 0; i < teamSize; i++)
    {
        if(team[i] == NULL)
        {
            return nullptr;
        }
        double distance = team[i]->distance(teamLeader);
        if (distance < minimumDistance && team[i]->isAlive())
        {
            minimumDistance = distance;
            indexOfCharacter = i;
        }
    }
                   
    if(indexOfCharacter == 10)
    {
        return nullptr;
    }
    return team[indexOfCharacter];
    
}