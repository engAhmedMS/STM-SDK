/* 
 * File:   bit_configurations.h
 * Company: Impulses-I
 * Section: Embedded systems section.
 * Author: Ahmad AbdUl-Mageed
 * 
 * Created on September 17, 2019, 2:29 AM
 * Version: 1
 * 
 * For more info: 
 * Web site: https://impulses-i.com
 * Mail: info@impulses-i.com
 * Phone: 01030303155
 * Facebook page: www.facebook.com/impulses.i
 */
/*
 * This file contains the bit configurations that let you can access any bit on any register and change it's value by setting or clearing it.
 */

#ifndef BIT_CONFIGURATIONS_H
#define	BIT_CONFIGURATIONS_H
#include <inttypes.h>

//setting bit functions
//set bit by sending a ptr to the desired address and the bit number
#define set_bit(x, bit) (x = x | (1<<bit))
//setting bit by sending the desired address and the bit number
#define set_bit_Add(x, bit) (*((uint32_t*)x) = (*((uint32_t*)x)) | (1<<bit))

//clearing bit functions
//clearing bit by sending a ptr to the desired address and the bit number 
#define clr_bit(x, bit) (x = x & ~(1<<bit))
//clearing bit by sending the desired address and the bit number
#define clr_bit_Add(x, bit) (*((uint32_t*)x) = (*((uint32_t*)x)) &~ (1<<bit))

//toggling bit funtions
//toggling bit by sending a ptr to the desired address and the bit number 
#define toggle_bit(x, bit) (x = x^(1<<bit))
//toggling bit by sending the desired address and the bit number
#define toggle_bit_Add(x, bit) (*((uint32_t*)x) = (*((uint32_t *)x)^(1<<bit)))

//get bit functions
//get bit by sending the desired address and the bit number
#define get_bit(x, bit) ((x & (1<<bit)) > 0)
//get bit by sending the desired address and the bit number
#define get_bit_Add(x, bit) (((*((uint32_t*)x)) & (1<<bit)) > 0)
#endif	/* BIT_CONFIGURATIONS_H */

