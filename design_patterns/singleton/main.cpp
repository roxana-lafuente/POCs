/*
 * @file   main.cpp
 * @Author Roxana Anabel Lafuente (roxana.lafuente@gmail.com)
 * @date   August, 2016
 * @brief  Example of how to use singleton.
 */

#include <iostream>
#include "singleton.h"
#include "printer.h"

using namespace std;

typedef Singleton<Printer> SingletonPrinter;

int main(void)
{
    // Illustration of how to use a Singleton.
    Singleton<Printer>::createInstance()->print("TEST");
    Singleton<Printer>::createInstance()->print("A");
    return 0;
}