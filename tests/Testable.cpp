/**
Author: Mr.Bloom
Date:   10/18/2019
*/

#include "Testable.h"
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

Testable::Testable(const string& n): name(n) {}

void Testable::run()
{
    cout << "Running " << name << endl << endl;
    cout << "Execution Time (ms) | Status | Remarks" << endl;
    cout << "======================================" << endl;
    while (tests.size() > 0)
    {
        auto& test = tests.front();
        
        auto before = chrono::high_resolution_clock::now();
        TestResult result = test();
        auto after = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(after - before);
        cout << left << setw(20) << duration.count() << left << setw(2) << "|";
        
        if (result.passed)
            cout << "\033[1;32mPassed\033[0m | -------" << endl;
        else
        {
            cout << "\033[1;31mFailed\033[0m | Expected: " << result.expected
                 << ", but obtained: " << result.result << endl;
        }
        
        tests.pop();
    }
    
    cout << endl;
}
