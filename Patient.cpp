/*
* Title: Heaps and Priority Queues
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 3
* Description: cpp file of Patient class
*/


#include "Patient.h"
#include <iostream>
using namespace std;

Patient :: Patient(int id, int priority, int arrivesAt, int examinationTime) {
    this->id = id;
    this->priority = priority;
    this->arrivesAt = arrivesAt;
    this->examinationTime = examinationTime;
}

Patient :: Patient() {
}

int Patient :: getId() {
    return id;
}

int Patient :: getPriority() {
    return priority;
}

int Patient :: getExaminationTime() {
    return examinationTime;
}

int Patient :: getArrivesAt() {
    return arrivesAt;
}
