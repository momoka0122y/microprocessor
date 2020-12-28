// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vcpu__Syms_H_
#define _Vcpu__Syms_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vcpu.h"

// SYMS CLASS
class Vcpu__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vcpu*                          TOPp;
    
    // CREATORS
    Vcpu__Syms(Vcpu* topp, const char* namep);
    ~Vcpu__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
