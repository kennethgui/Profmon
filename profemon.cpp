/*
Author: Kenneth Guillont
Course: CSCI-136
Instructor: Brandon Foster
Assignment: Project 2
*/

#include <string>
#include "profemon.hpp"
#include <iostream>

Profemon::Profemon()
{
    name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty)
{
    this->name = name;
    this->max_Health = max_health;
    this->expReq = 50;
    this->current_exp = 0;
    this->specialty = specialty;
    this->level = 0;
}

std::string Profemon::getName()
{
    return name;
}

Specialty Profemon::getSpecialty()
{
    return specialty;
}

int Profemon::getLevel()
{
    return level;
}

double Profemon::getMaxHealth()
{
    return max_Health;
}

void Profemon::setName(std::string name)
{
    this->name = name;
}

void Profemon::levelUp(int exp)
{
    current_exp += exp;

    while (current_exp >= expReq)
    {
        level++;
        current_exp -= expReq; 
        switch (specialty)
        {
        case ML:
            expReq += 10;
            break;
        case SOFTWARE:
            expReq += 15;
            break;
        case HARDWARE:
            expReq += 20;
            break;
        default:
            break;
        }
    }
}

bool Profemon::learnSkill(int slot, Skill skill) 
{
    if (slot >= 0 && slot < 3 && skill.getSpecialty() == specialty)
    {
        skills[slot] = skill;
        return true;
    }
    return false;
}

void Profemon::printProfemon(bool print_skills)
{
    std::string specialty_str;
    switch (specialty)
    {
    case ML:
        specialty_str = "ML";
        break;
    case SOFTWARE:
        specialty_str = "SOFTWARE";
        break;
    case HARDWARE:
        specialty_str = "HARDWARE";
        break;
    default:
        specialty_str = "Unknown";
        break;
    }

    std::cout << name << " [" << specialty_str << "] | lvl " << level << " | exp " << current_exp << "/" << expReq << " | hp " << max_Health << std::endl;

    if (print_skills)
    {
        for (int i = 0; i < 3; i++)
        {
            if (skills[i].getName() != "Undefined")
            {
                std::cout << "    " << skills[i].getName() << " [" << skills[i].getTotalUses() << "] : " << skills[i].getDescription() << std::endl;
            }
        }
    }
}
