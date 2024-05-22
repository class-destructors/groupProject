#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <fstream>

#include "order.h"

class printer
{
    private:
        order * order;
        std::ofstream outFile;

    public:
        void printOrders();
};

#endif