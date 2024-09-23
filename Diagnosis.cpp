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
        /*while ((cStack.size() < 2 && strcmp(newCon, list.conclusion[cStack.top()]) != 0) &&
               strcmp("DIA", list.conclusion[cStack.top()]) != 0) {
            cNumInc = cStack.top() + 1;
            cStack.pop();
            cStack.push(cNumInc);
        }*/
        //stops once empty cv is found (or at the end of the conclusion but this never happens)
        do{
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
                //askQuestion();
            }
        }while (strlen(claVar) != 0 && totalInc < 4);
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
            while(strcmp(list.conclusion[0], list.conclusion[cStack.top()]) != 0){
                cNumInc = cStack.top() + 1;
                cStack.pop();
                cStack.push(cNumInc);
            }
            //refresh cv stack
            cvStack.pop();
            cvStack.push(0);

        }
    }while(!cStack.empty());
    return problem;
}
void Diagnosis::initialize() {
    strcpy(list.conclusion[0], "DIA"); //Diagnosis
    strcpy(list.conclusion[1], "BAT"); //Battery issues
    strcpy(list.conclusion[2], "DIA");
    strcpy(list.conclusion[3], "DIA");
    strcpy(list.conclusion[4], "DIA");
    strcpy(list.conclusion[5], "EVH"); //Engine overheats
    strcpy(list.conclusion[6], "DIA");
    strcpy(list.conclusion[7], "DIA");
    strcpy(list.conclusion[8], "DIA");
    strcpy(list.conclusion[9], "DIA");
    strcpy(list.conclusion[10], "DIA"); 
    strcpy(list.conclusion[11], "DIA"); 
    strcpy(list.conclusion[12], "DIA");
    strcpy(list.conclusion[13], "DIA");
    strcpy(list.conclusion[14], "BRK"); //Brake issues
    strcpy(list.conclusion[15], "DIA");
    strcpy(list.conclusion[16], "DIA");
    strcpy(list.conclusion[17], "DIA");
    strcpy(list.conclusion[18], "DIA");
    strcpy(list.conclusion[19], "DIA");
    strcpy(list.conclusion[20], "DIA");
    strcpy(list.conclusion[21], "DIA");
    strcpy(list.conclusion[22], "DIA");
    strcpy(list.conclusion[23], "EGI"); //Engine issues
    strcpy(list.conclusion[24], "DIA");
    strcpy(list.conclusion[25], "DIA");
    strcpy(list.conclusion[26], "DIA");
    strcpy(list.conclusion[27], "DIA");
    strcpy(list.conclusion[28], "DIA");
    strcpy(list.conclusion[29], "DIA");
    strcpy(list.conclusion[30], "DIA");
    strcpy(list.conclusion[31], "DIA");

    //variable arrays also double as an answer storage with the additional secondary array size (see askQuestion())
    strcpy(list.variable[0], "CaT");//Car Troubles
    strcpy(list.variable[1], "CaS");//Car Starts
    strcpy(list.variable[2], "BCL");//Battery Check Light
    strcpy(list.variable[3], "HoC");//Holds Charge
    strcpy(list.variable[4], "TPL");//TPMS light
    strcpy(list.variable[5], "TpW");//Temp warning
    strcpy(list.variable[6], "Coo");//Coolant
    strcpy(list.variable[7], "Sqk");//Squeaking noise
    strcpy(list.variable[8], "RFC");//Radiator Fan clog
    strcpy(list.variable[9], "ThM");//Thermometer malf.
    strcpy(list.variable[10], "WWF");//WWF light
    strcpy(list.variable[11], "Win");//Window stuck
    strcpy(list.variable[12], "CkT");//Clicking noise when turn
    strcpy(list.variable[13], "DfT");//Difficulty turning
    strcpy(list.variable[14], "BkL");//Brake light
    strcpy(list.variable[15], "BkF");//Brake fluid
    strcpy(list.variable[16], "BkP");//Brake pads
    strcpy(list.variable[17], "ABS");//ABS light
    strcpy(list.variable[18], "Oil");//Oil pressure
    strcpy(list.variable[19], "TmB");//Timing Belt
    strcpy(list.variable[20], "EgL");//Engine light
    strcpy(list.variable[21], "StS");//Strange Smell
    strcpy(list.variable[22], "SkP");//Spark plugs
    strcpy(list.variable[23], "Spt");//Sputtering
    strcpy(list.variable[24], "Air");//Air filter
    strcpy(list.variable[25], "CkS");//Clicking while starting
    strcpy(list.variable[26], "PrA");//Poor acceleration
    strcpy(list.variable[27], "Gas");//Gas cap
    strcpy(list.variable[28], "Ems");//Emissions
    strcpy(list.variable[29], "Fue");//Fuel level

    strcpy(list.clauseVariable[0],"CaT");//Diagnosis: no problems
    strcpy(list.clauseVariable[4],"CaS");//Battery issues: true
    strcpy(list.clauseVariable[5],"BCL");
    strcpy(list.clauseVariable[8],"BAT");//Diagnosis: Dead Battery
    strcpy(list.clauseVariable[9],"HoC");
    strcpy(list.clauseVariable[12],"BAT");
    strcpy(list.clauseVariable[13],"HoC");
    strcpy(list.clauseVariable[16],"CaS");
    strcpy(list.clauseVariable[17],"TPL");
    strcpy(list.clauseVariable[20],"CaS");
    strcpy(list.clauseVariable[21],"TpW");
    strcpy(list.clauseVariable[24],"EVH");
    strcpy(list.clauseVariable[25],"Coo");
    strcpy(list.clauseVariable[28],"EVH");
    strcpy(list.clauseVariable[29],"Sqk");
    strcpy(list.clauseVariable[32],"EVH");
    strcpy(list.clauseVariable[33],"RFC");
    strcpy(list.clauseVariable[36],"EVH");
    strcpy(list.clauseVariable[37],"ThM");
    strcpy(list.clauseVariable[40],"CaS");
    strcpy(list.clauseVariable[41],"WWF");
    strcpy(list.clauseVariable[44],"CaS");
    strcpy(list.clauseVariable[45],"Win");
    strcpy(list.clauseVariable[48],"CaS");
    strcpy(list.clauseVariable[49],"CkT");
    strcpy(list.clauseVariable[52],"CaS");
    strcpy(list.clauseVariable[53],"DfT");
    strcpy(list.clauseVariable[56],"CaS");
    strcpy(list.clauseVariable[57],"BkL");
    strcpy(list.clauseVariable[60],"BRK");
    strcpy(list.clauseVariable[61],"BkF");
    strcpy(list.clauseVariable[64],"BRK");
    strcpy(list.clauseVariable[65],"BkP");
    strcpy(list.clauseVariable[68],"BRK");
    strcpy(list.clauseVariable[69],"BkF");
    strcpy(list.clauseVariable[70],"BkP");
    strcpy(list.clauseVariable[72],"CaS");
    strcpy(list.clauseVariable[73],"ABS");
    strcpy(list.clauseVariable[74],"BkF");
    strcpy(list.clauseVariable[76],"CaS");
    strcpy(list.clauseVariable[77],"ABS");
    strcpy(list.clauseVariable[78],"BkF");
    strcpy(list.clauseVariable[80],"CaS");
    strcpy(list.clauseVariable[81],"Oil");
    strcpy(list.clauseVariable[84],"CaS");
    strcpy(list.clauseVariable[85],"TmB");
    strcpy(list.clauseVariable[88],"CaS");
    strcpy(list.clauseVariable[89],"Fue");
    strcpy(list.clauseVariable[92],"CaS");
    strcpy(list.clauseVariable[93],"EgL");
    strcpy(list.clauseVariable[96],"EGI");
    strcpy(list.clauseVariable[97],"StS");
    strcpy(list.clauseVariable[100],"EGI");
    strcpy(list.clauseVariable[101],"SkP");
    strcpy(list.clauseVariable[104],"EGI");
    strcpy(list.clauseVariable[105],"Spt");
    strcpy(list.clauseVariable[108],"EGI");
    strcpy(list.clauseVariable[109],"Air");
    strcpy(list.clauseVariable[112],"EGI");
    strcpy(list.clauseVariable[113],"CkS");
    strcpy(list.clauseVariable[116],"EGI");
    strcpy(list.clauseVariable[117],"PrA");
    strcpy(list.clauseVariable[120],"EGI");
    strcpy(list.clauseVariable[121],"Gas");
    strcpy(list.clauseVariable[124],"EGI");
    strcpy(list.clauseVariable[125],"Ems");
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
    switch(cStack.top() + 1){
        //if no car problems
        /*case 1: if(list.variable[0][3] == '2' ){
                conSolved = 1;
                problem = "NO PROBLEM";
            }
            break;*/
        case 1:
            if(list.variable[0][3] == 0)
                askQuestion(0);
            if(list.variable[0][3] == '2' ){
                conSolved = true;
                problem = "NO PROBLEM";
            }
            break;
        //if car starts and battery light is on
        case 2:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if (list.variable[1][3] == '1') {
                if (list.variable[2][3] == 0)
                    askQuestion(2);
            }
            if (list.variable[1][3] == '1' && list.variable[2][3] == '1') {
                //conclusions have their own variables in header
                battery = true;
            }
            else
                battery = false;
            conSolved = true;
            break;
        // if battery issues and holds charge
        case 3:
            if (battery){
                if (list.variable[3][3] == 0)
                    askQuestion(3);
            }
            if(battery &&  list.variable[3][3] == '1' ){
                conSolved = true;
                problem = "DEAD BATTERY";
            }
            break;
        //if battery issues and doesn't hold charge
        case 4:
            if (battery){
                if (list.variable[3][3] == 0)
                    askQuestion(3);
            }
            if(battery &&  list.variable[3][3] == '2' ){
                conSolved = true;
                problem = "BAD ALTERNATOR";
            }
            break;
        //if car starts and TPMS light on
        case 5:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[4][3] == 0)
                    askQuestion(4);
            }
            if(list.variable[1][3] == '1' &&  list.variable[4][3] == '1' ){
                conSolved = true;
                problem = "DEFLATED TIRE";
            }
            break;
        //if car starts and temp warning light on
        case 6:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[5][3] == 0)
                    askQuestion(5);
            }
            if(list.variable[1][3] == '1' &&  list.variable[5][3] == '1' ){
                overheat = true;
            }
            else
                overheat = false;
            conSolved = true;
            break;
        //if overheating and coolant low
        case 7:
            if(overheat){
                if (list.variable[6][3] == 0)
                    askQuestion(6);
            }
            if(overheat &&  list.variable[6][3] == '1' ){
                conSolved = true;
                problem = "LOW COOLANT";
            }
            break;
        //if overheating and squeaking noises
        case 8:
            if(overheat){
                if (list.variable[7][3] == 0)
                    askQuestion(7);
            }
            if(overheat &&  list.variable[7][3] == '1' ){
                conSolved = true;
                problem = "BAD WATER PUMP";
            }
            break;
        //if overheating and radiator fan clogged
        case 9:
            if(overheat){
                if (list.variable[8][3] == 0)
                    askQuestion(8);
            }
            if(overheat &&  list.variable[8][3] == '1' ){
                conSolved = true;
                problem = "RADIATOR DAMAGE";
            }
            break;
        //if overheating and thermostat malf.
        case 10:
            if(overheat){
                if (list.variable[9][3] == 0)
                    askQuestion(9);
            }
            if(overheat &&  list.variable[9][3] == '1' ){
                conSolved = true;
                problem = "FAULTY THERMOSTAT";
            }
            break;
        //if car starts and WWF light on
        case 11:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[10][3] == 0)
                    askQuestion(10);
            }
            if(list.variable[1][3] == '1' &&  list.variable[10][3] == '1' ){
                conSolved = true;
                problem = "LOW WWF";
            }
            break;
        //if car starts and window stuck
        case 12:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[11][3] == 0)
                    askQuestion(11);
            }
            if(list.variable[1][3] == '1' &&  list.variable[11][3] == '1' ){
                conSolved = true;
                problem = "POWER WINDOW";
            }
            break;
        //if car starts and clicking while turning
        case 13:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[12][3] == 0)
                    askQuestion(12);
            }
            if(list.variable[1][3] == '1' &&  list.variable[12][3] == '1' ){
                conSolved = true;
                problem = "BROKEN CV JOINT";
            }
            break;
        //if car starts and difficulty turning
        case 14:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[13][3] == 0)
                    askQuestion(13);
            }
            if(list.variable[1][3] == '1' &&  list.variable[13][3] == '1' ){
                conSolved = true;
                problem = "POWER STEERING";
            }
            break;
        //if car starts and brake warning light on
        case 15:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[14][3] == 0)
                    askQuestion(14);
            }
            if(list.variable[1][3] == '1' &&  list.variable[14][3] == '1' ){
                brakes = true;
            }
            else
                brakes = false;
            conSolved = true;
            break;
        //if brake issues and brake fluid low
        case 16:
            if(brakes){
                if (list.variable[15][3] == 0)
                    askQuestion(15);
            }
            if(brakes &&  list.variable[15][3] == '1' ){
                conSolved = true;
                problem = "LOW BRAKE FLUID";
            }
            break;
        //if brake issues and brake pads worn
        case 17:
            if(brakes){
                if (list.variable[16][3] == 0)
                    askQuestion(16);
            }
            if(brakes &&  list.variable[16][3] == '1' ){
                conSolved = true;
                problem = "WORN BRAKE PADS";
            }
            break;
        //if brake issues and brake fluid and pads normal
        case 18:
            if(brakes){
                if (list.variable[16][3] == 0)
                    askQuestion(16);
            }
            if(brakes &&  list.variable[15][3] == '2' && list.variable[16][3] == '2'){
                conSolved = true;
                problem = "BRAKE SYS MALF";
            }
            break;
        // if car starts and ABS light on and brake fluid low
        case 19:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[17][3] == 0)
                    askQuestion(17);
                if(list.variable[17][3] == '1') {
                    if (list.variable[15][3] == 0)
                        askQuestion(15);
                }
            }
            if(list.variable[1][3] == '1' &&  list.variable[17][3] == '1' && list.variable[15][3] == '1'){
                conSolved = true;
                problem = "WHEEL SPEED SNS";
            }
            break;
        // if car starts and ABS light on and brake fluid normal
        case 20:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[17][3] == 0)
                    askQuestion(17);
                if(list.variable[17][3] == '1') {
                    if (list.variable[15][3] == 0)
                        askQuestion(15);
                }
            }
            if(list.variable[1][3] == '1' &&  list.variable[17][3] == '1' && list.variable[15][3] == '2'){
                conSolved = true;
                problem = "ABS SYSTEM MALF";
            }
            break;
        //if car starts and oil pressure low
        case 21:
            if(list.variable[1][3] == 0)
            askQuestion(1);
            if(list.variable[1][3] == '1') {
                if (list.variable[18][3] == 0)
                    askQuestion(18);
            }
            if(list.variable[1][3] == '1' &&  list.variable[18][3] == '1' ){
                conSolved = true;
                problem = "LOW OIL";
            }
            break;
        //if car doesn't start and timing belt not intact
        case 22:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '2') {
                if (list.variable[19][3] == 0)
                    askQuestion(19);
            }
            if(list.variable[1][3] == '2' &&  list.variable[19][3] == '1' ){
                conSolved = true;
                problem = "TIMING BELT BRK";
            }
            break;
        //if car doesn't start 
        case 23:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '2') {
                if (list.variable[29][3] == 0)
                    askQuestion(29);
            }
            if(list.variable[1][3] == '2' &&  list.variable[29][3] == '1' ){
                problem = "LOW FUEL";
                conSolved = true;
            }
            break;
        //if engine light on
        case 24:
            if(list.variable[1][3] == 0)
                askQuestion(1);
            if(list.variable[1][3] == '2') {
                if (list.variable[20][3] == 0)
                    askQuestion(20);
            }
            if(list.variable[1][3] == '2' &&  list.variable[20][3] == '1' ){
              engine = true;
            }
            else
                engine = false;
            conSolved = true;
            break;
        //if engine issues and strange smell
        case 25:
            if(engine){
                if (list.variable[21][3] == 0)
                    askQuestion(21);
            }
            if(engine && list.variable[21][3] == '1' ){
                conSolved = true;
                problem = "BAD OXYGEN SNSR";
            }
            break;
        //if engine issues and faulty spark plugs
        case 26:
            if(engine){
                if (list.variable[22][3] == 0)
                    askQuestion(22);
            }
            if(engine && list.variable[22][3] == '1' ){
                conSolved = true;
                problem = "BAD SPARK PLUG";
            }
            break;
        //if engine issues and sputtering while driving
        case 27:
            if(engine){
                if (list.variable[23][3] == 0)
                    askQuestion(23);
            }
            if(engine && list.variable[23][3] == '1' ){
                conSolved = true;
                problem = "BAD FUEL PUMP";
            }
            break;
        //if engine issues and air filter dirty
        case 28:
            if(engine){
                if (list.variable[24][3] == 0)
                    askQuestion(24);
            }
            if(engine && list.variable[24][3] == '1' ){
                conSolved = true;
                problem = "AIR FILTER CLOG";
            }
            break;
        //if engine issues and clicking while starting
        case 29:
            if(engine){
                if (list.variable[25][3] == 0)
                    askQuestion(25);
            }
            if(engine && list.variable[25][3] == '1' ){
                conSolved = true;
                problem = "STARTER MOTOR";
            }
            break;
        //if engine issues and poor acceleration
        case 30:
            if(engine){
                if (list.variable[26][3] == 0)
                    askQuestion(26);
            }
            if(engine && list.variable[26][3] == '1' ){
                conSolved = true;
                problem = "M AIR FLOW SNSR";
            }
            break;
        //if engine issues and loose gas cap
        case 31:
            if(engine){
                if (list.variable[27][3] == 0)
                    askQuestion(27);
            }
            if(engine && list.variable[27][3] == '1' ){
                conSolved = true;
                problem = "LOOSE GAS CAP";
            }
            break;
        //if engine issues and emissions increased
        case 32:
            if(engine){
                if (list.variable[28][3] == 0)
                    askQuestion(28);
            }
            if(engine && list.variable[28][3] == '1' ){
                conSolved = true;
                problem = "STUCK EGR VALVE";
            }
            break;
    }
}
void Diagnosis::askQuestion(int switchNum) {
    //switchNum = 0;
    //finds variable
    /*for (int i = 0; i < 29; i++) {
        if (strncmp(list.variable[i], list.clauseVariable[cVNum], 3) == 0) {
            switchNum = i;
            break;
        }
    }*/
    switch (switchNum + 1) {
        case 1:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "\nDoes the car have any issues?\n";
                cout << "Input 1 for yes or 2 for no\n";
                cin >> list.variable[0][3]; //3rd element is for storing answers
            }
            break;
        case 2:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
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
        case 4:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Will the battery hold a charge?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 5:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the Tire Pressure Monitoring System (TPMS) light on?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 6:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the temperature warning light on?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 7:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the coolant level low?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 8:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Does the engine emit a squeaking noise while running?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 9:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the radiator fan clogged?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 10:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the thermostat malfunctioning?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 11:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the Window Washer Fluid (WWF) light on?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 12:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Are any of the windows stuck in an open or closed position?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 13:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Does the car emit a clicking noise while turning?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 14:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the car difficult to turn?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 15:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the brake warning light on?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 16:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the brake fluid level low?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 17:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Are the brake pads worn?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 18:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the ABS light on?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 19:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the oil pressure low?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 20:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the timing belt present and intact?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 21:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the check engine light on?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 22:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is there a strange smell to the exhaust when the engine is running?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 23:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Are the spark plugs faulty?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 24:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Does the engine sputter while driving?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 25:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the air filter dirty and/or clogged?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 26:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Does the enigne make a clicking sound whle trying to start?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 27:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Does the car exhibit poor acceleration?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 28:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the gas cap fully seated and tightly sealed?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 29:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Is the car outputting increased emissions?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
        case 30:
            while(list.variable[switchNum][3] != '1' && list.variable[switchNum][3] != '2'){
                cout << "Does the car have no fuel?\nInput 1 for yes or 2 for no\n";
                cin >> list.variable[switchNum][3];
            }
            break;
    }
}