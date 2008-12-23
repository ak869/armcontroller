// TestVC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#import "..\AnvizOcx\Debug\AnvizOcx.tlb"
using namespace AnvizOcxLib;
int _tmain(int argc, _TCHAR* argv[])
{
	long ret;
	CoInitialize(NULL);
	try
	{
		IAMJ03Ptr machine(__uuidof(AMJ03));
		IDoorGroupsPtr dgs;
		machine->get_DoorGroups(&dgs);
		dgs->get_Count(&ret);
	}
	catch (const _com_error& Err)
	{
		std::cout << "Error: " << Err.ErrorMessage() << "\n";
	}
	catch (...)
	{
		std::cout << "Unexpected Error\n";
	}
	return 0;
}

