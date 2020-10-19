#include<fstream>
#include<SFML/Graphics.hpp>
#include<iostream>

class Maze
{
    private:
        unsigned int M{}, N{};
        char** tiles;
        const char* tileDirectory;
        std::ifstream* reader{new std::ifstream()};
        sf::Texture* texture;
        std::vector<sf::Sprite> sprites;
        float cropSize; 
        virtual void Generate();
    public:
        Maze(unsigned int, unsigned int, const char*, sf::Texture*, float);
        ~Maze();
        void AllocateMemory();
        void FillMaze();
        char** GetTiles() const;
};