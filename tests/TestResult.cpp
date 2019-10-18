
#include "TestResult.h"

TestResult::TestResult(const std::string& exp, const std::string& res, bool p):
    expected(exp),
    result(res),
    passed(p)
{}
