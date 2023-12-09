#include <iostream>
#include <string>
#include <fstream>


class Address {
private:
    std::string city;
    std::string street;
    std::string houseNumber;
    std::string flatNumber;
public:
    Address() : city(), street(), houseNumber(), flatNumber() {};
   /* Address(std::string city, std::string street, std::string houseNumber, std::string flatNumber) {
         this -> city = city;
         this -> street = street;
         this -> houseNumber = houseNumber;
         this -> flatNumber = flatNumber;
     };*/

    void readFromStream(std::ifstream& inStream) {
       inStream.ignore();
        std::getline(inStream, city);
        std::getline(inStream, street);
        std::getline(inStream, houseNumber);
        std::getline(inStream, flatNumber);
    }

    void writeToStream(std::ofstream& outStream) {
        outStream << city << ", " << street << ", " << houseNumber << ", " << flatNumber << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    int N;
    inputFile >> N;
    
// Address addresses[N];
    Address* addresses = new Address[N];

    for (int i = 0; i < N; i++) {
        addresses[i].readFromStream(inputFile);
    }

    outputFile << N << std::endl;
    for (int i = N - 1; i >= 0; i--) {
        addresses[i].writeToStream(outputFile);
    }

    inputFile.close();
    outputFile.close();
    delete[] addresses;
    
    return 0;
}