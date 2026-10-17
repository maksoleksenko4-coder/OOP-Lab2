#pragma once
#include <string>

class Bitstring {
private:
    
    unsigned long high;
    unsigned long low;

public:
    
    void Init(unsigned long h, unsigned long l);
    void Read();
    void Display() const;
    std::string toString() const;

    
    Bitstring And(const Bitstring& other) const;
    Bitstring Or(const Bitstring& other) const;
    Bitstring Xor(const Bitstring& other) const;
    Bitstring Not() const;

   
    Bitstring shiftleft(int n) const;
    Bitstring shiftright(int n) const;
};