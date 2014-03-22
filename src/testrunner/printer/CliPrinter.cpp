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

#include <iostream>
#include <vector>
#include "testrunner/printer/CliPrinter.h"


CliPrinter::CliPrinter() {
}


CliPrinter::~CliPrinter() {
}


void CliPrinter::print(std::vector<UnitTestInfo *> testsResults) {
    for (auto &element : testsResults) {
        std::cout << "Test case name: " << element->test_case_name << std::endl;
        std::cout << "Test name: " << element->test_name << std::endl;
        std::cout << "Test status: " << element->status << std::endl;
        std::cout << "Test summary: " << element->summary << std::endl;
        std::cout << "Test time: " << element->timeInMillis << std::endl << std::endl;
    }
}
