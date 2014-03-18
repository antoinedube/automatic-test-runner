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

#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include <vector>

#include <gtest/gtest.h>

#include "UnitTestInfo.h"
#include "TestsResults.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::TestResult;
using ::testing::UnitTest;


class TestSuite : public EmptyTestEventListener {
public:
    TestSuite ( TestsResults &testsResults );
    virtual ~TestSuite ( );

private:
    UnitTestInfo *currentTestInfo;
    TestsResults *testsResults;

    virtual void OnTestProgramStart(const UnitTest& /* unit_test */);
    virtual void OnTestProgramEnd(const UnitTest& unit_test);
    virtual void OnTestStart(const TestInfo& test_info);
    virtual void OnTestPartResult(const TestPartResult& test_part_result);
    virtual void OnTestEnd(const TestInfo& test_info);
};

#endif // TESTSUITE_H
