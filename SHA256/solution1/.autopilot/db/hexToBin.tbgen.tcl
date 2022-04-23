set moduleName hexToBin
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {hexToBin}
set C_modelType { void 0 }
set C_modelArgList {
	{ string_r int 8 regular {array 11 { 1 } 1 1 }  }
	{ bits int 7 regular {array 12 { 2 3 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "string_r", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "bits", "interface" : "memory", "bitwidth" : 7, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 14
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ string_r_address0 sc_out sc_lv 4 signal 0 } 
	{ string_r_ce0 sc_out sc_logic 1 signal 0 } 
	{ string_r_q0 sc_in sc_lv 8 signal 0 } 
	{ bits_address0 sc_out sc_lv 4 signal 1 } 
	{ bits_ce0 sc_out sc_logic 1 signal 1 } 
	{ bits_we0 sc_out sc_logic 1 signal 1 } 
	{ bits_d0 sc_out sc_lv 7 signal 1 } 
	{ bits_q0 sc_in sc_lv 7 signal 1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "string_r_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "string_r", "role": "address0" }} , 
 	{ "name": "string_r_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "string_r", "role": "ce0" }} , 
 	{ "name": "string_r_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "string_r", "role": "q0" }} , 
 	{ "name": "bits_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "bits", "role": "address0" }} , 
 	{ "name": "bits_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bits", "role": "ce0" }} , 
 	{ "name": "bits_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bits", "role": "we0" }} , 
 	{ "name": "bits_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "bits", "role": "d0" }} , 
 	{ "name": "bits_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "bits", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17"],
		"CDFG" : "hexToBin",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "string_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "bits", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "p_str_25", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_24", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_23", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_22", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_21", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_20", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_19", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_18", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_17", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_16", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_15", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_14", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_13", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_12", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_11", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_10", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_str_9", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_25_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_24_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_23_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_22_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_21_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_20_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_19_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_18_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_17_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_16_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_15_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_14_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_13_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_12_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_11_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_10_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.p_str_9_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	hexToBin {
		string_r {Type I LastRead 1 FirstWrite -1}
		bits {Type IO LastRead 3 FirstWrite 8}
		p_str_25 {Type I LastRead -1 FirstWrite -1}
		p_str_24 {Type I LastRead -1 FirstWrite -1}
		p_str_23 {Type I LastRead -1 FirstWrite -1}
		p_str_22 {Type I LastRead -1 FirstWrite -1}
		p_str_21 {Type I LastRead -1 FirstWrite -1}
		p_str_20 {Type I LastRead -1 FirstWrite -1}
		p_str_19 {Type I LastRead -1 FirstWrite -1}
		p_str_18 {Type I LastRead -1 FirstWrite -1}
		p_str_17 {Type I LastRead -1 FirstWrite -1}
		p_str_16 {Type I LastRead -1 FirstWrite -1}
		p_str_15 {Type I LastRead -1 FirstWrite -1}
		p_str_14 {Type I LastRead -1 FirstWrite -1}
		p_str_13 {Type I LastRead -1 FirstWrite -1}
		p_str_12 {Type I LastRead -1 FirstWrite -1}
		p_str_11 {Type I LastRead -1 FirstWrite -1}
		p_str_10 {Type I LastRead -1 FirstWrite -1}
		p_str_9 {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
]}

set Spec2ImplPortList { 
	string_r { ap_memory {  { string_r_address0 mem_address 1 4 }  { string_r_ce0 mem_ce 1 1 }  { string_r_q0 mem_dout 0 8 } } }
	bits { ap_memory {  { bits_address0 mem_address 1 4 }  { bits_ce0 mem_ce 1 1 }  { bits_we0 mem_we 1 1 }  { bits_d0 mem_din 1 7 }  { bits_q0 mem_dout 0 7 } } }
}
