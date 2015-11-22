#ifndef CPU_h
#define CPU_h
#include "Instruction.cpp"   // to be added 

class CPU
{
public: 

	CPU(string);    // class constructor receives the file name containing assembly code to be parsed
	~CPU(); 
	// Decode function
	void Decode();      // uses buffer1 as input and stores output in buffer2 

private:
string filename; 
vector <Instruction> IM; // instruction memory of type Instruction(class)
const int RegFile_Size = 16;  // size of register file
const int DataMem_Size;      //**** 
int RegFile[RegFile_Size];             // Declaring an array for Register File 
int DataMem[DataMem_Size];          // Declaring an array for Data Memory 
int buffer1[2]; // IF/ID
int buffer2[5]; // ID/EX
int buffer3[5]; // EX/Mem
int buffer4[3]; // MEM/WB


// Decode parameters:
// inputs to the register file
	int ReadReg1;      // Read register 1 (Rs)
	int ReadReg2;      // Read register 2 (Rt)
	int WrReg;        // Write register (Rd or Rt) - passed from final buffer 
	int WrData;       // Write data 
	// output stored in buffer2 (next PC, ReadData1, ReadData2, imm, rd)
	int ReadData1;    // Read data 1 (RegFile[Rs])
	int ReadData2;    // Read data 2 (RegFile[Rt])
	int RD;       // current rd 

};
#endif