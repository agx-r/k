#ifndef enum_hh_INCLUDED
#define enum_hh_INCLUDED

#include "meta.hh"
#include "string.hh"

namespace Kakoune {

template <typename T> struct EnumDesc {
	T value;
	StringView name;
};

template <typename T>
concept DescribedEnum = requires { enum_desc(Meta::Type<T>{}); };

} // namespace Kakoune

#endif // enum_hh_INCLUDED
