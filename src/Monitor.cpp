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


Monitor::Monitor ( ) {
    this->compiler = new Compiler();
    this->notifier = new Notifier();
    this->testSuite = new TestSuite();
}


Monitor::Monitor ( Compiler &compiler, Notifier &notifier, TestSuite &testSuite ) {
    this->compiler = new Compiler ( compiler );
    this->notifier = new Notifier ( notifier );
    this->testSuite = new TestSuite ( testSuite );
}


Monitor::~Monitor() {
    delete this->compiler;
    delete this->notifier;
    delete this->testSuite;
}


bool Monitor::isValid() {
    return ( this->compiler != NULL ) && ( this->notifier != NULL ) && ( this->testSuite != NULL );
}


void Monitor::initialize(int argc, char **argv) {
    std::string watchPath = "../test";
    this->notifier->addPath ( watchPath );
    watchPath = "../src";
    this->notifier->addPath ( watchPath );
    this->notifier->initialize();

    InitGoogleTest(&argc, argv);
    UnitTest& unit_test = *UnitTest::GetInstance();
    TestEventListeners& listeners = unit_test.listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new TestSuite(*this->testSuite));
}


void Monitor::startWatch() {
    std::string fileModified;

    while ( 1 ) {
        fileModified = this->notifier->waitForChange();

//        if (fileModified[0]!='.') {
            std::cout << fileModified << " has been modified" << std::endl;
            this->compiler->execute();
            this->testSuite->runAllTests();
//        }

        break;
    }

    this->notifier->terminate();
}
