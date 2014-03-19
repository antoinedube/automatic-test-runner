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

#include <gtest/gtest.h>

#include "testrunner/printer/CliPrinter.h"
#include "testrunner/printer/JsonPrinter.h"
#include "testrunner/printer/Printer.h"
#include "testrunner/TestsResults.h"
#include "testrunner/TestSuite.h"


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    UnitTest& unit_test = *UnitTest::GetInstance();
    TestEventListeners& listeners = unit_test.listeners();
    delete listeners.Release(listeners.default_result_printer());


    Printer *printer = new JsonPrinter();

    TestsResults *testsResults = new TestsResults(printer);

    TestSuite *testSuite = new TestSuite(testsResults);
    listeners.Append(testSuite);

    int returnValue = RUN_ALL_TESTS();

    testsResults->print();

    delete testsResults;
    delete printer;

    return returnValue;
}
