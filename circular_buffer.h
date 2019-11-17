/*
 * buffer.h
 *
 *  Created on: Mar 24, 2018
 *      Author: matt
 */


//TODO:  Make this better
#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_


namespace util{
template<typename buffer_type> class circular_buffer{


public:

    circular_buffer(uint8_t bufferSize){

        head = 0;
        tail = 0;
        bufSize = bufferSize;
    }

    void put(buffer_type value){

        buf[head] = value;
        head =(head + 1) % bufSize;

        if(head == tail)
        {

            tail = (tail + 1) % bufSize;

        }
    }

    buffer_type get(void){

        buffer_type value = buf[tail];
        tail = (tail + 1) % bufSize;
        return value;

    }

    int buffer_size()
    {

        return bufSize;
    }

    bool full(void)
    {

        return ((head + 1) % bufSize) == tail;

    }

    bool empty(void)
    {

        return head == tail;

    }

    void reset(void)
    {

        head = tail;

    }



private:
    //std::array<buffer_type, 50U> buf;
    uint8_t * bufPtr;
    uint8_t buf[50];
    uint8_t head;
    uint8_t tail;
    uint8_t bufSize;

};

}

#endif /* BUFFER_H_ */