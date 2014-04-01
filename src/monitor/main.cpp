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

#include <string>
#include <thread>
#include <vector>

#include <QApplication>

#include "display/TableWidget.h"

#include "monitor/Compiler.h"
#include "monitor/parser/JsonParser.h"
#include "monitor/Monitor.h"
#include "monitor/Notifier.h"
#include "monitor/TestRunner.h"


void START_MONITOR_THREAD(Monitor *monitor) {
    monitor->startWatch();
}


int main(int argc, char *argv[]) {

    QApplication *app = new QApplication(argc, argv); 

    TableWidget *tableWidget = new TableWidget();
    tableWidget->run();

    BashCommand *bashCommand = new BashCommand();

    Compiler *compiler = new Compiler(bashCommand);

    std::vector<std::string> watchPaths;
    watchPaths.push_back("../test");
    watchPaths.push_back("../TestRunner");

    Notifier *notifier = new Notifier();
    notifier->addPaths(watchPaths);

    notifier->initialize();

    JsonParser *jsonParser = new JsonParser(tableWidget);
    TestRunner *testRunner = new TestRunner(bashCommand, jsonParser);

    Monitor *monitor = new Monitor(compiler, notifier, testRunner);

    std::thread monitorThread(START_MONITOR_THREAD, monitor);

    app->exec();

    monitorThread.join();

    delete monitor;
    delete testRunner;
    delete jsonParser;
    delete notifier;
    delete compiler;
    delete bashCommand;
    delete tableWidget;
    delete app;

    return 0;
}

