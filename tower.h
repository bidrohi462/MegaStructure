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
        void drawWalls(int totalPoint,double p[][2],double height);
        void drawPolygon(int totalPoint,double p[][2]);
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

void Tower :: drawWalls(int totalPoint,double p[][2],double height)
{
    for(int i=0;i<totalPoint-1;i++)
    {
        glBegin(GL_QUADS);
        {
            glVertex3f(p[i][0],p[i][1],0);
            glVertex3f(p[i][0],p[i][1],height);
            glVertex3f(p[i+1][0],p[i+1][1],height);
            glVertex3f(p[i+1][0],p[i+1][1],0);
        }
        glEnd();
    }

}
void Tower :: drawPolygon(int totalPoint,double p[][2])
{
    glBegin(GL_POLYGON);
    for(int i=0;i<totalPoint;i++)
    {
        glVertex2f(p[i][0],p[i][1]);
    }
    glEnd();
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
        drawWalls(3,pnts1,lowerBaseHeight);

        double pnts5[][2]={
            {-lowerBaseRadius,0}
            ,{-lowerBaseRadius,-6.269}//
            ,{-lowerBaseRadius-4.790,-8}
            ,{-lowerBaseRadius-11.6,-7.411}
            ,{-lowerBaseRadius-10.842,-12.06},
        };
        drawWalls(5,pnts5,lowerBaseHeight);


/// lower layer roof starts here /////////////////////////////////////////
        glTranslatef(0,0,lowerBaseHeight);

        glColor3f(0.5,0.5,0.5);
        shapes.drawHalfCylinder(lowerBaseRadius-4.546,0.8);

        glColor3f(0.8,0.8,0);
        shapes.drawHalfCircle(lowerBaseRadius);
/// lower layer irregular shapes //////////////////////////////////////////

        drawPolygon(5,pnts1);

        double pnts2[][2]={
            {-lowerBaseRadius+4.456,0},
            {-lowerBaseRadius,0},
            {-lowerBaseRadius,-6.269},
            {-lowerBaseRadius+4.456,-10.871}
        };
        drawPolygon(4,pnts2);

        double pnts3[][2]={
            {-lowerBaseRadius,-6.269},
            {-lowerBaseRadius+4.456,-10.871},
            {-lowerBaseRadius-10.842,-12.06},
            {-lowerBaseRadius-4.790,-8}
        };
        drawPolygon(4,pnts3);

        double pnts4[][2]={
            {-lowerBaseRadius-10.842,-12.06},
            {-lowerBaseRadius-4.790,-8},
            {-lowerBaseRadius-11.6,-7.411}
        };
        drawPolygon(3,pnts4);


/// translation for upper layer
        glTranslatef(0,0,0.8);

        glColor3f(0,0.8,0);
        shapes.drawHalfCircle(lowerBaseRadius-4.456);

/// drawing irregular shaped portion in upper layer
        //glColor3f(0,0,1.0);
        glBegin(GL_POLYGON);
        {
            glVertex2f(lowerBaseRadius-4.456,0);
            glVertex2f(-lowerBaseRadius+4.456,0);
            glVertex2f(-lowerBaseRadius+4.456,-9.804);
            glVertex2f(0,-33.411);
        }
        glEnd();



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

/// roof building starts here //////////////////////////

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
/// roof building stops here ///////////////////////////
}

void Tower :: drawMajorBeams()
{
    for(int i=1;i<6;i++)
    {

    }
}
#endif // TOWER_H

