/**
Author: Mr.Bloom
Date:   10/18/2019
*/

#include "TestResult.h"

TestResult::TestResult(const std::string& exp, const std::string& res, bool p):
    expected(exp),
    result(res),
    passed(p)
{}
