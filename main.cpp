#include <iostream>
#include <string>
#include <fstream>
#include "Calculations.h"
using namespace std;

int main() {

  while (true)
  {

    // Get user input for which file they want to open and process:
    ifstream inFile;
    cout << "Enter the file you would like to process: ";
    string userFile;
    cin >> userFile;

    // Writing name/id/class onto the output file:
    ofstream outFile("AndrianaAgrusa.out", fstream::app);
    outFile << "Andriana Agrusa" << endl;
    outFile << "ID: 2344125" << endl;
    outFile << "CPSC 350-02" << endl;
    outFile << " " << endl;
    outFile.close();

    // Running the methods in Calculations.cpp on the file which the user opened:
    Calculations* calculations = new Calculations();
    calculations->sumDNA(userFile);
    calculations->meanDNA(userFile);
    calculations->standardDeviationDNA(userFile);
    calculations->varianceDNA(userFile);
    calculations->relProbability(userFile);
    calculations->bigramProbability(userFile);
    calculations->gaussianDistribution();

    // Asking the user if they would like to process another file:
    cout << "Results have been recorded. Would you like to process another file? (type yes or no)" << endl;
    string userChoice;
    cin >> userChoice;
    if (userChoice == "yes")
    {
      continue;
    }
    else
    {
      break;
    }
  }

  return 0;
}
