require(package "FTSFC");

FromDump(small-packets-1.pcap)
->CheckIPHeader(14)
->SetVLANAnno
->Queue
->FTFilterElement(1,4)
->ap::FTAppenderElement(1)
->CheckIPHeader(14)
->se1::FTStateElement(ID 1, F 1)
->CheckIPHeader(14)
->cmb::CounterMB(ID 1);

cmb
->CheckIPHeader(14)
->[1]se1;

// Second replica
se1[1]
->CheckIPHeader(14)
->se2::FTStateElement(ID 2, F 1)
->CheckIPHeader(14)
->cmb2::CounterMB(ID 2);

cmb2
->CheckIPHeader(14)
->[1]se2;

se2[1]
->CheckIPHeader(14)
->SetVLANAnno
->VLANEncap(VLAN_ID %d)
-> be :: FTBufferElement[1]
->CheckIPHeader(14)
->se1;

be
->ToDump(result.pcap);

//ControlSocket(TCP, 10000, VERBOSE true);