#include "person.cpp"
#include "personEstates.cpp"
#include <limits>
#include <iostream>
#include <fstream>


PersonEstates createPerson(){
    char nameBuffer[100];
    char egnBuffer[100];
    char addressBuffer[100];
    int numOfAddresses;

    std::cout<<"\n"<<"Enter name:";
    std::cin.getline(nameBuffer, 100);


    std::cout<<"Enter EGN:";
    std::cin.getline(egnBuffer, 100);


    std::cout<<"Enter primary address:";
    std::cin.getline(addressBuffer, 100);


    std::cout<<"Enter number of owned estates:";
    std::cin>>numOfAddresses;
    std::cin.ignore();


    const char** estateAddresses = new const char*[numOfAddresses];

    for (int i = 1; i < numOfAddresses; ++i) {
        char estateAddress[100];
        std::cout << "Enter estate address " << (i + 1) << ": ";
        std::cin.getline(estateAddress, 100);
        estateAddresses[i] = strdup(estateAddress);
    }

    return {nameBuffer, egnBuffer, addressBuffer, numOfAddresses, estateAddresses};

}

void saveToFile(const PersonEstates& personToSave){
    std::ofstream Data("C:/Docs/BPE C/untitled/data.txt", std::ios::app);
    if (!Data.is_open()) {
        std::cerr << "Error opening file: data.txt\n";
        return;
    }

    Data << personToSave;
    Data.close();
    if (Data.fail()) {
        std::cerr << "Error writing to file\n";
    } else {
        std::cout << "Data saved\n";
    }
    Data.close();
}

void findByAddress(const std::string& addressToFind){
    std::string infoBlock, line;

    std::ifstream Data("C:/Docs/BPE C/untitled/data.txt");
    if (!Data.is_open()) {
        std::cerr << "Error opening file: data.txt\n";
        return;
    }
    bool found = false;

    while (std::getline(Data, line)) {
        size_t blockStart = line.find("EGN");
        if (blockStart != std::string::npos){
            if(found){
                break;
            }
            infoBlock.clear();
        }
        infoBlock.append(line);
        infoBlock.append("\n");
        // Check if the line contains the address
        size_t pos = line.find("Address");
        if (pos != std::string::npos) {
            std::string foundAddress = line.substr(pos + strlen("Address "));
            if (foundAddress[0] == 'p'){
                foundAddress = line.substr(pos + strlen("Address primary: "));
            }
            else{
                foundAddress = line.substr(pos + strlen("Address of estate number x: "));
            }
            // Trim leading and trailing whitespaces
            foundAddress.erase(0, foundAddress.find_first_not_of(" \t\n\r\f\v"));
            foundAddress.erase(foundAddress.find_last_not_of(" \t\n\r\f\v") + 1);

            // Compare foundAddress with the target address
            if (foundAddress == addressToFind) {
                found = true;
            }
        }
    }
    if (!found) {
        std::cout <<"\n"<< "Address not found: " << addressToFind <<"\n" <<std::endl;
    }
    else{
        std::cout <<"\n"<< "Address found: " << addressToFind <<  "\n" << std::endl;
        std::cout << infoBlock <<std::endl;
        Data.close();
        return;


    }
    Data.close();


}


void addressToSearch(){
    char addressSearch[100];
    std::cout<<"\n"<<"Enter address: ";
    std::cin.getline(addressSearch, 100);
    findByAddress(addressSearch);
}

void findByEGN(const std::string& egnToSearch){
    std::ifstream Data("C:/Docs/BPE C/untitled/data.txt");
    if (!Data.is_open()) {
        std::cerr << "Error opening file: data.txt\n";
        return;
    }

    bool found = false;
    std::string line, infoBlock;

    while (std::getline(Data, line)) {


        if(!found){
            infoBlock.clear();
        }

        size_t pos = line.find("EGN");
        if (pos != std::string::npos) {
            if(found){
                break;
            }
            std::string foundEGN = line.substr(pos + strlen("EGN: "));
            if(foundEGN == egnToSearch){
                found = true;
            }
        }
        infoBlock.append(line);
        infoBlock.append("\n");
    }
    Data.close();
    if(found){
        std::cout<<"\nPerson found:\n"<<infoBlock<<std::endl;
        return;
    }
    else{
        std::cout<<"\nPerson could not be found!\n"<<std::endl;
    }
}

void egnToSearch(){
    char egnToSearch[10];
    std::cout<<"\n"<<"Enter EGN: ";
    std::cin.getline(egnToSearch, 10);
    findByEGN(egnToSearch);
}