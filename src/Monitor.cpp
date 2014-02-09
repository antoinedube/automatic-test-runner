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

Monitor::Monitor ( std::string &path ) {
    this->path = path;
    this->EVENT_SIZE = sizeof ( struct inotify_event );
    this->EVENT_BUF_LEN = 1024 * ( EVENT_SIZE + 16 );
    this->buffer = new char[EVENT_BUF_LEN];
}

Monitor::~Monitor() {
    delete[] this->buffer;
}

bool Monitor::isValid() {
    return true;
}

void Monitor::startWatch() {
    std::cout << "Start watch on " << path << std::endl;
    initialize();
    waitForChange();
    analyzeChange();
    terminate();
}

void Monitor::initialize() {
    fileDescriptor = inotify_init();
    watchDescriptor = inotify_add_watch ( fileDescriptor, path.c_str(), IN_CREATE | IN_DELETE | IN_MODIFY );
}

void Monitor::waitForChange() {
    length = read ( fileDescriptor, buffer, EVENT_BUF_LEN );
}

void Monitor::analyzeChange() {
    int i = 0;
    while ( i < length ) {
        struct inotify_event *event = ( struct inotify_event * ) &buffer[i];
        std::cout << "if event->len" << std::endl;
        if ( event->len ) {

            if ( event->mask & IN_CREATE ) {
                if ( event->mask & IN_ISDIR ) {
                    std::cout << "Directory created" << std::endl;
                }
                else {
                    std::cout << "File is created" << std::endl;
                }
            }
            else
                if ( event->mask & IN_DELETE ) {
                    if ( event->mask & IN_ISDIR ) {
                        std::cout << "Directory is deleted" << std::endl;
                    }
                    else {
                        std::cout << "File is deleted" << std::endl;
                    }
                }
                else
                    if ( event->mask & IN_MODIFY ) {
                        if ( event->mask & IN_ISDIR ) {
                            std::cout << "Directory is modified" << std::endl;
                        }
                        else {
                            std::cout << "File is modified" << std::endl;
                        }
                    }
        }
        i += EVENT_SIZE + event->len;
    }
}

void Monitor::terminate() {
    inotify_rm_watch ( fileDescriptor, watchDescriptor );
    close ( fileDescriptor );
}
