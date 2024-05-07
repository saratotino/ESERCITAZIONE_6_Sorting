#include "SortingAlgorithm.hpp"
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;
using namespace SortLibrary;


//Calcolo della durata del BubbleSort
template<typename T>
double BubbleSortDuration (vector<T>& v)
{
    chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
    
    BubbleSort(v);
    
    chrono::steady_clock::time_point t_end = chrono::steady_clock::now();
    
    double duration = chrono::duration_cast<chrono::nanoseconds>(t_end - t_begin).count();
    
    return duration;
    
}


//Calcolo della durata del MergeSort
template<typename T>
double MergeSortDuration (vector<T>& v)
{
    chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
    
    MergeSort(v);
    
    chrono::steady_clock::time_point t_end = chrono::steady_clock::now();
    
    double duration = chrono::duration_cast<chrono::nanoseconds>(t_end - t_begin).count();
    
    return duration; 
}
    



int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <dimension>" << endl;
        return 1;
    }


    unsigned int numberTest= 5;
    unsigned int dimension = stoi(argv[1]);


    //Test 1
    double sumBubble = 0;
    double sumMerge = 0;

    cout << "First Test: vector sorted in descending order" << endl;

    unsigned int dimension1;

    vector<int> vBubble(dimension);
    vector<int> vMerge(dimension);

    for(unsigned int i= 0; i < numberTest; i++)
    {
        dimension1 = dimension;

        generate(vBubble.begin(), vBubble.end(), [&dimension1] () {return dimension1--;});

        vMerge = vBubble;

        sumBubble += BubbleSortDuration(vBubble);
        sumMerge += MergeSortDuration(vMerge);
    }


    double meanBubble = sumBubble / numberTest;
    double meanMerge = sumMerge / numberTest;

    cout << "Average time for BubbleSort: " << meanBubble << "ns" << endl;
    cout << "Average time for MergeSort: " << meanMerge << "ns" << endl;

    if(meanBubble < meanMerge)
    {
        cout << "BubbleSort is the best." << endl << endl;
    }

    else
    {
        cout << "MergeSort is the best." << endl << endl;
    }



    //Test 2
    sumBubble = 0;
    sumMerge = 0;

    cout << "Second Test: vector sorted in ascending order" << endl;

    vector<int> vBubble2(dimension);
    vector<int> vMerge2(dimension);

    for(unsigned int i= 0; i < numberTest; i++)
    {
        dimension1 = 0;

        generate(vBubble2.begin(), vBubble2.end(), [&dimension1] () {return dimension1++;});

        vMerge2 = vBubble2;

        sumBubble += BubbleSortDuration(vBubble2);
        sumMerge += MergeSortDuration(vMerge2);
    }




    meanBubble = sumBubble / numberTest;
    meanMerge = sumMerge / numberTest;

    cout << "Average time for BubbleSort: " << meanBubble << "ns" << endl;
    cout << "Average time for MergeSort: " << meanMerge << "ns" << endl;

    if(meanBubble < meanMerge)
    {
        cout << "BubbleSort is the best." << endl << endl;
    }

    else
    {
        cout << "MergeSort is the best." << endl << endl;
    }




    //Test 3
    sumBubble = 0;
    sumMerge = 0;

    cout << "Third Test: random vector" << endl;

    for(unsigned int i = 0; i < dimension; i++)
    {
        vector<int> vBubble(dimension);

        for(unsigned int j = 0; j < dimension; j++)
        {
            vBubble[i] = rand() % dimension;
        }

        vector<int> vMerge = vBubble;

        sumBubble += BubbleSortDuration(vBubble);
        sumMerge += MergeSortDuration(vMerge);
    }

    meanBubble = sumBubble / numberTest;
    meanMerge = sumMerge / numberTest;

    cout << "Average time for BubbleSort: " << meanBubble << "ns" << endl;
    cout << "Average time for MergeSort: " << meanMerge << "ns" << endl;

    if(meanBubble < meanMerge)
    {
        cout << "BubbleSort is the best." << endl << endl;
    }

    else
    {
        cout << "MergeSort is the best." << endl << endl;
    }



    //Test 4
    sumBubble = 0;
    sumMerge = 0;

    cout << "Fourth Test: Partially ordered vector" << endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    for(unsigned int i = 0; i < dimension; i++)
    {
        vector<int> vBubble(dimension);

        iota(vBubble.begin(),vBubble.begin() + dimension/2 ,0);

        for(unsigned int j = numberTest - 1; j > dimension / 2 - 1; j--)
        {
            vBubble[j] = (rand() % dimension) + dimension / 2;
        }

        vector<int> vMerge = vBubble;

        sumBubble += BubbleSortDuration(vBubble);
        sumMerge += MergeSortDuration(vMerge);
    }

    meanBubble = sumBubble / numberTest;
    meanMerge = sumMerge / numberTest;

    cout << "Average time for BubbleSort: " << meanBubble << "ns" << endl;
    cout << "Average time for MergeSort: " << meanMerge << "ns" << endl;

    if(meanBubble < meanMerge)
    {
        cout << "BubbleSort is the best." << endl << endl;
    }

    else
    {
        cout << "MergeSort is the best." << endl << endl;
    }


    return 0;
}




