require(package "FTSFC");

FTFastTCPGen(1000, 4000, 60, 68:5b:35:c5:e9:39, 192.168.200.18,
68:5b:35:c5:e9:55, 192.168.200.17, 100, 10)
-> VLANEncap(VLAN_ID 5)
-> VLANEncap(VLAN_ID 5)
-> ToDevice(p1);