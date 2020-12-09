// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "Vcpu.h"              // For This
#include "Vcpu__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vcpu) {
    Vcpu__Syms* __restrict vlSymsp = __VlSymsp = new Vcpu__Syms(this, name());
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcpu::__Vconfigure(Vcpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcpu::~Vcpu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vcpu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu::eval\n"); );
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vcpu::_eval_initial_loop(Vcpu__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vcpu::_initial__TOP__1(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_initial__TOP__1\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp1,575,0,18);
    VL_SIGW(__Vtemp2,575,0,18);
    // Body
    // INITIAL at fetch.v:7
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x636f6465U;
    __Vtemp1[2U] = 0x7369732fU;
    __Vtemp1[3U] = 0x6e746865U;
    __Vtemp1[4U] = 0x725f5379U;
    __Vtemp1[5U] = 0x6b5f666fU;
    __Vtemp1[6U] = 0x656d6172U;
    __Vtemp1[7U] = 0x2f436f72U;
    __Vtemp1[8U] = 0x61726b73U;
    __Vtemp1[9U] = 0x6e63686dU;
    __Vtemp1[0xaU] = 0x722f6265U;
    __Vtemp1[0xbU] = 0x6573736fU;
    __Vtemp1[0xcU] = 0x70726f63U;
    __Vtemp1[0xdU] = 0x6963726fU;
    __Vtemp1[0xeU] = 0x6a6f2f6dU;
    __Vtemp1[0xfU] = 0x2f64656eU;
    __Vtemp1[0x10U] = 0x686f6d65U;
    __Vtemp1[0x11U] = 0x2fU;
    VL_READMEM_W (true,32,32769, 0,18, __Vtemp1, vlTOPp->cpu__DOT__fetch_body__DOT__ir_mem
		  ,0,~0);
    // INITIAL at data_mem.v:18
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x64617461U;
    __Vtemp2[2U] = 0x7369732fU;
    __Vtemp2[3U] = 0x6e746865U;
    __Vtemp2[4U] = 0x725f5379U;
    __Vtemp2[5U] = 0x6b5f666fU;
    __Vtemp2[6U] = 0x656d6172U;
    __Vtemp2[7U] = 0x2f436f72U;
    __Vtemp2[8U] = 0x61726b73U;
    __Vtemp2[9U] = 0x6e63686dU;
    __Vtemp2[0xaU] = 0x722f6265U;
    __Vtemp2[0xbU] = 0x6573736fU;
    __Vtemp2[0xcU] = 0x70726f63U;
    __Vtemp2[0xdU] = 0x6963726fU;
    __Vtemp2[0xeU] = 0x6a6f2f6dU;
    __Vtemp2[0xfU] = 0x2f64656eU;
    __Vtemp2[0x10U] = 0x686f6d65U;
    __Vtemp2[0x11U] = 0x2fU;
    VL_READMEM_W (true,32,32768, 0,18, __Vtemp2, vlTOPp->cpu__DOT__data_mem_body__DOT__ram
		  ,0,~0);
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__2\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__cpu__DOT__register_file_body__DOT__register_file__v0,4,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__register_file_body__DOT__register_file__v0,0,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__register_file_body__DOT__register_file__v1,0,0);
    VL_SIG8(__Vdly__cpu__DOT__uart0__DOT__bitcount,3,0);
    VL_SIG16(__Vdly__cpu__DOT__uart0__DOT__shifter,8,0);
    VL_SIG(__Vdlyvval__cpu__DOT__register_file_body__DOT__register_file__v0,31,0);
    VL_SIG(__Vdly__cpu__DOT__hardware_counter0__DOT__cycles,31,0);
    // Body
    __Vdly__cpu__DOT__hardware_counter0__DOT__cycles 
	= vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles;
    __Vdly__cpu__DOT__uart0__DOT__shifter = vlTOPp->cpu__DOT__uart0__DOT__shifter;
    __Vdly__cpu__DOT__uart0__DOT__bitcount = vlTOPp->cpu__DOT__uart0__DOT__bitcount;
    __Vdlyvset__cpu__DOT__register_file_body__DOT__register_file__v0 = 0U;
    __Vdlyvset__cpu__DOT__register_file_body__DOT__register_file__v1 = 0U;
    // ALWAYS at hardware_counter.v:16
    __Vdly__cpu__DOT__hardware_counter0__DOT__cycles 
	= ((IData)(vlTOPp->cpu_resetn) ? ((IData)(1U) 
					  + vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles)
	    : 0U);
    // ALWAYS at uart.v:44
    if (vlTOPp->cpu_resetn) {
	if ((((0xf6fff070U == vlTOPp->cpu__DOT__alu_result) 
	      & (IData)(vlTOPp->cpu__DOT__is_store)) 
	     & (~ (IData)(vlTOPp->cpu__DOT__uart0__DOT__uart_busy)))) {
	    __Vdly__cpu__DOT__uart0__DOT__shifter = 
		(0x1feU & (vlTOPp->cpu__DOT__srcreg2_data 
			   << 1U));
	    __Vdly__cpu__DOT__uart0__DOT__bitcount = 0xbU;
	}
	if (((IData)(vlTOPp->cpu__DOT__uart0__DOT__sending) 
	     & (~ (vlTOPp->cpu__DOT__uart0__DOT__d 
		   >> 0x1cU)))) {
	    __Vdly__cpu__DOT__uart0__DOT__shifter = 
		(0x100U | (0xffU & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__shifter) 
				    >> 1U)));
	    __Vdly__cpu__DOT__uart0__DOT__bitcount 
		= (0xfU & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
			   - (IData)(1U)));
	    vlTOPp->cpu__DOT__uart_OUT_data = (1U & (IData)(vlTOPp->cpu__DOT__uart0__DOT__shifter));
	}
    } else {
	__Vdly__cpu__DOT__uart0__DOT__bitcount = 0U;
	__Vdly__cpu__DOT__uart0__DOT__shifter = 0U;
	vlTOPp->cpu__DOT__uart_OUT_data = 1U;
    }
    // ALWAYS at reg_file.v:26
    if (vlTOPp->cpu_resetn) {
	if (((IData)(vlTOPp->cpu__DOT__reg_we) & (0U 
						  != (IData)(vlTOPp->cpu__DOT__dstreg_num)))) {
	    __Vdlyvval__cpu__DOT__register_file_body__DOT__register_file__v0 
		= ((IData)(vlTOPp->cpu__DOT__is_load)
		    ? (((0xbU == (IData)(vlTOPp->cpu__DOT__alucode)) 
			& (0xffffff00U == vlTOPp->cpu__DOT__alu_result))
		        ? vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles
		        : (((9U == (IData)(vlTOPp->cpu__DOT__alucode)) 
			    & (0U == (3U & vlTOPp->cpu__DOT__alu_result)))
			    ? ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
								       [
								       (0x7fffU 
									& (vlTOPp->cpu__DOT__alu_result 
									   >> 2U))] 
								       >> 7U)))) 
					       << 8U)) 
			       | (0xffU & vlTOPp->cpu__DOT__data_mem_body__DOT__ram
				  [(0x7fffU & (vlTOPp->cpu__DOT__alu_result 
					       >> 2U))]))
			    : (((9U == (IData)(vlTOPp->cpu__DOT__alucode)) 
				& (1U == (3U & vlTOPp->cpu__DOT__alu_result)))
			        ? ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
									   [
									   (0x7fffU 
									    & (vlTOPp->cpu__DOT__alu_result 
									       >> 2U))] 
									   >> 0xfU)))) 
						   << 8U)) 
				   | (0xffU & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
					       [(0x7fffU 
						 & (vlTOPp->cpu__DOT__alu_result 
						    >> 2U))] 
					       >> 8U)))
			        : (((9U == (IData)(vlTOPp->cpu__DOT__alucode)) 
				    & (2U == (3U & vlTOPp->cpu__DOT__alu_result)))
				    ? ((0xffffff00U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
								   [
								   (0x7fffU 
								    & (vlTOPp->cpu__DOT__alu_result 
								       >> 2U))] 
								   >> 0x17U)))) 
					   << 8U)) 
				       | (0xffU & (
						   vlTOPp->cpu__DOT__data_mem_body__DOT__ram
						   [
						   (0x7fffU 
						    & (vlTOPp->cpu__DOT__alu_result 
						       >> 2U))] 
						   >> 0x10U)))
				    : (((9U == (IData)(vlTOPp->cpu__DOT__alucode)) 
					& (3U == (3U 
						  & vlTOPp->cpu__DOT__alu_result)))
				        ? ((0xffffff00U 
					    & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
								       [
								       (0x7fffU 
									& (vlTOPp->cpu__DOT__alu_result 
									   >> 2U))] 
								       >> 0x1fU)))) 
					       << 8U)) 
					   | (0xffU 
					      & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
						 [(0x7fffU 
						   & (vlTOPp->cpu__DOT__alu_result 
						      >> 2U))] 
						 >> 0x18U)))
				        : (((0xaU == (IData)(vlTOPp->cpu__DOT__alucode)) 
					    & (0U == 
					       (3U 
						& vlTOPp->cpu__DOT__alu_result)))
					    ? ((0xffff0000U 
						& (VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
									   [
									   (0x7fffU 
									    & (vlTOPp->cpu__DOT__alu_result 
									       >> 2U))] 
									   >> 0xfU)))) 
						   << 0x10U)) 
					       | (0xffffU 
						  & vlTOPp->cpu__DOT__data_mem_body__DOT__ram
						  [
						  (0x7fffU 
						   & (vlTOPp->cpu__DOT__alu_result 
						      >> 2U))]))
					    : (((0xaU 
						 == (IData)(vlTOPp->cpu__DOT__alucode)) 
						& (1U 
						   == 
						   (3U 
						    & vlTOPp->cpu__DOT__alu_result)))
					        ? (
						   (0xffff0000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
									       [
									       (0x7fffU 
										& (vlTOPp->cpu__DOT__alu_result 
										>> 2U))] 
									       >> 0x17U)))) 
						       << 0x10U)) 
						   | (0xffffU 
						      & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							 [
							 (0x7fffU 
							  & (vlTOPp->cpu__DOT__alu_result 
							     >> 2U))] 
							 >> 8U)))
					        : (
						   ((0xaU 
						     == (IData)(vlTOPp->cpu__DOT__alucode)) 
						    & (2U 
						       == 
						       (3U 
							& vlTOPp->cpu__DOT__alu_result)))
						    ? 
						   ((0xffff0000U 
						     & (VL_NEGATE_I((IData)(
									    (1U 
									     & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
										[
										(0x7fffU 
										& (vlTOPp->cpu__DOT__alu_result 
										>> 2U))] 
										>> 0x1fU)))) 
							<< 0x10U)) 
						    | (0xffffU 
						       & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							  [
							  (0x7fffU 
							   & (vlTOPp->cpu__DOT__alu_result 
							      >> 2U))] 
							  >> 0x10U)))
						    : 
						   (((0xbU 
						      == (IData)(vlTOPp->cpu__DOT__alucode)) 
						     & (3U 
							== 
							(3U 
							 & vlTOPp->cpu__DOT__alu_result)))
						     ? 
						    vlTOPp->cpu__DOT__data_mem_body__DOT__ram
						    [
						    (0x7fffU 
						     & (vlTOPp->cpu__DOT__alu_result 
							>> 2U))]
						     : 
						    (((0xcU 
						       == (IData)(vlTOPp->cpu__DOT__alucode)) 
						      & (0U 
							 == 
							 (3U 
							  & vlTOPp->cpu__DOT__alu_result)))
						      ? 
						     (0xffU 
						      & vlTOPp->cpu__DOT__data_mem_body__DOT__ram
						      [
						      (0x7fffU 
						       & (vlTOPp->cpu__DOT__alu_result 
							  >> 2U))])
						      : 
						     (((0xcU 
							== (IData)(vlTOPp->cpu__DOT__alucode)) 
						       & (1U 
							  == 
							  (3U 
							   & vlTOPp->cpu__DOT__alu_result)))
						       ? 
						      (0xffU 
						       & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							  [
							  (0x7fffU 
							   & (vlTOPp->cpu__DOT__alu_result 
							      >> 2U))] 
							  >> 8U))
						       : 
						      (((0xcU 
							 == (IData)(vlTOPp->cpu__DOT__alucode)) 
							& (2U 
							   == 
							   (3U 
							    & vlTOPp->cpu__DOT__alu_result)))
						        ? 
						       (0xffU 
							& (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							   [
							   (0x7fffU 
							    & (vlTOPp->cpu__DOT__alu_result 
							       >> 2U))] 
							   >> 0x10U))
						        : 
						       (((0xcU 
							  == (IData)(vlTOPp->cpu__DOT__alucode)) 
							 & (3U 
							    == 
							    (3U 
							     & vlTOPp->cpu__DOT__alu_result)))
							 ? 
							(0xffU 
							 & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							    [
							    (0x7fffU 
							     & (vlTOPp->cpu__DOT__alu_result 
								>> 2U))] 
							    >> 0x18U))
							 : 
							(((0xdU 
							   == (IData)(vlTOPp->cpu__DOT__alucode)) 
							  & (0U 
							     == 
							     (3U 
							      & vlTOPp->cpu__DOT__alu_result)))
							  ? 
							 (0xffffU 
							  & vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							  [
							  (0x7fffU 
							   & (vlTOPp->cpu__DOT__alu_result 
							      >> 2U))])
							  : 
							 (((0xdU 
							    == (IData)(vlTOPp->cpu__DOT__alucode)) 
							   & (1U 
							      == 
							      (3U 
							       & vlTOPp->cpu__DOT__alu_result)))
							   ? 
							  (0xffffU 
							   & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							      [
							      (0x7fffU 
							       & (vlTOPp->cpu__DOT__alu_result 
								  >> 2U))] 
							      >> 8U))
							   : 
							  (((0xdU 
							     == (IData)(vlTOPp->cpu__DOT__alucode)) 
							    & (2U 
							       == 
							       (3U 
								& vlTOPp->cpu__DOT__alu_result)))
							    ? 
							   (0xffffU 
							    & (vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							       [
							       (0x7fffU 
								& (vlTOPp->cpu__DOT__alu_result 
								   >> 2U))] 
							       >> 0x10U))
							    : 
							   vlTOPp->cpu__DOT__data_mem_body__DOT__ram
							   [
							   (0x7fffU 
							    & (vlTOPp->cpu__DOT__alu_result 
							       >> 2U))]))))))))))))))))
		    : vlTOPp->cpu__DOT__alu_result);
	    __Vdlyvset__cpu__DOT__register_file_body__DOT__register_file__v0 = 1U;
	    __Vdlyvdim0__cpu__DOT__register_file_body__DOT__register_file__v0 
		= vlTOPp->cpu__DOT__dstreg_num;
	}
    } else {
	__Vdlyvset__cpu__DOT__register_file_body__DOT__register_file__v1 = 1U;
    }
    // ALWAYS at write_back.v:8
    if (vlTOPp->cpu_resetn) {
	if (vlTOPp->sysclk) {
	    vlTOPp->cpu__DOT__pc = vlTOPp->cpu__DOT__nextpc;
	}
    } else {
	vlTOPp->cpu__DOT__pc = 0x8000U;
    }
    vlTOPp->cpu__DOT__uart0__DOT__shifter = __Vdly__cpu__DOT__uart0__DOT__shifter;
    vlTOPp->cpu__DOT__uart0__DOT__bitcount = __Vdly__cpu__DOT__uart0__DOT__bitcount;
    vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles 
	= __Vdly__cpu__DOT__hardware_counter0__DOT__cycles;
    // ALWAYSPOST at reg_file.v:36
    if (__Vdlyvset__cpu__DOT__register_file_body__DOT__register_file__v0) {
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[__Vdlyvdim0__cpu__DOT__register_file_body__DOT__register_file__v0] 
	    = __Vdlyvval__cpu__DOT__register_file_body__DOT__register_file__v0;
    }
    if (__Vdlyvset__cpu__DOT__register_file_body__DOT__register_file__v1) {
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[1U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[2U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[3U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[4U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[5U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[6U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[7U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[8U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[9U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0xaU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0xbU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0xcU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0xdU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0xeU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0xfU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x10U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x11U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x12U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x13U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x14U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x15U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x16U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x17U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x18U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x19U] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x1aU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x1bU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x1cU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x1dU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x1eU] = 0U;
	vlTOPp->cpu__DOT__register_file_body__DOT__register_file[0x1fU] = 0U;
    }
    vlTOPp->cpu__DOT__uart0__DOT__uart_busy = (0U != 
					       (7U 
						& ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
						   >> 1U)));
    vlTOPp->cpu__DOT__uart0__DOT__sending = (0U != (IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount));
    vlTOPp->uart_tx = vlTOPp->cpu__DOT__uart_OUT_data;
    // ALWAYS at uart.v:35
    vlTOPp->cpu__DOT__uart0__DOT__d = ((IData)(vlTOPp->cpu_resetn)
				        ? vlTOPp->cpu__DOT__uart0__DOT__dNxt
				        : 0U);
    vlTOPp->cpu__DOT__ir = ((0x8000U >= (0xffffU & 
					 (vlTOPp->cpu__DOT__pc 
					  >> 2U))) ? 
			    vlTOPp->cpu__DOT__fetch_body__DOT__ir_mem
			    [(0xffffU & (vlTOPp->cpu__DOT__pc 
					 >> 2U))] : 0U);
    vlTOPp->cpu__DOT__uart0__DOT__dNxt = (0x1fffffffU 
					  & (vlTOPp->cpu__DOT__uart0__DOT__d 
					     + ((0x10000000U 
						 & vlTOPp->cpu__DOT__uart0__DOT__d)
						 ? 0x1c200U
						 : 0xfed09500U)));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__3(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__3\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v0,4,0);
    VL_SIG8(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v0,7,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v0,0,0);
    VL_SIG8(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v1,4,0);
    VL_SIG8(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v1,7,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v1,0,0);
    VL_SIG8(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v2,4,0);
    VL_SIG8(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v2,7,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v2,0,0);
    VL_SIG8(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v3,4,0);
    VL_SIG8(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v3,7,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v3,0,0);
    VL_SIG8(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v4,4,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v4,0,0);
    VL_SIG8(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v5,4,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v5,0,0);
    VL_SIG8(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v6,4,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v6,0,0);
    VL_SIG8(__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v7,0,0);
    VL_SIG16(__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v0,14,0);
    VL_SIG16(__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v1,14,0);
    VL_SIG16(__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v2,14,0);
    VL_SIG16(__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v3,14,0);
    VL_SIG16(__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v4,14,0);
    VL_SIG16(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v4,15,0);
    VL_SIG16(__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v5,14,0);
    VL_SIG16(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v5,15,0);
    VL_SIG16(__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v6,14,0);
    VL_SIG16(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v6,15,0);
    VL_SIG16(__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v7,14,0);
    VL_SIG(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v7,31,0);
    // Body
    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v0 = 0U;
    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v1 = 0U;
    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v2 = 0U;
    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v3 = 0U;
    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v4 = 0U;
    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v5 = 0U;
    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v6 = 0U;
    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v7 = 0U;
    // ALWAYS at data_mem.v:47
    if (vlTOPp->cpu__DOT__is_store) {
	if ((0xeU == (IData)(vlTOPp->cpu__DOT__alucode))) {
	    if ((2U & vlTOPp->cpu__DOT__alu_result)) {
		if ((1U & vlTOPp->cpu__DOT__alu_result)) {
		    __Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v0 
			= (0xffU & vlTOPp->cpu__DOT__srcreg2_data);
		    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v0 = 1U;
		    __Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v0 = 0x18U;
		    __Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v0 
			= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
				      >> 2U));
		} else {
		    __Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v1 
			= (0xffU & vlTOPp->cpu__DOT__srcreg2_data);
		    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v1 = 1U;
		    __Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v1 = 0x10U;
		    __Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v1 
			= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
				      >> 2U));
		}
	    } else {
		if ((1U & vlTOPp->cpu__DOT__alu_result)) {
		    __Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v2 
			= (0xffU & vlTOPp->cpu__DOT__srcreg2_data);
		    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v2 = 1U;
		    __Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v2 = 8U;
		    __Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v2 
			= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
				      >> 2U));
		} else {
		    __Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v3 
			= (0xffU & vlTOPp->cpu__DOT__srcreg2_data);
		    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v3 = 1U;
		    __Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v3 = 0U;
		    __Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v3 
			= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
				      >> 2U));
		}
	    }
	} else {
	    if ((0xfU == (IData)(vlTOPp->cpu__DOT__alucode))) {
		if ((2U & vlTOPp->cpu__DOT__alu_result)) {
		    if ((1U & (~ vlTOPp->cpu__DOT__alu_result))) {
			__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v4 
			    = (0xffffU & vlTOPp->cpu__DOT__srcreg2_data);
			__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v4 = 1U;
			__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v4 = 0x10U;
			__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v4 
			    = (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
					  >> 2U));
		    }
		} else {
		    if ((1U & vlTOPp->cpu__DOT__alu_result)) {
			__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v5 
			    = (0xffffU & vlTOPp->cpu__DOT__srcreg2_data);
			__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v5 = 1U;
			__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v5 = 8U;
			__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v5 
			    = (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
					  >> 2U));
		    } else {
			__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v6 
			    = (0xffffU & vlTOPp->cpu__DOT__srcreg2_data);
			__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v6 = 1U;
			__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v6 = 0U;
			__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v6 
			    = (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
					  >> 2U));
		    }
		}
	    } else {
		if ((0x10U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    __Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v7 
			= vlTOPp->cpu__DOT__srcreg2_data;
		    __Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v7 = 1U;
		    __Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v7 
			= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
				      >> 2U));
		}
	    }
	}
    }
    // ALWAYSPOST at data_mem.v:55
    if (__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v0) {
	vlTOPp->cpu__DOT__data_mem_body__DOT__ram[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v0] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v0))) 
		& vlTOPp->cpu__DOT__data_mem_body__DOT__ram
		[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v0]) 
	       | ((IData)(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v0) 
		  << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v0)));
    }
    if (__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v1) {
	vlTOPp->cpu__DOT__data_mem_body__DOT__ram[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v1] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v1))) 
		& vlTOPp->cpu__DOT__data_mem_body__DOT__ram
		[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v1]) 
	       | ((IData)(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v1) 
		  << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v1)));
    }
    if (__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v2) {
	vlTOPp->cpu__DOT__data_mem_body__DOT__ram[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v2] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v2))) 
		& vlTOPp->cpu__DOT__data_mem_body__DOT__ram
		[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v2]) 
	       | ((IData)(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v2) 
		  << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v2)));
    }
    if (__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v3) {
	vlTOPp->cpu__DOT__data_mem_body__DOT__ram[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v3] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v3))) 
		& vlTOPp->cpu__DOT__data_mem_body__DOT__ram
		[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v3]) 
	       | ((IData)(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v3) 
		  << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v3)));
    }
    if (__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v4) {
	vlTOPp->cpu__DOT__data_mem_body__DOT__ram[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v4] 
	    = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v4))) 
		& vlTOPp->cpu__DOT__data_mem_body__DOT__ram
		[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v4]) 
	       | ((IData)(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v4) 
		  << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v4)));
    }
    if (__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v5) {
	vlTOPp->cpu__DOT__data_mem_body__DOT__ram[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v5] 
	    = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v5))) 
		& vlTOPp->cpu__DOT__data_mem_body__DOT__ram
		[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v5]) 
	       | ((IData)(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v5) 
		  << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v5)));
    }
    if (__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v6) {
	vlTOPp->cpu__DOT__data_mem_body__DOT__ram[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v6] 
	    = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v6))) 
		& vlTOPp->cpu__DOT__data_mem_body__DOT__ram
		[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v6]) 
	       | ((IData)(__Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v6) 
		  << (IData)(__Vdlyvlsb__cpu__DOT__data_mem_body__DOT__ram__v6)));
    }
    if (__Vdlyvset__cpu__DOT__data_mem_body__DOT__ram__v7) {
	vlTOPp->cpu__DOT__data_mem_body__DOT__ram[__Vdlyvdim0__cpu__DOT__data_mem_body__DOT__ram__v7] 
	    = __Vdlyvval__cpu__DOT__data_mem_body__DOT__ram__v7;
    }
}

void Vcpu::_settle__TOP__4(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_settle__TOP__4\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cpu__DOT__uart0__DOT__uart_busy = (0U != 
					       (7U 
						& ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
						   >> 1U)));
    vlTOPp->cpu__DOT__uart0__DOT__sending = (0U != (IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount));
    vlTOPp->uart_tx = vlTOPp->cpu__DOT__uart_OUT_data;
    vlTOPp->cpu__DOT__uart0__DOT__dNxt = (0x1fffffffU 
					  & (vlTOPp->cpu__DOT__uart0__DOT__d 
					     + ((0x10000000U 
						 & vlTOPp->cpu__DOT__uart0__DOT__d)
						 ? 0x1c200U
						 : 0xfed09500U)));
    vlTOPp->cpu__DOT__ir = ((0x8000U >= (0xffffU & 
					 (vlTOPp->cpu__DOT__pc 
					  >> 2U))) ? 
			    vlTOPp->cpu__DOT__fetch_body__DOT__ir_mem
			    [(0xffffU & (vlTOPp->cpu__DOT__pc 
					 >> 2U))] : 0U);
    // ALWAYS at decoder.v:64
    if (((((((((0x13U == (0x7fU & vlTOPp->cpu__DOT__ir)) 
	       | (0x33U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	      | (0x37U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	     | (0x17U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	    | (0x6fU == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	   | (0x67U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	  | (0x63U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	 | (0x23U == (0x7fU & vlTOPp->cpu__DOT__ir)))) {
	if ((0x13U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
	    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 3U;
	    vlTOPp->cpu__DOT__alucode = ((0x4000U & vlTOPp->cpu__DOT__ir)
					  ? ((0x2000U 
					      & vlTOPp->cpu__DOT__ir)
					      ? ((0x1000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 0x17U
						  : 0x16U)
					      : ((0x1000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 
						 ((0x40000000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 0x1aU
						   : 0x19U)
						  : 0x15U))
					  : ((0x2000U 
					      & vlTOPp->cpu__DOT__ir)
					      ? ((0x1000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 0x14U
						  : 0x13U)
					      : ((0x1000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 0x18U
						  : 0x11U)));
	    vlTOPp->cpu__DOT__aluop1_type = 1U;
	    vlTOPp->cpu__DOT__aluop2_type = 2U;
	    vlTOPp->cpu__DOT__reg_we = 1U;
	    vlTOPp->cpu__DOT__is_load = 0U;
	    vlTOPp->cpu__DOT__is_store = 0U;
	} else {
	    if ((0x33U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
		vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 6U;
		vlTOPp->cpu__DOT__alucode = ((0x4000U 
					      & vlTOPp->cpu__DOT__ir)
					      ? ((0x2000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 
						 ((0x1000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 0x17U
						   : 0x16U)
						  : 
						 ((0x1000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 
						  ((0x40000000U 
						    & vlTOPp->cpu__DOT__ir)
						    ? 0x1aU
						    : 0x19U)
						   : 0x15U))
					      : ((0x2000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 
						 ((0x1000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 0x14U
						   : 0x13U)
						  : 
						 ((0x1000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 0x18U
						   : 
						  ((0x40000000U 
						    & vlTOPp->cpu__DOT__ir)
						    ? 0x12U
						    : 0x11U))));
		vlTOPp->cpu__DOT__aluop1_type = 1U;
		vlTOPp->cpu__DOT__aluop2_type = 1U;
		vlTOPp->cpu__DOT__reg_we = 1U;
		vlTOPp->cpu__DOT__is_load = 0U;
		vlTOPp->cpu__DOT__is_store = 0U;
	    } else {
		if ((0x37U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
		    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 1U;
		    vlTOPp->cpu__DOT__alucode = 0U;
		    vlTOPp->cpu__DOT__reg_we = 1U;
		    vlTOPp->cpu__DOT__aluop1_type = 0U;
		    vlTOPp->cpu__DOT__aluop2_type = 2U;
		    vlTOPp->cpu__DOT__is_load = 0U;
		    vlTOPp->cpu__DOT__is_store = 0U;
		} else {
		    if ((0x17U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
			vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 1U;
			vlTOPp->cpu__DOT__reg_we = 1U;
			vlTOPp->cpu__DOT__alucode = 0x11U;
			vlTOPp->cpu__DOT__aluop1_type = 2U;
			vlTOPp->cpu__DOT__aluop2_type = 3U;
			vlTOPp->cpu__DOT__is_load = 0U;
			vlTOPp->cpu__DOT__is_store = 0U;
		    } else {
			if ((0x6fU == (0x7fU & vlTOPp->cpu__DOT__ir))) {
			    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 2U;
			    vlTOPp->cpu__DOT__reg_we 
				= (0U == (0x1fU & (vlTOPp->cpu__DOT__ir 
						   >> 7U)));
			    vlTOPp->cpu__DOT__alucode = 1U;
			    vlTOPp->cpu__DOT__aluop1_type = 0U;
			    vlTOPp->cpu__DOT__aluop2_type = 3U;
			    vlTOPp->cpu__DOT__is_load = 0U;
			    vlTOPp->cpu__DOT__is_store = 0U;
			} else {
			    if ((0x67U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
				vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 3U;
				vlTOPp->cpu__DOT__reg_we 
				    = (0U == (0x1fU 
					      & (vlTOPp->cpu__DOT__ir 
						 >> 7U)));
				vlTOPp->cpu__DOT__alucode = 2U;
				vlTOPp->cpu__DOT__aluop1_type = 1U;
				vlTOPp->cpu__DOT__aluop2_type = 3U;
				vlTOPp->cpu__DOT__is_load = 0U;
				vlTOPp->cpu__DOT__is_store = 0U;
			    } else {
				if ((0x63U == (0x7fU 
					       & vlTOPp->cpu__DOT__ir))) {
				    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 4U;
				    vlTOPp->cpu__DOT__reg_we = 0U;
				    vlTOPp->cpu__DOT__aluop1_type = 1U;
				    vlTOPp->cpu__DOT__aluop2_type = 1U;
				    vlTOPp->cpu__DOT__is_load = 0U;
				    vlTOPp->cpu__DOT__is_store = 0U;
				    if ((0U == (7U 
						& (vlTOPp->cpu__DOT__ir 
						   >> 0xcU)))) {
					vlTOPp->cpu__DOT__alucode = 3U;
				    } else {
					if ((1U == 
					     (7U & 
					      (vlTOPp->cpu__DOT__ir 
					       >> 0xcU)))) {
					    vlTOPp->cpu__DOT__alucode = 4U;
					} else {
					    if ((4U 
						 == 
						 (7U 
						  & (vlTOPp->cpu__DOT__ir 
						     >> 0xcU)))) {
						vlTOPp->cpu__DOT__alucode = 5U;
					    } else {
						if (
						    (5U 
						     == 
						     (7U 
						      & (vlTOPp->cpu__DOT__ir 
							 >> 0xcU)))) {
						    vlTOPp->cpu__DOT__alucode = 6U;
						} else {
						    if (
							(6U 
							 == 
							 (7U 
							  & (vlTOPp->cpu__DOT__ir 
							     >> 0xcU)))) {
							vlTOPp->cpu__DOT__alucode = 7U;
						    } else {
							if (
							    (7U 
							     == 
							     (7U 
							      & (vlTOPp->cpu__DOT__ir 
								 >> 0xcU)))) {
							    vlTOPp->cpu__DOT__alucode = 8U;
							}
						    }
						}
					    }
					}
				    }
				} else {
				    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 5U;
				    vlTOPp->cpu__DOT__reg_we = 0U;
				    vlTOPp->cpu__DOT__aluop1_type = 1U;
				    vlTOPp->cpu__DOT__aluop2_type = 2U;
				    vlTOPp->cpu__DOT__is_load = 0U;
				    vlTOPp->cpu__DOT__is_store = 1U;
				    if ((0U == (7U 
						& (vlTOPp->cpu__DOT__ir 
						   >> 0xcU)))) {
					vlTOPp->cpu__DOT__alucode = 0xeU;
				    } else {
					if ((1U == 
					     (7U & 
					      (vlTOPp->cpu__DOT__ir 
					       >> 0xcU)))) {
					    vlTOPp->cpu__DOT__alucode = 0xfU;
					} else {
					    if ((2U 
						 == 
						 (7U 
						  & (vlTOPp->cpu__DOT__ir 
						     >> 0xcU)))) {
						vlTOPp->cpu__DOT__alucode = 0x10U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((3U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
	    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 3U;
	    vlTOPp->cpu__DOT__reg_we = 1U;
	    vlTOPp->cpu__DOT__aluop1_type = 1U;
	    vlTOPp->cpu__DOT__aluop2_type = 2U;
	    vlTOPp->cpu__DOT__is_load = 1U;
	    vlTOPp->cpu__DOT__is_store = 0U;
	    if ((0U == (7U & (vlTOPp->cpu__DOT__ir 
			      >> 0xcU)))) {
		vlTOPp->cpu__DOT__alucode = 9U;
	    } else {
		if ((1U == (7U & (vlTOPp->cpu__DOT__ir 
				  >> 0xcU)))) {
		    vlTOPp->cpu__DOT__alucode = 0xaU;
		} else {
		    if ((2U == (7U & (vlTOPp->cpu__DOT__ir 
				      >> 0xcU)))) {
			vlTOPp->cpu__DOT__alucode = 0xbU;
		    } else {
			if ((4U == (7U & (vlTOPp->cpu__DOT__ir 
					  >> 0xcU)))) {
			    vlTOPp->cpu__DOT__alucode = 0xcU;
			} else {
			    if ((5U == (7U & (vlTOPp->cpu__DOT__ir 
					      >> 0xcU)))) {
				vlTOPp->cpu__DOT__alucode = 0xdU;
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->cpu__DOT__dstreg_num = (0x1fU & ((1U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					      ? (0x1fU 
						 & (vlTOPp->cpu__DOT__ir 
						    >> 7U))
					      : ((2U 
						  == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						  ? 
						 (0x1fU 
						  & (vlTOPp->cpu__DOT__ir 
						     >> 7U))
						  : 
						 ((3U 
						   == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						   ? 
						  (0x1fU 
						   & (vlTOPp->cpu__DOT__ir 
						      >> 7U))
						   : 
						  ((4U 
						    == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						    ? 0U
						    : 
						   ((5U 
						     == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						     ? 0U
						     : 
						    ((6U 
						      == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						      ? 
						     (0x1fU 
						      & (vlTOPp->cpu__DOT__ir 
							 >> 7U))
						      : 0U)))))));
    vlTOPp->cpu__DOT__srcreg2_data = vlTOPp->cpu__DOT__register_file_body__DOT__register_file
	[(0x1fU & ((1U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
		    ? 0U : ((2U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
			     ? 0U : ((3U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				      ? 0U : ((4U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					       ? (0x1fU 
						  & (vlTOPp->cpu__DOT__ir 
						     >> 0x14U))
					       : ((5U 
						   == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						   ? 
						  (0x1fU 
						   & (vlTOPp->cpu__DOT__ir 
						      >> 0x14U))
						   : 
						  ((6U 
						    == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						    ? 
						   (0x1fU 
						    & (vlTOPp->cpu__DOT__ir 
						       >> 0x14U))
						    : 0U)))))))];
    vlTOPp->cpu__DOT__srcreg1_data = vlTOPp->cpu__DOT__register_file_body__DOT__register_file
	[(0x1fU & ((1U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
		    ? 0U : ((2U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
			     ? 0U : ((3U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				      ? (vlTOPp->cpu__DOT__ir 
					 >> 0xfU) : 
				     ((4U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				       ? (vlTOPp->cpu__DOT__ir 
					  >> 0xfU) : 
				      ((5U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				        ? (vlTOPp->cpu__DOT__ir 
					   >> 0xfU)
				        : ((6U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					    ? (vlTOPp->cpu__DOT__ir 
					       >> 0xfU)
					    : 0U)))))))];
    vlTOPp->cpu__DOT__imm = ((1U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
			      ? (0xfffff000U & vlTOPp->cpu__DOT__ir)
			      : ((2U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				  ? ((0xffe00000U & 
				      (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->cpu__DOT__ir 
							       >> 0x1fU)))) 
				       << 0x15U)) | 
				     ((0x100000U & 
				       (vlTOPp->cpu__DOT__ir 
					>> 0xbU)) | 
				      ((0xff000U & vlTOPp->cpu__DOT__ir) 
				       | ((0x800U & 
					   (vlTOPp->cpu__DOT__ir 
					    >> 9U)) 
					  | (0x7feU 
					     & (vlTOPp->cpu__DOT__ir 
						>> 0x14U))))))
				  : (((3U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type)) 
				      & (1U == (3U 
						& (vlTOPp->cpu__DOT__ir 
						   >> 0xcU))))
				      ? ((0xffffffe0U 
					  & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->cpu__DOT__ir 
								     >> 0x18U)))) 
					     << 5U)) 
					 | (0x1fU & 
					    (vlTOPp->cpu__DOT__ir 
					     >> 0x14U)))
				      : ((3U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					  ? ((0xfffff000U 
					      & (VL_NEGATE_I((IData)(
								     (1U 
								      & (vlTOPp->cpu__DOT__ir 
									 >> 0x1fU)))) 
						 << 0xcU)) 
					     | (0xfffU 
						& (vlTOPp->cpu__DOT__ir 
						   >> 0x14U)))
					  : ((4U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					      ? ((0xffffe000U 
						  & (VL_NEGATE_I((IData)(
									 (1U 
									  & (vlTOPp->cpu__DOT__ir 
									     >> 0x1fU)))) 
						     << 0xdU)) 
						 | ((0x1000U 
						     & (vlTOPp->cpu__DOT__ir 
							>> 0x13U)) 
						    | ((0x800U 
							& (vlTOPp->cpu__DOT__ir 
							   << 4U)) 
						       | ((0x7e0U 
							   & (vlTOPp->cpu__DOT__ir 
							      >> 0x14U)) 
							  | (0x1eU 
							     & (vlTOPp->cpu__DOT__ir 
								>> 7U))))))
					      : ((5U 
						  == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						  ? 
						 ((0xfffff000U 
						   & (VL_NEGATE_I((IData)(
									  (1U 
									   & (vlTOPp->cpu__DOT__ir 
									      >> 0x1fU)))) 
						      << 0xcU)) 
						  | ((0xfe0U 
						      & (vlTOPp->cpu__DOT__ir 
							 >> 0x14U)) 
						     | (0x1fU 
							& (vlTOPp->cpu__DOT__ir 
							   >> 7U))))
						  : 0U))))));
    // ALWAYS at execute.v:30
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__pc 
	= vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__imm 
	= vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__srcreg 
	= vlTOPp->cpu__DOT__srcreg1_data;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__aluop_type 
	= vlTOPp->cpu__DOT__aluop1_type;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__Vfuncout 
	= ((2U == (IData)(vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__aluop_type))
	    ? vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__imm
	    : ((3U == (IData)(vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__aluop_type))
	        ? vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__pc
	        : vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__srcreg));
    vlTOPp->cpu__DOT__execute_body__DOT__op1 = vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__Vfuncout;
    // ALWAYS at execute.v:31
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__pc 
	= vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__imm 
	= vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__srcreg 
	= vlTOPp->cpu__DOT__srcreg2_data;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__aluop_type 
	= vlTOPp->cpu__DOT__aluop2_type;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__Vfuncout 
	= ((2U == (IData)(vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__aluop_type))
	    ? vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__imm
	    : ((3U == (IData)(vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__aluop_type))
	        ? vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__pc
	        : vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__srcreg));
    vlTOPp->cpu__DOT__execute_body__DOT__op2 = vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__Vfuncout;
    // ALWAYS at alu.v:14
    if (((((((((0U == (IData)(vlTOPp->cpu__DOT__alucode)) 
	       | (1U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	      | (2U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	     | (3U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	    | (4U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	   | (5U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	  | (6U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	 | (7U == (IData)(vlTOPp->cpu__DOT__alucode)))) {
	if ((0U == (IData)(vlTOPp->cpu__DOT__alucode))) {
	    vlTOPp->cpu__DOT__alu_result = (0xfffff000U 
					    & vlTOPp->cpu__DOT__execute_body__DOT__op2);
	    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
	} else {
	    if ((1U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		vlTOPp->cpu__DOT__alu_result = ((IData)(4U) 
						+ vlTOPp->cpu__DOT__execute_body__DOT__op2);
		vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 1U;
	    } else {
		if ((2U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    vlTOPp->cpu__DOT__alu_result = 
			((IData)(4U) + vlTOPp->cpu__DOT__execute_body__DOT__op2);
		    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 1U;
		} else {
		    if ((3U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
			    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
			       == vlTOPp->cpu__DOT__execute_body__DOT__op2);
			vlTOPp->cpu__DOT__alu_result = 0U;
		    } else {
			if ((4U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			    vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
				= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
				   != vlTOPp->cpu__DOT__execute_body__DOT__op2);
			    vlTOPp->cpu__DOT__alu_result = 0U;
			} else {
			    if ((5U == (IData)(vlTOPp->cpu__DOT__alucode))) {
				vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
				    = VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__execute_body__DOT__op1, vlTOPp->cpu__DOT__execute_body__DOT__op2);
				vlTOPp->cpu__DOT__alu_result = 0U;
			    } else {
				if ((6U == (IData)(vlTOPp->cpu__DOT__alucode))) {
				    vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
					= VL_GTES_III(1,32,32, vlTOPp->cpu__DOT__execute_body__DOT__op1, vlTOPp->cpu__DOT__execute_body__DOT__op2);
				    vlTOPp->cpu__DOT__alu_result = 0U;
				} else {
				    vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
					= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					   < vlTOPp->cpu__DOT__execute_body__DOT__op2);
				    vlTOPp->cpu__DOT__alu_result = 0U;
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if (((((((((8U == (IData)(vlTOPp->cpu__DOT__alucode)) 
		   | (9U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		  | (0xaU == (IData)(vlTOPp->cpu__DOT__alucode))) 
		 | (0xbU == (IData)(vlTOPp->cpu__DOT__alucode))) 
		| (0xcU == (IData)(vlTOPp->cpu__DOT__alucode))) 
	       | (0xdU == (IData)(vlTOPp->cpu__DOT__alucode))) 
	      | (0xeU == (IData)(vlTOPp->cpu__DOT__alucode))) 
	     | (0xfU == (IData)(vlTOPp->cpu__DOT__alucode)))) {
	    if ((8U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
		    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
		       >= vlTOPp->cpu__DOT__execute_body__DOT__op2);
		vlTOPp->cpu__DOT__alu_result = 0U;
	    } else {
		if ((9U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    vlTOPp->cpu__DOT__alu_result = 
			(vlTOPp->cpu__DOT__execute_body__DOT__op1 
			 + vlTOPp->cpu__DOT__execute_body__DOT__op2);
		    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		} else {
		    if ((0xaU == (IData)(vlTOPp->cpu__DOT__alucode))) {
			vlTOPp->cpu__DOT__alu_result 
			    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
			       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
			vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		    } else {
			if ((0xbU == (IData)(vlTOPp->cpu__DOT__alucode))) {
			    vlTOPp->cpu__DOT__alu_result 
				= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
				   + vlTOPp->cpu__DOT__execute_body__DOT__op2);
			    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			} else {
			    if ((0xcU == (IData)(vlTOPp->cpu__DOT__alucode))) {
				vlTOPp->cpu__DOT__alu_result 
				    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
				       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
				vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			    } else {
				if ((0xdU == (IData)(vlTOPp->cpu__DOT__alucode))) {
				    vlTOPp->cpu__DOT__alu_result 
					= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					   + vlTOPp->cpu__DOT__execute_body__DOT__op2);
				    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				} else {
				    if ((0xeU == (IData)(vlTOPp->cpu__DOT__alucode))) {
					vlTOPp->cpu__DOT__alu_result 
					    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
					vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				    } else {
					vlTOPp->cpu__DOT__alu_result 
					    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
					vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				    }
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if (((((((((0x10U == (IData)(vlTOPp->cpu__DOT__alucode)) 
		       | (0x11U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		      | (0x12U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		     | (0x13U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		    | (0x14U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		   | (0x15U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		  | (0x16U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		 | (0x17U == (IData)(vlTOPp->cpu__DOT__alucode)))) {
		if ((0x10U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    vlTOPp->cpu__DOT__alu_result = 
			(vlTOPp->cpu__DOT__execute_body__DOT__op1 
			 + vlTOPp->cpu__DOT__execute_body__DOT__op2);
		    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		} else {
		    if ((0x11U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			vlTOPp->cpu__DOT__alu_result 
			    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
			       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
			vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		    } else {
			if ((0x12U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			    vlTOPp->cpu__DOT__alu_result 
				= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
				   - vlTOPp->cpu__DOT__execute_body__DOT__op2);
			    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			} else {
			    if ((0x13U == (IData)(vlTOPp->cpu__DOT__alucode))) {
				vlTOPp->cpu__DOT__alu_result 
				    = VL_LTS_III(32,32,32, vlTOPp->cpu__DOT__execute_body__DOT__op1, vlTOPp->cpu__DOT__execute_body__DOT__op2);
				vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			    } else {
				if ((0x14U == (IData)(vlTOPp->cpu__DOT__alucode))) {
				    vlTOPp->cpu__DOT__alu_result 
					= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					   < vlTOPp->cpu__DOT__execute_body__DOT__op2);
				    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				} else {
				    if ((0x15U == (IData)(vlTOPp->cpu__DOT__alucode))) {
					vlTOPp->cpu__DOT__alu_result 
					    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					       ^ vlTOPp->cpu__DOT__execute_body__DOT__op2);
					vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				    } else {
					if ((0x16U 
					     == (IData)(vlTOPp->cpu__DOT__alucode))) {
					    vlTOPp->cpu__DOT__alu_result 
						= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
						   | vlTOPp->cpu__DOT__execute_body__DOT__op2);
					    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
					} else {
					    vlTOPp->cpu__DOT__alu_result 
						= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
						   & vlTOPp->cpu__DOT__execute_body__DOT__op2);
					    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x18U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    vlTOPp->cpu__DOT__alu_result = 
			(vlTOPp->cpu__DOT__execute_body__DOT__op1 
			 << (0x1fU & vlTOPp->cpu__DOT__execute_body__DOT__op2));
		    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		} else {
		    if ((0x19U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			vlTOPp->cpu__DOT__alu_result 
			    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
			       >> (0x1fU & vlTOPp->cpu__DOT__execute_body__DOT__op2));
			vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		    } else {
			if ((0x1aU == (IData)(vlTOPp->cpu__DOT__alucode))) {
			    vlTOPp->cpu__DOT__alu_result 
				= VL_SHIFTRS_III(32,32,5, vlTOPp->cpu__DOT__execute_body__DOT__op1, 
						 (0x1fU 
						  & vlTOPp->cpu__DOT__execute_body__DOT__op2));
			    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			}
		    }
		}
	    }
	}
    }
    vlTOPp->cpu__DOT__nextpc = ((2U == (IData)(vlTOPp->cpu__DOT__alucode))
				 ? (vlTOPp->cpu__DOT__srcreg1_data 
				    + vlTOPp->cpu__DOT__imm)
				 : ((IData)(vlTOPp->cpu__DOT__execute_body__DOT__br_taken)
				     ? (vlTOPp->cpu__DOT__pc 
					+ vlTOPp->cpu__DOT__imm)
				     : ((IData)(4U) 
					+ vlTOPp->cpu__DOT__pc)));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__5(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__5\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at decoder.v:64
    if (((((((((0x13U == (0x7fU & vlTOPp->cpu__DOT__ir)) 
	       | (0x33U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	      | (0x37U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	     | (0x17U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	    | (0x6fU == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	   | (0x67U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	  | (0x63U == (0x7fU & vlTOPp->cpu__DOT__ir))) 
	 | (0x23U == (0x7fU & vlTOPp->cpu__DOT__ir)))) {
	if ((0x13U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
	    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 3U;
	    vlTOPp->cpu__DOT__alucode = ((0x4000U & vlTOPp->cpu__DOT__ir)
					  ? ((0x2000U 
					      & vlTOPp->cpu__DOT__ir)
					      ? ((0x1000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 0x17U
						  : 0x16U)
					      : ((0x1000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 
						 ((0x40000000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 0x1aU
						   : 0x19U)
						  : 0x15U))
					  : ((0x2000U 
					      & vlTOPp->cpu__DOT__ir)
					      ? ((0x1000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 0x14U
						  : 0x13U)
					      : ((0x1000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 0x18U
						  : 0x11U)));
	    vlTOPp->cpu__DOT__aluop1_type = 1U;
	    vlTOPp->cpu__DOT__aluop2_type = 2U;
	    vlTOPp->cpu__DOT__reg_we = 1U;
	    vlTOPp->cpu__DOT__is_load = 0U;
	    vlTOPp->cpu__DOT__is_store = 0U;
	} else {
	    if ((0x33U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
		vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 6U;
		vlTOPp->cpu__DOT__alucode = ((0x4000U 
					      & vlTOPp->cpu__DOT__ir)
					      ? ((0x2000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 
						 ((0x1000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 0x17U
						   : 0x16U)
						  : 
						 ((0x1000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 
						  ((0x40000000U 
						    & vlTOPp->cpu__DOT__ir)
						    ? 0x1aU
						    : 0x19U)
						   : 0x15U))
					      : ((0x2000U 
						  & vlTOPp->cpu__DOT__ir)
						  ? 
						 ((0x1000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 0x14U
						   : 0x13U)
						  : 
						 ((0x1000U 
						   & vlTOPp->cpu__DOT__ir)
						   ? 0x18U
						   : 
						  ((0x40000000U 
						    & vlTOPp->cpu__DOT__ir)
						    ? 0x12U
						    : 0x11U))));
		vlTOPp->cpu__DOT__aluop1_type = 1U;
		vlTOPp->cpu__DOT__aluop2_type = 1U;
		vlTOPp->cpu__DOT__reg_we = 1U;
		vlTOPp->cpu__DOT__is_load = 0U;
		vlTOPp->cpu__DOT__is_store = 0U;
	    } else {
		if ((0x37U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
		    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 1U;
		    vlTOPp->cpu__DOT__alucode = 0U;
		    vlTOPp->cpu__DOT__reg_we = 1U;
		    vlTOPp->cpu__DOT__aluop1_type = 0U;
		    vlTOPp->cpu__DOT__aluop2_type = 2U;
		    vlTOPp->cpu__DOT__is_load = 0U;
		    vlTOPp->cpu__DOT__is_store = 0U;
		} else {
		    if ((0x17U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
			vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 1U;
			vlTOPp->cpu__DOT__reg_we = 1U;
			vlTOPp->cpu__DOT__alucode = 0x11U;
			vlTOPp->cpu__DOT__aluop1_type = 2U;
			vlTOPp->cpu__DOT__aluop2_type = 3U;
			vlTOPp->cpu__DOT__is_load = 0U;
			vlTOPp->cpu__DOT__is_store = 0U;
		    } else {
			if ((0x6fU == (0x7fU & vlTOPp->cpu__DOT__ir))) {
			    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 2U;
			    vlTOPp->cpu__DOT__reg_we 
				= (0U == (0x1fU & (vlTOPp->cpu__DOT__ir 
						   >> 7U)));
			    vlTOPp->cpu__DOT__alucode = 1U;
			    vlTOPp->cpu__DOT__aluop1_type = 0U;
			    vlTOPp->cpu__DOT__aluop2_type = 3U;
			    vlTOPp->cpu__DOT__is_load = 0U;
			    vlTOPp->cpu__DOT__is_store = 0U;
			} else {
			    if ((0x67U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
				vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 3U;
				vlTOPp->cpu__DOT__reg_we 
				    = (0U == (0x1fU 
					      & (vlTOPp->cpu__DOT__ir 
						 >> 7U)));
				vlTOPp->cpu__DOT__alucode = 2U;
				vlTOPp->cpu__DOT__aluop1_type = 1U;
				vlTOPp->cpu__DOT__aluop2_type = 3U;
				vlTOPp->cpu__DOT__is_load = 0U;
				vlTOPp->cpu__DOT__is_store = 0U;
			    } else {
				if ((0x63U == (0x7fU 
					       & vlTOPp->cpu__DOT__ir))) {
				    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 4U;
				    vlTOPp->cpu__DOT__reg_we = 0U;
				    vlTOPp->cpu__DOT__aluop1_type = 1U;
				    vlTOPp->cpu__DOT__aluop2_type = 1U;
				    vlTOPp->cpu__DOT__is_load = 0U;
				    vlTOPp->cpu__DOT__is_store = 0U;
				    if ((0U == (7U 
						& (vlTOPp->cpu__DOT__ir 
						   >> 0xcU)))) {
					vlTOPp->cpu__DOT__alucode = 3U;
				    } else {
					if ((1U == 
					     (7U & 
					      (vlTOPp->cpu__DOT__ir 
					       >> 0xcU)))) {
					    vlTOPp->cpu__DOT__alucode = 4U;
					} else {
					    if ((4U 
						 == 
						 (7U 
						  & (vlTOPp->cpu__DOT__ir 
						     >> 0xcU)))) {
						vlTOPp->cpu__DOT__alucode = 5U;
					    } else {
						if (
						    (5U 
						     == 
						     (7U 
						      & (vlTOPp->cpu__DOT__ir 
							 >> 0xcU)))) {
						    vlTOPp->cpu__DOT__alucode = 6U;
						} else {
						    if (
							(6U 
							 == 
							 (7U 
							  & (vlTOPp->cpu__DOT__ir 
							     >> 0xcU)))) {
							vlTOPp->cpu__DOT__alucode = 7U;
						    } else {
							if (
							    (7U 
							     == 
							     (7U 
							      & (vlTOPp->cpu__DOT__ir 
								 >> 0xcU)))) {
							    vlTOPp->cpu__DOT__alucode = 8U;
							}
						    }
						}
					    }
					}
				    }
				} else {
				    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 5U;
				    vlTOPp->cpu__DOT__reg_we = 0U;
				    vlTOPp->cpu__DOT__aluop1_type = 1U;
				    vlTOPp->cpu__DOT__aluop2_type = 2U;
				    vlTOPp->cpu__DOT__is_load = 0U;
				    vlTOPp->cpu__DOT__is_store = 1U;
				    if ((0U == (7U 
						& (vlTOPp->cpu__DOT__ir 
						   >> 0xcU)))) {
					vlTOPp->cpu__DOT__alucode = 0xeU;
				    } else {
					if ((1U == 
					     (7U & 
					      (vlTOPp->cpu__DOT__ir 
					       >> 0xcU)))) {
					    vlTOPp->cpu__DOT__alucode = 0xfU;
					} else {
					    if ((2U 
						 == 
						 (7U 
						  & (vlTOPp->cpu__DOT__ir 
						     >> 0xcU)))) {
						vlTOPp->cpu__DOT__alucode = 0x10U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((3U == (0x7fU & vlTOPp->cpu__DOT__ir))) {
	    vlTOPp->cpu__DOT__decoder_body__DOT__op_type = 3U;
	    vlTOPp->cpu__DOT__reg_we = 1U;
	    vlTOPp->cpu__DOT__aluop1_type = 1U;
	    vlTOPp->cpu__DOT__aluop2_type = 2U;
	    vlTOPp->cpu__DOT__is_load = 1U;
	    vlTOPp->cpu__DOT__is_store = 0U;
	    if ((0U == (7U & (vlTOPp->cpu__DOT__ir 
			      >> 0xcU)))) {
		vlTOPp->cpu__DOT__alucode = 9U;
	    } else {
		if ((1U == (7U & (vlTOPp->cpu__DOT__ir 
				  >> 0xcU)))) {
		    vlTOPp->cpu__DOT__alucode = 0xaU;
		} else {
		    if ((2U == (7U & (vlTOPp->cpu__DOT__ir 
				      >> 0xcU)))) {
			vlTOPp->cpu__DOT__alucode = 0xbU;
		    } else {
			if ((4U == (7U & (vlTOPp->cpu__DOT__ir 
					  >> 0xcU)))) {
			    vlTOPp->cpu__DOT__alucode = 0xcU;
			} else {
			    if ((5U == (7U & (vlTOPp->cpu__DOT__ir 
					      >> 0xcU)))) {
				vlTOPp->cpu__DOT__alucode = 0xdU;
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->cpu__DOT__dstreg_num = (0x1fU & ((1U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					      ? (0x1fU 
						 & (vlTOPp->cpu__DOT__ir 
						    >> 7U))
					      : ((2U 
						  == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						  ? 
						 (0x1fU 
						  & (vlTOPp->cpu__DOT__ir 
						     >> 7U))
						  : 
						 ((3U 
						   == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						   ? 
						  (0x1fU 
						   & (vlTOPp->cpu__DOT__ir 
						      >> 7U))
						   : 
						  ((4U 
						    == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						    ? 0U
						    : 
						   ((5U 
						     == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						     ? 0U
						     : 
						    ((6U 
						      == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						      ? 
						     (0x1fU 
						      & (vlTOPp->cpu__DOT__ir 
							 >> 7U))
						      : 0U)))))));
    vlTOPp->cpu__DOT__srcreg2_data = vlTOPp->cpu__DOT__register_file_body__DOT__register_file
	[(0x1fU & ((1U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
		    ? 0U : ((2U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
			     ? 0U : ((3U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				      ? 0U : ((4U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					       ? (0x1fU 
						  & (vlTOPp->cpu__DOT__ir 
						     >> 0x14U))
					       : ((5U 
						   == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						   ? 
						  (0x1fU 
						   & (vlTOPp->cpu__DOT__ir 
						      >> 0x14U))
						   : 
						  ((6U 
						    == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						    ? 
						   (0x1fU 
						    & (vlTOPp->cpu__DOT__ir 
						       >> 0x14U))
						    : 0U)))))))];
    vlTOPp->cpu__DOT__srcreg1_data = vlTOPp->cpu__DOT__register_file_body__DOT__register_file
	[(0x1fU & ((1U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
		    ? 0U : ((2U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
			     ? 0U : ((3U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				      ? (vlTOPp->cpu__DOT__ir 
					 >> 0xfU) : 
				     ((4U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				       ? (vlTOPp->cpu__DOT__ir 
					  >> 0xfU) : 
				      ((5U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				        ? (vlTOPp->cpu__DOT__ir 
					   >> 0xfU)
				        : ((6U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					    ? (vlTOPp->cpu__DOT__ir 
					       >> 0xfU)
					    : 0U)))))))];
    vlTOPp->cpu__DOT__imm = ((1U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
			      ? (0xfffff000U & vlTOPp->cpu__DOT__ir)
			      : ((2U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
				  ? ((0xffe00000U & 
				      (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->cpu__DOT__ir 
							       >> 0x1fU)))) 
				       << 0x15U)) | 
				     ((0x100000U & 
				       (vlTOPp->cpu__DOT__ir 
					>> 0xbU)) | 
				      ((0xff000U & vlTOPp->cpu__DOT__ir) 
				       | ((0x800U & 
					   (vlTOPp->cpu__DOT__ir 
					    >> 9U)) 
					  | (0x7feU 
					     & (vlTOPp->cpu__DOT__ir 
						>> 0x14U))))))
				  : (((3U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type)) 
				      & (1U == (3U 
						& (vlTOPp->cpu__DOT__ir 
						   >> 0xcU))))
				      ? ((0xffffffe0U 
					  & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->cpu__DOT__ir 
								     >> 0x18U)))) 
					     << 5U)) 
					 | (0x1fU & 
					    (vlTOPp->cpu__DOT__ir 
					     >> 0x14U)))
				      : ((3U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					  ? ((0xfffff000U 
					      & (VL_NEGATE_I((IData)(
								     (1U 
								      & (vlTOPp->cpu__DOT__ir 
									 >> 0x1fU)))) 
						 << 0xcU)) 
					     | (0xfffU 
						& (vlTOPp->cpu__DOT__ir 
						   >> 0x14U)))
					  : ((4U == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
					      ? ((0xffffe000U 
						  & (VL_NEGATE_I((IData)(
									 (1U 
									  & (vlTOPp->cpu__DOT__ir 
									     >> 0x1fU)))) 
						     << 0xdU)) 
						 | ((0x1000U 
						     & (vlTOPp->cpu__DOT__ir 
							>> 0x13U)) 
						    | ((0x800U 
							& (vlTOPp->cpu__DOT__ir 
							   << 4U)) 
						       | ((0x7e0U 
							   & (vlTOPp->cpu__DOT__ir 
							      >> 0x14U)) 
							  | (0x1eU 
							     & (vlTOPp->cpu__DOT__ir 
								>> 7U))))))
					      : ((5U 
						  == (IData)(vlTOPp->cpu__DOT__decoder_body__DOT__op_type))
						  ? 
						 ((0xfffff000U 
						   & (VL_NEGATE_I((IData)(
									  (1U 
									   & (vlTOPp->cpu__DOT__ir 
									      >> 0x1fU)))) 
						      << 0xcU)) 
						  | ((0xfe0U 
						      & (vlTOPp->cpu__DOT__ir 
							 >> 0x14U)) 
						     | (0x1fU 
							& (vlTOPp->cpu__DOT__ir 
							   >> 7U))))
						  : 0U))))));
    // ALWAYS at execute.v:30
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__pc 
	= vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__imm 
	= vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__srcreg 
	= vlTOPp->cpu__DOT__srcreg1_data;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__aluop_type 
	= vlTOPp->cpu__DOT__aluop1_type;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__Vfuncout 
	= ((2U == (IData)(vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__aluop_type))
	    ? vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__imm
	    : ((3U == (IData)(vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__aluop_type))
	        ? vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__pc
	        : vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__srcreg));
    vlTOPp->cpu__DOT__execute_body__DOT__op1 = vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__0__Vfuncout;
    // ALWAYS at execute.v:31
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__pc 
	= vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__imm 
	= vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__srcreg 
	= vlTOPp->cpu__DOT__srcreg2_data;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__aluop_type 
	= vlTOPp->cpu__DOT__aluop2_type;
    vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__Vfuncout 
	= ((2U == (IData)(vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__aluop_type))
	    ? vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__imm
	    : ((3U == (IData)(vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__aluop_type))
	        ? vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__pc
	        : vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__srcreg));
    vlTOPp->cpu__DOT__execute_body__DOT__op2 = vlTOPp->__Vfunc_cpu__DOT__execute_body__DOT__op__1__Vfuncout;
    // ALWAYS at alu.v:14
    if (((((((((0U == (IData)(vlTOPp->cpu__DOT__alucode)) 
	       | (1U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	      | (2U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	     | (3U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	    | (4U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	   | (5U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	  | (6U == (IData)(vlTOPp->cpu__DOT__alucode))) 
	 | (7U == (IData)(vlTOPp->cpu__DOT__alucode)))) {
	if ((0U == (IData)(vlTOPp->cpu__DOT__alucode))) {
	    vlTOPp->cpu__DOT__alu_result = (0xfffff000U 
					    & vlTOPp->cpu__DOT__execute_body__DOT__op2);
	    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
	} else {
	    if ((1U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		vlTOPp->cpu__DOT__alu_result = ((IData)(4U) 
						+ vlTOPp->cpu__DOT__execute_body__DOT__op2);
		vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 1U;
	    } else {
		if ((2U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    vlTOPp->cpu__DOT__alu_result = 
			((IData)(4U) + vlTOPp->cpu__DOT__execute_body__DOT__op2);
		    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 1U;
		} else {
		    if ((3U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
			    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
			       == vlTOPp->cpu__DOT__execute_body__DOT__op2);
			vlTOPp->cpu__DOT__alu_result = 0U;
		    } else {
			if ((4U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			    vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
				= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
				   != vlTOPp->cpu__DOT__execute_body__DOT__op2);
			    vlTOPp->cpu__DOT__alu_result = 0U;
			} else {
			    if ((5U == (IData)(vlTOPp->cpu__DOT__alucode))) {
				vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
				    = VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__execute_body__DOT__op1, vlTOPp->cpu__DOT__execute_body__DOT__op2);
				vlTOPp->cpu__DOT__alu_result = 0U;
			    } else {
				if ((6U == (IData)(vlTOPp->cpu__DOT__alucode))) {
				    vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
					= VL_GTES_III(1,32,32, vlTOPp->cpu__DOT__execute_body__DOT__op1, vlTOPp->cpu__DOT__execute_body__DOT__op2);
				    vlTOPp->cpu__DOT__alu_result = 0U;
				} else {
				    vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
					= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					   < vlTOPp->cpu__DOT__execute_body__DOT__op2);
				    vlTOPp->cpu__DOT__alu_result = 0U;
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if (((((((((8U == (IData)(vlTOPp->cpu__DOT__alucode)) 
		   | (9U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		  | (0xaU == (IData)(vlTOPp->cpu__DOT__alucode))) 
		 | (0xbU == (IData)(vlTOPp->cpu__DOT__alucode))) 
		| (0xcU == (IData)(vlTOPp->cpu__DOT__alucode))) 
	       | (0xdU == (IData)(vlTOPp->cpu__DOT__alucode))) 
	      | (0xeU == (IData)(vlTOPp->cpu__DOT__alucode))) 
	     | (0xfU == (IData)(vlTOPp->cpu__DOT__alucode)))) {
	    if ((8U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		vlTOPp->cpu__DOT__execute_body__DOT__br_taken 
		    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
		       >= vlTOPp->cpu__DOT__execute_body__DOT__op2);
		vlTOPp->cpu__DOT__alu_result = 0U;
	    } else {
		if ((9U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    vlTOPp->cpu__DOT__alu_result = 
			(vlTOPp->cpu__DOT__execute_body__DOT__op1 
			 + vlTOPp->cpu__DOT__execute_body__DOT__op2);
		    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		} else {
		    if ((0xaU == (IData)(vlTOPp->cpu__DOT__alucode))) {
			vlTOPp->cpu__DOT__alu_result 
			    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
			       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
			vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		    } else {
			if ((0xbU == (IData)(vlTOPp->cpu__DOT__alucode))) {
			    vlTOPp->cpu__DOT__alu_result 
				= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
				   + vlTOPp->cpu__DOT__execute_body__DOT__op2);
			    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			} else {
			    if ((0xcU == (IData)(vlTOPp->cpu__DOT__alucode))) {
				vlTOPp->cpu__DOT__alu_result 
				    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
				       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
				vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			    } else {
				if ((0xdU == (IData)(vlTOPp->cpu__DOT__alucode))) {
				    vlTOPp->cpu__DOT__alu_result 
					= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					   + vlTOPp->cpu__DOT__execute_body__DOT__op2);
				    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				} else {
				    if ((0xeU == (IData)(vlTOPp->cpu__DOT__alucode))) {
					vlTOPp->cpu__DOT__alu_result 
					    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
					vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				    } else {
					vlTOPp->cpu__DOT__alu_result 
					    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
					vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				    }
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if (((((((((0x10U == (IData)(vlTOPp->cpu__DOT__alucode)) 
		       | (0x11U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		      | (0x12U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		     | (0x13U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		    | (0x14U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		   | (0x15U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		  | (0x16U == (IData)(vlTOPp->cpu__DOT__alucode))) 
		 | (0x17U == (IData)(vlTOPp->cpu__DOT__alucode)))) {
		if ((0x10U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    vlTOPp->cpu__DOT__alu_result = 
			(vlTOPp->cpu__DOT__execute_body__DOT__op1 
			 + vlTOPp->cpu__DOT__execute_body__DOT__op2);
		    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		} else {
		    if ((0x11U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			vlTOPp->cpu__DOT__alu_result 
			    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
			       + vlTOPp->cpu__DOT__execute_body__DOT__op2);
			vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		    } else {
			if ((0x12U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			    vlTOPp->cpu__DOT__alu_result 
				= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
				   - vlTOPp->cpu__DOT__execute_body__DOT__op2);
			    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			} else {
			    if ((0x13U == (IData)(vlTOPp->cpu__DOT__alucode))) {
				vlTOPp->cpu__DOT__alu_result 
				    = VL_LTS_III(32,32,32, vlTOPp->cpu__DOT__execute_body__DOT__op1, vlTOPp->cpu__DOT__execute_body__DOT__op2);
				vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			    } else {
				if ((0x14U == (IData)(vlTOPp->cpu__DOT__alucode))) {
				    vlTOPp->cpu__DOT__alu_result 
					= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					   < vlTOPp->cpu__DOT__execute_body__DOT__op2);
				    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				} else {
				    if ((0x15U == (IData)(vlTOPp->cpu__DOT__alucode))) {
					vlTOPp->cpu__DOT__alu_result 
					    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
					       ^ vlTOPp->cpu__DOT__execute_body__DOT__op2);
					vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
				    } else {
					if ((0x16U 
					     == (IData)(vlTOPp->cpu__DOT__alucode))) {
					    vlTOPp->cpu__DOT__alu_result 
						= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
						   | vlTOPp->cpu__DOT__execute_body__DOT__op2);
					    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
					} else {
					    vlTOPp->cpu__DOT__alu_result 
						= (vlTOPp->cpu__DOT__execute_body__DOT__op1 
						   & vlTOPp->cpu__DOT__execute_body__DOT__op2);
					    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x18U == (IData)(vlTOPp->cpu__DOT__alucode))) {
		    vlTOPp->cpu__DOT__alu_result = 
			(vlTOPp->cpu__DOT__execute_body__DOT__op1 
			 << (0x1fU & vlTOPp->cpu__DOT__execute_body__DOT__op2));
		    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		} else {
		    if ((0x19U == (IData)(vlTOPp->cpu__DOT__alucode))) {
			vlTOPp->cpu__DOT__alu_result 
			    = (vlTOPp->cpu__DOT__execute_body__DOT__op1 
			       >> (0x1fU & vlTOPp->cpu__DOT__execute_body__DOT__op2));
			vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
		    } else {
			if ((0x1aU == (IData)(vlTOPp->cpu__DOT__alucode))) {
			    vlTOPp->cpu__DOT__alu_result 
				= VL_SHIFTRS_III(32,32,5, vlTOPp->cpu__DOT__execute_body__DOT__op1, 
						 (0x1fU 
						  & vlTOPp->cpu__DOT__execute_body__DOT__op2));
			    vlTOPp->cpu__DOT__execute_body__DOT__br_taken = 0U;
			}
		    }
		}
	    }
	}
    }
    vlTOPp->cpu__DOT__nextpc = ((2U == (IData)(vlTOPp->cpu__DOT__alucode))
				 ? (vlTOPp->cpu__DOT__srcreg1_data 
				    + vlTOPp->cpu__DOT__imm)
				 : ((IData)(vlTOPp->cpu__DOT__execute_body__DOT__br_taken)
				     ? (vlTOPp->cpu__DOT__pc 
					+ vlTOPp->cpu__DOT__imm)
				     : ((IData)(4U) 
					+ vlTOPp->cpu__DOT__pc)));
}

void Vcpu::_initial__TOP__6(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_initial__TOP__6\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at cpu.v:143
    VL_WRITEF("pc=%10#, ir=%b, reg1=%10#, reg2=%10#, uart=%1#\n\n",
	      32,vlTOPp->cpu__DOT__pc,32,vlTOPp->cpu__DOT__ir,
	      32,vlTOPp->cpu__DOT__srcreg1_data,32,
	      vlTOPp->cpu__DOT__srcreg2_data,1,(IData)(vlTOPp->uart_tx));
}

void Vcpu::_eval(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((~ (IData)(vlTOPp->cpu_resetn)) & (IData)(vlTOPp->__Vclklast__TOP__cpu_resetn)) 
	 | ((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk))))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->cpu_resetn)) & (IData)(vlTOPp->__Vclklast__TOP__cpu_resetn)) 
	 | ((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk))))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__cpu_resetn = vlTOPp->cpu_resetn;
    vlTOPp->__Vclklast__TOP__sysclk = vlTOPp->sysclk;
}

void Vcpu::_eval_initial(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_initial\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->_initial__TOP__6(vlSymsp);
}

void Vcpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::final\n"); );
    // Variables
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcpu::_eval_settle(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_settle\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData Vcpu::_change_request(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_change_request\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sysclk & 0xfeU))) {
	Verilated::overWidthError("sysclk");}
    if (VL_UNLIKELY((cpu_resetn & 0xfeU))) {
	Verilated::overWidthError("cpu_resetn");}
}
#endif // VL_DEBUG

void Vcpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_ctor_var_reset\n"); );
    // Body
    sysclk = VL_RAND_RESET_I(1);
    cpu_resetn = VL_RAND_RESET_I(1);
    uart_tx = VL_RAND_RESET_I(1);
    cpu__DOT__pc = VL_RAND_RESET_I(32);
    cpu__DOT__ir = VL_RAND_RESET_I(32);
    cpu__DOT__dstreg_num = VL_RAND_RESET_I(5);
    cpu__DOT__imm = VL_RAND_RESET_I(32);
    cpu__DOT__alucode = VL_RAND_RESET_I(6);
    cpu__DOT__aluop1_type = VL_RAND_RESET_I(2);
    cpu__DOT__aluop2_type = VL_RAND_RESET_I(2);
    cpu__DOT__reg_we = VL_RAND_RESET_I(1);
    cpu__DOT__is_load = VL_RAND_RESET_I(1);
    cpu__DOT__is_store = VL_RAND_RESET_I(1);
    cpu__DOT__srcreg1_data = VL_RAND_RESET_I(32);
    cpu__DOT__srcreg2_data = VL_RAND_RESET_I(32);
    cpu__DOT__nextpc = VL_RAND_RESET_I(32);
    cpu__DOT__alu_result = VL_RAND_RESET_I(32);
    cpu__DOT__uart_OUT_data = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32769; ++__Vi0) {
	    cpu__DOT__fetch_body__DOT__ir_mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu__DOT__decoder_body__DOT__op_type = VL_RAND_RESET_I(3);
    cpu__DOT__execute_body__DOT__op1 = VL_RAND_RESET_I(32);
    cpu__DOT__execute_body__DOT__op2 = VL_RAND_RESET_I(32);
    cpu__DOT__execute_body__DOT__br_taken = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32768; ++__Vi0) {
	    cpu__DOT__data_mem_body__DOT__ram[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    cpu__DOT__register_file_body__DOT__register_file[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
    cpu__DOT__uart0__DOT__bitcount = VL_RAND_RESET_I(4);
    cpu__DOT__uart0__DOT__shifter = VL_RAND_RESET_I(9);
    cpu__DOT__uart0__DOT__uart_busy = VL_RAND_RESET_I(1);
    cpu__DOT__uart0__DOT__sending = VL_RAND_RESET_I(1);
    cpu__DOT__uart0__DOT__d = VL_RAND_RESET_I(29);
    cpu__DOT__uart0__DOT__dNxt = VL_RAND_RESET_I(29);
    __Vfunc_cpu__DOT__execute_body__DOT__op__0__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__execute_body__DOT__op__0__aluop_type = VL_RAND_RESET_I(2);
    __Vfunc_cpu__DOT__execute_body__DOT__op__0__srcreg = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__execute_body__DOT__op__0__imm = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__execute_body__DOT__op__0__pc = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__execute_body__DOT__op__1__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__execute_body__DOT__op__1__aluop_type = VL_RAND_RESET_I(2);
    __Vfunc_cpu__DOT__execute_body__DOT__op__1__srcreg = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__execute_body__DOT__op__1__imm = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__execute_body__DOT__op__1__pc = VL_RAND_RESET_I(32);
    __Vclklast__TOP__cpu_resetn = VL_RAND_RESET_I(1);
    __Vclklast__TOP__sysclk = VL_RAND_RESET_I(1);
}
