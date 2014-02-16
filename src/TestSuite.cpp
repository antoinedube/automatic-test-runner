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


TestSuite::TestSuite ( ) {

}


TestSuite::~TestSuite ( ) {

}


void TestSuite::runAllTests() {
    std::cout << "Running Test Suite" << std::endl;
}


void TestSuite::OnTestProgramStart(const UnitTest& /* unit_test */) {
    std::cout << "TestProgramStart" << std::endl;
}


void TestSuite::OnTestProgramEnd(const UnitTest& unit_test) {
    std::cout << "TestProgramEnd: " << unit_test.Passed() << std::endl;
}


void TestSuite::OnTestStart(const TestInfo& test_info) {
    std::cout << "Test starting: " << test_info.test_case_name() << ", " << test_info.name() << std::endl;
}


void TestSuite::OnTestPartResult(const TestPartResult& test_part_result) {
    std::cout << "TestPartResult" << std::endl;
    std::cout << test_part_result.failed() << std::endl;
    std::cout << test_part_result.summary() << std::endl;
}


void TestSuite::OnTestEnd(const TestInfo& test_info) {
    const TestResult *testResult = test_info.result();
    std::cout << "TestEnd: " << test_info.test_case_name() << "." << test_info.name() << "\t" << testResult->Passed() << std::endl;
}
