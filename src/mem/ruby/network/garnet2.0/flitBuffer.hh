#ifndef __MEM_RUBY_NETWORK_GARNET2_0_FLITBUFFER_HH__
#define __MEM_RUBY_NETWORK_GARNET2_0_FLITBUFFER_HH__

#include <algorithm>
#include <iostream>
#include <vector>

#include "mem/ruby/network/garnet2.0/CommonTypes.hh"
#include "mem/ruby/network/garnet2.0/flit.hh"

class flitBuffer
{
  public:
    flitBuffer();
    flitBuffer(int maximum_size);

    bool isReady(Cycles curTime);
    bool isEmpty();
    void print(std::ostream& out) const;
    bool isFull();
    void setMaxSize(int maximum);
    int getSize() const { return m_buffer.size(); }

    flit *
    getTopFlit()
    {
        flit *f = m_buffer.front();
        std::pop_heap(m_buffer.begin(), m_buffer.end(), flit::greater);
        m_buffer.pop_back();
        return f;
    }

    flit *
    peekTopFlit()
    {
        return m_buffer.front();
    }

    void
    insert(flit *flt)
    {
        m_buffer.push_back(flt);
        std::push_heap(m_buffer.begin(), m_buffer.end(), flit::greater);
    }

    uint32_t functionalWrite(Packet *pkt);

  private:
    std::vector<flit *> m_buffer;
    int max_size;
};

inline std::ostream&
operator<<(std::ostream& out, const flitBuffer& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __MEM_RUBY_NETWORK_GARNET2_0_FLITBUFFER_HH__
