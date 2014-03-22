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

#include <stdio.h>
#include <jsoncpp/json/writer.h>
#include "testrunner/printer/JsonPrinter.h"
#include "testrunner/UnitTestInfo.h"

JsonPrinter::JsonPrinter() {
}


JsonPrinter::~JsonPrinter() {
}


void JsonPrinter::print(std::vector<UnitTestInfo *> testsResults) {
    Json::Value allValues(Json::arrayValue);
    Json::Value currentValue;

    for (auto &element : testsResults) {
        currentValue["Test case name"] = element->test_case_name;
        currentValue["Test name"] = element->test_name;
        currentValue["status"] = element->status;
        currentValue["summary"] = element->summary;
        currentValue["time"] = int(element->timeInMillis);
        allValues.append(currentValue);
    }
    std::cout << allValues << std::endl;
}
