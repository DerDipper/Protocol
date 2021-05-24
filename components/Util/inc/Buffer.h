/**
 * @file Buffer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once 


#include <stddef.h>

#define BUFFER_DEFINE(TYPE) struct { TYPE* values; size_t size;}