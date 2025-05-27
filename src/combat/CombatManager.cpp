#include "combat/CombatManager.h"
#include "combat/Enemy.h"
#include "combat/Player.h"
#include "combat/UI.h"
#include <iostream>
#include <iterator>
#include <string>
CombatManager::CombatManager(std::vector<Player*> company, std::vector<Enemy*> horde)
: state(CombatManager::CombatState::nullState), horde(horde), currentEnnemy(0), company(company), currentHero(0), currentAttack(nullptr)
{}

void CombatManager::handlePlayerInput(unsigned int actionID)
{
	std::cout << "combat manager: receiving" << actionID << std::endl;
	switch (actionID) 
	{
		case 0:
		case 1:
		case 2:
		case 3:
			currentAttack = company[currentHero]->getAttacks()[actionID]; // we select the attack
			break;
	}
	state = PlayerAttack;
}

void CombatManager::update()
{
	//std::cout << state << std::endl;
	switch (state) 
	{
		case CombatManager::CombatState::nullState:
			UI::setTextMessage("au combat !");
			//we display the start message;
			break;

		case CombatManager::CombatState::PlayerTurnStart:
			UI::setTextMessage("que vas-tu faire ?");
			// we display "please choose an attack"
			break;

		case CombatManager::CombatState::PlayerTurn:
			// we wait for an attack from the player
			break;

		case CombatManager::CombatState::PlayerAttack:
			UI::setTextMessage(currentAttack->attackMessage(company[currentHero], horde[currentEnnemy]));
			state = PlayerAttackDone;
			// we display "player did X damages"
			break;

		case EnemyAttack:
			currentAttack = horde[currentEnnemy]->chooseAttack();
			// we select a random attack for the ennemy and
			UI::setTextMessage(currentAttack->attackMessage(horde[currentEnnemy], company[currentHero]));
			// we display "the enemy did X damages"
			state = EnemyAttackDone;
			break;
	
		case Victory:
			std::cout << "victory" << std::endl;
			UI::setTextMessage("bravo, tu as vaincu " + horde[0]->getName());
			// we display the loot won and XP
			break;

		case Defeat:
			UI::setTextMessage((company.size() > 1)?"tous tes héros sont morts au combat...":(company[0]->getName() + " n'a pas survécu"));
			// we display a message for the looser
			break;
		case EnemyAttackDone:
		case PlayerAttackDone:
			break;
	}
}

void CombatManager::updateState()
{
	CombatState newCase;
	switch(state)
	{
		case Victory:
		case Defeat:
			break;
		case nullState:
			priority = (company[currentHero]->getSpeed() >= horde[currentEnnemy]->getSpeed());
			state = priority?CombatState::PlayerTurnStart:CombatState::EnemyAttack;
			break;
		case PlayerAttackDone:
			currentAttack->attack(company[currentHero], horde[currentEnnemy]);	// update ennemyLife with savedAttack

			if (horde[currentEnnemy]->getActualHP() <= 0)// if enemy life below zero and no other ennemy: victory
			{
				std::cout << "enemy dead" << std::endl;
				if (currentEnnemy + 1 >= horde.size())
				{
					std::cout << "owmy" <<std::endl;
					state = Victory;
					
					std::cout << "owmy :)" <<std::endl;
					break;
				}
				currentEnnemy++;
			}
			if (priority)
				state = CombatState::EnemyAttack;
			else
			{
				priority = (company[currentHero]->getSpeed() >= horde[currentEnnemy]->getSpeed());
				state = priority?CombatState::PlayerTurnStart:CombatState::EnemyAttack;
			}
			break;
		case EnemyAttackDone:
			currentAttack->attack(horde[currentEnnemy], company[currentHero]);
			// update heroLife with saved attack;
			if (company[currentHero]->getActualHP() <= 0)
			{
				if (currentHero +1 >= company.size())
				{
					state = Defeat;
					break;
				}
				currentHero++;
			}
			if (priority)
			{
				priority = (company[currentHero]->getSpeed() >= horde[currentEnnemy]->getSpeed());
				state = priority?CombatState::PlayerTurnStart:CombatState::EnemyAttack;
			}
			else
				state = CombatState::PlayerTurnStart;
			break;
		case PlayerTurnStart:
			state = PlayerTurn;
			break;
		default:
			state = nullState;
	}
}

Player *CombatManager::getCurrentHero()
{
	return company[currentHero];
}

Enemy*CombatManager::getCurrentEnemy()
{
	return horde[currentEnnemy];
}
