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

#include "testrunner/TestSuite.h"


TestSuite::TestSuite(TestsResults *testsResults) {
    this->testsResults = testsResults;
}


TestSuite::~TestSuite() {}


void TestSuite::OnTestProgramStart(const UnitTest& /* unit_test */) {
}


void TestSuite::OnTestProgramEnd(const UnitTest& /*unit_test*/) {
}


void TestSuite::OnTestStart(const TestInfo& test_info) {
    this->currentTestInfo = new UnitTestInfo();
    this->currentTestInfo->test_case_name = test_info.test_case_name();
    this->currentTestInfo->test_name = test_info.name();
}


// Called after failed assertion or SUCCEED()
void TestSuite::OnTestPartResult(const TestPartResult& test_part_result) {
    this->currentTestInfo->status = !test_part_result.failed();
    this->currentTestInfo->summary = test_part_result.summary();
}


void TestSuite::OnTestEnd(const TestInfo& test_info) {
    const TestResult *testResult = test_info.result();

    if (testResult->Passed()) {
        this->currentTestInfo->status = true;
        this->currentTestInfo->summary = "Test passed";
    }

    this->currentTestInfo->timeInMillis = testResult->elapsed_time();

    this->testsResults->addResult(this->currentTestInfo);

    delete this->currentTestInfo;
}
