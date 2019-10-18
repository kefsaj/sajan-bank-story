#ifndef TEST_RESULT_H
#define TEST_RESULT_H

#include <string>

struct TestResult
{
public:
    TestResult(const std::string& exp, const std::string& res, bool p);
    std::string expected;
    std::string result;
    bool passed;
}

#endif /* TEST_RESULT_H */
