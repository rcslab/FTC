# Generated by 'click-buildtool elem2make' on Tue Jun 13 01:51:02 UTC 2017
ELEMENT_OBJS__0 = \
CounterMB.u.o \
FTAppenderElement.u.o \
FTBufferElement.u.o \
FTControlElement.u.o \
FTFastTCPGen.u.o \
FTFilterElement.u.o \
FTLoggerElement.u.o \
FTPassElement.u.o \
FTRandomDropElement.u.o \
FTStateElement.u.o \
NFCounterMB.u.o \
Transmitter.u.o \
TrivialCounterMB.u.o \

ELEMENT_OBJS = \
$(ELEMENT_OBJS__0) \

$(ELEMENT_OBJS__0): %.u.o: ./%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
	$(FIXDEP)
$(patsubst %.u.o,%.s,$(ELEMENT_OBJS__0)): %.s: ./%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.u.o,%.ii,$(ELEMENT_OBJS__0)): %.ii: ./%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

ELEMENT_LIBS = -L/usr/local/lib -lboost_iostreams -lboost_serialization