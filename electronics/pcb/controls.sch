EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 3 5
Title "Breeze Ventilator Electronics Board"
Date ""
Rev ""
Comp "MTL Ventilator"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_Motor:L298HN U1
U 1 1 5E8D4284
P 5250 3000
F 0 "U1" H 4900 3800 50  0000 C CNN
F 1 "L298HN" H 5000 3700 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-15_P2.54x2.54mm_StaggerOdd_Lead5.84mm_TabDown" H 5300 2350 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000240.pdf" H 5400 3250 50  0001 C CNN
	1    5250 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 2800 8050 2900
Wire Wire Line
	8050 2900 8350 2900
Wire Wire Line
	8350 3200 7650 3200
Wire Wire Line
	5850 2900 6800 2900
Wire Wire Line
	7950 2900 7950 3000
Wire Wire Line
	7950 3000 8350 3000
Wire Wire Line
	5850 3100 7000 3100
$Comp
L power:GND #PWR0102
U 1 1 5E8D8EDE
P 5150 3900
F 0 "#PWR0102" H 5150 3650 50  0001 C CNN
F 1 "GND" H 5155 3727 50  0000 C CNN
F 2 "" H 5150 3900 50  0001 C CNN
F 3 "" H 5150 3900 50  0001 C CNN
	1    5150 3900
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0103
U 1 1 5E8DA7AB
P 5250 1150
F 0 "#PWR0103" H 5250 1000 50  0001 C CNN
F 1 "+12V" H 5265 1323 50  0000 C CNN
F 2 "" H 5250 1150 50  0001 C CNN
F 3 "" H 5250 1150 50  0001 C CNN
	1    5250 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2300 5250 2000
Wire Wire Line
	5250 2000 5350 2000
Wire Wire Line
	5350 2000 5350 2200
Connection ~ 5250 2000
Wire Wire Line
	5250 3700 5250 3800
Wire Wire Line
	5250 3800 5150 3800
Wire Wire Line
	5050 3800 5050 3700
Wire Wire Line
	5050 3800 4950 3800
Wire Wire Line
	4950 3800 4950 3700
Connection ~ 5050 3800
Wire Wire Line
	5150 3900 5150 3800
Connection ~ 5150 3800
Wire Wire Line
	5150 3800 5050 3800
Wire Wire Line
	4400 3100 4650 3100
Wire Wire Line
	4400 2700 4650 2700
Text HLabel 4400 3100 0    50   Input ~ 0
EnB
Text HLabel 4400 2700 0    50   Input ~ 0
EnA
Wire Wire Line
	4650 2500 4400 2500
Wire Wire Line
	4400 2600 4650 2600
Wire Wire Line
	4650 2900 4400 2900
Wire Wire Line
	4400 3000 4650 3000
Text HLabel 4400 3000 0    50   Input ~ 0
IN4
Text HLabel 4400 2900 0    50   Input ~ 0
IN3
Text HLabel 4400 2600 0    50   Input ~ 0
IN2
Text HLabel 4400 2500 0    50   Input ~ 0
IN1
$Comp
L Connector_Generic:Conn_01x04 J13
U 1 1 5EA0D72F
P 8550 3000
F 0 "J13" H 8630 2992 50  0000 L CNN
F 1 "Conn_01x04" H 8630 2901 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-04A_1x04_P2.54mm_Vertical" H 8550 3000 50  0001 C CNN
F 3 "~" H 8550 3000 50  0001 C CNN
	1    8550 3000
	1    0    0    -1  
$EndComp
Text Notes 4650 700  0    118  ~ 0
Stepper Motor
$Comp
L Connector_Generic:Conn_01x03 J5
U 1 1 5EA36E3A
P 3300 2450
F 0 "J5" H 3380 2492 50  0000 L CNN
F 1 "Conn_01x03" H 3380 2401 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-03A_1x03_P2.54mm_Vertical" H 3300 2450 50  0001 C CNN
F 3 "~" H 3300 2450 50  0001 C CNN
	1    3300 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2450 2750 2450
Wire Wire Line
	3100 2350 2900 2350
Wire Wire Line
	2900 2350 2900 2750
$Comp
L power:GND #PWR0106
U 1 1 5EA38B7B
P 2900 2750
F 0 "#PWR0106" H 2900 2500 50  0001 C CNN
F 1 "GND" H 2905 2577 50  0000 C CNN
F 2 "" H 2900 2750 50  0001 C CNN
F 3 "" H 2900 2750 50  0001 C CNN
	1    2900 2750
	1    0    0    -1  
$EndComp
Text HLabel 1750 2550 0    50   Input ~ 0
SERVO_PWM1
Wire Wire Line
	1750 2550 3100 2550
$Comp
L power:+5VP #PWR0110
U 1 1 5EA46646
P 1800 1500
F 0 "#PWR0110" H 1800 1350 50  0001 C CNN
F 1 "+5VP" H 1815 1673 50  0000 C CNN
F 2 "" H 1800 1500 50  0001 C CNN
F 3 "" H 1800 1500 50  0001 C CNN
	1    1800 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0112
U 1 1 5EA44106
P 9100 1700
F 0 "#PWR0112" H 9100 1550 50  0001 C CNN
F 1 "+12V" H 9115 1873 50  0000 C CNN
F 2 "" H 9100 1700 50  0001 C CNN
F 3 "" H 9100 1700 50  0001 C CNN
	1    9100 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 2050 9450 2050
Wire Wire Line
	8400 1500 8400 1600
$Comp
L power:+5V #PWR0114
U 1 1 5EA41D30
P 8400 1500
F 0 "#PWR0114" H 8400 1350 50  0001 C CNN
F 1 "+5V" H 8415 1673 50  0000 C CNN
F 2 "" H 8400 1500 50  0001 C CNN
F 3 "" H 8400 1500 50  0001 C CNN
	1    8400 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 1900 8400 2050
$Comp
L Device:R_US R13
U 1 1 5EA41D25
P 8400 1750
F 0 "R13" H 8468 1796 50  0000 L CNN
F 1 "1K" H 8468 1705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8440 1740 50  0001 C CNN
F 3 "~" H 8400 1750 50  0001 C CNN
	1    8400 1750
	1    0    0    -1  
$EndComp
Connection ~ 8400 2050
Wire Wire Line
	8100 2050 8400 2050
Text HLabel 8100 2050 0    50   Output ~ 0
FAN_TACH
$Comp
L power:GND #PWR0115
U 1 1 5EA3DFC5
P 9250 2350
F 0 "#PWR0115" H 9250 2100 50  0001 C CNN
F 1 "GND" H 9255 2177 50  0000 C CNN
F 2 "" H 9250 2350 50  0001 C CNN
F 3 "" H 9250 2350 50  0001 C CNN
	1    9250 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 1850 9250 1850
Wire Wire Line
	9100 1950 9100 1700
Wire Wire Line
	9450 1950 9100 1950
$Comp
L Connector_Generic:Conn_01x03 J14
U 1 1 5EA3DFB7
P 9650 1950
F 0 "J14" H 9730 1992 50  0000 L CNN
F 1 "Conn_01x03" H 9730 1901 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-03A_1x03_P2.54mm_Vertical" H 9650 1950 50  0001 C CNN
F 3 "~" H 9650 1950 50  0001 C CNN
	1    9650 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5EA62D30
P 2850 5700
F 0 "J3" H 2930 5742 50  0000 L CNN
F 1 "Conn_01x03" H 2930 5651 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-03A_1x03_P2.54mm_Vertical" H 2850 5700 50  0001 C CNN
F 3 "~" H 2850 5700 50  0001 C CNN
	1    2850 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5600 2450 5600
Wire Wire Line
	2450 5600 2450 6000
$Comp
L power:GND #PWR0116
U 1 1 5EA62D3E
P 2450 6000
F 0 "#PWR0116" H 2450 5750 50  0001 C CNN
F 1 "GND" H 2455 5827 50  0000 C CNN
F 2 "" H 2450 6000 50  0001 C CNN
F 3 "" H 2450 6000 50  0001 C CNN
	1    2450 6000
	1    0    0    -1  
$EndComp
Text HLabel 1300 5800 0    50   Input ~ 0
ESC_PWM1
Wire Wire Line
	1300 5800 2650 5800
Text Notes 1850 950  0    118  ~ 0
Servo Interface
Text Notes 2450 5350 0    118  ~ 0
ESC (Speed Controller)\nControl Interface & Power
Text Notes 8650 1300 0    118  ~ 0
Fan
Text HLabel 1700 2100 0    50   Input ~ 0
SERVO_OFF
$Comp
L Connector_Generic:Conn_01x02 J10
U 1 1 5EACAE19
P 5250 6700
F 0 "J10" H 5330 6692 50  0000 L CNN
F 1 "Conn_01x02" H 5330 6601 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 5250 6700 50  0001 C CNN
F 3 "~" H 5250 6700 50  0001 C CNN
	1    5250 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 6800 5050 6800
$Comp
L Device:Fuse F1
U 1 1 5EAD6DD1
P 4450 6700
F 0 "F1" V 4253 6700 50  0000 C CNN
F 1 "Fuse" V 4344 6700 50  0000 C CNN
F 2 "ventilator-parts:LittelFuse_clips_01110501Z_10mm_fuse" V 4380 6700 50  0001 C CNN
F 3 "~" H 4450 6700 50  0001 C CNN
	1    4450 6700
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 6700 5050 6700
Wire Wire Line
	4300 6700 4150 6700
Wire Wire Line
	4150 6700 4150 5950
$Comp
L power:+12V #PWR0119
U 1 1 5EAE865B
P 4600 5650
F 0 "#PWR0119" H 4600 5500 50  0001 C CNN
F 1 "+12V" H 4615 5823 50  0000 C CNN
F 2 "" H 4600 5650 50  0001 C CNN
F 3 "" H 4600 5650 50  0001 C CNN
	1    4600 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R11
U 1 1 5EAEFC7F
P 2000 2100
F 0 "R11" V 1795 2100 50  0000 C CNN
F 1 "R_US" V 1886 2100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2040 2090 50  0001 C CNN
F 3 "~" H 2000 2100 50  0001 C CNN
	1    2000 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 2100 2350 2100
Wire Wire Line
	2350 2100 2350 1900
Wire Wire Line
	1850 2100 1700 2100
$Comp
L Transistor_FET:SUD19P06-60 Q1
U 1 1 5EAF472F
P 2350 1700
F 0 "Q1" V 2693 1700 50  0000 C CNN
F 1 "SUD19P06-60" V 2602 1700 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 2545 1625 50  0001 L CIN
F 3 "https://www.vishay.com/docs/69253/sud19p06.pdf" H 2350 1700 50  0001 C CNN
	1    2350 1700
	0    1    -1   0   
$EndComp
Wire Wire Line
	1800 1500 1800 1600
Wire Wire Line
	1800 1600 2150 1600
Wire Wire Line
	2550 1600 2750 1600
Wire Wire Line
	2750 1600 2750 2450
$Comp
L Device:R_Shunt_US R?
U 1 1 5E8F78A5
P 5250 1450
AR Path="/5EAFE471/5E8F78A5" Ref="R?"  Part="1" 
AR Path="/5E8D3A4A/5E8F78A5" Ref="R12"  Part="1" 
F 0 "R12" H 4600 1650 50  0000 C CNN
F 1 "LVK12R010FER" H 4800 1550 50  0000 C CNN
F 2 "Resistor_SMD:R_Shunt_Ohmite_LVK12" V 5180 1450 50  0001 C CNN
F 3 "~" H 5250 1450 50  0001 C CNN
	1    5250 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 1150 5250 1250
Wire Wire Line
	5250 1650 5250 2000
$Comp
L Amplifier_Current:INA138 U?
U 1 1 5E93FE23
P 6400 1450
AR Path="/5E93FE23" Ref="U?"  Part="1" 
AR Path="/5E69BAD3/5E93FE23" Ref="U?"  Part="1" 
AR Path="/5EAFE471/5E93FE23" Ref="U?"  Part="1" 
AR Path="/5E8D3A4A/5E93FE23" Ref="U4"  Part="1" 
F 0 "U4" H 6400 1800 50  0000 L CNN
F 1 "INA138" H 6400 1700 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 6400 1450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ina138.pdf" H 6400 1455 50  0001 C CNN
F 4 "Digikey Electronics" H 6400 1450 50  0001 C CNN "VN"
F 5 "Texas Instruments" H 6400 1450 50  0001 C CNN "MFN"
F 6 "INA138NA/3K" H 6400 1450 50  0001 C CNN "MPN"
F 7 "296-17936-1-ND" H 6400 1450 50  0001 C CNN "VPN"
	1    6400 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1450 6800 1450
$Comp
L power:GND #PWR?
U 1 1 5E93FE4C
P 6300 1950
AR Path="/5E93FE4C" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E93FE4C" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E93FE4C" Ref="#PWR?"  Part="1" 
AR Path="/5E8D3A4A/5E93FE4C" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 6300 1700 50  0001 C CNN
F 1 "GND" H 6305 1777 50  0000 C CNN
F 2 "" H 6300 1950 50  0001 C CNN
F 3 "" H 6300 1950 50  0001 C CNN
	1    6300 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1950 6300 1750
Wire Wire Line
	6300 800  6300 850 
Text HLabel 7200 1450 2    50   Output ~ 0
STEPPER_CURRENT
$Comp
L Device:R_US R?
U 1 1 5E93FE63
P 6800 1700
AR Path="/5E69BAD3/5E93FE63" Ref="R?"  Part="1" 
AR Path="/5EAFE471/5E93FE63" Ref="R?"  Part="1" 
AR Path="/5E8D3A4A/5E93FE63" Ref="R15"  Part="1" 
F 0 "R15" H 6868 1746 50  0000 L CNN
F 1 "R_US" H 6868 1655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6840 1690 50  0001 C CNN
F 3 "~" H 6800 1700 50  0001 C CNN
F 4 "Digikey Electronics" H 6800 1700 50  0001 C CNN "VN"
	1    6800 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1950 6800 1950
Wire Wire Line
	6800 1950 6800 1850
Wire Wire Line
	6800 1450 6800 1550
Connection ~ 6800 1450
Wire Wire Line
	6800 1450 6700 1450
Wire Wire Line
	5400 1350 6100 1350
Wire Wire Line
	5400 1550 6100 1550
Connection ~ 6300 1950
$Comp
L power:+5V #PWR0121
U 1 1 5E951320
P 6300 800
F 0 "#PWR0121" H 6300 650 50  0001 C CNN
F 1 "+5V" H 6315 973 50  0000 C CNN
F 2 "" H 6300 800 50  0001 C CNN
F 3 "" H 6300 800 50  0001 C CNN
	1    6300 800 
	1    0    0    -1  
$EndComp
NoConn ~ 2650 5700
$Comp
L Jumper:Jumper_3_Open JP1
U 1 1 5EA13B04
P 4150 5800
F 0 "JP1" H 4150 6024 50  0000 C CNN
F 1 "Jumper_3_Open" H 4150 5933 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4150 5800 50  0001 C CNN
F 3 "~" H 4150 5800 50  0001 C CNN
	1    4150 5800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4400 5800 4600 5800
Wire Wire Line
	4600 5800 4600 5650
Wire Wire Line
	3900 5800 3650 5800
Wire Wire Line
	3650 5800 3650 5650
$Comp
L power:+24V #PWR0122
U 1 1 5EA1AB77
P 3650 5650
F 0 "#PWR0122" H 3650 5500 50  0001 C CNN
F 1 "+24V" H 3665 5823 50  0000 C CNN
F 2 "" H 3650 5650 50  0001 C CNN
F 3 "" H 3650 5650 50  0001 C CNN
	1    3650 5650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5E956B2D
P 7400 5450
F 0 "J2" H 7480 5442 50  0000 L CNN
F 1 "Conn_01x02" H 7480 5351 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 7400 5450 50  0001 C CNN
F 3 "~" H 7400 5450 50  0001 C CNN
	1    7400 5450
	-1   0    0    -1  
$EndComp
$Comp
L Relay:G6S-2 K?
U 1 1 5E95E0E5
P 9400 5100
AR Path="/5EAFE471/5E95E0E5" Ref="K?"  Part="1" 
AR Path="/5E8D3A4A/5E95E0E5" Ref="K1"  Part="1" 
F 0 "K1" V 8633 5100 50  0000 C CNN
F 1 "G6S-2" V 8724 5100 50  0000 C CNN
F 2 "Relay_SMD:Relay_DPDT_Omron_G6S-2F" H 9400 5100 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g6s.pdf" H 9400 5100 50  0001 C CNN
	1    9400 5100
	0    1    1    0   
$EndComp
Text HLabel 6700 4200 0    50   Input ~ 0
ALARM_OFF
Wire Wire Line
	6700 4200 10050 4200
Wire Wire Line
	10050 4200 10050 4700
Wire Wire Line
	10050 4700 9700 4700
$Comp
L power:GND #PWR013
U 1 1 5E969287
P 8900 4750
F 0 "#PWR013" H 8900 4500 50  0001 C CNN
F 1 "GND" H 8905 4577 50  0000 C CNN
F 2 "" H 8900 4750 50  0001 C CNN
F 3 "" H 8900 4750 50  0001 C CNN
	1    8900 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 4750 8900 4700
Wire Wire Line
	8900 4700 9100 4700
Wire Wire Line
	9700 5000 10050 5000
Wire Wire Line
	10050 5000 10050 5400
Wire Wire Line
	8250 5000 8250 5100
Wire Wire Line
	8250 5100 8850 5100
Wire Wire Line
	7950 4800 7800 4800
Wire Wire Line
	7800 4800 7800 4650
$Comp
L power:+12V #PWR011
U 1 1 5E9AD366
P 7800 4650
F 0 "#PWR011" H 7800 4500 50  0001 C CNN
F 1 "+12V" H 7815 4823 50  0000 C CNN
F 2 "" H 7800 4650 50  0001 C CNN
F 3 "" H 7800 4650 50  0001 C CNN
	1    7800 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 5450 8650 4800
Wire Wire Line
	8650 4800 8550 4800
$Comp
L Device:C C10
U 1 1 5E9D82D4
P 7050 1050
F 0 "C10" H 7165 1096 50  0000 L CNN
F 1 "C" H 7165 1005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7088 900 50  0001 C CNN
F 3 "~" H 7050 1050 50  0001 C CNN
	1    7050 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 850  7050 850 
Wire Wire Line
	7050 850  7050 900 
Connection ~ 6300 850 
Wire Wire Line
	6300 850  6300 1150
$Comp
L power:GND #PWR?
U 1 1 5E9DEB7E
P 7050 1200
AR Path="/5E9DEB7E" Ref="#PWR?"  Part="1" 
AR Path="/5E69BAD3/5E9DEB7E" Ref="#PWR?"  Part="1" 
AR Path="/5EAFE471/5E9DEB7E" Ref="#PWR?"  Part="1" 
AR Path="/5E8D3A4A/5E9DEB7E" Ref="#PWR010"  Part="1" 
F 0 "#PWR010" H 7050 950 50  0001 C CNN
F 1 "GND" H 7055 1027 50  0000 C CNN
F 2 "" H 7050 1200 50  0001 C CNN
F 3 "" H 7050 1200 50  0001 C CNN
	1    7050 1200
	1    0    0    -1  
$EndComp
Text Notes 6900 4100 0    118  ~ 0
Arduino-controlled Backup Alarm
Wire Wire Line
	8850 5100 8850 5500
Wire Wire Line
	8850 5500 9100 5500
Connection ~ 8850 5100
Wire Wire Line
	8850 5100 9100 5100
Wire Wire Line
	9700 5400 10050 5400
Connection ~ 10050 5400
Wire Wire Line
	10050 5400 10050 6550
Text Notes 6300 5500 0    50   ~ 0
9V Battery\n(power system backup)
Text Notes 6450 6250 0    50   ~ 0
Jump or connect to switch -\n3rd pole of main power switch\nor alarm enable switch
Wire Wire Line
	8650 6450 8450 6450
Wire Wire Line
	8650 6200 8650 6450
Wire Wire Line
	8450 6200 8650 6200
$Comp
L Connector_Generic:Conn_01x02 J8
U 1 1 5E923EAD
P 8250 6450
F 0 "J8" H 8330 6442 50  0000 L CNN
F 1 "Conn_01x02" H 8330 6351 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 8250 6450 50  0001 C CNN
F 3 "~" H 8250 6450 50  0001 C CNN
	1    8250 6450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8650 5800 8650 5550
Connection ~ 8650 5800
Wire Wire Line
	8800 5800 8650 5800
Wire Wire Line
	8800 5850 8800 5800
$Comp
L power:GND #PWR012
U 1 1 5E982745
P 8800 5850
F 0 "#PWR012" H 8800 5600 50  0001 C CNN
F 1 "GND" H 8805 5677 50  0000 C CNN
F 2 "" H 8800 5850 50  0001 C CNN
F 3 "" H 8800 5850 50  0001 C CNN
	1    8800 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 6100 8650 5800
Wire Wire Line
	8450 6100 8650 6100
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 5E9571D4
P 8250 6100
F 0 "J7" H 8330 6092 50  0000 L CNN
F 1 "Conn_01x02" H 8330 6001 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 8250 6100 50  0001 C CNN
F 3 "~" H 8250 6100 50  0001 C CNN
	1    8250 6100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10050 6550 8450 6550
Wire Wire Line
	7600 5550 8650 5550
Text Notes 7350 6500 0    50   ~ 0
Buzzer
Text Label 2750 1850 3    50   ~ 0
p_5
Text Label 5900 2800 0    50   ~ 0
p_6
Text Label 5900 2900 0    50   ~ 0
p_7
Text Label 5900 3100 0    50   ~ 0
p_8
Text Label 5900 3200 0    50   ~ 0
p_9
Text Label 4650 6700 0    50   ~ 0
p_11
Text Label 5250 1850 1    50   ~ 0
p_13
Text Label 4150 6250 1    50   ~ 0
p_10
Wire Wire Line
	6850 2550 6850 2900
Connection ~ 6850 2900
Wire Wire Line
	6850 2900 7950 2900
Wire Wire Line
	6250 2550 6250 2800
Connection ~ 6250 2800
Wire Wire Line
	7050 2550 7050 3100
Connection ~ 7050 3100
Wire Wire Line
	7050 3100 8350 3100
Wire Wire Line
	7650 2550 7650 3200
Connection ~ 7650 3200
Wire Wire Line
	7650 3200 7600 3200
Wire Wire Line
	6250 2800 8050 2800
$Comp
L Diode:BAV756S D2
U 1 1 5EA4B7E0
P 6550 2550
F 0 "D2" H 6550 2673 50  0000 C CNN
F 1 "BAV756S" H 6550 2764 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 6550 2150 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/BAV756S_BAW56_SER.pdf" H 6550 2150 50  0001 C CNN
	1    6550 2550
	1    0    0    1   
$EndComp
$Comp
L Diode:BAV756S D3
U 1 1 5EA4EDA1
P 7350 2550
F 0 "D3" H 7350 2673 50  0000 C CNN
F 1 "BAV756S" H 7350 2764 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 7350 2150 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/BAV756S_BAW56_SER.pdf" H 7350 2150 50  0001 C CNN
	1    7350 2550
	1    0    0    1   
$EndComp
$Comp
L Diode:BAV756S D2
U 2 1 5EA57703
P 6500 3500
F 0 "D2" H 6500 3716 50  0000 C CNN
F 1 "BAV756S" H 6500 3625 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 6500 3100 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/BAV756S_BAW56_SER.pdf" H 6500 3100 50  0001 C CNN
	2    6500 3500
	1    0    0    -1  
$EndComp
$Comp
L Diode:BAV756S D3
U 2 1 5EA57FFB
P 7300 3500
F 0 "D3" H 7300 3716 50  0000 C CNN
F 1 "BAV756S" H 7300 3625 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 7300 3100 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/BAV756S_BAW56_SER.pdf" H 7300 3100 50  0001 C CNN
	2    7300 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3500 6200 2800
Wire Wire Line
	5850 2800 6200 2800
Connection ~ 6200 2800
Wire Wire Line
	6200 2800 6250 2800
Wire Wire Line
	6800 3500 6800 2900
Connection ~ 6800 2900
Wire Wire Line
	6800 2900 6850 2900
Wire Wire Line
	7000 3500 7000 3100
Connection ~ 7000 3100
Wire Wire Line
	7000 3100 7050 3100
Wire Wire Line
	7600 3500 7600 3200
Connection ~ 7600 3200
Wire Wire Line
	7600 3200 5850 3200
$Comp
L power:GND #PWR016
U 1 1 5EA7443B
P 6500 3700
F 0 "#PWR016" H 6500 3450 50  0001 C CNN
F 1 "GND" H 6505 3527 50  0000 C CNN
F 2 "" H 6500 3700 50  0001 C CNN
F 3 "" H 6500 3700 50  0001 C CNN
	1    6500 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5EA747D2
P 7300 3700
F 0 "#PWR018" H 7300 3450 50  0001 C CNN
F 1 "GND" H 7305 3527 50  0000 C CNN
F 2 "" H 7300 3700 50  0001 C CNN
F 3 "" H 7300 3700 50  0001 C CNN
	1    7300 3700
	1    0    0    -1  
$EndComp
$Comp
L Diode:BAV70W D1
U 1 1 5EA89460
P 8250 4800
F 0 "D1" H 8250 5016 50  0000 C CNN
F 1 "BAV70W" H 8250 4925 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 8250 4800 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/BAV70_SER.pdf" H 8250 4800 50  0001 C CNN
	1    8250 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 1850 9250 2350
Wire Wire Line
	7350 2350 7350 2200
Wire Wire Line
	7350 2200 6550 2200
Connection ~ 5350 2200
Wire Wire Line
	5350 2200 5350 2300
Wire Wire Line
	6550 2350 6550 2200
Connection ~ 6550 2200
Wire Wire Line
	6550 2200 5350 2200
Wire Wire Line
	4950 6800 4950 6900
$Comp
L power:GND #PWR0118
U 1 1 5EACCB5F
P 4950 6900
F 0 "#PWR0118" H 4950 6650 50  0001 C CNN
F 1 "GND" H 4955 6727 50  0000 C CNN
F 2 "" H 4950 6900 50  0001 C CNN
F 3 "" H 4950 6900 50  0001 C CNN
	1    4950 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 5450 8650 5450
$EndSCHEMATC
