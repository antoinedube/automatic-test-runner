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

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "TersePrinter.h"

#include "TestBashCommand.h"
#include "TestCompiler.h"
#include "TestMonitor.h"
#include "TestNotifier.h"
// #include "Test.h"
// #include "TestSuite.h"


// int main ( int argc, char **argv ) {
//     ::testing::InitGoogleMock ( &argc, argv );
//     return RUN_ALL_TESTS();
// }



using ::testing::InitGoogleTest;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::UnitTest;


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);

    UnitTest& unit_test = *UnitTest::GetInstance();

        TestEventListeners& listeners = unit_test.listeners();

        // Removes the default console output listener from the list so it will
        // not receive events from Google Test and won't print any output. Since
        // this operation transfers ownership of the listener to the caller we
        // have to delete it as well.
        delete listeners.Release(listeners.default_result_printer());

        // Adds the custom output listener to the list. It will now receive
        // events from Google Test and print the alternative output. We don't
        // have to worry about deleting it since Google Test assumes ownership
        // over it after adding it to the list.
        listeners.Append(new TersePrinter);

    int ret_val = RUN_ALL_TESTS();

    // This is an example of using the UnitTest reflection API to inspect test
    // results. Here we discount failures from the tests we expected to fail.
    int unexpectedly_failed_tests = 0;
    for (int i = 0; i < unit_test.total_test_case_count(); ++i) {
        const TestCase& test_case = *unit_test.GetTestCase(i);
        for (int j = 0; j < test_case.total_test_count(); ++j) {

            std::cout << "TestCase, Test : " << i << j << std::endl;

            const TestInfo& test_info = *test_case.GetTestInfo(j);

            // Counts failed tests that were not meant to fail (those without
            // 'Fails' in the name).
            if (test_info.result()->Failed() && strcmp(test_info.name(), "Fails") != 0) {
                unexpectedly_failed_tests++;
            }
        }
    }

    // Test that were meant to fail should not affect the test program outcome.
    if (unexpectedly_failed_tests == 0) {
        ret_val = 0;
    }

    return ret_val;
}
