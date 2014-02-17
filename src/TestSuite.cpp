/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014 Antoine Dube antoine.dube@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "TestSuite.h"

#include "SampleTestCase.h"


TestSuite::TestSuite ( ) {

}


TestSuite::~TestSuite ( ) {
    for ( auto & element : this->unitTestsInfo ) {
        std::cout << "\tTest case name: " << element->test_case_name << std::endl;
        std::cout << "\tTest name: " << element->test_name << std::endl;
        std::cout << "\tTest time: " << element->timeInMillis << std::endl;
        std::cout << "\tTest status: " << element->status << std::endl;
        std::cout << "\tTest summary: " << element->summary << std::endl << std::endl;
        delete element;
    }
}


void TestSuite::initialize(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    UnitTest& unit_test = *UnitTest::GetInstance();
    TestEventListeners& listeners = unit_test.listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new TestSuite(*this));
}


void TestSuite::runAllTests() {
    std::cout << "Running Test Suite" << std::endl;
    int returnValue = RUN_ALL_TESTS();
    std::cout << "Return value RUN_ALL_TESTS: " << returnValue << std::endl;
}


void TestSuite::OnTestProgramStart(const UnitTest& /* unit_test */) {
    std::cout << "TestProgramStart" << std::endl;
}


void TestSuite::OnTestProgramEnd(const UnitTest& unit_test) {
    std::cout << "TestProgramEnd: " << unit_test.Passed() << std::endl;
}


void TestSuite::OnTestStart(const TestInfo& test_info) {
    std::cout << "TestStart: " << test_info.test_case_name() << ", " << test_info.name() << std::endl;

    std::string testCaseName = test_info.test_case_name();
    std::string testName = test_info.name();
    bool status = false;
    std::string summary = "";
    long long int timeInMillis = 0;
    this->currentTestInfo = new UnitTestInfo(testCaseName, testName, status, summary, timeInMillis);
}


// Called after failed assertion or SUCCEED()
void TestSuite::OnTestPartResult(const TestPartResult& test_part_result) {
    std::cout << "TestPartResult" << std::endl;

    if (test_part_result.failed()) {
        this->currentTestInfo->status = false;
        this->currentTestInfo->summary = test_part_result.summary();
    }
}


void TestSuite::OnTestEnd(const TestInfo& test_info) {
    std::cout << "TestEnd" << std::endl;
    const TestResult *testResult = test_info.result();

    if (testResult->Passed()) {
        this->currentTestInfo->status = true;
        this->currentTestInfo->summary = "Test passed";
    }

    this->currentTestInfo->timeInMillis = testResult->elapsed_time();

    this->unitTestsInfo.push_back(new UnitTestInfo(*this->currentTestInfo));
    delete this->currentTestInfo;
}
