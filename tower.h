#ifndef TOWER_H
#define TOWER_H


#include <cmath>
#include "primitives.h"

class Tower
{
    private:
        Shapes shapes;
        double lowerBaseHeight;
        double lowerBaseRadius;
        double upperBaseHeight;
        double beamHeight;
        void drawLowerBase();
        void drawUpperBase();
        double calcCurvPoints();
        void drawMajorBeams();

    public:
        Tower();
        void drawTower();
};

Tower :: Tower()
{
    lowerBaseRadius=18.816;
    lowerBaseHeight=2.5;
    upperBaseHeight=4.179;
    beamHeight=100.021;

}

void Tower :: drawTower()
{
    drawLowerBase();
    drawUpperBase();
    drawMajorBeams();
}



void Tower :: drawLowerBase()
{
    glColor3f(0.5,0.5,0.5);
    shapes.drawHalfCylinder(lowerBaseRadius,lowerBaseHeight);
    glPushMatrix();{
        glColor3f(0,0,0.5);
        double pnts1[][2]={
            {lowerBaseRadius,0}
            ,{lowerBaseRadius+19.169,-10.871}
            ,{lowerBaseRadius+14.5,-16.546}
            ,{lowerBaseRadius-7,-13.250}
            ,{lowerBaseRadius-4.456,0}
        };
        shapes.drawWalls(3,pnts1,lowerBaseHeight);

        double pnts2[][2]={
            {-lowerBaseRadius,0}
            ,{-lowerBaseRadius,-6.269}//
            ,{-lowerBaseRadius-4.790,-8}
            ,{-lowerBaseRadius-11.6,-7.411}
            ,{-lowerBaseRadius-10.842,-12.06},
        };
        shapes.drawWalls(5,pnts2,lowerBaseHeight);


/// lower layer roof starts here /////////////////////////////////////////
        glTranslatef(0,0,lowerBaseHeight);

        glColor3f(0.5,0.5,0.5);
        shapes.drawHalfCylinder(lowerBaseRadius-4.546,0.8);

        glColor3f(0.8,0.8,0);
        shapes.drawHalfCircle(lowerBaseRadius);
/// lower layer irregular shapes //////////////////////////////////////////

        shapes.drawPolygon(5,pnts1);

        double pnts3[][2]={
            {-lowerBaseRadius+4.456,0},
            {-lowerBaseRadius,0},
            {-lowerBaseRadius,-6.269},
            {-lowerBaseRadius+4.456,-10.871}
        };
        shapes.drawPolygon(4,pnts3);

        double pnts4[][2]={
            {-lowerBaseRadius,-6.269},
            {-lowerBaseRadius+4.456,-10.871},
            {-lowerBaseRadius-10.842,-12.06},
            {-lowerBaseRadius-4.790,-8}
        };
        shapes.drawPolygon(4,pnts4);

        double pnts5[][2]={
            {-lowerBaseRadius-10.842,-12.06},
            {-lowerBaseRadius-4.790,-8},
            {-lowerBaseRadius-11.6,-7.411}
        };
        shapes.drawPolygon(3,pnts5);


/// translation for upper layer
        glTranslatef(0,0,0.8);

        glColor3f(0,0.8,0);
        shapes.drawHalfCircle(lowerBaseRadius-4.456);

/// drawing irregular shaped portion in upper layer
        //glColor3f(0,0,1.0);
        double pnts6[][2]={
            {lowerBaseRadius-4.456,0}
            ,{-lowerBaseRadius+4.456,0}
            ,{-lowerBaseRadius+4.456,-9.804}
            ,{0,-33.411}
        };
        shapes.drawPolygon(4,pnts6);

    }glPopMatrix();


}

void Tower :: drawUpperBase()
{
    glTranslatef(2,-4.8,lowerBaseHeight+0.85);
    glRotatef(30,0,0,1);
    glColor3f(0.5,1.0,1.0);
    //draw half of the upper base
    double x[]={5.247,13.017,11.15,10.33,
                7.753,6.835,5.804,11.660,0};
    double y[]={14.0,0,-2.623,-10.461,
                -12.385,-10.927,-11.589,-21.136,-24.890};

/// building side walls //////////////////////////////////////////
    glBegin(GL_QUADS);
    {
        glVertex3f(x[0],y[0],0);
        glVertex3f(x[0],y[0],upperBaseHeight);
        glVertex3f(-x[0],y[0],upperBaseHeight);
        glVertex3f(-x[0],y[0],0);
    }
    glEnd();
    for(int i=0;i<7;i++)
    {
        glBegin(GL_QUADS);
        {
            glVertex3f(x[i],y[i],0);
            glVertex3f(x[i],y[i],upperBaseHeight);
            glVertex3f(x[i+1],y[i+1],upperBaseHeight);
            glVertex3f(x[i+1],y[i+1],0);
        }
        glEnd();
    }
    for(int i=1;i<8;i++)
    {
        glBegin(GL_QUADS);
        {
            glVertex3f(-x[8-i],y[8-i],0);
            glVertex3f(-x[8-i],y[8-i],upperBaseHeight);
            glVertex3f(-x[7-i],y[7-i],upperBaseHeight);
            glVertex3f(-x[7-i],y[7-i],0);
        }
        glEnd();
    }
/// side walls built ////////////////////////////////

/// roof building starts here //////////////////////////

    glTranslatef(0,0,upperBaseHeight);
    glColor3f(1.0,0,0);

    double pnts1[][2]={

        {-x[0],y[0]},
        {-x[1],y[1]},
        {-x[2],y[2]},
        {x[2],y[2]},
        {x[1],y[1]},
        {x[0],y[0]}
    };
    shapes.drawPolygon(6,pnts1);

    double pnts2[][2]={
        {-x[2],y[2]},
        {-x[5],y[5]},
        {x[5],y[5]},
        {x[2],y[2]}
    };
    shapes.drawPolygon(4,pnts2);

    double pnts3[][2]={
        {-x[2],y[2]},
        {-x[3],y[3]},
        {-x[4],y[4]},
        {-x[5],y[5]},
        {x[5],y[5]},
        {x[4],y[4]},
        {x[3],y[3]},
        {x[2],y[2]}
    };
    shapes.drawPolygon(4,pnts3);
    glPushMatrix();
    {
        glRotatef(180,0,1,0);
        shapes.drawPolygon(4,pnts3);
    }
    glPopMatrix();
    double pnts4[][2]={
        {-x[6],y[6]},
        {-x[5],y[5]},
        {x[5],y[5]},
        {x[6],y[6]}
    };
    shapes.drawPolygon(4,pnts4);

    shapes.drawArc(24.138,-atan(21.136/11.660),-2*atan(11.660/21.136),8);

/// roof building stops here ///////////////////////////
}
void Tower :: drawMajorBeams()
{
    for(int i=1;i<6;i++)
    {

    }
}
#endif // TOWER_H

