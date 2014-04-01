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

    if (reader.parse(text, values)) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << "Failure" << std::endl;
    }

    for (auto element: values) {
        currentValue = element;
        std::cout << "Test case name: " << currentValue["Test case name"].asString() << std::endl;
        std::cout << "Test name: " << currentValue["Test name"].asString() << std::endl;
        std::cout << "Test status: " << currentValue["status"].asString() << std::endl;
        std::cout << "Test summary: " << currentValue["summary"].asString() << std::endl;
        std::cout << "Test time: " << currentValue["time"].asInt() << std::endl;
    }

    this->tableWidget->updateValues();
}

