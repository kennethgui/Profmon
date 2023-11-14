#include "profemon.hpp"
#include "skill.hpp"
#include "trainer.hpp"
#include "department.hpp"
using namespace std;

int main() {
    // Create Skills
    Skill oop("OOP", "a programming paradigm based on the concept of objects, which can contain data and code", SOFTWARE, 30);
    Skill dynamic_array("Vector", "a c++ dynamic array library", SOFTWARE, 30);
    Skill pointer("Pointer", "a pointer stores a memory address", SOFTWARE, 10);

    Skill sorting("Sorting", "algorithms to sort things in order", SOFTWARE, 30);
    Skill polymorphism("Polymorphism", "the same entity (function or object) behaves differently in different scenarios", SOFTWARE, 20);
    Skill searching("Searching", "algorithms to efficiently search items in data structures", SOFTWARE, 30);

    Skill report("Report", "report a student for cheating", SOFTWARE, 30);
    Skill tree("Tree", "an abstract data type that represents a hierarchical tree structure with a set of connected nodes", SOFTWARE, 25);
    Skill hashtable("HashTable", "an abstract data type that maps keys to values", SOFTWARE, 30);

    Skill nickname("Nickname", "assign a nickname to the students", HARDWARE, 20);
    Skill mips("MIPS", "an assembly level programming language", HARDWARE, 10);
    Skill multiplexer("Multiplexer", "a device that selects between several analog or digital input signals and forwards the selected input to a single output line", HARDWARE, 30);

    Skill flashbag("Flashbag", "creates and throws rgb backpack to blind enemies", HARDWARE, 5);
    Skill induction("Induction", "a method of mathematical proof typically used to establish a given statement for all possible cases", HARDWARE, 15);
    Skill recurrence("Recurrence", "n equation that defines a sequence based on a rule that gives the next term as a function of the previous term(s)", HARDWARE, 15);

    Skill flipflop("Flip-Flop", "circuits that can store state(on/off) information", HARDWARE, 20);
    Skill number_system("Number System", "a technique to represent numbers", HARDWARE, 20);
    Skill kmap("Karnaugh Map", "a table that simplifies the expressions to Boolean functions", HARDWARE, 5);

    Skill supervised("Supervised Learning", "a ML training method that uses labeled datasets and algorithms classify data or predict outcomes accurately", ML, 25);
    Skill unsupervised("Unsupervised Learning", "a ML training method that can discover hidden patterns or data groupings without the need for human intervention", ML, 30);
    Skill reinforcement("Reinforcement Learning", "a ML training method based on rewarding desired behaviors and/or punishing undesired ones", ML, 15);

    Skill ngrams("Ngrams", "a contiguous sequence of n items from a given sample of text or speech", ML, 10);
    Skill tokenizing("Tokenizing", "breaks the raw text into words, sentences called tokens", ML, 30);
    Skill lemmatizing("Lemmatizing", "the process of grouping together different inflected forms of the same word", ML, 20);

    Skill perceptron("Perceptron", "a ML algorithm that can decide whether an input belongs to some specific class", ML, 20);
    Skill neuralnetwork("Neural Network", "a series of perceptrons that have an input, output, and hidden layer", ML, 30);
    Skill autoencoder("Autoencoder", "a ML technique that involves the use of a generator which generates fake information and a discriminator which can discern whether the information is fake or not", ML, 30);

    // Create Profemons
    Profemon maryash("Maryash", 13500, SOFTWARE);
    Profemon ligorio("Ligorio", 23500, SOFTWARE);
    Profemon shostak("Shostak", 33500, SOFTWARE);
    Profemon shankar("Shankar", 26000, HARDWARE);
    Profemon schweitzer("Schweitzer", 15000, HARDWARE);
    Profemon zamfirescu("Zamfirescu", 16000, HARDWARE);
    Profemon raja("Raja", 35000, ML);
    Profemon levitan("Levitan", 49362, ML);
    Profemon epstein("Epstein", 49377, ML);

    // Test Skill Learning and Printing Profemon Information
    cout << maryash.learnSkill(0, oop) << endl;                 // prints 1
    maryash.printProfemon(true);

    cout << ligorio.learnSkill(2, perceptron) << endl;          // prints 0

    shostak.levelUp(200);
    cout << shostak.getLevel() << endl;                         // prints 3

    shankar.learnSkill(1, mips);
    schweitzer.learnSkill(0, flashbag);
    raja.levelUp(10);

    // Create a Trainer and add Profemons to the team and profedex
    Trainer mlTrainer({raja, levitan, epstein});
    mlTrainer.addProfemon(shankar);
    mlTrainer.addProfemon(schweitzer);
    mlTrainer.addProfemon(zamfirescu);
    mlTrainer.addProfemon(epstein);

    // Print Profedex and Team
    cout << "Profedex:" << endl;
    mlTrainer.printProfedex();
    cout << "Team:" << endl;
    mlTrainer.printTeam();

    // Test choosing a Profemon from the team
    mlTrainer.chooseProfemon(1);
    cout << "Current Profemon: " << mlTrainer.getCurrent().getName() << endl;

    // Test removing a Profemon from the team
    mlTrainer.removeProfemon("Shankar");
    cout << "Team after removing Shankar:" << endl;
    mlTrainer.printTeam();

    // Test adding a Profemon to the team
    Profemon newProfemon("NewProfemon", 20000, ML);
    mlTrainer.addProfemon(newProfemon);
    cout << "Team after adding NewProfemon:" << endl;
    mlTrainer.printTeam();

    // ... continue testing other functionalities

    // Create and test ML Department
    MLDepartment mlDepartment({raja, levitan, epstein});
    mlDepartment.addProfemon(levitan);
    cout << "ML Department Profedex:" << endl;
    mlDepartment.printProfedex();

    return 0;
}

