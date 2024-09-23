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
    bool ruleFound, repaired = false;
    char carDiagnosis[30];
    int rNum, cVNum = 0;
    string repair;
    stack <int> cvStack;
    struct List{
        char variable[29][30];
        char clauseVariable[60][30];
    }list;
public:
    string findTreatment(const string&);
    void initialize();
    void findRule();
    void checkRules();
};


#endif //PROJECT1_TREATMENT_H
