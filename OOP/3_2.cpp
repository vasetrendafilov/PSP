#include "iostream"
#include "string"
#include "math.h"
using namespace std;

class Point{
protected:
  float x,y;
public:
  Point(float a=0,float b=0):x(a),y(b){}//napravi default
  Point(const Point &a):x(a.x),y(a.y){}//sekogas koristi kopiconstructor
  friend ostream & operator << (ostream &out, const Point &x);
};
ostream & operator << (ostream &out, const Point &x){
  return out<<x.x<<" "<<x.y;
};

class Circle:public Point{
protected:
  float r;
public:
  Circle(float x,float y,float a):Point(x,y),r(a){}
  float P(){return 3.14*r*r;}
  friend ostream & operator << (ostream &out, const Circle &x);

};
ostream & operator << (ostream &out, const Circle &x){
  return out<<x.x<<" "<<x.y<<" "<<x.r;
}

class Sphere:public Circle{
private:
  float z;
public:
  Sphere(float x,float y,float a,float r):Circle(x,y,r),z(a){}
  float P(){ return 4*Circle::P(); }
  float V(){ return 4/3*r*r*r*3.14; }
  friend ostream & operator << (ostream &out, const Sphere &x);

};
ostream & operator << (ostream &out, const Sphere &x){
  return out<<x.x<<" "<<x.y<<" "<<x.z<<" "<<x.r;
}


int main(){
   Point a(1,2);
   Circle b(1,1,5);
    cout<<b.P()<<endl;
  return 0;
}
