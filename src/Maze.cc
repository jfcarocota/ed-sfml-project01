#include "Maze.hh"

Maze::Maze(unsigned int M, unsigned int N, const char* tilesDirectory, sf::Texture*& texture, float cropSize, float spriteScale)
{
    this->M = M;
    this->N = N;
    this->tiles = new char*[M];
    this->tileDirectory = tilesDirectory;
    this->texture = texture;
    this->cropSize = cropSize;
    this->spriteScale = spriteScale;
    AllocateMemory();
    FillMaze();
    Generate();
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
    for(int i{}; i < M; i++)
    {
        for(int j{}; j < N; j++)
        {
            char& tile{tiles[i][j]};

            switch (tile)
            {
                case 'w':
                    mazeTiles.push_back(new Tile(16 * 1, 16 * 1, spriteScale, 16, texture));
                    break;
                case 'q':
                    mazeTiles.push_back(new Tile(16 * 1, 16 * 2, spriteScale, 16, texture));
                    break;
                case 'e':
                    mazeTiles.push_back(new Tile(16 * 1, 16 * 3, spriteScale, 16, texture));
                    break;
                case 'g':
                    mazeTiles.push_back(new Tile(16 * 1, 16 * 4, spriteScale, 16, texture));
                    break;
                case 'f':
                    mazeTiles.push_back(new Tile(16 * 2, 16 * 4, spriteScale, 16, texture));
                    break;
                case 'd':
                    mazeTiles.push_back(new Tile(16 * 3, 16 * 4, spriteScale, 16, texture));
                    break;    
                case 'a':
                    mazeTiles.push_back(new Tile(16 * 1, 16 * 5, spriteScale, 16, texture));
                    break;
                case 's':
                    mazeTiles.push_back(new Tile(16 * 2, 16 * 5, spriteScale, 16, texture));
                    break;
                case 'z':
                    mazeTiles.push_back(new Tile(16 * 3, 16 * 5, spriteScale, 16, texture));
                    break;
                case 'x':
                    mazeTiles.push_back(new Tile(16 * 1, 16 * 6, spriteScale, 16, texture));
                    break;
                case 'c':
                    mazeTiles.push_back(new Tile(16 * 2, 16 * 6, spriteScale, 16, texture));
                    break;
                case 'v':
                    mazeTiles.push_back(new Tile(16 * 3, 16 * 6, spriteScale, 16, texture));
                    break;              
                default:
                    break;
            }
            mazeTiles.back()->Move(cropSize * spriteScale * j, cropSize * spriteScale * i);
        }
    }
}

unsigned int Maze::GetCols() const
{
    return N;
}

unsigned int Maze::GetRows() const
{
    return M;
}

std::vector<Tile*> Maze::GetMazeTiles() const
{
    return mazeTiles;
}
