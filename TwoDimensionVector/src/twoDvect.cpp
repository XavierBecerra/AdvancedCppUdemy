#include <iostream>
#include <vector>

int main ()
{
    std::vector< std::vector<int> > grid(3, std::vector<int>(4, 6) );//presize 3 rows 4 columns with 6cd  values

    grid[1].push_back(8);

    for(auto row : grid)
    {
        for(auto col : row)
        {
            std::cout << col << std::flush;
        }
        std::cout << std::endl;
    }
    
    return 0;
}