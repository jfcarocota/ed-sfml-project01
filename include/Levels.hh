#include "Maze.hh"
#include<SFML/Graphics.hpp>
#include<iostream>

class Levels
{
    private:
        std::vector<Maze*> mazes;
        std::vector<sf::Texture*> textures;
        const float tileBaseWidth{16 * 4.f};
        const float tileBaseHeight{16 * 4.f};
    public:
        Levels(/* args */);
        ~Levels();
        void Level1();
};

Levels::Levels(/* args */)
{   
    textures.push_back(new sf::Texture());
    textures.back()->loadFromFile("assets/sprites/tiles3.png");
    //mazes.push_back(new Maze(10, 13, "assets/mazes/maze1/maze.txt", textures.at(0), 16));
}

Levels::~Levels()
{
}

void Levels::Level1()
{

}
