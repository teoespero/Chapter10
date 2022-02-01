#pragma once

using namespace std;

enum Color {
    blue,
    red,
    black,
    green,
    orange,
    violet
};

enum PenType {
    ballpoint,
    marker,
    fountainpen
};

class Pen {
public:
    Color InkColor;
    Color ShellColor;
    PenType Style;

    int inklevel;
    string penbrand;
    int howmanypens;

    void checkinklevel() {
        if (inklevel <= 100) {
            cout << "Lots of ink available..." << endl;
        }
        else if (inklevel <= 50) {
            cout << "50% or less left..." << endl;
        }
        else if (inklevel <= 25) {
            cout << "50% or less left..." << endl;
        }
        else if (inklevel <= 0) {
            cout << "Empty..." << endl;
        }
    }
    
    void setInkColor(Color colortoadd) {
        InkColor = colortoadd;
    }

    void setInkLevel(int inkleveltoadd) {
        inklevel = inkleveltoadd;
    }

    void setpentype(PenType typeofpen) {
        Style = typeofpen;
    }

    void setpenquantity(int quantity) {
        howmanypens = quantity;
    }

    void setshellcolor(Color casing) {
        ShellColor = casing;
    }

    void setpenbrand(string thebrand) {
        penbrand = thebrand;
    }

    string getcolor(Color thecolor) {
        if (thecolor == 0)
            return "blue";
        else if (thecolor == 1)
            return "red";
        else if (thecolor == 2)
            return "black";
        else if (thecolor == 3)
            return "green";
        else if (thecolor == 4)
            return "orange";
        else if (thecolor == 5)
            return "violet";
        else
            return "invalid color set";
    }

    void showinfo() {
        cout << endl << endl;
        cout << "brand....." << penbrand << endl;
        cout << "case color....." << getcolor(ShellColor) << endl;
        cout << "ink color....." << getcolor(InkColor) << endl;
        cout << "ink level....." << inklevel<< endl;
        cout << "remarks: ";
        checkinklevel();
        cout << "quantity....." << howmanypens << endl;

    }

};

