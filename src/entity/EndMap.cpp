#include <entity/EndMap.h>
#include <game/GameManager.h>
#include <entity/Player.h>

EndMap::EndMap(Vector2F grid)
:Entity(grid,"endmap",0),m_grid(grid),m_fin(false)
{}

void EndMap::render(const Vector2F &ref){
}

void EndMap::update(){
    Player player = GameManager::getLevel().getPlayer();
    //comparer si player sur endmap
    if (player.getGrid()[0]==int(m_grid[0]) && player.getGrid()[1]==int(m_grid[1])){
        std::cout<< "fin du niveau" << std::endl;
        //changer de niveau
        m_fin=true;
    }
}