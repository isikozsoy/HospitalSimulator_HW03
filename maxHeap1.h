/*
* Title: Heaps and Priority Queues
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 3
* Description: header file of maxHeap1
*/

const int MAX_PATIENT = 2000;

#ifndef MaxHeap1_h
#define MaxHeap1_h

#include "Patient.h"
#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int size;
    Patient* patients[MAX_PATIENT];
public:
    MaxHeap();
    void rebuild(int); //checked
    bool isEmpty(); //done
    void addPatient(Patient*); //checked
    Patient* deletePatient(); //checked
};
#endif
