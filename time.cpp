#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	time_t tim;
	tim = time(NULL);
	cout << "Time= " << tim;
	return 0;
}