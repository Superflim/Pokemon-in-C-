#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>


std::ifstream Pokemons_txt("Pokemons.txt"); //Opens the text file

void Check_file(){ //Function checks if the file can be opened.
    if (!Pokemons_txt.is_open()) {
        std::cerr << "Error opening file";
        exit(-1);
        }
}

/////////////Global variables/////////
bool Missed; //Creates boolean to check if the attack hit or not

//////////////////Classes/////////////////
class Pokemon{
    private:
        std::string Name;
        std::string AttackName;
        int Hp;
        int Dmg;

    public:
    Pokemon(int hp, std::string name){ ////The constructor, defines values that can be set later
        Name = name;
        Hp = hp; 
    }

    Pokemon(std::string attackname, int dmg){
        AttackName = attackname;
        Dmg = dmg;
    }

    //Function to introduce
    void Introduction(){
        std::cout << "You have chosen: " << Name << ". " << Name << " has " << Hp << "HP. " << "Have fun battling!" << std::endl;
    }

    //Function to attack with special move
    void AttackFunctionMega(){
        Missed = false;
        std::cout << "You have chosen: " << AttackName << ". " << std::endl;
        sleep(1);
        int RandomAttack = rand() % 10 + 1;
        if (RandomAttack >= 3){
            std::cout << "The attack was a hit! You did: " << Dmg << " Dmg" << std::endl;
        }

        else{
            std::cout << "You missed..." << std::endl;
            Missed = true;
            }
        }

    //Function to attack
    void AttackFunction(){
        std::cout << "You have chosen: " << AttackName << ". " << std::endl;
        sleep(1);
            std::cout << "The attack was a hit! You did:  " << Dmg << " Dmg" << std::endl;
        }
  
    void AttackFunctionEnemy(){
        std::cout << "Your opponent has chosen: " << AttackName << ". " << "Your opponent did " << Dmg << " Dmg" << std::endl;
    }

    void AttackFunctionEnemyMega(){
        Missed = false;
        std::cout << "Your opponent has chosen: " << AttackName << ". " << std::endl;
        sleep(1);
        int RandomAttack = rand() % 10 + 1;
        if (RandomAttack >= 3){
            std::cout << "The attack was a hit! Your opponent did: " << Dmg << " Dmg" << std::endl;
        }

        else{
            std::cout << "Your opponent missed..." << std::endl;
            Missed = true;
        }
    }


    //Setters
    void SetHp(int hp){
        Hp = hp;
    };

    void SetAttackName(std::string attackname){
        AttackName = attackname;
    };

    void SetDmg(int dmg){
        Dmg = dmg;
    };


    //Getters
    int GetHp(){
        return (Hp);
    };

    int GetDmg(){
        return(Dmg);
    };

    std::string GetAttackName(){
        return (AttackName);
    };

};


int main() {
    Check_file(); //Checks if the file can be opened.

    std::string Pokemons; //Creates string of Pokemon
    std::vector<std::string> MyPokemons; //Creates vector of strings called MyPokemons

    while (std::getline(Pokemons_txt, Pokemons)){ //Imports all strings of pokemons into the vector MyPokemons
        MyPokemons.push_back(Pokemons);
    }

    ////////////Pokemons//////////
    Pokemon Squirtle = Pokemon(200, "Squirtle"); //Makes a pokemon squirtle and gives it stats
    Pokemon Bulbasaur = Pokemon(170, "Bulbasaur"); //Makes a pokemon Bulbasaur and gives it stats
    Pokemon Charmander = Pokemon(220, "Charmander"); //Makes a pokemon Charmander and gives it stats
    Pokemon AiSquirtle = Pokemon(200, "AiSquirtle"); //Makes a pokemon squirtle and gives it stats

    Pokemon Tackle = Pokemon("Tackle", 19); //declares all the moves
    Pokemon HydroPump = Pokemon("HydroPump", 30);
    Pokemon GigaDrain = Pokemon("GigaDrain", 31);
    Pokemon MagmaStorm = Pokemon("MagmaStorm", 35);

    /////////Beginning//////////
    std::cout << "\nWelcome to the Pokemon game!" << std::endl;

    std::cout << "Which pokemon would you like to play with? Pick one from the list. \n" << std::endl;
    sleep(1); //sleeps for 1 second

    std::cout << "Type the name carefully, it's CaSe SeNsItIvE \n" << std::endl;

    for (int i = 0; i < MyPokemons.size(); i++){ //Prints all the available pokemons
        std::cout << MyPokemons[i] << std::endl;
        sleep(0); //sleeps for 1 second
    }
    std::cout << "\n";

    std::string ChosenPokemon; //Creates a string for the possible pokemon you can pick
    std::cin >> ChosenPokemon; //Asks the user input

    //////These lines of code will determine which string the user typed in and follow it up accordingly.
    int Compare_Char = ChosenPokemon.compare("Charmander");
    int Compare_Bulba = ChosenPokemon.compare("Bulbasaur");
    int Compare_Squirt = ChosenPokemon.compare("Squirtle");

    ////Code for when user choose Charmander//////
    if (Compare_Char == 0){
        Charmander.Introduction(); //Introduces the pokemon Charmander

        while ((AiSquirtle.GetHp() > 0) or (Charmander.GetHp() > 0)){
            int NewHpAiSquirtleTackle = AiSquirtle.GetHp() - Tackle.GetDmg();
            int NewHpAiSquirtleMagmastorm = AiSquirtle.GetHp() - MagmaStorm.GetDmg();

            int NewHpCharmanderTackle = Charmander.GetHp() - Tackle.GetDmg();
            int NewHpCharmanderHydropump = Charmander.GetHp() - HydroPump.GetDmg();

            std::cout << "What move would you like to do? You can choose from the following: \n" << std::endl;
        
            sleep(1);

            std::cout << "press 1 for: " << Tackle.GetAttackName() << std::endl; //Asks the user to attack
            std::cout << "or press 2 for: " << MagmaStorm.GetAttackName() << std::endl;
            
            int move1;
            std::cin >> move1; //Gets the user input (1 or 2)

            std::cout << "\n"; //Adds a space

            if (move1 == 1){
                Tackle.AttackFunction();
                AiSquirtle.SetHp(NewHpAiSquirtleTackle);
            }
            else{
                MagmaStorm.AttackFunctionMega();
                if (Missed == true){}

                else{
                    AiSquirtle.SetHp(NewHpAiSquirtleMagmastorm);
                }
            }

            std::cout << "The enemy pokemon now has: " << AiSquirtle.GetHp() << " Hp"<< std::endl; //Now the enemy moves

            sleep(2);

            std::cout << "The enemy is thinking about what move to do next. \n" << std::endl;
            sleep(2);
      
            int RandomAttack = rand() % 2 + 1; //Picks a random number between 1 and 2 to randomize enemy attack

            //////Enemy's turn /////////
            if (RandomAttack == 1){
                Tackle.AttackFunctionEnemy();
                Charmander.SetHp(NewHpCharmanderTackle); //Sets the new Hp
            } 
                else{
                    HydroPump.AttackFunctionEnemyMega();
                    sleep(1);
                    if (Missed == true){}
                        else{
                        Charmander.SetHp(NewHpCharmanderHydropump); //Sets the new Hp}
                        std::cout << "hi" << std::endl;
                        }
                    }
                    
            std::cout << "Ahhh this hurt. You only have: " << Charmander.GetHp() << " Hp left. \n"<< std::endl; //Now the enemy moves
            sleep(2);
        }
    }

    ////Code for when user choose Bulbasaur//////
    else if (Compare_Bulba == 0){
            Bulbasaur.Introduction(); //Introduces the pokemon Bulbasaur

            while ((AiSquirtle.GetHp() > 0) or (Bulbasaur.GetHp() > 0)) {
                int NewHpAiSquirtleTackle = AiSquirtle.GetHp() - Tackle.GetDmg();
                int NewHpAiSquirtleGigaDrain = AiSquirtle.GetHp() - GigaDrain.GetDmg();
                int NewHpBulbasaurTackle = Bulbasaur.GetHp() - Tackle.GetDmg();
                int NewHpBulbasaurHydropump = Bulbasaur.GetHp() - HydroPump.GetDmg();

                std::cout << "What move would you like to do? You can choose from the following: \n" << std::endl;
            
                sleep(1);

                std::cout << "press 1 for: " << Tackle.GetAttackName() << std::endl; //Asks the user to attack
                std::cout << "or press 2 for: " << GigaDrain.GetAttackName() << std::endl;
                
                int move1;
                std::cin >> move1; //Gets the user input (1 or 2)

                std::cout << "\n"; //Adds a space

                if (move1 == 1){
                    Tackle.AttackFunction();
                    AiSquirtle.SetHp(NewHpAiSquirtleTackle);
                }
                    else{
                        GigaDrain.AttackFunctionMega();
                        sleep(1);
                        
                        if (Missed == true){}
                            else{
                            AiSquirtle.SetHp(NewHpAiSquirtleGigaDrain); //Sets the new Hp}
                            }
                    }
            

                std::cout << "The enemy pokemon now has: " << AiSquirtle.GetHp() << " Hp"<< std::endl; //Now the enemy moves

                sleep(2);

                std::cout << "The enemy is thinking about what move to do next. \n" << std::endl;
                sleep(2);
        
                int RandomAttack = rand() % 2 + 1; //Picks a random number between 1 and 2 to randomize enemy attack

                if (RandomAttack == 1){
                    Tackle.AttackFunctionEnemy();
                    Bulbasaur.SetHp(NewHpBulbasaurTackle); //Sets the new Hp
                    } 
                    else{
                        HydroPump.AttackFunctionEnemyMega();
                        sleep (2);
                        if (Missed == true){}
                            else{
                                Bulbasaur.SetHp(NewHpBulbasaurHydropump); //Sets the new Hp
                            }
                        } 
                
                std::cout << "Ahhh this hurt. You only have: " << Bulbasaur.GetHp() << " Hp left. \n"<< std::endl; //Now the enemy moves
            }
        }

    ////Code for when user choose Squirtle//////
    else if (Compare_Squirt == 0){
            Squirtle.Introduction();  //Introduces the pokemon Squirtle
             while ((AiSquirtle.GetHp() > 0) or (Squirtle.GetHp() > 0)) {
                int NewHpAiSquirtleTackle = AiSquirtle.GetHp() - Tackle.GetDmg();
                int NewHpAiSquirtleHydropump = AiSquirtle.GetHp() - HydroPump.GetDmg();
                int NewHpSquirtleTackle = Squirtle.GetHp() - Tackle.GetDmg();
                int NewHpSquirtleHydropump = Squirtle.GetHp() - HydroPump.GetDmg();

                std::cout << "What move would you like to do? You can choose from the following: \n" << std::endl;
            
                sleep(1);

                std::cout << "press 1 for: " << Tackle.GetAttackName() << std::endl; //Asks the user to attack
                std::cout << "or press 2 for: " << HydroPump.GetAttackName() << std::endl;
                
                int move1;
                std::cin >> move1; //Gets the user input (1 or 2)

                std::cout << "\n"; //Adds a space

                if (move1 == 1){
                    Tackle.AttackFunction();
                    AiSquirtle.SetHp(NewHpAiSquirtleTackle);
                }
                    else{
                        HydroPump.AttackFunctionMega();
                        if (Missed = true){}
                            else{
                                AiSquirtle.SetHp(NewHpAiSquirtleHydropump);
                            }
                        
                    }

                std::cout << "The enemy pokemon now has: " << AiSquirtle.GetHp() << " Hp"<< std::endl; //Now the enemy moves

                sleep(2);

                std::cout << "The enemy is thinking about what move to do next. \n" << std::endl;
                sleep(2);
        
                int RandomAttack = rand() % 2 + 1; //Picks a random number between 1 and 2 to randomize enemy attack

                if (RandomAttack == 1){
                    Tackle.AttackFunctionEnemy();
                    Squirtle.SetHp(NewHpSquirtleTackle); //Sets the new Hp
                    } 
                    else{
                        HydroPump.AttackFunctionEnemyMega();
                        if (Missed == true){}
                        else{
                            Squirtle.SetHp(NewHpSquirtleHydropump); //Sets the new Hp
                        }
                    } 
                
                std::cout << "Ahhh this hurt. You only have: " << Squirtle.GetHp() << " Hp left. \n"<< std::endl; //Now the enemy moves
                sleep(2);
            }
            
    } 
        
    //If the user did not type a correct pokemon, break.    
    else{
        std::cout << "You have not chosen a pokemon from the list!" << std::endl; 
        exit(-1);}

    return(0);
} 

