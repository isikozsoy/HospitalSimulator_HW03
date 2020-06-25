/*
* Title: Heaps and Priority Queues
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 3
* Description: cpp file of maxHeap1
*/

#include "maxHeap1.h"
#include "Patient.h"
#include <iostream>

using namespace std;

MaxHeap :: MaxHeap()
{
    size = 0;
}

void MaxHeap :: rebuild(int root)
{
    int child = 2 * root + 1; 	// index of root's left child, if any
    if ( child < size )
    {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1; 	// index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChild < size) &&
                ( patients[rightChild]->getPriority() > patients[child]->getPriority() ||
                  (patients[rightChild]->getPriority() == patients[child]->getPriority() && patients[rightChild]->getArrivesAt() < patients[child]->getArrivesAt()) ) )
            child = rightChild; 	// index of larger child

        // If root’s item is smaller than larger child, swap values
        if ( patients[root]->getPriority() < patients[child]->getPriority() ||
                (patients[root]->getPriority() == patients[child]->getPriority() && patients[root]->getArrivesAt() > patients[child]->getArrivesAt()))
        {
            Patient* temp = patients[root];
            patients[root] = patients[child];
            patients[child] = temp;

            // transform the new subtree into a heap
            rebuild(child);
        }
    }

}

bool MaxHeap :: isEmpty()
{
    return size == 0;
}

void MaxHeap :: addPatient(Patient* patient)
{
    if(size != MAX_PATIENT)
    {
        patients[size] = patient;
        int place = size;
        int parent = (place - 1)/2;
        while ( place > 0 && (patients[place]->getPriority() > patients[parent]->getPriority() ||
                              (patients[place]->getPriority() == patients[parent]->getPriority() && patients[place]->getArrivesAt() < patients[parent]->getArrivesAt())))
        {
            Patient* temp = patients[parent];
            patients[parent] = patients[place];
            patients[place] = temp;

            place = parent;
            parent = (place - 1) / 2;
            temp = 0;
        }
        ++size;
    }
}

Patient* MaxHeap :: deletePatient()
{
    if(!isEmpty())
    {
        Patient* deletedPatient = patients[0];
        patients[0] = patients[--size];
        rebuild(0);
        return deletedPatient;
    }
    return 0;
}
