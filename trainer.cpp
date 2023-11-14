/*
Author: Kenneth Guillont
*/

#include <iostream>
#include "trainer.hpp"

Trainer::Trainer()
{
    std::vector<Profemon> profedex;
    Profemon team[3];
    current = nullptr;
}

Trainer::Trainer(std::vector<Profemon> profemons)
{
    current = nullptr;

    for (int i = 0; i < 3; i++)
    {
        if (i < profemons.size())
        {
            team[i] = profemons[i];
        }
        else
        {
            team[i] = Profemon(); 
        }
    }

    for (int i = 3; i < profemons.size(); i++)
    {
        profedex.push_back(profemons[i]);
    }

    current = &team[0];
}

bool Trainer::contains(std::string name)
{
    for (int i = 0; i < 3; i++)
    {
        if (team[i].getName() == name)
            return true;
    }

    for (int i = 0; i < profedex.size(); i++)
    {
        if (profedex[i].getName() == name)
            return true;
    }

    return false;
} 


bool Trainer::addProfemon(Profemon profemon)
{
    if (contains(profemon.getName()))
        return false;

    for (int i = 0; i < 3; i++)
    {
        if (team[i].getName() == "Undefined")
        {
            team[i] = profemon;
            return true;
        }
    }

    profedex.push_back(profemon);
    return true;
}

bool Trainer::removeProfemon(std::string name)
{
    for (int i = 0; i < 3; i++)
    {
        if (team[i].getName() == name)
        {
            team[i] = Profemon(); 
            return true;
        }
    }

    for (size_t i = 0; i < profedex.size(); i++)
    {
        if (profedex[i].getName() == name)
        {
            for (size_t j = i; j < profedex.size() - 1; j++)
            {
                profedex[j] = profedex[j + 1];
            }
            profedex.pop_back();
            return true;
        }
    }

    return false;
}

void Trainer::setTeamMember(int slot, std::string name)
{
    if (slot < 0 || slot >= 3)
        return;

    Profemon *profedexProfemon = nullptr;
    for (auto &profemon : profedex)
    {
        if (profemon.getName() == name)
        {
            profedexProfemon = &profemon;
            break;
        }
    }

    if (profedexProfemon == nullptr)
        return;

    if (team[slot].getName() == "Undefined")
    {
        team[slot] = *profedexProfemon;
        for (size_t i = 0; i < profedex.size(); i++)
        {
            if (&profedex[i] == profedexProfemon)
            {
                for (size_t j = i; j < profedex.size() - 1; j++)
                {
                    profedex[j] = profedex[j + 1];
                }
                profedex.pop_back();
                break;
            }
        }
    }
    else
    {
        std::swap(team[slot], *profedexProfemon);
    }
}

bool Trainer::chooseProfemon(int slot)
{
    if (slot < 0 || slot >= 3)
        return false;

    if (team[slot].getName() != "Undefined")
    {
        current = &team[slot];
        return true;
    }

    return false;
}

Profemon Trainer::getCurrent()
{
    if (current != nullptr)
        return *current;
    else
        return Profemon(); 
}

void Trainer::printProfedex()
{
    for (int i = 0; i < profedex.size(); i++)
    {
        profedex[i].printProfemon(false); 
        std::cout << std::endl;
    }
}

void Trainer::printTeam()
{
    for (int i = 0; i < 3; i++)
    {
        if (team[i].getName() != "Undefined")
        {
            team[i].printProfemon(true); 
            std::cout << std::endl;
        }
    }
}
