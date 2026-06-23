#ifndef IORDENADOR_H
#define IORDENADOR_H

#include <vector>
using namespace std;

template<typename T>
class IOrdenador{
public:
    virtual void ordenar(vector<T>& datos) = 0;
    virtual ~IOrdenador() {}
};

#endif
