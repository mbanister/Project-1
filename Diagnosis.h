#ifndef PROJECT1_DIAGNOSIS_H
#define PROJECT1_DIAGNOSIS_H
#include <iostream>
#include<string>
#include <stack>
#include<fstream>
#include <cstring>
#include<limits>

using namespace std;

class Diagnosis{
private:
    bool conSolved, conFound,
        battery, overheat, brakes, engineIssue; //Todo: create other conclusion variables
    string problem;
    int cVNum, cvNumInc, /*cNumInc,*/ switchNum;
    char newCon[4], claVar[4] = "emp";
    stack <int> cStack;
    stack <int> cvStack;
    struct List{
        char conclusion[52][4];
        char variable[32][5];
        char clauseVariable[311][4] = {};
    }list;
public:
    string startDiagnosis();
    void initialize();
    void findConclusion(char conSearch[4]);
    void askQuestion();
    void checkRules();
};



#endif //PROJECT1_DIAGNOSIS_H
