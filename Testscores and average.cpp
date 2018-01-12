/*
author: Jorge Castillo
Project : VL16
*/

#include <iostream>
#include <iomanip>

using namespace std;

void arrSort(double *, int testScores);
double arrAvScore(double *, int size);

int main()
{
    double *TestScores,
    total = 0.0,
    average;
    int Testnum,
    count;
    
    cout << "How many test scores are they?";
    cin >> Testnum;
    TestScores = new double[Testnum];
    cout << "Enter the test scores.\n";
    for (count = 0; count < Testnum; count++)
    {
        cout << "Test Score " << (count + 1) << ": ";
        cin >> TestScores[count];
        
        while (TestScores[count]<0 || TestScores[count]>100)
        {
            cout << "Invalid, please positive test scores only" << endl;
            cout << "Please try again: ";
            cin >> TestScores[count];
        }
    }
    
    arrSort(TestScores, Testnum);
    average = arrAvScore(TestScores, Testnum);
    
    cout << fixed << showpoint << setprecision(2);
    cout << "The test scores in ascending order, are: \n";
    for (count = 0; count < Testnum; count++)
    {
        cout << TestScores[count] << " ";
        cout << endl;
    }
    
	cout << "The average of  test scores is " << average << endl;
	
    delete [] TestScores;
    TestScores = 0;


    return 0;
}

//
void arrSort(double *arr, int size)
{

    int Scan;
    int MinIn;
    double MinEle;
    double temp;

    for (Scan = 0; Scan < (size - 1); Scan++)
    {
        MinIn = Scan;
        MinEle = arr[Scan];
        for (int index = Scan; index < size; index++)
        {
            if (arr[index] < MinEle)
            {
                MinEle = arr[index];
                MinIn = index;
            }
        }
        if (MinIn!=Scan)
        {
            temp = arr[MinIn];
            arr[MinIn] = arr[Scan];
            arr[Scan] = temp;
        }
    }
}

//
double arrAvScore (double *arr, int size)
{
    double total = 0.0, average;
    int Testnum;
    for (int count = 0; count < size; count++)
    {
        total += arr[count];
    }
    average = total / size;
    return average;
}
/*
How many test scores are they?4
Enter the test scores.
Test Score 1: 50
Test Score 2: 20
Test Score 3: 70
Test Score 4: 99
The test scores in ascending order, are:
20.00
50.00
70.00
99.00
The average of  test scores is 59.75
Press any key to continue . . 
*/
