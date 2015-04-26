#ifndef CUSTOMTYPES_H
#define CUSTOMTYPES_H

struct Point3{
    double x;
    double y;
    double z;
    Point3(){}
    Point3(double a, double b, double c){x=a;y=b;z=c;}

    void set(double a, double b, double c){x=a;y=b;z=c;}
    void set(Point3 a){x=a.x;y=a.y;z=a.z;}
};
typedef Point3 Point3;
struct Vector3{
    double x;
    double y;
    double z;
    Vector3(){}
    Vector3(double a, double b, double c){x=a;y=b;z=c;}

    void set(double a, double b, double c){x=a;y=b;z=c;}
    void set(Vector3 a){x=a.x;y=a.y;z=a.z;}
    Vector3 operator-(){Vector3 a(-x,-y,-z);return a;}
    double dot(Vector3 a);//prototype
    Vector3 cross(Vector3 a);//prototype
    void normalize();//prototype
    double getMagnitude();
};
typedef Vector3 Vector3;
double Vector3 :: dot(Vector3 a)
{
    return (x*a.x + y*a.y + z*a.z);

}
Vector3 Vector3:: cross(Vector3 a)
{
    a.set(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
    return a;
}
void Vector3:: normalize()
{
    double d=sqrt(x*x+y*y+z*z);
    this->set(x/d,y/d,z/d);
}

double Vector3:: getMagnitude()
{
    return sqrt(x*x+y*y+z*z);
}

#endif // CUSTOMTYPES_H
