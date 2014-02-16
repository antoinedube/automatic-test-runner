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

#ifndef TERSEPRINTER_H
#define TERSEPRINTER_H

#include <stdio.h>
#include "gtest/gtest.h"

using ::testing::EmptyTestEventListener;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::TestResult;
using ::testing::UnitTest;


// Provides alternative output mode which produces minimal amount of
// information about tests.
class TersePrinter : public EmptyTestEventListener {
    private:

        // Called before any test activity starts.
    virtual void OnTestProgramStart(const UnitTest& /* unit_test */) {

    }

    // Called after all test activities have ended.
    virtual void OnTestProgramEnd(const UnitTest& unit_test) {
        fprintf(stdout, "TEST %s\n", unit_test.Passed() ? "PASSED" : "FAILED");
        fflush(stdout);
    }

    // Called before a test starts.
    virtual void OnTestStart(const TestInfo& test_info) {
        fprintf(stdout,
                "*** Test %s.%s starting.\n",
                test_info.test_case_name(),
                test_info.name());
        fflush(stdout);
    }

    // Called after a failed assertion or a SUCCEED() invocation.
    virtual void OnTestPartResult(const TestPartResult& test_part_result) {
        fprintf(stdout,
                "%s in %s:%d\n%s\n",
                test_part_result.failed() ? "*** Failure" : "Success",
                test_part_result.file_name(),
                test_part_result.line_number(),
                test_part_result.summary());
        fflush(stdout);
    }

    // Called after a test ends.
    virtual void OnTestEnd(const TestInfo& test_info) {
        const TestResult *testResult = test_info.result();

        fprintf(stdout,
                "*** Test %s.%s ending.\tStatus: %d\n",
                test_info.test_case_name(),
                test_info.name(),
                testResult->Passed() );
        fflush(stdout);
    }
};

#endif
