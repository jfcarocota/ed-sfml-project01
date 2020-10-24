#include<fstream>
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Tile.hh"

class Maze
{
    private:
        unsigned int M{}, N{};
        char** tiles;
        const char* tileDirectory;
        std::ifstream* reader{new std::ifstream()};
        sf::Texture* texture;
        std::vector<Tile*> mazeTiles;
        float cropSize; 
        float spriteScale;
    public:
        Maze(unsigned int, unsigned int, const char*, sf::Texture*&, float, float);
        ~Maze();
        void AllocateMemory();
        void FillMaze();
        char** GetTiles() const;
        void Generate();
        unsigned int GetRows() const;
        unsigned int GetCols() const;
        std::vector<Tile*> GetMazeTiles() const;
};