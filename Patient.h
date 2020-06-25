/*
* Title: Heaps and Priority Queues
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 3
* Description: header file of Patient class
*/

#ifndef Patient_h
#define Patient_h

#include <iostream>
using namespace std;

class Patient {
public:
    Patient();
    Patient(int, int, int, int);
    int getExaminationTime();
    int getPriority();
    int getArrivesAt();
    int getId();
private:
    int examinationTime;
    int priority;
    int arrivesAt;
    int assignedTime;
    int id;
};
#endif
