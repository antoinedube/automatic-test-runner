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

#include <iostream>
#include <string>
#include <vector>

#include <QtCore/QString>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTableWidgetItem>

#include "display/TableWidget.h"


TableWidget::TableWidget() {
    this->tableWidget = new QTableWidget(0,5);
    qRegisterMetaType<QVector<int> >("QVector<int>");

    this->tableWidget->setFixedSize(800,400);

    this->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Test case name"));
    this->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Test name"));
    this->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Status"));
    this->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Summary"));
    this->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Elapsed time"));

    this->tableWidget->setColumnWidth(0,150);
    this->tableWidget->setColumnWidth(1,150);
    this->tableWidget->setColumnWidth(2,75);
    this->tableWidget->setColumnWidth(3,300);
    this->tableWidget->setColumnWidth(4,100);
}


TableWidget::~TableWidget() {
    delete this->tableWidget;
}


void TableWidget::run() {
    this->tableWidget->show();
}


void TableWidget::updateValues(std::vector<std::string> *testValues) {
    int rowCount = this->tableWidget->rowCount();
    int column = 0;
    this->tableWidget->insertRow(rowCount);
        
    for (auto element : *testValues) {
        QTableWidgetItem *currentItem = new QTableWidgetItem(QString::fromStdString(element));
        this->tableWidget->setItem(rowCount, column, currentItem);
        column++;
    }
}

