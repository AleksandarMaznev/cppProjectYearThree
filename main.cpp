#include <iostream>
#include "person.cpp"
#include "personEstates.cpp"
#include "functions.cpp"

int main() {

    int choice = 0;

    while (true){
        std::cout<<"What would you like to do?\n0. Exit\n1. Add new person\n2. Find person by address\n3. Find person bt EGN\n"<<std::endl;
        std::cout<<"Enter choice:";
        std::cin>> choice;
        std::cin.ignore();
        if (choice == 0){
            break;
        }
        else if(choice == 1) {
            int save = 0;
            PersonEstates person = createPerson();
            std::cout<<"\n"<<person<<std::endl;
            std::cout<<"Would you like to save this information? (1/0):";
            std::cin>>save;
            std::cout<<"\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (save == 1){
                saveToFile(person);
            }
        }
        else if(choice == 2){
            addressToSearch();
        }

        else if(choice == 3){
            egnToSearch();
        }

        else{
            std::cout<< "Invalid response!\n"<< std::endl;
        }
    }

    return 0;
}
