#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

const std::string databaseName = "/home/xavi/Projects/CppCourses/AdvancedCppUdemy/StdLists/dat/database.bin";
const unsigned int DataSize = 50;

void displayRecipes(const std::list<std::string> & recipes)
{
    for(auto it = recipes.begin() ; it != recipes.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

void displayEntry(const std::list<std::string> & recipes)
{
    std::cout << "Welome to the Recipe Ingredient storage system!" <<std::endl<<std::endl;

    std::cout << "the current list of recipes is: " <<std::endl;
    if( recipes.empty() )
    {
        std::cout << "Empty! " <<std::endl;
    }
    else
    {
        displayRecipes(recipes);
    }
    
}

void displayOptions()
{
    std::cout <<std::endl;
    std::cout << "Chose an option: " <<std::endl;
    std::cout << "1. View ingredients from recipe." <<std::endl;
    std::cout << "2. Delete a recipe." <<std::endl;
    std::cout << "3. Add new recipe" <<std::endl;
    std::cout << "4. Save and Exit" <<std::endl;
    std::cout << "5. Exit" <<std::endl;
}

void showIngredients(const std::string fileName)
{
    std::ifstream ingredients;

    std::cout << "Ingredients from " << fileName << ": " <<std::endl;

    std::string file = "/home/xavi/Projects/CppCourses/AdvancedCppUdemy/StdLists/etc/" + fileName + ".txt";
    ingredients.open(file);

    if( !ingredients.is_open() )
    {
        std::cout << "An error occurred opening " << file <<std::endl;
        return;
    }
    
    std::string line;
    while( !ingredients.eof() )
    {
        std::getline(ingredients, line);
        std::cout<< line << std::endl;
    }
    ingredients.close();
}

void viewIngredientsFromRecipe(const std::list<std::string> & recipes)
{
    std::cout << "Chose a recipe by name: " <<std::endl;
    displayRecipes(recipes);

    bool found = false;
    std::string recipe;
    std::cin >> recipe;

    for(auto it = recipes.begin() ; it != recipes.end(); it++)
    {
        if( *it == recipe)
        {
            found = true;
            showIngredients(*it);
            break;
        }
    }

    if (!found)
        std::cout << "Wrong selection." << std::endl;
}

void addRecipe(std::list<std::string> & recipes)
{
    std::cout << "Insert a new recipe by name: " <<std::endl;
    std::string new_recipe;
    bool is_new = true;
    std::cin >> new_recipe;
    auto it = recipes.begin();

    //Try to identify if recipe already exists
    while(it != recipes.end() )
    {
        if(*it == new_recipe)
        {
            is_new = false;
            break;
        }
        it++;
    }

    if(is_new)
    {
        recipes.push_back(new_recipe);
    }
}

void deleteRecipe(std::list<std::string> & recipes)
{
    displayRecipes(recipes);
    std::cout << "What recipe do you want to delete? " <<std::endl;
    std::string undesired_recipe;
    bool exists = false;
    std::cin >> undesired_recipe;
    auto it = recipes.begin();

    //Try to identify if recipe already exists
    while(it != recipes.end() )
    {
        std::cout << *it<<std::endl;
        if(*it == undesired_recipe)
        {
            exists = true;
            break;
        }
        it++;
    }

    if(exists)
    {
        recipes.erase(it);
    }
}

void saveRecipes(std::list<std::string> & recipes)
{
    std::ofstream databaseToSave;
    std::cout << "Saving current list of Recipes... " <<std::flush;

    databaseToSave.open(databaseName, std::ios::binary);

    if(!databaseToSave.is_open())
    {
        std::cout<< std::endl<< "Cannot open file " << databaseName << " for saving"<< std::endl;
        return;
    }

    //protocol is to save nr of entries and then entries
    int size = static_cast<int>( recipes.size() );
    databaseToSave.write( reinterpret_cast<char *>(&size) , sizeof(int) );
    for(auto recipe = recipes.begin() ; recipe != recipes.end(); recipe++)
    {
        databaseToSave.write( (*recipe).c_str() , sizeof(char[DataSize]) );
    }
    
    databaseToSave.close();
    std::cout << "Success! " <<std::endl;

}

void loadData(std::list<std::string> & recipes)
{
    std::ifstream databaseToRead;

    databaseToRead.open(databaseName, std::ios::binary);

    if(!databaseToRead.is_open())
    {
        std::cout<< "Cannot load file " << databaseName << " list will be empty!" << std::endl;
        return;
    }

    char entry[DataSize];
    int nrEntries;

    databaseToRead.get( reinterpret_cast<char*>(&nrEntries) , sizeof(int) );
    databaseToRead.get( );  // needed to jump to next entry
    //std::cout<< nrEntries << " position " <<databaseToRead.tellg() << std::endl;
    

    while( static_cast<int>(recipes.size()) != nrEntries )
    {
        databaseToRead.get( entry , sizeof(char[DataSize]) ); 
        //std::cout<< entry << " position " <<databaseToRead.tellg() << std::endl;
        databaseToRead.get( ); // needed to jump to next entry
        recipes.push_back(entry);
    }

    databaseToRead.close();
}

int main()
{
    std::list<std::string> recipes;
    //recipes.push_back("spaghetti_carbonara");
    //recipes.push_back("burger");

    int option = 0;
    bool quit = false;

    loadData(recipes);

    displayEntry(recipes);
    displayOptions();
    std::cin >> option;
    
    while(!quit)
    {
        switch(option)
        {
            case 1: 
            {
                viewIngredientsFromRecipe(recipes);
                displayOptions();
                std::cin >> option;
                break;
            }
            case 2: 
            {
                deleteRecipe(recipes);
                displayOptions();
                std::cin >> option;
                break;
            }
            case 3: 
            {
                addRecipe(recipes);
                displayOptions();
                std::cin >> option;
                break;
            }
            case 4: 
            {
                saveRecipes(recipes);
                quit=true;
                break;
            }
            case 5: 
            {
                std::cout << "Are you sure you do not want to save? [y/N]"<< std::endl;
                std::string is_sure;
                std::cin >> is_sure;
                if(is_sure == "y" || is_sure == "Y" || is_sure == "yes" || is_sure == "Yes")
                {
                    quit=true;
                }
                else
                {
                    displayOptions();
                    std::cin >> option;
                }
                break;
            }
            case 6:
            {
                std::cout<< recipes.size() << std::endl;
                std::cout<< recipes.max_size() << std::endl;
                displayRecipes(recipes);
                std::cin >> option;
                break;
            }
            default: 
            {
                displayOptions();
                std::cin >> option;
                break;
            }
        }
        std::cout << "option "<< option <<std::endl;

    }


    return 0;
}