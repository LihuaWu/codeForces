#pragma once

#include <string>
#include <memory>
#include <boost/noncopyable.hpp>

namespace muyu {

class PerfTest : public boost::noncopyable {
public:
    PerfTest(const std::string& conf) noexcept;
    ~PerfTest() noexcept;
    void run() noexcept;
private:
    class PerfTestImpl;
    std::unique_ptr<PerfTestImpl> _impl;
};

} //muyu
