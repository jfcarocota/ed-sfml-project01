#include "Maze.hh"

Maze::Maze(unsigned int M, unsigned int N, const char* tilesDirectory, sf::Texture* texture, float cropSize)
{
    this->M = M;
    this->N = N;
    this->tiles = new char*[M];
    this->tileDirectory = tilesDirectory;
    this->texture = texture;
    this->cropSize = cropSize;
    AllocateMemory();
    FillMaze();
}

Maze::~Maze()
{
}

void Maze::AllocateMemory()
{
    for(int i{}; i < M; i++)
    {
        tiles[i] = new char[N];
    }
}

void Maze::FillMaze()
{
    reader->open(tileDirectory);
    for(int i{}; i < M; i++)
    {
        for(int j{}; j < N; j++)
        {
            *reader >> tiles[i][j];
        }
    }
}

char** Maze::GetTiles() const
{
    return tiles;
}

void Maze::Generate()
{
    
}
