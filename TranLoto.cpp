#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define _zero	"0000"
#define _one	"0001"
#define _two	"0010"
#define _three	"0011"
#define _four	"0100"
#define _five	"0101"
#define _six	"0110"
#define _seven	"0111"
#define _eight	"1000"
#define _nine	"1001"

using namespace std;

struct LotoNumber
{
	int	Number1;
	int	Number2;
	int	Number3;
	int	Number4;
	int	Number5;
	int	Number6;
	int	SpecNumber;
};

int main(void)
{
	fstream			file;
	fstream			fileOut;
	LotoNumber		BufferNum;
	string			OpenDateBuffer;
	string			TakeDateBuffer;
	string			IDBuffer;
	ostringstream	StrOut;
	
	file.open("loto.txt", ios::in);
	fileOut.open("loto1.txt", ios::out);

	while (file >> IDBuffer >> OpenDateBuffer 
		    >> BufferNum.Number1
		    >> BufferNum.Number2
		    >> BufferNum.Number3
		    >> BufferNum.Number4
		    >> BufferNum.Number5
		    >> BufferNum.Number6
		    >> BufferNum.SpecNumber
		    >> TakeDateBuffer)
	{
		StrOut.seekp(0);
		// check open date
		for (int i = 0 ; i < 6 ; i++)
		{
			if (IDBuffer[i] == '0') StrOut << _zero;
			if (IDBuffer[i] == '1') StrOut << _one;
			if (IDBuffer[i] == '2') StrOut << _two;
			if (IDBuffer[i] == '3') StrOut << _three;
			if (IDBuffer[i] == '4') StrOut << _four;
			if (IDBuffer[i] == '5') StrOut << _five;
			if (IDBuffer[i] == '6') StrOut << _six;
			if (IDBuffer[i] == '7') StrOut << _seven;
			if (IDBuffer[i] == '8') StrOut << _eight;
			if (IDBuffer[i] == '9') StrOut << _nine;
			// cout << "strOut one = " << StrOut.str() << endl;
		}

		// loto number
		StrOut << " " << OpenDateBuffer
			   << " " << BufferNum.Number1
		       << " " << BufferNum.Number2
		       << " " << BufferNum.Number3
		       << " " << BufferNum.Number4
		       << " " << BufferNum.Number5
		       << " " << BufferNum.Number6
		       << " " << BufferNum.SpecNumber
			   << " " << TakeDateBuffer << ends;

		// fileOut write
		fileOut << StrOut.str() << endl;
	}

	file.close();
	fileOut.close();


	return 0;
}