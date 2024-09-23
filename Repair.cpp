#include "Repair.h"

using namespace std;

string Repair::findTreatment(const string& diagnosis){
    strcpy(carDiagnosis, diagnosis.c_str());
    initialize();
    while (!repaired) {
        findCondition();
        if (conFound) {
            rNum = ((cVNum/4) + 1);
            checkRules();
        }
        else
            findCondition();
    }
    return repair;
}
void Repair::initialize() {
    //TODO: add variables and clause variables from google sheet (google sheet also needs to be completed)
    strcpy(list.variable[1], "NO PROBLEM");
    strcpy(list.variable[2], "DEAD BATTERY");
    strcpy(list.variable[3], "BAD ALTERNATOR");

    strcpy(list.clauseVariable[1], "NO PROBLEM");
    strcpy(list.clauseVariable[5], "DEAD BATTERY");
    strcpy(list.clauseVariable[9], "BAD ALTERNATOR");
}
void Repair::findCondition(){
    conFound = false;
        //TODO:replace (1) with total clause variable
        for (int i = 0; i < (3); i++) {
            if (strcmp(carDiagnosis, list.clauseVariable[i]) == 0) {
                conFound = true;
                cVNum = i;
            }
        }
}
void Repair::checkRules() {
    //todo: Add repairs
    switch (rNum) {
        case 1:
            if (strcmp(carDiagnosis, list.variable[1]) == 0){
                repair = "No Repair Needed";
                repaired = true;
            }
            break;
        case 2:
            if (strcmp(carDiagnosis, list.variable[2]) == 0){
                repair = "Recharge or Replace Battery";
                repaired = true;
            }
            break;
    }
}

