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

#ifndef SRC_MONITOR_PARSER_JSONPARSER_H_
#define SRC_MONITOR_PARSER_JSONPARSER_H_

#include <string>
#include "monitor/parser/Parser.h"

class JsonParser : public Parser {
 public:
    JsonParser();
    virtual ~JsonParser();
    virtual void parse(std::string &text);
};

#endif  // SRC_MONITOR_PARSER_JSONPARSER_H_
