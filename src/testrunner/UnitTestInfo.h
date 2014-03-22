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

#ifndef SRC_TESTRUNNER_UNITTESTINFO_H_
#define SRC_TESTRUNNER_UNITTESTINFO_H_

#include <string>


class UnitTestInfo {
 public:
    UnitTestInfo();
    virtual ~UnitTestInfo();

    std::string test_case_name;
    std::string test_name;
    bool status;
    std::string summary;
    int64_t timeInMillis;
};

#endif  // SRC_TESTRUNNER_UNITTESTINFO_H_
