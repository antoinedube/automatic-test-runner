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

#include "Compiler.h"


Compiler::Compiler ( ) {
    this->commands.push_back ( "echo 'rm -rf *'" );
    this->commands.push_back ( "echo 'cmake ..'" );
    this->commands.push_back ( "echo 'make clean'" );
    this->commands.push_back ( "echo 'make'" );
}


Compiler::~Compiler() {

}


void Compiler::execute() {
    std::string commandOutput;

    for ( auto & value : this->commands ) {
        this->bashCommand = new BashCommand(value);
        commandOutput = this->bashCommand->execute();
        std::cout << "Command output : " << commandOutput;
        delete this->bashCommand;
    }
}
