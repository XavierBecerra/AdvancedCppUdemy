#include <iostream>
#include <fstream>

//About Structs: 
// Members of struct are public by default. (not the case for classes).
// Structs are quite oftn used for writting to files because we can map the bites tdirectly to the members of the structs (different sizes)
// When declaring internal members of a struct that we want to write int file for future uses, we need to be carefull.
// For instance, std::string does not store the text directly into this variable (so not on the stack memory), but it allocates it (using new) in the heap memory and it
// (the string class) has a pointer in memory that points to the created memory in the heap (in the RAM) so if we save std::string
// we are just saving the pointer, so if we recall the binary we would be recalling a pointer that no longer points to any meaningfull memory in the heap.

#pragma pack(push,1)// Preprocessor directive thaat enables saving the struct bite by bite. So we write into the binary the needed bites. with 1 is aligning the data on whatever follows in 1 byte. So no padding.
struct Person_t
{
    //std::string name; // DO NOT USE! use char array instead
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)
struct Person_padding_t
{
    //std::string name; // DO NOT USE! use char array instead
    char name[50];
    int age;
    double height;
};


int main()
{
    //test
    std::cout << "Size of Person_t struct is: " << sizeof(Person_t) << std::endl;
    std::cout << "Size of Person_padding_t struct is: " << sizeof(Person_padding_t) << std::endl;

    Person_t person = {"Messi", 30, 1.70};

    std::string fileName = "binTest.bin";

    //Letś write the binary file
    std::ofstream outFile;
    outFile.open(fileName, std::ios::binary); //need to pass ios::binary to prevent cpp from messing with the file.

    if(!outFile.is_open())
    {
        std::cout<< "Cannot open file " << fileName.data() << " For writing"<< std::endl;
        return 1;
    }

    outFile.write( reinterpret_cast<char *>(&person) , sizeof(Person_t) ); //About casting see https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
    outFile.close();

    //Letś read the binary file
    std::ifstream inFile;
    inFile.open(fileName, std::ios::binary); 
    if(!inFile.is_open())
    {
        std::cout<< "Cannot open file " << fileName.data() << " For reading"<< std::endl;
        return 1;
    }

    Person_t newPerson = {"Noone", 0, 0.0};
    std::cout<< "New Person after birth: name - " << newPerson.name << ", age - " << newPerson.age << ", height - " << newPerson.height << std::endl; 

    inFile.read( reinterpret_cast<char *>(&newPerson) , sizeof(Person_t) ); 
    inFile.close();

    std::cout<< "New Person mature: name - " << newPerson.name << ", age - " << newPerson.age << ", height - " << newPerson.height << std::endl; 


    return 0;
}