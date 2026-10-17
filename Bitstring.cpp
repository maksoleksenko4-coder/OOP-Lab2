#include "Bitstring.h"
#include <iostream>
#include <bitset>

using namespace std;

void Bitstring::Init(unsigned long h, unsigned long l) {
    high = h;
    low = l;
}

void Bitstring::Read() {
    cout << "¬вед≥ть старшу частину (ц≥ле число): ";
    cin >> high;
    cout << "¬вед≥ть молодшу частину (ц≥ле число): ";
    cin >> low;
}

string Bitstring::toString() const {
    bitset<32> h_bits(high);
    bitset<32> l_bits(low);
    return h_bits.to_string() + l_bits.to_string();
}

void Bitstring::Display() const {
    cout << toString() << endl;
}

Bitstring Bitstring::And(const Bitstring& other) const {
    Bitstring result;
    result.Init(high & other.high, low & other.low);
    return result;
}

Bitstring Bitstring::Or(const Bitstring& other) const {
    Bitstring result;
    result.Init(high | other.high, low | other.low);
    return result;
}

Bitstring Bitstring::Xor(const Bitstring& other) const {
    Bitstring result;
    result.Init(high ^ other.high, low ^ other.low);
    return result;
}

Bitstring Bitstring::Not() const {
    Bitstring result;
    result.Init(~high, ~low);
    return result;
}

Bitstring Bitstring::shiftleft(int n) const {
    Bitstring result;
    if (n >= 64) {
        result.Init(0, 0);
    }
    else if (n >= 32) {
        result.Init(low << (n - 32), 0);
    }
    else if (n > 0) {
        result.Init((high << n) | (low >> (32 - n)), low << n);
    }
    else {
        result.Init(high, low);
    }
    return result;
}

Bitstring Bitstring::shiftright(int n) const {
    Bitstring result;
    if (n >= 64) {
        result.Init(0, 0);
    }
    else if (n >= 32) {
        result.Init(0, high >> (n - 32));
    }
    else if (n > 0) {
        result.Init(high >> n, (low >> n) | (high << (32 - n)));
    }
    else {
        result.Init(high, low);
    }
    return result;
}