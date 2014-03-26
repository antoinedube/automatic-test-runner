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

#include <QApplication>
#include <QtWidgets/QTableWidget>
#include "display/TableWidget.h"


TableWidget::TableWidget() {
    int argc = 0;
    char *argv[0];

    QApplication app(argc, argv);
    this->tableWidget = new QTableWidget(5,5);
    this->tableWidget->show();
    app.exec();
}

TableWidget::~TableWidget() {
    delete this->tableWidget;
}
