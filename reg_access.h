/*
 * reg_access.h
 *
 *  Created on: Jul 18, 2018
 *      Author: matt
 */

#ifndef REG_ACCESS_H_
#define REG_ACCESS_H_


template<typename addr_type,
        typename reg_type,
        const addr_type address,
        const reg_type value>
class reg_access
{

public:
    static void reg_set()
    {
        *reinterpret_cast<volatile reg_type*>(address) = value;
    }

    static void reg_or()
    {

        *reinterpret_cast<volatile reg_type*>(address) |= value;

    }

    static void reg_xor()
    {

        *reinterpret_cast<volatile reg_type*>(address) ^= value;

    }

    static void reg_and_not()
    {

        *reinterpret_cast<volatile reg_type*>(address) &= reg_type (~value);

    }

    static void reg_and()
    {

        *reinterpret_cast<volatile reg_type*>(address) &= value;

    }

    static reg_type reg_get()
    {

        return *reinterpret_cast<volatile reg_type*>(address);

    }
};


#endif /* REG_ACCESS_H_ */


