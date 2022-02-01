//  PenProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <iostream>
#include "pen.h"


int main(){
	Pen teo, josie;

	teo.setInkColor(blue);
	josie.setInkColor(black);

	teo.setInkLevel(100);
	josie.setInkLevel(50);

	teo.setpentype(marker);
	josie.setpentype(ballpoint);

	teo.setpenquantity(5);
	josie.setpenquantity(10);

	teo.setshellcolor(black);
	josie.setshellcolor(green);

	teo.setpenbrand("sharpie");
	josie.setpenbrand("friction");

	teo.showinfo();
	josie.showinfo();

	return 0;
}
