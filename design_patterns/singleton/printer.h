/*
 * @file   printer.h
 * @Author Roxana Anabel Lafuente (roxana.lafuente@gmail.com)
 * @date   August, 2016
 * @brief  Dummy printer class to ilustrate use of Singleton.
 */

#ifndef __PRINTER_H_
#define __PRINTER_H_

#include <iostream>
#include <cassert>

using namespace std;

/*
 * Singleton class implemented by using templates.
 */
class Printer
{
public:
    Printer() {};
    ~Printer() {};
    void print(string str){
        cout << str << endl;
    }
};

#endif