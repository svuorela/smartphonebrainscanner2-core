/**
* Smartphone Brain Scanner 2 License Agreement (MIT License)
*
* Copyright (c) 2012 Arkadiusz Stopczynski, Jakob Eg Larsen, Carsten Stahlhut, Michael Kai Petersen, Lars Kai Hansen.
* Technical University of Denmark, DTU Informatics, Cognitive Systems Section. http://code.google.com/p/smartphonebrainscanner2
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy,
* modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom
* the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef SBS2FILTER_H
#define SBS2FILTER_H

#include <QObject>
#include <sbs2common.h>
#include <QFile>
#include <QStringList>
#include <dtu_array_2d.h>

/**
  @todo Filter should be a container for particular implementations of the filter, either static or adaptive.
  */


/**
  @class Class of a temporal filter.
  */


class Sbs2Filter : public QObject
{
    Q_OBJECT

public:
    Sbs2Filter(int fbandLow_, int fbandHigh_, int order_, QObject *parent = 0);
    void loadFilter();
    void updateFilter(int fbandLow_, int fbandHigh_);
    void doFilter(DTU::DtuArray2D<double>* values, DTU::DtuArray2D<double>* returnValues);
    ~Sbs2Filter();
    void turnOn() { on = true; }
    void turnOff() { on = false; }
    bool isOn() { return on; }

private:

private:
    DTU::DtuArray2D<double>* hcoef2;
    bool on;
    int fbandLow;
    int fbandHigh;
    int order;

signals:
    
public slots:
    
};

#endif // SBS2FILTER_H


