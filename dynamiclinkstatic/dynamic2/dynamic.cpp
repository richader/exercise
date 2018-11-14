#include "dynamic.h"
#include "../staticf/static.h"

#include <iostream>

using namespace std;

void SetMyValue(){
	SetValue(2);
}

void PrintValue(){
	cout<<"print value in dynamc2:"<<GetValue()<<endl;
}