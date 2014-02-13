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
    this->EVENT_SIZE = sizeof ( struct inotify_event );
    this->EVENT_BUF_LEN = 1024 * ( EVENT_SIZE + 16 );
    this->buffer = new char[EVENT_BUF_LEN];

    this->compiler = new Compiler();
}


Monitor::Monitor ( Compiler &compiler ) {
    this->EVENT_SIZE = sizeof ( struct inotify_event );
    this->EVENT_BUF_LEN = 1024 * ( EVENT_SIZE + 16 );
    this->buffer = new char[EVENT_BUF_LEN];

    this->compiler = new Compiler(compiler);
}


Monitor::~Monitor() {
    delete[] this->buffer;
    delete this->compiler;
}


bool Monitor::isValid() {
    return true;
}


void Monitor::startWatch() {
    std::cout << "Start watch on " << std::endl;
    for (const auto& value : this->paths) {
        std::cout << value << std::endl;
    }

    initialize();

    while(1) {
        waitForChange();
        analyzeChange();
        break;
    }

    terminate();
}


void Monitor::addPath(std::string &path) {
    this->paths.push_back(path);
}


void Monitor::initialize() {
    fileDescriptor = inotify_init();

    for (const auto& value : this->paths) {
        watchDescriptor = inotify_add_watch ( fileDescriptor, value.c_str(), IN_CREATE | IN_MODIFY );
    }
}


void Monitor::waitForChange() {
    length = read ( fileDescriptor, buffer, EVENT_BUF_LEN );
}


void Monitor::analyzeChange() {
    int i = 0;
    std::string filename;
    while ( i < length ) {
        struct inotify_event *event = ( struct inotify_event * ) &buffer[i];
        filename = std::string ( event->name, event->len);

        if ( event->len && filenameIsValid(filename)) {
            std::cout << "File " << filename << " has changed" << std::endl;
            this->compiler->execute();
        }
        i += EVENT_SIZE + event->len;
    }
}


void Monitor::terminate() {
    inotify_rm_watch ( fileDescriptor, watchDescriptor );
    close ( fileDescriptor );
}


bool Monitor::filenameIsValid(std::string &filename)
{
    bool status = false;

    if (filename[0]!='.' && filename.length()>0) {
        status = true;
    }

    return status;
}
