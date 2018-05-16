#include <iostream>
#include <map>

class Recipe_t
{
public:
    Recipe_t() :
        m_minutes(0),
        m_name("Empty"),
        m_rating(0.0) {}; // needed in order to use it as a map key or value.

    //copy constructor :Implicitly, by cpp default, will copy all members. BUT Define it like here if there are pointers involved that are not to point to the same memory that copied instance.
    Recipe_t(const Recipe_t &other) 
        { 
            m_minutes = other.m_minutes;
            m_name = other.m_name;
            m_rating = other.m_rating;
            std::cout << "Copy constructor running | " << m_name << std::endl; 
        }; // needed in order to use it as a map key or value.
        

    Recipe_t( const std::string name, const int minutes,const double rating):
        m_minutes(minutes),
        m_name(name),
        m_rating(rating)
    {};

    void print() const // needs to be const if we want to call this method when Recipe_t is in the key of the map. 
    //Map keys are const, they can not change since they are the way map is ordered.
    {
        std::cout << "Food: " << m_name << ", "
            << "Time: " << m_minutes << ", "
            << "Rating: " << m_rating << ", "<< std::endl;
    };

    //Cpp needs to compate two objects of same class when used as std::map key. So we donnot repeat. Itcompares using <operator
    bool operator< (const Recipe_t &other) const
    {
        return m_name < other.m_name;
    };

private:
    std::string m_name;
    int m_minutes;
    double m_rating;
};

int main ()
{
    // Custom class as value of the maps.
    std::map<int , Recipe_t> recipeBook;

    recipeBook[4] = Recipe_t("Pizza", 40, 9.5);
    recipeBook[2] = Recipe_t("Panacotta", 70, 9.1);

    recipeBook.insert( std::make_pair(1, Recipe_t("Bread", 120, 9.8) ) );//this runs the Copy constructor.
    //map will order the entries based on the value of the key.

    for (auto it : recipeBook)
    {
        std::cout << it.first << " : " << std::flush;
        it.second.print();
    }


    //custom objects as KEY of the map.
    std::cout << std::endl << " custom objects as KEY of the map " << std::endl;
    std::map< Recipe_t, int > recipeBook2;

    recipeBook2[Recipe_t("Pizza", 40, 9.5)] = 2;
    recipeBook2[Recipe_t("Pizza", 40, 9.5)] = 6;
    recipeBook2[Recipe_t("Pizza", 30, 9.5)] = 7;
    recipeBook2[Recipe_t("Panacotta", 70, 9.1)] = 5;

    for (auto it : recipeBook2)
    {//Note: this calls copy constructor
        std::cout << it.second << " : " << std::flush;
        it.first.print();
    }
    for (auto it = recipeBook2.begin(); it != recipeBook2.end(); it++)
    {
        std::cout << it->second << " : " << std::flush;
        it->first.print();
    }

    return 0;
}