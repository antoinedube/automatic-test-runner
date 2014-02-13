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

#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <string>
#include <sys/inotify.h>
#include <unistd.h>
#include <vector>

#include "Compiler.h"

class Monitor {
public:
    Monitor ( );
    Monitor ( Compiler &compiler );
    virtual ~Monitor();
    virtual bool isValid();
    virtual void startWatch();
    virtual void addPath(std::string &path);

    virtual void initialize();
    virtual void waitForChange();
    virtual void analyzeChange();
    virtual void terminate();
    virtual bool filenameIsValid(std::string &filename);

private:
    std::vector<std::string> paths;

    Compiler *compiler;

    int EVENT_SIZE;
    int EVENT_BUF_LEN;
    char *buffer;
    int fileDescriptor;
    int watchDescriptor;
    int length;

};

#endif // MONITOR_H
