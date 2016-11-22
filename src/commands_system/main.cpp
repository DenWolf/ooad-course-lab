#define _CRTDBG_MAP_ALLOC 1
#include <stdlib.h>
#include <crtdbg.h>


#include "utils/Test.h"

#include "view/imp/HTTPView.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_WNDW);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_WNDW);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_WNDW);

	#if COMPILE_WITH_TESTS
	Test::All();
	#endif


	cout << "ctrl+c to stop" << endl;
	{
	  HTTPView view;
		view.server();
	}
	cout << "stopped" << endl;

	return 0;
}

