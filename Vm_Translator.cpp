// Nikhil Nunna
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>
using namespace std;

void NOT(ofstream& output)
{
	output << "@SP" << endl;
	output << "A=M-1" << endl;
	output << "M=!M" << endl;
}


void NEG(ofstream& output)
{
	output << "@SP" << endl;
	output << "A=M-1" << endl;
	output << "M=-M" << endl;
}


void SUB(ofstream& output)
{
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "A=A-1" << endl;
	output << "M=M-D" << endl;

}

void ADD(ofstream& output)
{
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "A=A-1" << endl;
	output << "M=M+D" << endl;
}


void AND(ofstream& output)
{
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "A=A-1" << endl;
	output << "M=M&D" << endl;
}


void OR(ofstream& output)
{
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "A=A-1" << endl;
	output << "M=M|D" << endl;
}


int con = 0;
int counter()
{
	con++;
	return con;
}




void EQ(ofstream& output)
{
	int count = counter();
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "A=A-1" << endl;
	output << "D=M-D" << endl;
	output << "@EqualsTrue" << count << endl;
	output << "D;JEQ" << endl;
	output << "@SP" << endl;
	output << "A=M-1" << endl;
	output << "M=0" << endl;
	output << "@EqualsFalse" << count << endl;
	output << "0;JMP" << endl;
	output << "(EqualsTrue" << count << ")" << endl;
	output << "@SP" << endl;
	output << "A=M-1" << endl;
	output << "M=-1" << endl;
	output << "(EqualsFalse" << count << ")" << endl;
}

void GT(ofstream& output)
{
	int count = counter();
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "A=A-1" << endl;
	output << "D=M-D" << endl;
	output << "@GreaterThanTrue" << count << endl;
	output << "D;JGT" << endl;
	output << "@SP" << endl;
	output << "A=M-1" << endl;
	output << "M=0" << endl;
	output << "@GreaterThanFalse" << count << endl;
	output << "0;JMP" << endl;
	output << "(GreaterThanTrue" << count << ")" << endl;
	output << "@SP" << endl;
	output << "A=M-1" << endl;
	output << "M=-1" << endl;
	output << "(GreaterThanFalse" << count << ")" << endl;
}

void LT(ofstream& output)
{
	int count = counter();
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "A=A-1" << endl;
	output << "D=M-D" << endl;
	output << "@LessThanTrue" << count << endl;
	output << "D;JLT" << endl;
	output << "@SP" << endl;
	output << "A=M-1" << endl;
	output << "M=0" << endl;
	output << "@LessThanFalse" << count << endl;
	output << "0;JMP" << endl;
	output << "(LessThanTrue" << count << ")" << endl;
	output << "@SP" << endl;
	output << "A=M-1" << endl;
	output << "M=-1" << endl;
	output << "(LessThanFalse" << count << ")" << endl;
}

/////////////////PUSH////////////////////////

void PUSH_CON(ofstream& output , string num)
{
	output << "@" + num << endl;
	output << "D=A" << endl;
	output << "@SP" << endl;
	output << "AM=M+1" << endl;
	output << "A=A-1" << endl;
	output << "M=D" << endl;
}

void PUSH_LCL(ofstream& output, string num)
{
	output << "@LCL" << endl;
	output << "D=M" << endl;
	output << "@" + num << endl;
	output << "A=D+A" << endl;
	output << "D=M" << endl;
	output << "@SP" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "M=M+1" << endl;
}


void PUSH_ARG(ofstream& output, string num)
{
	output << "@ARG" << endl;
	output << "D=M" << endl;
	output << "@" + num << endl;
	output << "A=D+A" << endl;
	output << "D=M" << endl;
	output << "@SP" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "M=M+1" << endl;
}


void PUSH_THIS(ofstream& output, string num)
{
	output << "@THIS" << endl;
	output << "D=M" << endl;
	output << "@" + num << endl;
	output << "A=D+A" << endl;
	output << "D=M" << endl;
	output << "@SP" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "M=M+1" << endl;
}


void PUSH_THAT(ofstream& output, string num)
{
	output << "@THAT" << endl;
	output << "D=M" << endl;
	output << "@" + num << endl;
	output << "A=D+A" << endl;
	output << "D=M" << endl;
	output << "@SP" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "M=M+1" << endl;
}

void PUSH_STA(ofstream& output, string num, string name)
{
	output << "@" + name + "." + num << endl;
	output << "D=M" << endl;
	output << "@SP" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "M=M+1" << endl;
}

void PUSH_TEMP(ofstream& output, string num)
{
	output << "@" << 5 + stoi(num) << endl;
	output << "D=M" << endl;
	output << "@SP" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "M=M+1" << endl;
}

void PUSH_POINTER(ofstream& output, string num)
{
	if (stoi(num) == 0)
	{
		output << "@THIS" << endl;
	}
	if (stoi(num) == 1)
	{
		output << "@THAT" << endl;
	}
	output << "D=M" << endl;
	output << "@SP" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "M=M+1" << endl;
}

///////////////POP////////////////////////////
void POP_LCL(ofstream& output, string num)
{
	output << "@" + num << endl;
	output << "D=A" << endl;
	output << "@LCL" << endl;
	output << "D=M+D" << endl;
	output << "@hold" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "@hold" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
}

void POP_ARG(ofstream& output, string num)
{
	output << "@" + num << endl;
	output << "D=A" << endl;
	output << "@ARG" << endl;
	output << "D=M+D" << endl;
	output << "@hold" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "@hold" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
}

void POP_THIS(ofstream& output, string num)
{
	output << "@" + num << endl;
	output << "D=A" << endl;
	output << "@THIS" << endl;
	output << "D=M+D" << endl;
	output << "@hold" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "@hold" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
}

void POP_THAT(ofstream& output, string num)
{
	output << "@" + num << endl;
	output << "D=A" << endl;
	output << "@THAT" << endl;
	output << "D=M+D" << endl;
	output << "@hold" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "@hold" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
}


void POP_STA(ofstream& output, string num, string name)
{
	output << "@" + name + "." + num << endl;
	output << "D=A" << endl;
	output << "@hold" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "@hold" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
}

void POP_TEMP(ofstream& output, string num)
{
	output << "@" << 5 + stoi(num) << endl;
	output << "D=A" << endl;
	output << "@hold" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "@hold" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
}

void POP_POINTER(ofstream& output, string num)
{
	if (stoi(num) == 0)
	{
		output << "@THIS" << endl;
	}
	if (stoi(num) == 1)
	{
		output << "@THAT" << endl;
	}
	output << "D=A" << endl;
	output << "@hold" << endl;
	output << "M=D" << endl;
	output << "@SP" << endl;
	output << "AM=M-1" << endl;
	output << "D=M" << endl;
	output << "@hold" << endl;
	output << "A=M" << endl;
	output << "M=D" << endl;
}

string Remove_Comment(string line)
{
	string no_comment;
	int i = line.size();
	for (int k = 0; k < i; ++k)
	{
		if (line.compare(k, 1, "/"))
		{
			no_comment = no_comment + line.substr(k, 1);
		}
		else
		{
			k = i;
		}
	}
	return no_comment;
}


void VM(string input_file)
{
	string line;
	string ptline;
	ifstream in(input_file);
	ofstream out;
	string output = input_file.substr(0, input_file.find(".")) + ".asm";
	out.open(output);
	while (!in.eof())
	{
		getline(in, line);
		line = Remove_Comment(line);
		if (line != "")
		{
			//////////////////PUSH/////////////////////////////
			if (line.find("push constant") != string::npos)
			{
				ptline = line.substr(14, line.size());
				PUSH_CON(out, ptline);
			}
			if (line.find("push local") != string::npos)
			{
				ptline = line.substr(11, line.size());
				PUSH_LCL(out, ptline);
			}
			if (line.find("push argument") != string::npos)
			{
				ptline = line.substr(14, line.size());
				PUSH_ARG(out, ptline);
			}
			if (line.find("push this") != string::npos)
			{
				ptline = line.substr(10, line.size());
				PUSH_THIS(out, ptline);
			}
			if (line.find("push that") != string::npos)
			{
				ptline = line.substr(10, line.size());
				PUSH_THAT(out, ptline);
			}

			if (line.find("push static") != string::npos)
			{
				ptline = line.substr(12, line.size());
				PUSH_STA(out, ptline, input_file.substr(0, input_file.find(".")));
			}

			if (line.find("push temp") != string::npos)
			{
				ptline = line.substr(10, line.size());
				PUSH_TEMP(out, ptline);
			}

			if (line.find("push pointer") != string::npos)
			{
				ptline = line.substr(13, line.size());
				PUSH_POINTER(out, ptline);
			}


			////////////////////POP////////////////////

			if (line.find("pop local") != string::npos)
			{
				ptline = line.substr(10, line.size());
				POP_LCL(out, ptline);
			}

			if (line.find("pop argument") != string::npos)
			{
				ptline = line.substr(13, line.size());
				POP_ARG(out, ptline);
			}
			if (line.find("pop this") != string::npos)
			{
				ptline = line.substr(9, line.size());
				POP_THIS(out, ptline);
			}
			if (line.find("pop that") != string::npos)
			{
				ptline = line.substr(9, line.size());
				POP_THAT(out, ptline);
			}

			if (line.find("pop static") != string::npos)
			{
				ptline = line.substr(11, line.size());
				POP_STA(out, ptline, input_file.substr(0, input_file.find(".")));
			}

			if (line.find("pop temp") != string::npos)
			{
				ptline = line.substr(9, line.size());
				POP_TEMP(out, ptline);
			}

			if (line.find("pop pointer") != string::npos)
			{
				ptline = line.substr(12, line.size());
				POP_POINTER(out, ptline);
			}

			////////////////LOGIC//////////////////////
			if (line.find("eq") != string::npos)
			{
				EQ(out);
			}

			if (line.find("lt") != string::npos)
			{
				LT(out);
			}
			if (line.find("gt") != string::npos)
			{
				GT(out);
			}
			if (line.find("add") != string::npos)
			{
				ADD(out);
			}
			if (line.find("sub") != string::npos)
			{
				SUB(out);
			}
			if (line.find("neg") != string::npos)
			{
				NEG(out);
			}
			if (line.find("and") != string::npos)
			{
				AND(out);
			}
			if (line.find("or") != string::npos)
			{
				OR(out);
			}
			if (line.find("not") != string::npos)
			{
				NOT(out);
			}
			//cout << line << endl;
		}

	}

}

int main(int argc, char* argv[])
{
	
	string file_name1 = argv[1];
	VM(file_name1);
	return 0;
}