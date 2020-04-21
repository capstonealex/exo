/**
 * The <code>Bitmask</code> class represents Bit maniputation class for Bitwise opperations.
 * This class can be useb by any I/O hardware needed. Using unit32_t ensures the BitMask is platform agnostic.
 * 
 * 
 * Version 0.1
 * Date: 07/04/2020
 *
 */

#ifndef BITMASK_H
#define BITMASK_H
#include "stdint.h"
class Bitmask {
   private:
    uint32_t bits;

   public:
    Bitmask();

    /**
         * @brief Overwrites this bitmask with input Bitmask.
         * 
         * @param Bitmask object
         */
    void SetMask(Bitmask& other);
    /**
         * @brief  Return binary representation of bitmask Object.
         * 
         * @param uint32_t
         */
    uint32_t GetMask() const;
    /**
         * @brief Is bit set at input position
         * 
         * @param position
         * @return true if bit at input position = 1
         * @return false if not
         */
    bool GetBit(int pos) const;
    /**
         * @brief  Sets bit at specified pos to 1 or 0 (true or false).
         * 
         * @param int position
         * @param bool on/off
         */
    void SetBit(int pos, bool on);
    /**
         * @brief  Sets bit at pos to 1.
         * 
         * @param int position
         */
    void SetBit(int pos);

    /**
         * @brief  Sets bit at pos to 0.
         * 
         * @param int position
         */
    void ClearBit(int pos);

    /**
         * @brief  Sets bit at pos to 0.
         * 
         */
    void Clear();
};
#endif