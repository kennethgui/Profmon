/*
Author: Kenneth Guillont
Course: CSCI-136
Instructor: Brandon Foster
Assignment: Project 2
*/

#ifndef TRAINER_HPP
#define TRAINER_HPP

#include "profemon.hpp"
#include <vector>

class Trainer
{
protected:
    std::vector<Profemon> profedex;
    Profemon team[3];
    Profemon* current;

public:
    Trainer();
    Trainer(std::vector<Profemon> profemons);
    bool contains(std::string name);
    bool addProfemon(Profemon profemon);
    bool removeProfemon(std::string name);
    void setTeamMember(int slot, std::string name);
    bool chooseProfemon(int slot);
    Profemon getCurrent();
    void printProfedex();
    void printTeam();
};

#endif
