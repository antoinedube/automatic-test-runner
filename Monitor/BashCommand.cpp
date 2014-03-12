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

#include "BashCommand.h"


BashCommand::BashCommand ( std::string &command ) {
    this->command = command;
    this->parser = new Parser();
}


BashCommand::~BashCommand() {
    delete this->parser;
}


void BashCommand::execute() {
    FILE *popenOutput;

    popenOutput = popen(this->command.c_str(), "r");
    this->parser->parse(popenOutput);
    pclose(popenOutput);

//     std::cout << "command: " << this->command << "\toutput: " << buffer << ", " << std::string(buffer) << std::endl;
}
