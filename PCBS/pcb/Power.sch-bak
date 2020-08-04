EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title "Breeze Ventilator Electronics Board"
Date ""
Rev ""
Comp "MTL Ventilator"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	1750 2650 1900 2650
Wire Wire Line
	1900 2650 1900 2750
Wire Wire Line
	1750 2750 1900 2750
Connection ~ 1900 2750
Wire Wire Line
	1900 2750 1900 2850
Wire Wire Line
	1750 2850 1900 2850
Connection ~ 1900 2850
Wire Wire Line
	1900 2850 1900 2950
$Comp
L power:GND #PWR0132
U 1 1 5EB06E2C
P 1900 3550
F 0 "#PWR0132" H 1900 3300 50  0001 C CNN
F 1 "GND" H 1905 3377 50  0000 C CNN
F 2 "" H 1900 3550 50  0001 C CNN
F 3 "" H 1900 3550 50  0001 C CNN
	1    1900 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2550 1800 2550
Wire Wire Line
	1800 2550 1800 2450
Wire Wire Line
	1750 2450 1800 2450
$Comp
L Device:Fuse F3
U 1 1 5EB07422
P 2650 3000
F 0 "F3" V 2453 3000 50  0000 C CNN
F 1 "Fuse" V 2544 3000 50  0000 C CNN
F 2 "ventilator-parts:LittelFuse_clips_01110501Z_10mm_fuse" V 2580 3000 50  0001 C CNN
F 3 "~" H 2650 3000 50  0001 C CNN
	1    2650 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Shunt_US R26
U 1 1 5EB07F9D
P 3750 2350
F 0 "R26" V 3525 2350 50  0000 C CNN
F 1 "LVK12R010FER" V 3616 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_Shunt_Ohmite_LVK12" V 3680 2350 50  0001 C CNN
F 3 "~" H 3750 2350 50  0001 C CNN
	1    3750 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 2350 3550 2350
Text Notes 1150 2400 0    50   ~ 0
INT BAT
Text Notes 1150 2500 0    50   ~ 0
EXT BAT
Text Notes 1150 2600 0    50   ~ 0
EXT BAT
Text Notes 1300 2700 0    50   ~ 0
GND
Text Notes 1300 2800 0    50   ~ 0
GND
Text Notes 1300 2900 0    50   ~ 0
GND
Text Notes 5950 1100 0    50   ~ 0
Maximum recharge current = 4A
$Comp
L Transistor_FET:SUD19P06-60 Q?
U 1 1 5E971EF2
P 4950 2000
AR Path="/5E8D3A4A/5E971EF2" Ref="Q?"  Part="1" 
AR Path="/5EAFE471/5E971EF2" Ref="Q2"  Part="1" 
F 0 "Q2" V 5293 2000 50  0000 C CNN
F 1 "SUD19P06-60" V 5202 2000 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 5145 1925 50  0001 L CIN
F 3 "https://www.vishay.com/docs/69253/sud19p06.pdf" H 4950 2000 50  0001 C CNN
	1    4950 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	1900 2250 1750 2250
Text HLabel 5050 3000 0    50   Input ~ 0
BATT_CHARGE_CTRL
Wire Wire Line
	2100 1250 4850 1250
Wire Wire Line
	4850 1250 4850 1800
Wire Wire Line
	4850 2350 4850 2200
Wire Wire Line
	3950 2350 4850 2350
$Comp
L Amplifier_Operational:OPA188xxDBV U?
U 1 1 5E990A6C
P 7100 3100
AR Path="/5E9ADB55/5E990A6C" Ref="U?"  Part="1" 
AR Path="/5EAFE471/5E990A6C" Ref="U11"  Part="1" 
F 0 "U11" H 7444 3146 50  0000 L CNN
F 1 "OPA188xxDBV" H 7100 2900 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-5" H 7100 3100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/opa188.pdf" H 7100 3300 50  0001 C CNN
	1    7100 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3000 5200 3000
$Comp
L power:GND #PWR?
U 1 1 5E993AA4
P 7000 3400
AR Path="/5E993AA4" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E993AA4" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E993AA4" Ref="#PWR0133"  Part="1" 
F 0 "#PWR0133" H 7000 3150 50  0001 C CNN
F 1 "GND" H 7005 3227 50  0000 C CNN
F 2 "" H 7000 3400 50  0001 C CNN
F 3 "" H 7000 3400 50  0001 C CNN
	1    7000 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5E9A4053
P 6300 4000
AR Path="/5E9A4053" Ref="R?"  Part="1" 
AR Path="/5E69BAD3/5E9A4053" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E9A4053" Ref="R30"  Part="1" 
F 0 "R30" H 6368 4046 50  0000 L CNN
F 1 "10K" H 6368 3955 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6340 3990 50  0001 C CNN
F 3 "~" H 6300 4000 50  0001 C CNN
F 4 "Digikey Electronics" H 6300 4000 50  0001 C CNN "VN"
F 5 "TE Connectivity Passive Product" H 6300 4000 50  0001 C CNN "MFN"
F 6 "CRG0805F51K" H 6300 4000 50  0001 C CNN "MPN"
F 7 "A126373CT-ND" H 6300 4000 50  0001 C CNN "VPN"
	1    6300 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9A54DF
P 6300 4150
AR Path="/5E9A54DF" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E9A54DF" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E9A54DF" Ref="#PWR0134"  Part="1" 
F 0 "#PWR0134" H 6300 3900 50  0001 C CNN
F 1 "GND" H 6305 3977 50  0000 C CNN
F 2 "" H 6300 4150 50  0001 C CNN
F 3 "" H 6300 4150 50  0001 C CNN
	1    6300 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3200 6300 3200
Wire Wire Line
	6300 3200 6300 3700
Wire Wire Line
	6950 3700 6300 3700
Connection ~ 6300 3700
Wire Wire Line
	6300 3700 6300 3850
Wire Wire Line
	7250 3700 7850 3700
Wire Wire Line
	7850 3700 7850 3100
Wire Wire Line
	7850 3100 7400 3100
$Comp
L Device:C C6
U 1 1 5E9AD81A
P 6300 2600
F 0 "C6" H 6415 2646 50  0000 L CNN
F 1 "C" H 6415 2555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6338 2450 50  0001 C CNN
F 3 "~" H 6300 2600 50  0001 C CNN
	1    6300 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 3100 7850 2850
Wire Wire Line
	7850 2000 7350 2000
Connection ~ 7850 3100
Wire Wire Line
	4850 1250 7000 1250
Wire Wire Line
	7000 1250 7000 2250
Connection ~ 4850 1250
Text Notes 4950 1550 0    50   ~ 0
Mount on 1" square pad for heatsink
$Comp
L Device:R_US R?
U 1 1 5E9D9995
P 7100 3700
AR Path="/5E9D9995" Ref="R?"  Part="1" 
AR Path="/5E69BAD3/5E9D9995" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E9D9995" Ref="R31"  Part="1" 
F 0 "R31" V 7250 3600 50  0000 L CNN
F 1 "20K" V 7350 3600 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7140 3690 50  0001 C CNN
F 3 "~" H 7100 3700 50  0001 C CNN
F 4 "Digikey Electronics" H 7100 3700 50  0001 C CNN "VN"
F 5 "TE Connectivity Passive Product" H 7100 3700 50  0001 C CNN "MFN"
F 6 "CRG0805F51K" H 7100 3700 50  0001 C CNN "MPN"
F 7 "A126373CT-ND" H 7100 3700 50  0001 C CNN "VPN"
	1    7100 3700
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5E9DA926
P 5350 3000
AR Path="/5E9DA926" Ref="R?"  Part="1" 
AR Path="/5E69BAD3/5E9DA926" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E9DA926" Ref="R28"  Part="1" 
F 0 "R28" V 5500 2900 50  0000 L CNN
F 1 "20K" V 5600 2900 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5390 2990 50  0001 C CNN
F 3 "~" H 5350 3000 50  0001 C CNN
F 4 "Digikey Electronics" H 5350 3000 50  0001 C CNN "VN"
F 5 "TE Connectivity Passive Product" H 5350 3000 50  0001 C CNN "MFN"
F 6 "CRG0805F51K" H 5350 3000 50  0001 C CNN "MPN"
F 7 "A126373CT-ND" H 5350 3000 50  0001 C CNN "VPN"
	1    5350 3000
	0    1    1    0   
$EndComp
Text Notes 6500 4150 0    50   ~ 0
OA is RR output, neg-rail input, so OK
$Comp
L Device:R_US R?
U 1 1 5E8F3140
P 7850 2700
AR Path="/5E8F3140" Ref="R?"  Part="1" 
AR Path="/5E69BAD3/5E8F3140" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E8F3140" Ref="R33"  Part="1" 
F 0 "R33" V 8000 2600 50  0000 L CNN
F 1 "20K" V 8100 2600 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7890 2690 50  0001 C CNN
F 3 "~" H 7850 2700 50  0001 C CNN
F 4 "Digikey Electronics" H 7850 2700 50  0001 C CNN "VN"
F 5 "TE Connectivity Passive Product" H 7850 2700 50  0001 C CNN "MFN"
F 6 "CRG0805F51K" H 7850 2700 50  0001 C CNN "MPN"
F 7 "A126373CT-ND" H 7850 2700 50  0001 C CNN "VPN"
	1    7850 2700
	-1   0    0    1   
$EndComp
Wire Wire Line
	7850 2550 7850 2000
$Comp
L Device:R_US R?
U 1 1 5E8F398E
P 7850 1650
AR Path="/5E8F398E" Ref="R?"  Part="1" 
AR Path="/5E69BAD3/5E8F398E" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E8F398E" Ref="R32"  Part="1" 
F 0 "R32" V 8000 1550 50  0000 L CNN
F 1 "10K" V 8100 1550 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7890 1640 50  0001 C CNN
F 3 "~" H 7850 1650 50  0001 C CNN
F 4 "Digikey Electronics" H 7850 1650 50  0001 C CNN "VN"
F 5 "TE Connectivity Passive Product" H 7850 1650 50  0001 C CNN "MFN"
F 6 "CRG0805F51K" H 7850 1650 50  0001 C CNN "MPN"
F 7 "A126373CT-ND" H 7850 1650 50  0001 C CNN "VPN"
	1    7850 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 1250 7850 1500
Connection ~ 7000 1250
Connection ~ 7850 2000
Text HLabel 7650 5650 2    50   Output ~ 0
BATT_VOLT_SENSE
Text HLabel 7650 4700 2    50   Output ~ 0
BATT_CURRENT_SENSE
Text Notes 5500 5100 0    50   ~ 0
1. Voltage divider for midpoint, since current could be in either direction\n2. Use voltage reference?\n3. Input AREF from voltage reference?
Wire Wire Line
	3650 4800 4450 4800
Wire Wire Line
	4650 5300 4650 5200
Wire Wire Line
	3650 2500 3650 4800
Wire Wire Line
	3850 4600 4450 4600
Wire Wire Line
	3850 4600 3850 2500
$Comp
L power:+5V #PWR0135
U 1 1 5E9533CE
P 4650 3950
F 0 "#PWR0135" H 4650 3800 50  0001 C CNN
F 1 "+5V" H 4665 4123 50  0000 C CNN
F 2 "" H 4650 3950 50  0001 C CNN
F 3 "" H 4650 3950 50  0001 C CNN
	1    4650 3950
	1    0    0    -1  
$EndComp
Connection ~ 4650 5200
Wire Wire Line
	5150 5200 5150 5100
Wire Wire Line
	4650 5200 5150 5200
Wire Wire Line
	5150 4700 5050 4700
Connection ~ 5150 4700
Wire Wire Line
	5150 4700 5150 4800
$Comp
L Device:R_US R?
U 1 1 5E8EDC6F
P 5150 4950
AR Path="/5E69BAD3/5E8EDC6F" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E8EDC6F" Ref="R27"  Part="1" 
F 0 "R27" H 5218 4996 50  0000 L CNN
F 1 "R_US" H 5218 4905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5190 4940 50  0001 C CNN
F 3 "~" H 5150 4950 50  0001 C CNN
F 4 "Digikey Electronics" H 5150 4950 50  0001 C CNN "VN"
	1    5150 4950
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Current:INA138 U?
U 1 1 5E8EDC18
P 4750 4700
AR Path="/5E8EDC18" Ref="U?"  Part="1" 
AR Path="/5E69BAD3/5E8EDC18" Ref="U?"  Part="1" 
AR Path="/5EAFE471/5E8EDC18" Ref="U10"  Part="1" 
F 0 "U10" H 4750 5050 50  0000 L CNN
F 1 "INA138" H 4750 4950 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 4750 4700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ina138.pdf" H 4750 4705 50  0001 C CNN
F 4 "Digikey Electronics" H 4750 4700 50  0001 C CNN "VN"
F 5 "Texas Instruments" H 4750 4700 50  0001 C CNN "MFN"
F 6 "INA138NA/3K" H 4750 4700 50  0001 C CNN "MPN"
F 7 "296-17936-1-ND" H 4750 4700 50  0001 C CNN "VPN"
	1    4750 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 4700 5400 4700
$Comp
L power:GND #PWR?
U 1 1 5E8EDBEB
P 4650 5300
AR Path="/5E8EDBEB" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E8EDBEB" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E8EDBEB" Ref="#PWR0136"  Part="1" 
F 0 "#PWR0136" H 4650 5050 50  0001 C CNN
F 1 "GND" H 4655 5127 50  0000 C CNN
F 2 "" H 4650 5300 50  0001 C CNN
F 3 "" H 4650 5300 50  0001 C CNN
	1    4650 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 5200 4650 5000
Wire Wire Line
	4650 3950 4650 4050
Wire Wire Line
	3450 5650 7650 5650
Wire Wire Line
	3450 5650 3450 5500
Connection ~ 3450 5650
Wire Wire Line
	3450 6150 3450 6100
$Comp
L power:GND #PWR?
U 1 1 5E8EDBCD
P 3450 6150
AR Path="/5E8EDBCD" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E8EDBCD" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E8EDBCD" Ref="#PWR0137"  Part="1" 
F 0 "#PWR0137" H 3450 5900 50  0001 C CNN
F 1 "GND" H 3455 5977 50  0000 C CNN
F 2 "" H 3450 6150 50  0001 C CNN
F 3 "" H 3450 6150 50  0001 C CNN
	1    3450 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 5800 3450 5650
$Comp
L Device:R_US R?
U 1 1 5E8EDBC6
P 3450 5950
AR Path="/5E8EDBC6" Ref="R?"  Part="1" 
AR Path="/5E69BAD3/5E8EDBC6" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E8EDBC6" Ref="R25"  Part="1" 
F 0 "R25" H 3518 5996 50  0000 L CNN
F 1 "10K" H 3518 5905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3490 5940 50  0001 C CNN
F 3 "~" H 3450 5950 50  0001 C CNN
F 4 "Digikey Electronics" H 3450 5950 50  0001 C CNN "VN"
F 5 "TE Connectivity Passive Product" H 3450 5950 50  0001 C CNN "MFN"
F 6 "CRGH0805F10K" H 3450 5950 50  0001 C CNN "MPN"
F 7 "A126417CT-ND" H 3450 5950 50  0001 C CNN "VPN"
	1    3450 5950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5E8EDBBC
P 3450 5350
AR Path="/5E8EDBBC" Ref="R?"  Part="1" 
AR Path="/5E69BAD3/5E8EDBBC" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E8EDBBC" Ref="R24"  Part="1" 
F 0 "R24" H 3518 5396 50  0000 L CNN
F 1 "20K" H 3518 5305 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3490 5340 50  0001 C CNN
F 3 "~" H 3450 5350 50  0001 C CNN
F 4 "Digikey Electronics" H 3450 5350 50  0001 C CNN "VN"
F 5 "TE Connectivity Passive Product" H 3450 5350 50  0001 C CNN "MFN"
F 6 "CRG0805F20K" H 3450 5350 50  0001 C CNN "MPN"
F 7 "A126349CT-ND" H 3450 5350 50  0001 C CNN "VPN"
	1    3450 5350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J19
U 1 1 5E909646
P 10150 4250
F 0 "J19" H 10230 4242 50  0000 L CNN
F 1 "Conn_01x04" H 10230 4151 50  0000 L CNN
F 2 "ventilator-parts:Buck_Converter_Module" H 10150 4250 50  0001 C CNN
F 3 "~" H 10150 4250 50  0001 C CNN
	1    10150 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0138
U 1 1 5E90A34A
P 9450 4000
F 0 "#PWR0138" H 9450 3850 50  0001 C CNN
F 1 "+12V" H 9465 4173 50  0000 C CNN
F 2 "" H 9450 4000 50  0001 C CNN
F 3 "" H 9450 4000 50  0001 C CNN
	1    9450 4000
	1    0    0    -1  
$EndComp
Wire Notes Line
	9250 3350 10450 3350
Wire Notes Line
	10450 3350 10450 2800
Wire Notes Line
	10450 2800 9250 2800
Wire Notes Line
	9250 2800 9250 3350
Text Notes 9800 2750 0    50   ~ 0
39
Text Notes 9100 3100 0    50   ~ 0
17
Text Notes 9400 2600 0    50   ~ 0
DC-DC step-down Top view
Text Notes 10400 2750 0    50   ~ 0
1
Text Notes 9250 2750 0    50   ~ 0
2
Text Notes 9250 3450 0    50   ~ 0
3
Text Notes 10400 3450 0    50   ~ 0
4
Text Notes 9300 2900 0    50   ~ 0
IN+
Text Notes 9300 3350 0    50   ~ 0
IN-
Text Notes 10250 3350 0    50   ~ 0
OUT-
Text Notes 10250 2900 0    50   ~ 0
OUT+
Wire Wire Line
	9450 4250 9950 4250
Wire Wire Line
	9450 4000 9450 4250
Wire Wire Line
	9950 4350 9750 4350
Wire Wire Line
	9750 4350 9750 4450
$Comp
L power:GND #PWR0139
U 1 1 5E91204B
P 9750 4600
F 0 "#PWR0139" H 9750 4350 50  0001 C CNN
F 1 "GND" H 9755 4427 50  0000 C CNN
F 2 "" H 9750 4600 50  0001 C CNN
F 3 "" H 9750 4600 50  0001 C CNN
	1    9750 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 4450 9750 4450
Connection ~ 9750 4450
Wire Wire Line
	9750 4450 9750 4600
Wire Wire Line
	9950 4150 9800 4150
Wire Wire Line
	9800 4150 9800 4000
$Comp
L power:+5V #PWR0140
U 1 1 5E9180B6
P 9800 4000
F 0 "#PWR0140" H 9800 3850 50  0001 C CNN
F 1 "+5V" H 9815 4173 50  0000 C CNN
F 2 "" H 9800 4000 50  0001 C CNN
F 3 "" H 9800 4000 50  0001 C CNN
	1    9800 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J20
U 1 1 5E919A5B
P 10150 5650
F 0 "J20" H 10230 5642 50  0000 L CNN
F 1 "Conn_01x04" H 10230 5551 50  0000 L CNN
F 2 "ventilator-parts:Buck_Converter_Module" H 10150 5650 50  0001 C CNN
F 3 "~" H 10150 5650 50  0001 C CNN
	1    10150 5650
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0141
U 1 1 5E919A65
P 9450 5400
F 0 "#PWR0141" H 9450 5250 50  0001 C CNN
F 1 "+12V" H 9465 5573 50  0000 C CNN
F 2 "" H 9450 5400 50  0001 C CNN
F 3 "" H 9450 5400 50  0001 C CNN
	1    9450 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 5650 9950 5650
Wire Wire Line
	9450 5400 9450 5650
Wire Wire Line
	9950 5750 9750 5750
Wire Wire Line
	9750 5750 9750 5850
$Comp
L power:GND #PWR0142
U 1 1 5E919A73
P 9750 6000
F 0 "#PWR0142" H 9750 5750 50  0001 C CNN
F 1 "GND" H 9755 5827 50  0000 C CNN
F 2 "" H 9750 6000 50  0001 C CNN
F 3 "" H 9750 6000 50  0001 C CNN
	1    9750 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 5850 9750 5850
Connection ~ 9750 5850
Wire Wire Line
	9750 5850 9750 6000
Wire Wire Line
	9950 5550 9800 5550
Wire Wire Line
	9800 5550 9800 5400
$Comp
L power:+5VP #PWR0143
U 1 1 5E91FEC8
P 9800 5400
F 0 "#PWR0143" H 9800 5250 50  0001 C CNN
F 1 "+5VP" H 9815 5573 50  0000 C CNN
F 2 "" H 9800 5400 50  0001 C CNN
F 3 "" H 9800 5400 50  0001 C CNN
	1    9800 5400
	1    0    0    -1  
$EndComp
Text Notes 9400 3650 0    79   ~ 0
Clean +5V
Text Notes 9400 5050 0    79   ~ 0
Dirty +5V
Wire Wire Line
	7850 1800 7850 2000
Wire Wire Line
	7000 1250 7350 1250
Text Notes 850  2300 0    50   ~ 0
RECTIFIER B NEG
Text Notes 850  2200 0    50   ~ 0
RECTIFIER B POS
$Comp
L power:+12V #PWR0144
U 1 1 5E959F1C
P 7850 1150
F 0 "#PWR0144" H 7850 1000 50  0001 C CNN
F 1 "+12V" H 7865 1323 50  0000 C CNN
F 2 "" H 7850 1150 50  0001 C CNN
F 3 "" H 7850 1150 50  0001 C CNN
	1    7850 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 1150 7850 1250
Connection ~ 7850 1250
Text Notes 8650 2300 0    50   ~ 0
In rectifier power fail condition, MOSFET initially\nconducts via parasitic diode, causing an initial drop \nfrom 15V to ~~0.6V under the battery voltage. MOSFET \ncan be turned on fully by lowering the op amp output \nunder software control, in order to eliminate the diode drop.\n\nConversely, if MOSFET is full on in power fail condition, \nwhen power is restored the battery might get too much charging\ncurrent and in the worst case it might OVC the rectifier. \n\nFor initial power-up conditions, capacitor to +5 on OA input\nkeeps MOSFET off.\n\nWILL THIS PREVENT INITIAL POWER-UP ON BATTERY ONLY?\n\nSituations to test:\n\n* Normal power on (AC and charged battery)\n* AC and depleted battery\n* Charged battery but no AC\n
Text Notes 850  2100 0    50   ~ 0
RECTIFIER A NEG
Text Notes 850  2000 0    50   ~ 0
RECTIFIER A POS
Wire Wire Line
	1750 2050 1900 2050
Wire Wire Line
	1900 2050 1900 2250
$Comp
L Connector:Screw_Terminal_01x16 J18
U 1 1 5E9649DD
P 1550 2650
F 0 "J18" H 1468 3567 50  0000 C CNN
F 1 "Screw_Terminal_01x16" H 1468 3476 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-16-3.5-H_1x16_P3.50mm_Horizontal" H 1550 2650 50  0001 C CNN
F 3 "~" H 1550 2650 50  0001 C CNN
	1    1550 2650
	-1   0    0    -1  
$EndComp
Connection ~ 2100 1950
Wire Wire Line
	1750 1950 2100 1950
Wire Wire Line
	2100 1250 2100 1950
Wire Wire Line
	2100 1950 2100 2150
Wire Wire Line
	1750 2150 2100 2150
Text Notes 700  3400 0    50   ~ 0
BATTERY-ONOFF-A
Wire Wire Line
	3450 2350 3450 5200
Wire Wire Line
	2650 2350 2650 2850
Connection ~ 1800 2450
Wire Wire Line
	1750 3450 3050 3450
Wire Wire Line
	3050 3450 3050 2350
Wire Wire Line
	3050 2350 3450 2350
Connection ~ 3450 2350
Text Notes 700  3500 0    50   ~ 0
BATTERY-ONOFF-B
Wire Wire Line
	2450 2450 1800 2450
Wire Wire Line
	2450 3350 1750 3350
Connection ~ 2450 3350
Wire Wire Line
	2650 3350 2450 3350
Wire Wire Line
	2450 3350 2450 2450
Wire Wire Line
	2650 3150 2650 3350
Wire Wire Line
	1750 2350 2650 2350
Text Notes 500  2600 0    50   ~ 0
External battery \nmust be fused\n
$Comp
L Device:C C7
U 1 1 5E9BBBDC
P 7350 1650
F 0 "C7" H 7465 1696 50  0000 L CNN
F 1 "C" H 7465 1605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7388 1500 50  0001 C CNN
F 3 "~" H 7350 1650 50  0001 C CNN
	1    7350 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1250 7350 1500
Wire Wire Line
	7350 1800 7350 2000
Connection ~ 7350 1250
Wire Wire Line
	7350 1250 7850 1250
Connection ~ 7350 2000
Wire Wire Line
	7350 2000 5150 2000
Connection ~ 6300 3000
Wire Wire Line
	6300 3000 6800 3000
Wire Wire Line
	6300 2750 6300 3000
$Comp
L power:+5V #PWR0145
U 1 1 5E9C5AED
P 5250 2300
F 0 "#PWR0145" H 5250 2150 50  0001 C CNN
F 1 "+5V" H 5265 2473 50  0000 C CNN
F 2 "" H 5250 2300 50  0001 C CNN
F 3 "" H 5250 2300 50  0001 C CNN
	1    5250 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3000 5850 3000
$Comp
L Device:R_US R?
U 1 1 5E9D3AEF
P 5550 2350
AR Path="/5E9D3AEF" Ref="R?"  Part="1" 
AR Path="/5E69BAD3/5E9D3AEF" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E9D3AEF" Ref="R29"  Part="1" 
F 0 "R29" V 5700 2250 50  0000 L CNN
F 1 "20K" V 5800 2250 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5590 2340 50  0001 C CNN
F 3 "~" H 5550 2350 50  0001 C CNN
F 4 "Digikey Electronics" H 5550 2350 50  0001 C CNN "VN"
F 5 "TE Connectivity Passive Product" H 5550 2350 50  0001 C CNN "MFN"
F 6 "CRG0805F51K" H 5550 2350 50  0001 C CNN "MPN"
F 7 "A126373CT-ND" H 5550 2350 50  0001 C CNN "VPN"
	1    5550 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	5250 2300 5250 2350
Wire Wire Line
	5250 2350 5400 2350
Wire Wire Line
	6300 2350 6300 2450
Wire Wire Line
	5700 2350 5850 2350
Wire Wire Line
	5850 2450 5850 2350
Connection ~ 5850 2350
Wire Wire Line
	5850 2350 6300 2350
$Comp
L power:GND #PWR?
U 1 1 5E9D08B2
P 5850 2750
AR Path="/5E9D08B2" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E9D08B2" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E9D08B2" Ref="#PWR0146"  Part="1" 
F 0 "#PWR0146" H 5850 2500 50  0001 C CNN
F 1 "GND" H 5855 2577 50  0000 C CNN
F 2 "" H 5850 2750 50  0001 C CNN
F 3 "" H 5850 2750 50  0001 C CNN
	1    5850 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5E9C6B19
P 5850 2600
F 0 "C4" H 5965 2646 50  0000 L CNN
F 1 "C" H 5965 2555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5888 2450 50  0001 C CNN
F 3 "~" H 5850 2600 50  0001 C CNN
	1    5850 2600
	1    0    0    -1  
$EndComp
Text Notes 650  4700 0    50   ~ 0
Improvement: sense each \nrectifier output state for failure\ndetection.
Text Notes 650  4250 0    50   ~ 0
Notes:\n\n* External battery must be fused.\n* Connections provided for redundant rectifiers.\n* Rectifier must tolerate voltage on its output and\nadmint minimal leakage during AC mains faliure.
Wire Wire Line
	5850 3100 5850 3000
$Comp
L power:GND #PWR?
U 1 1 5E9F2AD6
P 5850 3400
AR Path="/5E9F2AD6" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E9F2AD6" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E9F2AD6" Ref="#PWR0147"  Part="1" 
F 0 "#PWR0147" H 5850 3150 50  0001 C CNN
F 1 "GND" H 5855 3227 50  0000 C CNN
F 2 "" H 5850 3400 50  0001 C CNN
F 3 "" H 5850 3400 50  0001 C CNN
	1    5850 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5E9F2AE0
P 5850 3250
F 0 "C5" H 5965 3296 50  0000 L CNN
F 1 "C" H 5965 3205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5888 3100 50  0001 C CNN
F 3 "~" H 5850 3250 50  0001 C CNN
	1    5850 3250
	1    0    0    -1  
$EndComp
Connection ~ 5850 3000
Wire Wire Line
	5850 3000 6300 3000
Text Notes 1300 3000 0    50   ~ 0
GND
Text Notes 1300 3100 0    50   ~ 0
GND
Text Notes 1250 3200 0    50   ~ 0
+24V
Wire Wire Line
	1900 2250 1900 2650
Connection ~ 1900 2250
Connection ~ 1900 2650
Wire Wire Line
	1750 3150 2050 3150
Wire Wire Line
	2050 3150 2050 3050
$Comp
L power:+24V #PWR0148
U 1 1 5EA2EA5F
P 2050 3050
F 0 "#PWR0148" H 2050 2900 50  0001 C CNN
F 1 "+24V" H 2065 3223 50  0000 C CNN
F 2 "" H 2050 3050 50  0001 C CNN
F 3 "" H 2050 3050 50  0001 C CNN
	1    2050 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2950 1900 2950
Connection ~ 1900 2950
Wire Wire Line
	1900 2950 1900 3050
Wire Wire Line
	1750 3050 1900 3050
Connection ~ 1900 3050
Wire Wire Line
	1900 3050 1900 3550
$Comp
L Connector:USB_A J1
U 1 1 5E95870E
P 1400 5750
F 0 "J1" H 1457 6217 50  0000 C CNN
F 1 "USB_A" H 1457 6126 50  0000 C CNN
F 2 "ventilator-parts:USB_A_TE_Connectivity_292303-1" H 1550 5700 50  0001 C CNN
F 3 " ~" H 1550 5700 50  0001 C CNN
	1    1400 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E95C5E3
P 1400 6150
AR Path="/5E95C5E3" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E95C5E3" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E95C5E3" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 1400 5900 50  0001 C CNN
F 1 "GND" H 1405 5977 50  0000 C CNN
F 2 "" H 1400 6150 50  0001 C CNN
F 3 "" H 1400 6150 50  0001 C CNN
	1    1400 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 5550 2050 5550
Wire Wire Line
	2050 5550 2050 5350
$Comp
L power:+5V #PWR0111
U 1 1 5E962D4B
P 2050 5350
F 0 "#PWR0111" H 2050 5200 50  0001 C CNN
F 1 "+5V" H 2065 5523 50  0000 C CNN
F 2 "" H 2050 5350 50  0001 C CNN
F 3 "" H 2050 5350 50  0001 C CNN
	1    2050 5350
	1    0    0    -1  
$EndComp
Text Notes 750  5000 0    118  ~ 0
Raspberry Pi Power
$Comp
L Device:C C11
U 1 1 5E9C6624
P 4200 4300
F 0 "C11" H 4315 4346 50  0000 L CNN
F 1 "C" H 4315 4255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4238 4150 50  0001 C CNN
F 3 "~" H 4200 4300 50  0001 C CNN
	1    4200 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9CA67C
P 4200 4450
AR Path="/5E9CA67C" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E9CA67C" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E9CA67C" Ref="#PWR014"  Part="1" 
F 0 "#PWR014" H 4200 4200 50  0001 C CNN
F 1 "GND" H 4205 4277 50  0000 C CNN
F 2 "" H 4200 4450 50  0001 C CNN
F 3 "" H 4200 4450 50  0001 C CNN
	1    4200 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 4150 4200 4050
Wire Wire Line
	4200 4050 4650 4050
Connection ~ 4650 4050
Wire Wire Line
	4650 4050 4650 4200
$Comp
L Device:C C12
U 1 1 5E9CF32E
P 7400 2500
F 0 "C12" H 7515 2546 50  0000 L CNN
F 1 "C" H 7515 2455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7438 2350 50  0001 C CNN
F 3 "~" H 7400 2500 50  0001 C CNN
	1    7400 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9CF338
P 7400 2650
AR Path="/5E9CF338" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E9CF338" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E9CF338" Ref="#PWR015"  Part="1" 
F 0 "#PWR015" H 7400 2400 50  0001 C CNN
F 1 "GND" H 7405 2477 50  0000 C CNN
F 2 "" H 7400 2650 50  0001 C CNN
F 3 "" H 7400 2650 50  0001 C CNN
	1    7400 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2350 7400 2250
Wire Wire Line
	7400 2250 7000 2250
Connection ~ 7000 2250
Wire Wire Line
	7000 2250 7000 2800
Text Label 2100 2350 0    50   ~ 0
p_1
Text Label 2100 2450 0    50   ~ 0
p_2
Text Label 2100 3450 0    50   ~ 0
p_3
Text Label 4250 2350 0    50   ~ 0
p_4
$Comp
L Device:R_US R?
U 1 1 5E9FC6A2
P 5400 4400
AR Path="/5E69BAD3/5E9FC6A2" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E9FC6A2" Ref="R1"  Part="1" 
F 0 "R1" H 5468 4446 50  0000 L CNN
F 1 "R_US" H 5468 4355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5440 4390 50  0001 C CNN
F 3 "~" H 5400 4400 50  0001 C CNN
F 4 "Digikey Electronics" H 5400 4400 50  0001 C CNN "VN"
	1    5400 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 4700 5400 4550
Wire Wire Line
	5400 4200 4650 4200
Wire Wire Line
	5400 4250 5400 4200
Connection ~ 5400 4700
Wire Wire Line
	5400 4700 5150 4700
Connection ~ 4650 4200
Wire Wire Line
	4650 4200 4650 4400
$EndSCHEMATC
