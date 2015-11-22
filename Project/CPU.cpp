#include "CPU.h"
using namespace std;
#include <iostream>

CPU::CPU(string name)    // constructor receives the file name 
{
	filename = name; 
}

CPU::~CPU()
{
}

void CPU::Decode() 
{
	Instruction Inst = buffer1[1]; 
	// Assuming all parameters of instruction (Rs,Rt,Rd,Imm are initialized to -1)
	ReadReg1 = Inst.rs;      // rs
	ReadReg2 = Inst.rt;      // rt
	ReadData1 = RegFile[ReadReg1];
	ReadData2 = RegFile[ReadReg2];

	// if R-format
	if (Inst.num == 1 | Inst.num == 3 | Inst.num == 8)  // ADD/XOR/SLT
		RD = Inst.rd;
	else // if I-format
		if (Inst.num == 2 | Inst.num == 4)   // ADDI/LW
			RD = Inst.rt;
		else
			if (Inst.num == 9) //JAL
				// RD = index of rs

	buffer2[0] = buffer1[0];
	buffer2[1] = ReadData1;
	buffer2[2] = ReadData2; 
	buffer2[3] =  Inst.imm;
	buffer2[4] = RD; 
}