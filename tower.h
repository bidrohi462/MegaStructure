#ifndef TOWER_H
#define TOWER_H

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
        void drawMajorBeams();
    public:
        Tower();
        void drawTower();

};

Tower :: Tower()
{
    lowerBaseRadius=16.930;
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
        glTranslatef(0,0,lowerBaseHeight);
        glColor3f(0.8,0,0);
        shapes.drawHalfCircle(lowerBaseRadius);

        glColor3f(0.5,0.5,0.5);
        shapes.drawHalfCylinder(lowerBaseRadius-4.546,0.8);
        glPushMatrix();{
            glTranslatef(0,0,0.8);
            glColor3f(0.9,0,0);
            shapes.drawHalfCircle(lowerBaseRadius-4.456);
        }glPopMatrix();

    }glPopMatrix();
}

void Tower :: drawUpperBase()
{
    glTranslatef(0,-8.0,lowerBaseHeight+0.85);
    glColor3f(0.5,1.0,1.0);
    //draw half of the upper base
    double x[]={5.247,13.017,11.15,10.33,
                7.753,6.835,5.804,11.660,0};
    double y[]={14.0,0,-2.623,-10.461,
                -12.385,-10.927,-11.589,-21.136,-24.890};

/// building side walls
    glBegin(GL_QUADS);
    {
        glVertex3f(x[0],y[0],0);
        glVertex3f(x[0],y[0],upperBaseHeight);
        glVertex3f(-x[0],y[0],upperBaseHeight);
        glVertex3f(-x[0],y[0],0);
    }
    glEnd();
    for(int i=0;i<8;i++)
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
    for(int i=0;i<8;i++)
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

    glTranslatef(0,0,upperBaseHeight);
    glColor3f(1.0,0,0);
    glBegin(GL_LINE_LOOP);
    {
        for(int i=0;i<9;i++)
        {
            glVertex2f(x[i],y[i]);
        }
        for(int i=1;i<9;i++)//skip repeated last point
        {
            glVertex2f(-x[8-i],y[8-i]);
        }
    }
    glEnd();
}

void Tower :: drawMajorBeams()
{
    for(int i=1;i<6;i++)
    {

    }
}
#endif // TOWER_H

