#ifndef COMBAT_MANAGER
#define COMBAT_MANAGER

#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "combat/Attack.h"
class CombatManager
{
private:
	enum CombatState
	{
		nullState,
		PlayerTurnStart, 	// displays "choose your attack"
		PlayerTurn, 		// waitings for player input
		PlayerAttack,		// displays "player did X damages"
		PlayerAttackDone,
		EnemyAttack,		// displays "enemy did X damages"
		EnemyAttackDone,
		Victory, 		// displays loot won
		Defeat, 		// restarts the game
	};

	CombatState state;
	bool priority; // 1 if player attacks first, else 0
	
	std::vector<Enemy*> horde;
	unsigned int currentEnnemy;

	std::vector<Player*> company; // "What a company I ended up with," Geralt continued, shaking his head. "... A poetaster with a lute. A wild and lippy half-dryad, half-woman. A vampire, who's about to notch up his fifth century. And a bloody Nilfgaardian who insists he isn't a Nilfgaardian."
	unsigned int currentHero;

	Attack* currentAttack;

public:
	CombatManager(std::vector<Player*> company, std::vector<Enemy*> horde);
	
	void switchCurrentHero(int id);

	bool update(); // changes combat state
	
	void handlePlayerInput(int actionID);

	void updateState();
	
	bool HasMultipleHeroes();

	Player *getCurrentHero();
	Enemy *getCurrentEnemy();
	
	unsigned int getNbHeroAlive();
	unsigned int getIDCurrentHero();
	std::vector<Player*> getCompany();
};

#endif
