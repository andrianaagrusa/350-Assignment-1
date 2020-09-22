// This file contains the methods which calculate the necessary data for the DNA strings.

#include <iostream>
#include <string>
#include <fstream>
#include "Calculations.h"
#include <math.h>
#include <random>

using namespace std;

// Calculate the total number (Sum) of nucleotides in the file:
float Calculations::sumDNA(string userFile)
{
  ifstream inFile;
  string line;
  inFile.open(userFile); // Opens the file to process
  int sumCount = 0;

  while (getline(inFile, line)) // Reads through each line of the file
  {
    lineLength = line.length();
    sumCount += lineLength; // Cumulates the length of each line to the total sum
  }

  // Write results to output file:
  ofstream outFile("AndrianaAgrusa.out", fstream::app);
  outFile << "The sum of the length of the DNA strings is: " << sumCount << endl;
  outFile << " " << endl;
  return sumCount;
}

// Calculate the Mean (average) number of nucleotides per line:
void Calculations::meanDNA(string userFile)
{
  ifstream inFile;
  string line;
  inFile.open(userFile); // Opens the file to process
  float sumCount = 0; // Represents the total number of nucleotides in the file
  float numOfLines = 0; // Represents the number of lines of DNA

  while (getline(inFile, line)) // Reads through each line of the file
  {
    float lineLength = line.length(); // Represents the length of the individual line of DNA
    sumCount += lineLength;
    numOfLines += 1;
  }

  meanValue = sumCount / numOfLines;

  // Write results to output file:
  ofstream outFile("AndrianaAgrusa.out", fstream::app);
  outFile << "The Mean of the length of the DNA strings is: " << meanValue << endl;
  outFile << " " << endl;
  outFile.close();

}

// Calculate the Variance in length of the DNA strings:
void Calculations::varianceDNA(string userFile)
{
  varianceValue = (finalStandardDeviation * finalStandardDeviation); // Variance = Standard Deviation ^2

  // Write results to output file:
  ofstream outFile("AndrianaAgrusa.out", fstream::app);
  outFile << "The variance of the length of the DNA strings is: " << varianceValue << endl;
  outFile << " " << endl;
  outFile.close();
}

// Calculate the Standard Deviation of the length of the DNA strings:
void Calculations::standardDeviationDNA(string userFile)
{
  ifstream inFile;
  string line;
  inFile.open(userFile);
  float sumCount = 0;
  float numOfLines = 0;

  while (getline(inFile, line))
  {
    float lineLength = line.length();
    sumCount += lineLength;
    numOfLines += 1;

    // Use Standard Deviation formula:
    float numerator = (lineLength - meanValue);
    standardDeviationValue += (numerator * numerator); // Represents the sum of the numerators throughout the loop
  }

  finalStandardDeviation = (standardDeviationValue/(numOfLines-1)); // Final value of Standard Deviation

  // Write results to output file:
  ofstream outFile("AndrianaAgrusa.out", fstream::app);
  outFile << "The Standard Deviation of the length of the DNA strings is: " << finalStandardDeviation << endl;
  outFile << " " << endl;
  outFile.close();
}

// Calculate the Relative Probability of each nucleotide occuring:
void Calculations::relProbability(string userFile)
{
  ifstream inFile;
  string line;
  inFile.open(userFile);

  // Variables representing the number of each nucleotide occuring:
  float Acount = 0;
  float Ccount = 0;
  float Gcount = 0;
  float Tcount = 0;

  float sumCount = 0; // Represents the total number of nucleotides

  while(getline(inFile, line))
  {
    // Read and analyze each individual nucleotide:
    for (int i = 0; i < line.length(); i++)
    {
      // If the letter is found, increment its count by 1
      if (toupper(line[i]) == 'A')
      {
        Acount +=1;
        sumCount +=1;
        continue;
      }
      else if (toupper(line[i]) == 'C')
      {
        Ccount +=1;
        sumCount +=1;
        continue;
      }
      else if (toupper(line[i]) == 'G')
      {
        Gcount +=1;
        sumCount +=1;
        continue;
      }
      else if (toupper(line[i]) == 'T')
      {
        Tcount +=1;
        sumCount +=1;
        continue;
      }
    }
  }

  // Probability formula for each letter:
  probA = (Acount / sumCount);
  probC = (Ccount / sumCount);
  probG = (Gcount / sumCount);
  probT = (Tcount / sumCount);

  // Write results to output file
  ofstream outFile("AndrianaAgrusa.out", fstream::app);
  outFile << "Here is the relative probability of each nucleotide: " << endl;
  outFile << "A: " << probA << endl;
  outFile << "C: " << probC << endl;
  outFile << "G: " << probG << endl;;
  outFile << "T: " << probT << endl;
  outFile << " " << endl;
  outFile.close();
}

// Calculate the probability of each Bigram (pair combination) occuring:
void Calculations::bigramProbability(string userFile)
{
  ifstream inFile;
  string line;
  inFile.open(userFile);
  float sumCount = sumDNA(userFile);

  while(getline(inFile, line))
  {
    for (int i = 0; i < line.length(); i++)
    {
      // Bigrams starting with 'A':
      if (toupper(line[i]) == 'A')
      {
        if (toupper(line[i+1]) == 'A')
        {
          AAcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'C')
        {
          ACcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'G')
        {
          AGcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'T')
        {
          ATcount += 1;
          continue;
        }
      }
      //Bigrams starting with 'C':
      else if (toupper(line[i]) == 'C')
      {
        if (toupper(line[i+1]) == 'A')
        {
          CAcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'C')
        {
          CCcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'G')
        {
          CGcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'T')
        {
          CTcount += 1;
          continue;
        }
      }
      // Bigrams starting with 'G':
      else if (toupper(line[i]) == 'G')
      {
        if (toupper(line[i+1]) == 'A')
        {
          GAcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'C')
        {
          GCcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'G')
        {
          GGcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'T')
        {
          GTcount += 1;
          continue;
        }
      }
      // Bigrams starting with 'T':
      else if (toupper(line[i]) == 'T')
      {
        if (toupper(line[i+1]) == 'A')
        {
          TAcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'C')
        {
          TCcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'G')
        {
          TGcount += 1;
          continue;
        }
        else if (toupper(line[i+1]) == 'T')
        {
          TTcount += 1;
          continue;
        }
      }
    }
  }

  // Variables representing each Bigram:
  float probAA = AAcount / sumCount;
  float probAC = ACcount / sumCount;
  float probAG = AGcount / sumCount;
  float probAT = ATcount / sumCount;
  float probCA = CAcount / sumCount;
  float probCC = CCcount / sumCount;
  float probCG = CGcount / sumCount;
  float probCT = CTcount / sumCount;
  float probGA = GAcount / sumCount;
  float probGC = GCcount / sumCount;
  float probGG = GGcount / sumCount;
  float probGT = GTcount / sumCount;
  float probTA = TAcount / sumCount;
  float probTC = TCcount / sumCount;
  float probTG = TGcount / sumCount;
  float probTT = TTcount / sumCount;

  // Write results to output file:
  ofstream outFile("AndrianaAgrusa.out", fstream::app);
  outFile << "Here is the relative probability of each nucleotide bigram: " << endl;
  outFile << "AA: " << probAA << endl;
  outFile << "AC: " << probAC << endl;
  outFile << "AG: " << probAG << endl;
  outFile << "AT: " << probAT << endl;
  outFile << "CA: " << probCA << endl;
  outFile << "CC: " << probCC << endl;
  outFile << "CG: " << probCG << endl;
  outFile << "CT: " << probCT << endl;
  outFile << "GA: " << probGA << endl;
  outFile << "GC: " << probGC << endl;
  outFile << "GG: " << probGG << endl;
  outFile << "GT: " << probGT << endl;
  outFile << "TA: " << probTA << endl;
  outFile << "TC: " << probTC << endl;
  outFile << "TG: " << probTG << endl;
  outFile << "TT: " << probTT << endl;
  outFile << " " << endl;
  outFile.close();
}

// Generate 1000 lines of DNA based on the Mean and Standard Deviation calculated in the above methods:
void Calculations::gaussianDistribution()
{
  ofstream outFile("AndrianaAgrusa.out", fstream::app);
  outFile << "1000 Generated DNA strings: " << endl;
  outFile << " " << endl;

  for (int i = 0; i < 1000; i++)
  {
    // Calculate the length of each new DNA strand using Box-Muller transform:
    float a = rand() / (RAND_MAX + 1.0);
    float b = rand() / (RAND_MAX + 1.0);
    float c = (sqrt(-2*log(a)) * cos(2*M_PI+b));
    int newLineLength = ((finalStandardDeviation * c) + meanValue);

    string newLine;

    for (int i = 0; i < newLineLength; i++)
    {
      float randProbability = rand() / (RAND_MAX + 1.0); // Creates a probability to compare nucleotide probability with

      /* Determine which nucleotide probability corresponds with the randProbability
      to distrubte the nucleotides accordingly: */
      if (0 < randProbability && randProbability < probA)
      {
        newLine += 'A';
      }
      if (probA < randProbability && randProbability < probA + probC)
      {
        newLine += 'C';
      }
      if (probA + probC < randProbability && randProbability < probA + probC + probG)
      {
        newLine += 'G';
      }
      else
      {
        newLine += 'T';
      }
    }
    // Write each new line to output file:
    outFile << newLine << endl;
  }
  outFile.close();
}
