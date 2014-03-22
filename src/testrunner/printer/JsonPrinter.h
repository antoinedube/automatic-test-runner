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

#ifndef SRC_TESTRUNNER_PRINTER_JSONPRINTER_H_
#define SRC_TESTRUNNER_PRINTER_JSONPRINTER_H_

#include "testrunner/printer/Printer.h"
#include "testrunner/UnitTestInfo.h"


class JsonPrinter : public Printer {
 public:
    JsonPrinter();
    virtual ~JsonPrinter();

    virtual void print(std::vector<UnitTestInfo *> testsResults);
};

#endif  // SRC_TESTRUNNER_PRINTER_JSONPRINTER_H_
