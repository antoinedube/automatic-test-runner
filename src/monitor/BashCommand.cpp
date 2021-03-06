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

#include <stdio.h>

#include "monitor/BashCommand.h"


BashCommand::BashCommand() {
}


BashCommand::~BashCommand() {
}


std::string BashCommand::execute(std::string &command) {
    FILE *popenOutput;
    int testValue;
    char valueToWrite[100];
    std::string currentString;

    popenOutput = popen(command.c_str(), "r");

    testValue = fgetc(popenOutput);
    while (testValue!=-1) {
        sprintf(valueToWrite, "%c", (char)testValue);
        currentString.append(std::string(valueToWrite));
        testValue = fgetc(popenOutput);
    }

    pclose(popenOutput);

    return currentString;
}

