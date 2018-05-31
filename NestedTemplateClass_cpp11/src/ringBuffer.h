#ifndef MY_RING_BUFF_H
#define MY_RING_BUFF_H

#include <iostream>
#include <array>
#include <initializer_list>

template< class T>
class RingBuffer_t
{
public:
    class iterator;

    RingBuffer_t( ) : m_size(1), m_last(0) , buffer(NULL) {
        buffer = new T[1];
    };

    RingBuffer_t( int size ) : m_size(size), m_last(0) , buffer(NULL) {
        buffer = new T[size];
    };

    RingBuffer_t( int size, std::initializer_list<T> list ) : m_size(size), m_last(0) , buffer(NULL) {
        buffer = new T[size];

        if(size < list.size()) {
            std::cout<< "ERROR: Size mismatch"<< std::endl;
        }

        for (auto it : list) {
            add(it);
        }
    };

    ~RingBuffer_t( )  {
        delete [] buffer;
        buffer = NULL;
    };

    void add(const T & obj) {
        if(m_last >= m_size){
            m_last = 0;
        }
        buffer[m_last] = obj;
        m_last ++;
    };

    T & get(const int pos) const {
        return buffer[pos];
    };

    const int & size() const {
        return m_size;
    };

    iterator begin() noexcept{
        return iterator(0, *this);
    };
    //iterator begin() const noexcept{
    //    return iterator(0, *this);
    //};

    iterator end() noexcept{
        return iterator(m_size, *this);
    };

private:
    int m_size;
    int m_last;
    T *buffer;
};

template<typename T>
class RingBuffer_t<T>::iterator
{
public:
    iterator( int pos , RingBuffer_t & buff ) : 
        m_pos(pos), m_buff(buff) {};

    iterator & operator++ (int) { //int says this is a post fix expresion ++
        m_pos ++;
        return *this;
    };

    iterator & operator++ () { //this is a pre fix expresion ++
        m_pos ++;
        return *this;
    };

    T & operator* () { 
        return m_buff.get(m_pos);
    };

   bool operator!= (const iterator & other) const { //this is a pre fix expresion ++
        return (m_pos != other.m_pos);
    };

private:
    int m_pos;
    RingBuffer_t & m_buff;
};


#endif // MY_RING_BUFF_H