/*
* Title: Heaps and Priority Queues
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 3
* Description: header file of maxHeap2
*/

#ifndef MaxHeap2_h
#define MaxHeap2_h

#include "Patient.h"
#include <iostream>
using namespace std;
class MaxHeap {
private:
    int size;
    Patient* patients;
    int maxPatients;
public:
    MaxHeap();
    void rebuild(int); //checked
    bool isEmpty(); //done
    void addPatient(Patient*); //checked
    Patient* deletePatient(); //checked
};
#endif
