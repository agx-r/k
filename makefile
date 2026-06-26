.SUFFIXES: .cc .opt.o

CXX    = c++
PREFIX = /usr/local
BIN    = out/kpurified

.PATH.cc: src != find src -type d

sources != find src -type f -name '*.cc'
objects = $(sources:t:R:%=out/%.opt.o)

CPPFLAGS += -DKAK_BIN_PATH=\"$(DESTDIR)$(PREFIX)/bin/k\"
CXXFLAGS += -std=c++2b -O3 -g3 -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-sign-compare

all: $(BIN)

.cc.opt.o:
	@mkdir -p out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MD -MP -MF $(@:.opt.o=.opt.d) -c -o $@ $<

$(BIN): out/.version.opt.o $(objects)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $> $(LIBS) -o $@

out/.version.cc:
	@mkdir -p out
	echo 'namespace Kakoune { const char *version = "purified"; }' > $@

clean:
	rm -rf out

.MAKEFLAGS: -W
