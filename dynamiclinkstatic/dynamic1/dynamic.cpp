#include "dynamic.h"
#include "../staticf/static.h"

#include <iostream>

using namespace std;

void SetMyValue(){
	SetValue(1);
}

void PrintValue(){
	cout<<"print value in dynamc1:"<<GetValue()<<endl;
}