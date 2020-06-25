/*
* Title: Heaps and Priority Queues
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 3
* Description: simulation
*/

#include "maxHeap1.h"
#include "Patient.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

static void driver(int avgWaiting, int numPatient, MaxHeap* maxHeap, Patient* patients[])
{
    double avgMin = 0;
    int numDoctor = 0;
    while(avgMin == 0 || avgMin > double(avgWaiting))
    {
        double totWaiting = 0;
        numDoctor++;
        int* doctors = new int[numDoctor]; // It holds current time of the doctors.
        for(int i = 0; i < numDoctor; i++)
            doctors[i] = 0;
        int startIndex = 0;
        int time = 0;
        while(numPatient != startIndex || !maxHeap->isEmpty()) {
            for( ; patients[startIndex]->getArrivesAt() == time && startIndex != numPatient; startIndex++) {
                maxHeap->addPatient(patients[startIndex]);
            }
            for(int i = 0; i < numDoctor; i++) {
                if(doctors[i] <= time && !maxHeap->isEmpty()) {
                    Patient* deletedPatient = maxHeap->deletePatient();
                    totWaiting += time - deletedPatient->getArrivesAt();
                    if(doctors[i] < deletedPatient->getArrivesAt())
                        doctors[i] = deletedPatient->getArrivesAt();
                    doctors[i] += deletedPatient->getExaminationTime();
                }
            }
            time++;
        }
        avgMin = totWaiting / double(numPatient);
    }
    cout << endl;
    cout << "Minimum number of doctors required: " << numDoctor << endl;
    cout << endl;
    cout << "Simulation with " << numDoctor << " doctors:" << endl;
    cout << endl;

    int* doctors = new int[numDoctor]; // It holds current time of the doctors.
        for(int i = 0; i < numDoctor; i++)
            doctors[i] = 0;
        int startIndex = 0;
        int time = 0;
        while(numPatient != startIndex || !maxHeap->isEmpty()) {
            for( ; patients[startIndex]->getArrivesAt() == time && startIndex != numPatient; startIndex++) {
                maxHeap->addPatient(patients[startIndex]);
            }
            for(int i = 0; i < numDoctor; i++) {
                if(doctors[i] <= time && !maxHeap->isEmpty()) {
                    Patient* deletedPatient = maxHeap->deletePatient();
                    cout << "Doctor " << i << " takes patient " << deletedPatient->getId() << " at minute " << time <<
                        " (wait: " << time - deletedPatient->getArrivesAt() << " mins)" << endl;
                    if(doctors[i] < deletedPatient->getArrivesAt())
                        doctors[i] = deletedPatient->getArrivesAt();
                    doctors[i] += deletedPatient->getExaminationTime();
                }
            }
            time++;
        }

    cout << endl;
    cout << "Average time is " << fixed << setprecision(2) << avgMin << endl;
}

int main(int argc, char* argv[])
{
    // We read data from txt
    string fileName = argv[1];
    int expectedAvWaiting = std::stoi(argv[2]);

    string str;		// str contains lines in file
    ifstream file;
    file.open(fileName);	// we open file
    getline(file, str);
    int numPatient = std::stoi(str);
    Patient* patients[numPatient];
    int cur = -1;
    for (int i = 0; getline(file, str); i++)		// until there is no new line in file
    {
        cur = str.find(" "); // we find the first index containing space
        int id = std::stoi(str.substr(0, cur));

        str.erase(0, cur + 1);
        cur = str.find(" ");
        while(cur == 0)
        {
            str.erase(0, 1);
            cur = str.find(" ");
        }

        int priority = std::stoi(str.substr(0, cur));

        str.erase(0, cur + 1);
        cur = str.find(" ");
        while(cur == 0)
        {
            str.erase(0, 1);
            cur = str.find(" ");
        }

        int arrivesAt = std::stoi(str.substr(0, cur));

        str.erase(0, cur + 1);
        cur = str.find(" ");
        while(cur == 0)
        {
            str.erase(0, 1);
            cur = str.find(" ");
        }
        int examinationTime = std::stoi(str);
        Patient* temp = new Patient(id, priority, arrivesAt, examinationTime); // We created our Patient with the data in the line
        patients[i] = temp;  // We put into array
    }
    file.close(); // we close file

    MaxHeap* test = new MaxHeap();
    driver(expectedAvWaiting, numPatient, test, patients);
    delete test;
    return 0;
}
