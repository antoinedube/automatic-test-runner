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

#ifndef SRC_TESTRUNNER_TESTSRESULTS_H_
#define SRC_TESTRUNNER_TESTSRESULTS_H_

#include <string>
#include <vector>

#include "testrunner/UnitTestInfo.h"
#include "testrunner/printer/Printer.h"


class TestsResults {
 public:
    explicit TestsResults(Printer *printer);
    virtual ~TestsResults();

    void addResult(UnitTestInfo *unitTestInfo);
    void print();

 private:
    std::vector<UnitTestInfo *> testsResults;
    Printer *printer;
};

#endif  // SRC_TESTRUNNER_TESTSRESULTS_H_
