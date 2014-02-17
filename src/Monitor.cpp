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

#include "Monitor.h"


Monitor::Monitor ( Compiler &compiler, Notifier &notifier, TestSuite &testSuite ) {
    this->compiler = &compiler;
    this->notifier = &notifier;
    this->testSuite = &testSuite;
}


Monitor::~Monitor() {

}


bool Monitor::isValid() {
    return ( this->compiler != NULL ) && ( this->notifier != NULL ) && ( this->testSuite != NULL );
}


void Monitor::startWatch() {
    std::string fileModified;

    while ( 1 ) {
//         fileModified = this->notifier->waitForChange();
        fileModified = "Blablabla";

//        if (fileModified[0]!='.') {
            std::cout << fileModified << " has been modified" << std::endl;
            this->compiler->execute();
            this->testSuite->runAllTests();
//        }

        break;
    }

    this->notifier->terminate();
}
