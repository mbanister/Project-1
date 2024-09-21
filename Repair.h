#ifndef PROJECT1_TREATMENT_H
#define PROJECT1_TREATMENT_H
#include <iostream>
#include<string>
#include <stack>
#include<vector>
#include<fstream>
#include <cstring>
#include<limits>

using namespace std;

class Repair{
private:
    bool conFound, repaired = false;
    char carDiagnosis[15];
    int rNum, cVNum = 0;
    string repair;stack <int> cvStack;
    struct List{
        char variable[8][15];
        char clauseVariable[67][15];
    }list;
public:
    string findTreatment(const string&);
    void initialize();
    void findCondition();
    void checkRules();
};


#endif //PROJECT1_TREATMENT_H
