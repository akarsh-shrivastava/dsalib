TARGET    =     linkedlisttest
CX        =     g++
LD        =     g++

INCLUDES0 =     include
INCLUDES1 =     ../include
CXOBJ     =     .obj
CXSRC     =     src

HEADERS   =     $(INCLUDES0)/*.h $(INCLUDES1)/*.h
CXSOURCE  =     $(CXSRC)/*.cpp
CXOBJECT  =     $(CXOBJ)/inserttest.o \
                $(CXOBJ)/testmain.o

CXFLAGS    =    -c -I$(INCLUDES0) -I$(INCLUDES1) -O3 --std=c++17
LDFLAGS    =    -lgtest -lgtest_main -lpthread

$(TARGET): $(CXOBJECT)
	$(LD) $^ $(LDFLAGS) -o $@ 

$(CXOBJ)/%.o: $(CXSRC)/%.cpp $(HEADERS)
	$(CX) $(CXFLAGS) $< -o $@

