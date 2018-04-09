#include "fileSystem.h"

void main()
{
	cout << "FileSystem beta1.0" << endl; 
	loadSuper("vm.dat");
	root = iget(0);
	while (!login())
	{
		NULL;
	}
	current = root;
	while (!logout)
	{
		dispatcher();
	}
}