#ifndef local_scope_hh_INCLUDED
#define local_scope_hh_INCLUDED

#include "context.hh"
#include "scope.hh"

namespace Kakoune {

struct LocalScope : Scope {
	LocalScope(Context& context) : Scope(context.scope()), m_context{context} {
		m_context.m_local_scopes.push_back(this);
	}

	~LocalScope() {
		kak_assert(not m_context.m_local_scopes.empty() and
		           m_context.m_local_scopes.back() == this);
		m_context.m_local_scopes.pop_back();
	}

private:
	Context& m_context;
};

} // namespace Kakoune

#endif // local_scope_hh_INCLUDED
