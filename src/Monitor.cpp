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
}


Monitor::Monitor ( Compiler &compiler, Notifier &notifier ) {
    this->compiler = new Compiler(compiler);
    this->notifier = new Notifier(notifier);
}


Monitor::~Monitor() {
    delete this->compiler;
    delete this->notifier;
}


bool Monitor::isValid() {
    return (this->compiler!=NULL) && (this->notifier!=NULL);
}

void Monitor::startWatch()
{
    std::string fileModified;
    std::string watchPath = "../test";
    this->notifier->addPath(watchPath);
    watchPath = "../src";
    this->notifier->addPath(watchPath);

    this->notifier->initialize();

    fileModified = this->notifier->waitForChange();
    std::cout << fileModified << " has been modified" << std::endl;
//     if (fileModified[0]!='.' && fileModified.length()>0) {
//         std::cout << fileModified << " has been modified" << std::endl;
//     }
//     else {
//         std::cout << "Error in fileModified : " << fileModified << std::endl;
//     }

    this->notifier->terminate();
}
