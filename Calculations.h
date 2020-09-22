// Header file for Calculations.cpp

using namespace std;
#include <string>
#include <iostream>

class Calculations {

  public:
    Calculations(){}

    float sumDNA(string userFile);
    void meanDNA(string userFile);
    void standardDeviationDNA(string userFile);
    void varianceDNA(string userFile);
    void relProbability(string userFile);
    void bigramProbability(string userFile);
    void gaussianDistribution();

    float sumCount;
    float lineLength;
    float meanValue;
    float standardDeviationValue;
    float varianceValue;
    float finalStandardDeviation;

    float probA;
    float probC;
    float probG;
    float probT;

    float AAcount;
    float ACcount;
    float AGcount;
    float ATcount;
    float CAcount;
    float CCcount;
    float CGcount;
    float CTcount;
    float GAcount;
    float GCcount;
    float GGcount;
    float GTcount;
    float TAcount;
    float TCcount;
    float TGcount;
    float TTcount;
};
