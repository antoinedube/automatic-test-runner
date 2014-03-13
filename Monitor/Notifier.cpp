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

#include "Notifier.h"


Notifier::Notifier() {
    this->EVENT_SIZE = sizeof ( struct inotify_event );
    this->EVENT_BUF_LEN = 1024 * ( EVENT_SIZE + 16 );
    this->buffer = new char[EVENT_BUF_LEN];
}


Notifier::~Notifier() {
    delete[] this->buffer;
}


void Notifier::addPaths(std::vector<std::string> &paths) {
    this->paths = paths;
}


void Notifier::initialize() {
    fileDescriptor = inotify_init();

    for ( auto & value : this->paths ) {
        watchDescriptor = inotify_add_watch ( fileDescriptor, value.c_str(), IN_CREATE | IN_MODIFY );
    }

    std::cout << "Start watch on " << std::endl;
    for ( auto & value : this->paths ) {
        std::cout << value << std::endl;
    }
}


std::string Notifier::waitForChange() {
    length = read ( fileDescriptor, buffer, EVENT_BUF_LEN );

    int i = 0;
    struct inotify_event *event = ( struct inotify_event * ) &buffer[i];
    return std::string ( event->name, event->len );
}


void Notifier::terminate() {
    inotify_rm_watch ( fileDescriptor, watchDescriptor );
    close ( fileDescriptor );
}
