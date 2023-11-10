
#include <iostream>
#include <string>
#include <fstream>
struct figa {
    int st;
    figa(int st) :st(st){};
};
struct Line:figa {
    int x1;
    int y1;
    int x2;
    int y2;
    Line(int x1, int y1, int x2,int y2,int st) : x1(x1), y1(y1), x2(x2), y2(y2),figa(st){};
};
std::ostream& operator<<(std::ostream& os, const Line& l) {
    os << "<line x1=\"" << l.x1 << "\" y1=\"" << l.y1 << "\" x2=\"" << l.x2 << "\" y2=\"" << l.y2 
        << "\" stroke=\"black\" stroke-width=\""<<l.st<<"\" />";
    return os;
}

struct Circle:figa {
    int x;
    int y;
    int r;
    std::string fill;
    double opacity;
    Circle(int x, int y, int r, std::string fill, double opacity, int st) : x(x), y(y), r(r), fill(fill), opacity(opacity),figa(st) {};

};
std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "<circle cx=\"" << circle.x << "\" cy=\"" << circle.y << "\" r=\"" << circle.r
        << "\" fill=\"" << circle.fill << "\" stroke-width=\"" << circle.st << "\" stroke=\"black\" opacity=\""<< circle.opacity << "\" />";
    return os;
}

struct Polyline {
    int x1, x2, x3, y1, y2, y3;
    std::string fill;
    double opacity;
};
std::ostream& operator<<(std::ostream& os, const Polyline& polyline) {
       os << "<polyline points=\"" << polyline.x1 << " " << polyline.y1 << ","
           << polyline.x2 << " " << polyline.y2 << ","
           << polyline.x3 << " " << polyline.y3 << "\" fill=\"" << polyline.fill
           << "\" opacity=\"" << polyline.opacity << "\" />";
        return os;
}


int main() {
    std::ofstream f("pain.svg");
    f << "<svg width = \"1458\" height = \"820\" viewBox = \"0 -0 1458 820\" xmlns = \"http://www.w3.org/2000/svg\" xmlns:xlink = \"http://www.w3.org/1999/xlink\">"
        << "<g opacity = \"1\">"
        << "<rect x = \"0\" y = \"0\" width = \"1458\" height = \"820\" fill = \"white\" stroke-width = \"4\" stroke = \"black\" />";
    Circle c( 729,410,675,"black",1,7);
    f << c;
    c = { 729,410,625,"white",1,7 };
    f << c;
    Polyline p = { 0,820,1300,-200,200,820,"orange",0.5 };
    f << p;
    p = { 1300,900,300,-200,1450,820,"blue",0.5 };
    f << p;
    c = { 700,430,200,"lime",0.8,0 };
    f << c;
    c = { 900,380,180,"green",0.8,0 };
    f << c;
    c = { 729,190,100,"red",0.8,0 };
    f << c;
    c = { 600,150,140,"pink",0.8,0 };
    f << c;

    Line l = { 250,100,1150,220,7};
    f << l;
    l = { 200,400,1200,600,7};
    f << l;
    l = { 300,650,750,50,7};
    f << l;
    l = { 550,750,980,0,7};
    f << l;
    c = { 879,169,50,"black",1,0};
    f << c;
    f << "</g> </svg>";

    f.close();
    return 0;
}