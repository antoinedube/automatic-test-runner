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

}


void TestSuite::initialize(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    UnitTest& unit_test = *UnitTest::GetInstance();
    TestEventListeners& listeners = unit_test.listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new TestSuite(*this));
}


void TestSuite::runAllTests() {
//     std::cout << "\n\nRunning Test Suite" << std::endl;
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
}


// Called after failed assertion or SUCCEED()
void TestSuite::OnTestPartResult(const TestPartResult& test_part_result) {
    std::cout << "TestPartResult" << std::endl;
    std::cout << "\tfailed(): " << test_part_result.failed() << std::endl;
    std::cout << "\tsummary(): " << test_part_result.summary() << std::endl;
    std::cout << "End of TestPartResult" << std::endl;

//     if (test_part_result.failed()) {
//         std::string name = test_part_result.
//         this->unitTests.push_back();
//     }
}


void TestSuite::OnTestEnd(const TestInfo& test_info) {
    const TestResult *testResult = test_info.result();
    std::cout << "TestEnd: " << test_info.test_case_name() << "." << test_info.name() << "\t" << testResult->Passed() << "\n\n" << std::endl;
}
