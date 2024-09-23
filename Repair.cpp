#include "Repair.h"

using namespace std;

string Repair::findTreatment(const string& diagnosis){
    strcpy(carDiagnosis, diagnosis.c_str());
    initialize();
    while (!repaired) {
        findRule();
        if (ruleFound) {
            rNum = ((cVNum/4) + 1);
            checkRules();
        }
        else
            findRule();
    }
    return repair;
}
void Repair::initialize() {
    strcpy(list.variable[1], "NO PROBLEM");
    strcpy(list.variable[2], "DEAD BATTERY");
    strcpy(list.variable[3], "BAD ALTERNATOR");
    strcpy(list.variable[4], "DEFLATED TIRE");
    strcpy(list.variable[5], "LOW COOLANT");
    strcpy(list.variable[6], "BAD WATER PUMP");
    strcpy(list.variable[7], "RADIATOR DAMAGE");
    strcpy(list.variable[8], "FAULTY THERMOSTAT");
    strcpy(list.variable[9], "LOW WWF");
    strcpy(list.variable[10], "POWER WINDOW");
    strcpy(list.variable[11], "BROKEN CV JOINT");
    strcpy(list.variable[12], "POWER STEERING");
    strcpy(list.variable[13], "LOW BRAKE FLUID");
    strcpy(list.variable[14], "WORN BRAKE PADS");
    strcpy(list.variable[15], "BRAKE SYS MALF");
    strcpy(list.variable[16], "WHEEL SPEED SNS");
    strcpy(list.variable[17], "ABS SYSTEM MALF");
    strcpy(list.variable[18], "LOW OIL");
    strcpy(list.variable[19], "TIMING BELT BRK");
    strcpy(list.variable[20], "NO FUEL");
    strcpy(list.variable[21], "BAD OXYGEN SNSR");
    strcpy(list.variable[22], "BAD SPARK PLUG");
    strcpy(list.variable[23], "BAD FUEL PUMP");
    strcpy(list.variable[24], "AIR FILTER CLOG");
    strcpy(list.variable[25], "STARTER MOTOR");
    strcpy(list.variable[26], "M AIR FLOW SNSR");
    strcpy(list.variable[27], "LOOSE GAS CAP");
    strcpy(list.variable[28], "STUCK EGR VALVE");

    strcpy(list.clauseVariable[1], "NO PROBLEM");
    strcpy(list.clauseVariable[5], "DEAD BATTERY");
    strcpy(list.clauseVariable[9], "BAD ALTERNATOR");
    strcpy(list.clauseVariable[10], "BAD WATER PUMP");
    strcpy(list.clauseVariable[11], "RADIATOR DAMAGE");
    strcpy(list.clauseVariable[13], "DEFLATED TIRE");
    strcpy(list.clauseVariable[17], "LOW COOLANT");
    strcpy(list.clauseVariable[18], "LOW WWF");
    strcpy(list.clauseVariable[19], "LOW BRAKE FLUID");
    strcpy(list.clauseVariable[20], "LOW OIL");
    strcpy(list.clauseVariable[21], "FAULTY THERMOSTAT");
    strcpy(list.clauseVariable[22], "WHEEL SPEED SNS");
    strcpy(list.clauseVariable[23], "BAD OXYGEN SNSR");
    strcpy(list.clauseVariable[24], "M AIR FLOW SNSR");
    strcpy(list.clauseVariable[25], "POWER WINDOW");
    strcpy(list.clauseVariable[26], "ABS SYSTEM MALF");
    strcpy(list.clauseVariable[27], "STARTER MOTOR");
    strcpy(list.clauseVariable[29], "BROKEN CV JOINT");
    strcpy(list.clauseVariable[33], "POWER STEERING");
    strcpy(list.clauseVariable[37], "WORN BRAKE PADS");
    strcpy(list.clauseVariable[38], "TIMING BELT BRK");
    strcpy(list.clauseVariable[39], "BAD SPARK PLUG");
    strcpy(list.clauseVariable[40], "BAD FUEL PUMP");
    strcpy(list.clauseVariable[41], "BRAKE SYS MALF");
    strcpy(list.clauseVariable[45], "NO FUEL");
    strcpy(list.clauseVariable[49], "AIR FILTER CLOG");
    strcpy(list.clauseVariable[53], "LOOSE GAS CAP");
    strcpy(list.clauseVariable[57], "STUCK EGR VALVE");
}
void Repair::findRule(){
    ruleFound = false;
        for (int i = 0; i < (60); i++) {
            if (strcmp(carDiagnosis, list.clauseVariable[i]) == 0) {
                ruleFound = true;
                cVNum = i;
            }
        }
}
void Repair::checkRules() {
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
        case 3:
            if (strcmp(carDiagnosis, list.variable[3]) == 0 || strcmp(carDiagnosis, list.variable[6]) == 0 ||
                strcmp(carDiagnosis, list.variable[7]) == 0){
                repair = "Replace inner components";
                repaired = true;
            }
            break;
        case 4:
            if (strcmp(carDiagnosis, list.variable[4]) == 0){
                repair = "Replace or inflate tire";
                repaired = true;
            }
            break;
        case 5:
            if (strcmp(carDiagnosis, list.variable[5]) == 0 || strcmp(carDiagnosis, list.variable[9]) == 0 ||
                strcmp(carDiagnosis, list.variable[13]) == 0|| strcmp(carDiagnosis, list.variable[18]) == 0){
                repair = "Refill";
                repaired = true;
            }
            break;
        case 6:
            if (strcmp(carDiagnosis, list.variable[8]) == 0 || strcmp(carDiagnosis, list.variable[16]) == 0 ||
                strcmp(carDiagnosis, list.variable[21]) == 0 || strcmp(carDiagnosis, list.variable[26]) == 0){
                repair = "Replace Sensor";
                repaired = true;
            }
            break;
        case 7:
            if (strcmp(carDiagnosis, list.variable[10]) == 0 || strcmp(carDiagnosis, list.variable[17]) == 0 ||
                strcmp(carDiagnosis, list.variable[25]) == 0){
                repair = "Repair wiring/fuses";
                repaired = true;
            }
            break;
        case 8:
            if (strcmp(carDiagnosis, list.variable[11]) == 0){
                repair = "Replace CV Axle";
                repaired = true;
            }
            break;
        case 9:
            if (strcmp(carDiagnosis, list.variable[12]) == 0){
                repair = "Replace power steering pump";
                repaired = true;
            }
            break;
        case 10:
            if (strcmp(carDiagnosis, list.variable[14] ) == 0 || strcmp(carDiagnosis, list.variable[19]) == 0 ||
                strcmp(carDiagnosis, list.variable[22]) == 0 || strcmp(carDiagnosis, list.variable[23]) == 0){
                repair = "Replace entire part";
                repaired = true;
            }
            break;
        case 11:
            if (strcmp(carDiagnosis, list.variable[15]) == 0){
                repair = "Parking brake adjustment or check hydraulics";
                repaired = true;
            }
            break;
        case 12:
            if (strcmp(carDiagnosis, list.variable[20]) == 0){
                repair = "Refuel";
                repaired = true;
            }
            break;
        case 13:
            if (strcmp(carDiagnosis, list.variable[24]) == 0){
                repair = "Replace filter";
                repaired = true;
            }
            break;
        case 14:
            if (strcmp(carDiagnosis, list.variable[27]) == 0){
                repair = "Tighten gas cap";
                repaired = true;
            }
            break;
        case 15:
            if (strcmp(carDiagnosis, list.variable[28]) == 0){
                repair = "Clean and replace gasket";
                repaired = true;
            }
            break;
    }
}

