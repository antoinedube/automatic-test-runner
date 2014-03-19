#
# <one line to give the program's name and a brief idea of what it does.>
# Copyright (C) 2014 Antoine Dube antoine.dube@gmail.com
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#

cmake_minimum_required (VERSION 2.8)
project(automatictestrunner)

set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -Werror -Wextra")

include_directories("src")
include_directories("test")

file (
    GLOB
    src_monitor
    src/monitor/*.cpp
)

add_executable(monitor ${src_monitor})


file (
    GLOB
    src_testrunner
    src/testrunner/*.cpp
    src/testrunner/printer/*.cpp
)

add_executable(testrunner ${src_testrunner})
target_link_libraries(testrunner gtest pthread gmock)
