#ifndef __CREATEENTITIES_H__
#define __CREATEENTITIES_H__

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <vector>
#include <tuple>

#include "Attack.h"
#include "AttackToLife.h"
#include "Enemy.h"
#include "Player.h"

class createEntities {
    public:
    
    static std::vector<std::vector<std::string>> readCSV(std::string filename)
    {
        std::ifstream fichier(filename);
        if (!fichier.is_open())
        {
            std::cout << "Le fichier n'a pas pu etre ouvert" << std::endl;
            exit(EXIT_FAILURE);
        }
        // le fichier a ete lu
        std::vector<std::vector<std::string>> data;
        std::vector<std::string> ligne;
        std::string l, w;
        while (getline(fichier, l))
        {
            ligne.clear();
            std::stringstream ss(l);
            char delimiteur = *";";
            while (getline(ss, w, delimiteur))
            {
                ligne.push_back(w);
            }
            data.push_back(ligne);
        }
        fichier.close();
        return data;
    }

    static std::vector<std::tuple<Attack*,std::string>> createAttacks(std::string filePath){
        std::vector<std::tuple<Attack*,std::string>> attacks;
        std::vector<std::vector<std::string>> data = createEntities::readCSV(filePath);
        for (int i = 0; i<data.size();i++)
        {
            for (int j = 0; j<data[0].size();j++)
            {
                if (data[i][4].compare("attackToLife"))
                {
                    int ppMax = std::stoi(data[i][1]);
                    unsigned int damage = std::stoi(data[i][2]);
                    attacks.push_back(std::make_tuple(new AttackToLife(ppMax, data[i][0], damage),data[i][3]));
                    std::cout << data[i][j] << std::endl;
                }   
            }
        }
        return attacks;
    }

    static std::vector<Enemy*> createEnemies(std::string filePath){
        std::vector<std::tuple<Attack*,std::string>> attacks(createAttacks("assets/csvForEntities/attaques.csv"));
        std::vector<Enemy*> enemies;
        std::vector<std::vector<std::string>> data = createEntities::readCSV(filePath);
        for (int i = 0; i<data.size();i++)
        {
            for (int j = 0; j<data[0].size();j++)
            {

                if (data[i][4].compare("attackToLife"))
                {
                    std::vector<Attack*> enemyAttacks;
                    for (int k = 0; k<attacks.size(); k++)
                    {
                        if(data[i][3].compare(std::get<1>(attacks[k])))
                        {
                            enemyAttacks.push_back(std::get<0>(attacks[k]));
                        }
                    }
                    double maxHP = std::stoi(data[i][1]);
                    int speed = std::stoi(data[i][2]);
                    int lootXP = std::stoi(data[i][4]);
                    unsigned int damage = std::stoi(data[i][2]);
                    std::string texture = "assets/entities/"+data[i][4];
                    enemies.push_back(new Enemy(maxHP, speed, data[i][0], lootXP, enemyAttacks, texture));
                    std::cout << data[i][j] << std::endl;
                }   
            }
        }
        return enemies;
    }

    static std::vector<Player*> createHeroes(std::string filePath){
        std::vector<std::tuple<Attack*,std::string>> attacks(createAttacks("assets/csvForEntities/attaques.csv"));
        std::vector<Player*> heroes;
        std::vector<std::vector<std::string>> data = createEntities::readCSV(filePath);
        for (int i = 0; i<data.size();i++)
        {
            for (int j = 0; j<data[0].size();j++)
            {

                if (data[i][4].compare("attackToLife"))
                {
                    std::vector<Attack*> heroAttacks;
                    for (int k = 0; k<attacks.size(); k++)
                    {
                        if(data[i][3].compare(std::get<1>(attacks[k])))
                        {
                            heroAttacks.push_back(std::get<0>(attacks[k]));
                        }
                    }
                    double maxHP = std::stoi(data[i][1]);
                    int speed = std::stoi(data[i][2]);
                    // Création d'un vecteur d'items vide pour le joueur
                    std::vector<Item*> playerItems;
                    unsigned int damage = std::stoi(data[i][2]);
                    std::string texture = "assets/entities/"+data[i][6];
                    heroes.push_back(new Player(maxHP, speed, data[i][0], heroAttacks, playerItems, texture));
                    std::cout << data[i][j] << std::endl;
                }   
            }
        }
        return heroes;
    }


};

#endif //__CREATEENTITIES_H__