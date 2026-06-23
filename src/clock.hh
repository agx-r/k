#ifndef clock_hh_INCLUDED
#define clock_hh_INCLUDED

#include <chrono>

namespace Kakoune {

using Clock = std::chrono::steady_clock;
using TimePoint = Clock::time_point;

} // namespace Kakoune

#endif // clock_hh_INCLUDED
