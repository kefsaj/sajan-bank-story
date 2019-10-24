/*
*  Created on: 10/24/2019
*      Author: Bryan Morfe
*/

#include "DateTests.h"

#include "../source/Date.h"

DateTests::DateTests( const string& n ) : Testable( n ) {}

void DateTests::build()
{
    tests.push([]() -> TestResult {
        string expected = "01/01/1970";
        string result = Date::refDate().formattedString();
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "02/12/2010";
        string result = Date(12, 2, 2010).formattedString();
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "false";
        string result = ( Date::refDate() == Date::now() ? "true" : "false" );
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "true";
        string result = ( Date::refDate() < Date::now() ? "true" : "false" );
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "false";
        string result = ( Date::refDate() > Date::now() ? "true" : "false" );
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "01/01/1970";
        string result = Date(0).formattedString();
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "01/15/1970";
        string result = Date(14).formattedString();
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "01/01/1971";
        string result = Date(366).formattedString();
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "01/05/1971";
        string result = Date(370).formattedString();
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "0";
        string result = to_string( Date::refDate().daysSinceRefDate() );
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "100";
        string result = to_string( Date(100).daysSinceRefDate() );
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "1000";
        string result = to_string( Date(1000).daysSinceRefDate() );
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "01/04/1970";
        string result = ( Date::refDate() + Date(3) ).formattedString();
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
    
    tests.push([]() -> TestResult {
        string expected = "01/01/1971";
        string result = ( Date::refDate() + Date(366) ).formattedString();
        bool passed = ( expected == result );
        
        return TestResult( expected, result, passed );
    });
}
