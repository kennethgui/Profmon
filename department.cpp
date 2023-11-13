/*
Author: Kenneth Guillont
Course: CSCI-136
Instructor: Brandon Foster
Assignment: Project 2
*/

#include "department.hpp"

MLDepartment::MLDepartment(std::vector<Profemon> profemons) : Trainer(profemons) {
    for (auto it = profedex.begin(); it != profedex.end(); ) {
        if (it->getSpecialty() != ML) {
            it = profedex.erase(it);
        } else {
            ++it;
        }
    }
}

bool MLDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() != ML) {
        return false;
    }

    if (team.size() < 3) {
        team.push_back(profemon);
    } else {
        profedex.push_back(profemon);
    }

    return true;
}

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons) : Trainer(profemons) {
    for (auto it = profedex.begin(); it != profedex.end(); ) {
        if (it->getSpecialty() != SOFTWARE) {
            it = profedex.erase(it);
        } else {
            ++it;
        }
    }
}

bool SoftwareDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() != SOFTWARE) {
        return false;
    }

    
    if (team.size() < 3) {
        team.push_back(profemon);
    } else {
        profedex.push_back(profemon);
    }

    return true;
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons) : Trainer(profemons) {
    for (auto it = profedex.begin(); it != profedex.end(); ) {
        if (it->getSpecialty() != HARDWARE) {
            it = profedex.erase(it);
        } else {
            ++it;
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() != HARDWARE) {
        return false;
    }

    // Add the profémon to the team or profédex
    if (team.size() < 3) {
        team.push_back(profemon);
    } else {
        profedex.push_back(profemon);
    }

    return true;
}
