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

#include "Compiler.h"
#include "Monitor.h"
#include "Notifier.h"
#include "TestRunner.h"


int main( ) {

    Compiler *compiler = new Compiler();

    Notifier *notifier = new Notifier();
    std::string watchPath = "../test";
    notifier->addPath ( watchPath );
    watchPath = "../src";
    notifier->addPath ( watchPath );
    notifier->initialize();

    TestRunner *testRunner = new TestRunner();

    Monitor *monitor = new Monitor (*compiler, *notifier, *testRunner);
    monitor->startWatch();

    delete monitor;
    delete testRunner;
    delete notifier;
    delete compiler;

    return 0;
}
