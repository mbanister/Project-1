#include "Diagnosis.h"

using namespace std;

string Diagnosis::startDiagnosis(){
    initialize();
    //start conclusion stack with first conclusion (DIAGNOSIS)
    cStack.push(0);
    //initializes cvStack (gets popped in do while loop)
    cvStack.push(0);
    //cNumInc = 0;
    //cvNumInc = 0;
    //total increments (mostly useless but exists if there happens to be a 4th variable to a rule)
    int totalInc;
    //while conclusions still on stack
    do{
        totalInc = 0;
        //stops once empty cv is found (or at the end of the conclusion but this never happens)
        while (strlen(claVar) != 0 && totalInc < 4){
            //conclusion on stack not found
            conFound = false;
            //YE OL' GENERAL FORMULA (4 * (rule number / 10 -1) + 1)
            cVNum = 4 * cStack.top() + cvStack.top();
            //pops current cv and places next one on stack
            cvNumInc = cvStack.top() + 1;
            cvStack.pop();
            cvStack.push(cvNumInc);
            totalInc++;
            //brings cv from cv stack
            strcpy(claVar, list.clauseVariable[cVNum]);
            //if cv is not blank
            if(strlen(claVar) != 0){
                findConclusion(claVar);
                if (conFound){
                    //push a buffer to save next cv for later
                    cvStack.push(0);
                    totalInc = 0;
                    //skips question
                    continue;
                }
                askQuestion();
            }
        }
        checkRules();
        if (conSolved){
            //pop stacks
            cStack.pop();
            cvStack.pop();
            conSolved = false;
        }
        else{
            //stacks point to next conclusion
            int cNumInc = cStack.top() + 1;
            cStack.pop();
            cStack.push(cNumInc);
            //refresh cv stack
            cvStack.pop();
            cvStack.push(0);
        }
    }while(!cStack.empty());
    return problem;
}
void Diagnosis::initialize() {
    //TODO: Add conclusions, variables and clause variables from google sheet
    strcpy(list.conclusion[0], "DIA"); //Diagnosis
    strcpy(list.conclusion[1], "BAT"); //Battery issues
    strcpy(list.conclusion[2], "DIA");

    //variable arrays also double as an answer storage with the additional secondary array size (see askQuestion())
    strcpy(list.variable[0], "CaT");//Car Troubles
    strcpy(list.variable[1], "CaS");//Car Starts
    strcpy(list.variable[2], "BCL");//Battery Check Light
    strcpy(list.variable[3], "HoC");//Holds Charge


    strcpy(list.clauseVariable[0],"CaT");//Diagnosis: no problems
    strcpy(list.clauseVariable[4],"CaS");//Battery issues: true
    strcpy(list.clauseVariable[5],"BCL");
    strcpy(list.clauseVariable[8],"BAT");//Diagnosis: Dead Battery



}

void Diagnosis::findConclusion(char conSearch[4]) {
    //steps through conclusion until passed var is found
    for (int i = 0; i < 32; i++) {
        //if con found, pushes on stack
        if (strcmp(conSearch, list.conclusion[i]) == 0) {
            cStack.push(i);
            conFound = true;
            *newCon = 0;
            strcpy(newCon, conSearch);
            return;
        }
    }
}
void Diagnosis::checkRules() {
    //TODO: Finish rules (finish askQuestion() first) keep in mind char array size of carDiagnosis in repair.h
    switch(cStack.top() + 1){
        //if no car problems
        case 1: if(list.variable[0][3] == '2' ){
                conSolved = 1;
                problem = "NO PROBLEM";
            }
            break;
        //if car starts and battery light is on
        case 2: if(list.variable[1][3] == '1' && list.variable[2][3] == '1'){
                conSolved = 1;
                //conclusions have their own variables in header
                battery = true;
            }
            break;
        // if battery issues and holds charge
        case 3: if(battery &&  list.variable[3][3] == '1' ){
                conSolved = 1;
                problem = "DEAD BATTERY";
            }
            break;
    }
}
void Diagnosis::askQuestion() {
    switchNum = 0;
    //finds variable
    for (int i = 0; i < 29; i++) {
        if (strncmp(list.variable[i], list.clauseVariable[cVNum], 3) == 0) {
            switchNum = i;
            break;
        }
    }
    //TODO: add questions
    switch (switchNum + 1) {
        case 1:
            while(list.variable[0][3] != '1' || list.variable[0][3] != '2'){
                cout << "Does the car have any issues?\n";
                cout << "Input 1 for yes or 2 for no\n";
                cin >> list.variable[0][3]; //3rd element is for storing answers
            }
            break;
        case 2:
            while(list.variable[1][3] != '1' && list.variable[1][3] != '2'){
                cout << "Will the car start?\n";
                cout << "Input 1 for yes or 2 for no\n";
                cin >> list.variable[1][3];
            }
            break;
        case 3:
            //[switchNum][3] also works
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the battery check light on?\n";
                cout << "Input 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
    }
}


