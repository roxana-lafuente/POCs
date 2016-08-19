/*
 * @file   singleton.h
 * @Author Roxana Anabel Lafuente (roxana.lafuente@gmail.com)
 * @date   August, 2016
 * @brief  Singleton design pattern - It restricts the instantiation of a class to one object.
 */

#ifndef __SINGLETON_H_
#define __SINGLETON_H_

#include <iostream>
#include <cassert>

/*
 * Singleton class implemented by using templates.
 * Credits:
 * Based on the proposed implementation on http://www.yolinux.com/TUTORIALS/C++Singleton.html
 */ 
template<class T>
struct Singleton
{
    static T* createInstance(void){
        if(!mInstance){
            mInstance = new T;
        }
        assert(mInstance != NULL);
        return mInstance;
    }
    protected:
        Singleton(); // Protected constructor.
        ~Singleton(); // Protected destructor.
    private:
        Singleton(Singleton const&); // Private copy constructor so it is forbidden to call it.
        Singleton& operator=(Singleton const&); // Private assignment operator.
        static T* mInstance; // The only instance.
};

template <class T> T* Singleton<T>::mInstance = NULL;

#endif