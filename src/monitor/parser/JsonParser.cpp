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
#include <string>
#include <vector>
#include <jsoncpp/json/reader.h>

#include "monitor/parser/JsonParser.h"


JsonParser::JsonParser(TableWidget *tableWidget) {
    this->tableWidget = tableWidget;
}


JsonParser::~JsonParser() {
}


void JsonParser::parse(std::string &text) {
    Json::Value currentValue;
    Json::Value values;
    Json::Reader reader;
    reader.parse(text, values);

    std::vector<std::string> *testValues;

    for (auto element: values) {
        currentValue = element;

        testValues = new std::vector<std::string>;

        testValues->push_back(currentValue["Test case name"].asString());
        testValues->push_back(currentValue["Test name"].asString());
        testValues->push_back(currentValue["status"].asString());
        testValues->push_back(currentValue["summary"].asString());
        testValues->push_back(std::to_string(currentValue["time"].asInt()));

        this->tableWidget->updateValues(testValues);

        delete testValues;
    }

}

