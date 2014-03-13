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

#include "Parser.h"


Parser::Parser ( ) {
}


Parser::~Parser( ) {
}


void Parser::parseOutput(FILE *file) {
    int testValue;
    char valueToWrite[100];
    std::string currentString;
    std::cout << "Output Parser" << std::endl;

    while (1) {
        testValue = fgetc(file);

        if (testValue==-1) break;
        else if (testValue=='\n') {
            std::cout << "currentString: " << currentString << std::endl;
            currentString = "";
        }
        else {
            sprintf(valueToWrite, "%c", (char)testValue);
//             std::cout << "currentCharacter: " << testValue << std::endl;
            currentString.append( std::string(valueToWrite) );
        }
    }

    std::cout << "\n" << std::endl;
}
