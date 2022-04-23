# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_CRTLS {
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
ap_return { 
	dir o
	width 64
	depth 1
	mode ap_ctrl_hs
	offset 16
	offset_end 0
}
input_r { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 28
	offset_end 35
}
hash { 
	dir O
	width 8
	depth 1
	mode ap_vld
	offset 36
	offset_end 43
}
}
dict set axilite_register_dict CRTLS $port_CRTLS


