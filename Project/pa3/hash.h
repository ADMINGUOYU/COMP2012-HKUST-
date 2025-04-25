#ifndef HASH_H
#define HASH_H

#include <string>

template <typename T>
unsigned int int_convert(T val) {
    return (unsigned int) val;
}

template <typename T>
unsigned int int_convert(T* val) {
    unsigned long long p = reinterpret_cast<unsigned long long>(val);
    return p ^ (p >> 32);
}

template <>
unsigned int int_convert(double val) {
    // Convert double to unsigned int by bit manipulation
    unsigned long long int_val = *reinterpret_cast<unsigned long long*>(&val);
    return static_cast<unsigned int>(int_val);
}

template <>
unsigned int int_convert(float val) {
    // Convert float to unsigned int by bit manipulation
    unsigned int int_val = *reinterpret_cast<unsigned int*>(&val);
    return int_val;
}

template <>
unsigned int int_convert(std::string val) {
    // Convert string to unsigned int by summing ASCII values, with 256 weight
    unsigned long long hash = 0;
    for (char c : val) {
        hash = (hash * 256 + static_cast<unsigned int>(c)) % 0xFFFFFFFF;
    }
    return static_cast<unsigned int>(hash);
}

template <>
unsigned int int_convert(const char* val) {
    return int_convert<std::string>(val);
}

// The hash function that is given to you already
template <typename T>
unsigned int pa3_hash(T val, int nonce = 0) {
    unsigned int h = nonce;
    h += int_convert(val);
    h ^= (h >> 20) ^ (h >> 12);
    return (h ^ (h >> 7) ^ (h >> 4)) & 0x7FFFFFFF;
}

#endif // HASH_H