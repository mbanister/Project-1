#include <iostream>
#include<string>
#include "Diagnosis.h"
#include "Repair.h"
using namespace std;

int main() {
    Diagnosis dCar;
    Repair rCar;
    string Diagnosis;
    string fix;
    Diagnosis = dCar.startDiagnosis();
    cout << "Problem: "<< Diagnosis << endl;
    fix = rCar.findTreatment(Diagnosis);
    cout << "Fix: " << fix;
    return 0;
}
