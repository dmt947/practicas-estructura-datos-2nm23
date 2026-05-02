#include "Lista.h"

Lista::Lista():ultimo(-1) {}

Lista::~Lista() {}

int Lista::longitud() const
{
    return ultimo+1;
}
