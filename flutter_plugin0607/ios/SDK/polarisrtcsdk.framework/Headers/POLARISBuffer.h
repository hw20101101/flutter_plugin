#ifndef POLARISBUFFER_H
#define POLARISBUFFER_H

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <cassert>

#include "POLARISRtcInternalDef.h"

NS_POLARIS_START

template <typename T>
class POLARISBuffer
{
public:
    POLARISBuffer(size_t capacity):
            _capacity(capacity),
            _used(capacity),
            _ptr(0),
            _ownMem(true)
    {
        if (capacity > 0)
        {
            _ptr = new T[capacity];
        }
    }

    POLARISBuffer(T* pMem, size_t length):
    _capacity(length),
            _used(length),
            _ptr(pMem),
            _ownMem(false)
    {
    }

    POLARISBuffer(const T* pMem, size_t length):
            _capacity(length),
            _used(length),
            _ptr(0),
            _ownMem(true)
    {
        if (_capacity > 0)
        {
            _ptr = new T[_capacity];
            std::memcpy(_ptr, pMem, _used * sizeof(T));
        }
    }

    POLARISBuffer(const POLARISBuffer& other):
            _capacity(other._used),
            _used(other._used),
            _ptr(0),
            _ownMem(true)
    {
        if (_used)
        {
            _ptr = new T[_used];
            std::memcpy(_ptr, other._ptr, _used * sizeof(T));
        }
    }

    POLARISBuffer& operator = (const POLARISBuffer& other)
    {
        if (this != &other)
        {
            POLARISBuffer tmp(other);
            swap(tmp);
        }

        return *this;
    }

    ~POLARISBuffer()
    {
        if (_ownMem) delete [] _ptr;
    }

    void resize(size_t newCapacity, bool preserveContent = true)
    {
        if (newCapacity > _capacity)
        {
            T* ptr = new T[newCapacity];
            if (preserveContent)
            {
                std::memcpy(ptr, _ptr, _used * sizeof(T));
            }
            delete [] _ptr;
            _ptr = ptr;
            _capacity = newCapacity;
        }

        _used = newCapacity;
    }

    void setCapacity(size_t newCapacity, bool preserveContent = true)
    {
        if (newCapacity != _capacity)
        {
            T* ptr = 0;
            if (newCapacity > 0)
            {
                ptr = new T[newCapacity];
                if (preserveContent)
                {
                    size_t newSz = _used < newCapacity ? _used : newCapacity;
                    std::memcpy(ptr, _ptr, newSz * sizeof(T));
                }
            }
            delete [] _ptr;
            _ptr = ptr;
            _capacity = newCapacity;

            if (newCapacity < _used) _used = newCapacity;
        }
    }

    void assign(const T* buf, size_t sz)
    {
        if (0 == sz) return;
        if (sz > _capacity) resize(sz, false);
        std::memcpy(_ptr, buf, sz * sizeof(T));
        _used = sz;
    }

    void append(const T* buf, size_t sz)
    {
        if (0 == sz) return;
        resize(_used + sz, true);
        std::memcpy(_ptr + _used - sz, buf, sz * sizeof(T));
    }

    void append(T val)
    {
        resize(_used + 1, true);
        _ptr[_used - 1] = val;
    }

    void append(const POLARISBuffer& buf)
    {
        append(buf.begin(), buf.size());
    }

    size_t capacity() const
    {
        return _capacity;
    }

    size_t capacityAllBytes() const
    {
        return _capacity * sizeof(T);
    }

    void swap(POLARISBuffer& other)
    {
        using std::swap;

        swap(_ptr, other._ptr);
        swap(_capacity, other._capacity);
        swap(_used, other._used);
    }

    bool operator == (const POLARISBuffer& other) const
    {
        if (this != &other)
        {
            if (_used == other._used)
            {
                if (std::memcmp(_ptr, other._ptr, _used * sizeof(T)) == 0)
                {
                    return true;
                }
            }
            return false;
        }

        return true;
    }

    bool operator != (const POLARISBuffer& other) const
    {
        return !(*this == other);
    }

    void clear()
    {
        std::memset(_ptr, 0, _used * sizeof(T));
    }

    size_t size() const
    {
        return _used;
    }

    size_t sizeBytes() const
    {
        return _used * sizeof(T);
    }

    T* begin()
    {
        return _ptr;
    }

    const T* begin() const
    {
        return _ptr;
    }

    T* end()
    {
        return _ptr + _used;
    }

    const T* end() const
    {
        return _ptr + _used;
    }

    bool empty() const
    {
        return 0 == _used;
    }

    T& operator [] (size_t index)
    {
        assert (index < _used);

        return _ptr[index];
    }

    const T& operator [] (size_t index) const
    {
        assert (index < _used);

        return _ptr[index];
    }

private:
    POLARISBuffer();

    size_t _capacity;
    size_t _used;
    T*          _ptr;
    bool        _ownMem;
};

NS_POLARIS_END
	
#endif //POLARISBUFFER_H
