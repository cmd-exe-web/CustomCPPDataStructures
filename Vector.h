#pragma once

template <typename T>
class Vector
{
public:
    Vector()
    {
        // Initially vector will be of size = 3
        ReAlloc(2);
    };

    ~Vector()
    {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    size_t Size() const { return m_Size; }

    T &operator[](size_t index) { return m_Data[index]; }             // assert
    const T &operator[](size_t index) const { return m_Data[index]; } // assert

    void Push_Back(T &&element)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Size + m_Size / 2);
        m_Data[m_Size] = std::move(element);
        m_Size++;
    }
    void Push_Back(const T &element)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Size + m_Size / 2);
        m_Data[m_Size] = element;
        m_Size++;
    }

    template <typename... Args>
    T &Emplace_Back(Args &&...args)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        new (m_Data + m_Size) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    void Pop_Back()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }
    void Clear()
    {
        for (size_t i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }
        m_Size = 0;
    }

private:
    void ReAlloc(size_t newCapacity)
    {
        // 1. allocate
        T *newData = (T *)::operator new(newCapacity * sizeof(T));
        // 2. copy or move
        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; i++)
        {
            new (&newData[i]) T(std::move(m_Data[i]));
            // newData[i] = std::move(m_Data[i]);
        }

        // 3. delete
        for (size_t i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }
        ::operator delete(m_Data, m_Capacity * sizeof(T));

        m_Data = newData;
        m_Capacity = newCapacity;
    }

private:
    T *m_Data;
    size_t m_Capacity = 0;
    size_t m_Size = 0;
};
