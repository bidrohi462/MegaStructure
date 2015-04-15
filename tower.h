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
        void drawSingleBeam();
        void drawMajorBeams();
        void drawBeamDetailsHalf();
        void drawBeamDetails();
        void drawUpperConeHalf();
        void drawUpperCone();

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
    drawUpperCone();
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
/// curved wall building
    shapes.drawCurvedWall(24.139,-atan(21.136/11.660),-2*atan(11.660/21.136),8,upperBaseHeight);
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

    double pnts5[][2]={
        {-x[6],y[6]},
        {-x[7],y[7]},
        {x[7],y[7]},
        {x[6],y[6]}
    };
    shapes.drawPolygon(4,pnts5);
    shapes.drawCurvedRoof(24.138,-atan(21.136/11.660),-2*atan(11.660/21.136),8);

/// roof building stops here ///////////////////////////
}

void Tower :: drawSingleBeam()
{
    double pnts[][2]={
        {2.62,0}
        ,{9.22,0}
        ,{0,2.9}
        };
    double hexgnSide = (pnts[1][0]-pnts[0][0])/2.0;
    double tilt=2.1;
    glPushMatrix();
    {
        glRotatef(-tilt,0,1,0);
        glTranslatef(pnts[0][0]+hexgnSide,0,0.1);
        glColor3f(0,0.2,0);

        glRotatef(180,0,0,1);
        for(int i=0;i<4;i++)
        {
            glColor3f(0.15*i,0.15*i,0.15*i);
            glRotatef(60,0,0,1);
            glBegin(GL_QUADS);
            {
                glVertex3f(hexgnSide,0,0);
                glVertex3f(hexgnSide,0,beamHeight);
                glVertex3f(hexgnSide * 0.5 ,hexgnSide * 0.866 ,beamHeight);
                glVertex3f(hexgnSide * 0.5 ,hexgnSide * 0.866 ,0);
            }
            glEnd();
        }
/// inner blank portion start here ///////////////////////////////////

        //hexgnSide-=1.0;
        for(int i=0;i<2;i++)
        {
            glColor3f(0.15*i,0.15*i,0.15*i);
            //glColor3f(0,1.0,0);
            glRotatef(60,0,0,1);
            glBegin(GL_QUADS);
            {
                glVertex3f(hexgnSide,0,0);
                glVertex3f(hexgnSide,0,beamHeight);
                glVertex3f(hexgnSide * 0.5 ,hexgnSide * 0.866 ,beamHeight);
                glVertex3f(hexgnSide * 0.5 ,hexgnSide * 0.866 ,0);
            }
            glEnd();
        }
        //hexgnSide+=1.0;

/// inner blank ends //////////////////////////////////////////////////
        glTranslatef(0,0,beamHeight-.5);
        glPushMatrix();
        {
            glRotatef(5,0,1,0);
            glRotatef(60,0,0,1);
            hexgnSide-=0.05;
            for(int i=0;i<2;i++)
            {
                glColor3f(0.3*i,0.3*i,0.3*i);
                //glColor3f(0,0.8,0);
                glRotatef(60,0,0,1);
                glBegin(GL_QUADS);
                {
                    glVertex3f(hexgnSide,0,22.097);
                    glVertex3f(hexgnSide,0,0);
                    glVertex3f(hexgnSide * 0.5 ,hexgnSide * 0.866 ,0);
                    glVertex3f(hexgnSide * 0.5 ,hexgnSide * 0.866 ,22.097);
                }
                glEnd();
            }
            hexgnSide+=0.05;
        }
        glPopMatrix();
    }
    glPopMatrix();

}

void Tower :: drawMajorBeams()
{
    glPushMatrix();
    {
        drawSingleBeam();
        glRotatef(180,0,0,1);
        drawSingleBeam();
    }
    glPopMatrix();
    drawBeamDetails();
}

void Tower :: drawBeamDetailsHalf()
{
    double circleRadius = 0.4;
    double h1 = 63.137;
    double h2 = 7.810;
    double h3= 100.021-h1-h2;
    double h4 = 100.021;
    double h5 = 121.95;
    double pnts1[][2]={
        {0.64,0.46}
    };
    double pnts2[][2]={
        {1.4,2.7}
    };
    /*
    double pnts3[][2]={
        {1.65,2.9}
    };
    */
    double pnts4[][2]={
        //{0.617,2.143}
        {0.617,2.25}
    };

    double pnts5[][2]={
                    {-circleRadius,0}
                    ,{-circleRadius*0.75,0.66 * circleRadius}
                    ,{-circleRadius/2.0,0.866 * circleRadius}
                    ,{0,circleRadius}
                    ,{circleRadius/2.0,0.866 * circleRadius}
                    ,{circleRadius*0.75,0.66 * circleRadius}
                    ,{circleRadius,0}
            };
    double pnts6[4][2];
    pnts6[0][0]=2.8;
    pnts6[0][1]=0;
    pnts6[1][0]=(pnts6[0][0]+.428)*cos(PI*67.0/180.0);
    pnts6[1][1]=(pnts6[0][0]+.428)*sin(PI*60.0/180.0);
    pnts6[2][0]=-pnts6[1][0];
    pnts6[2][1]=pnts6[1][1];
    pnts6[3][0]=-pnts6[0][0];
    pnts6[3][1]=0;

    double pnts7[][3]={
        //{3.85,pnts2[0][1]+0.2,h3-2.1+2.4}
        {3.85,pnts2[0][1]+0.13,h3-2.1+2.4}
    };
    glPushMatrix();
    {
        glColor3f(0,1.0,0);

        glTranslatef(0,0,h1);
        glColor3f(1.0,0,0);
        glBegin(GL_QUADS);
        {
            glVertex3f(-pnts1[0][0],pnts1[0][1],0);
            glVertex3f(pnts1[0][0],pnts1[0][1],0);
            glVertex3f(pnts1[0][0],0,0);
            glVertex3f(-pnts1[0][0],0,0);
        }
        glEnd();

/// tilted side wall /////////////////////////////////////////////////

        glColor3f(0.9,0.9,0.2);
        glBegin(GL_QUADS);
        {
            glVertex3f(pnts2[0][0],pnts2[0][1],h2);
            glVertex3f(pnts1[0][0],pnts1[0][1],0);
            glVertex3f(-pnts1[0][0],pnts1[0][1],0);
            glVertex3f(-pnts2[0][0],pnts2[0][1],h2);
        }
        glEnd();

        glTranslatef(0,0,h2);
        glColor3f(0.5,0.5,0.5);

/// tilted side wall end //////////////////////////////////////////////////

/// intrusion and curved wall ///////////////////////////////////////////////
        glTranslatef(0,0,.01);
        glBegin(GL_QUADS);
        {
            glVertex3f(pnts2[0][0]/2,pnts2[0][1],h3+.15);
            glVertex3f(pnts2[0][0],pnts2[0][1],0);
            glVertex3f(-pnts2[0][0],pnts2[0][1],0);
            glVertex3f(-pnts2[0][0]/2,pnts2[0][1],h3+.15);
        }
        glEnd();
/// /////////////////////////////////////////////////////////////////

        h3+=2.4;
        glPushMatrix();
        {
            glTranslatef(0,pnts2[0][1],h3);
            glRotatef(90,1,0,0);

            /// half circle shape floor
            glColor3f(0.5,0.5,0.5);
            shapes.drawPolygon(7,pnts5);

            /// half circle shape wall
            glColor3f(0,0,0);
            shapes.drawWalls(7,pnts5,-0.2);

            //glColor3f(0,0,1.0);
            glBegin(GL_QUADS);
            {
                glVertex3f( circleRadius ,0, 0);
                glVertex3f( circleRadius ,0,-0.2);
                glVertex3f( pnts4[0][0]  ,-pnts4[0][1],-0.2);
                glVertex3f( pnts4[0][0]  ,-pnts4[0][1],0);
            }
            glEnd();

            glBegin(GL_QUADS);
            {   //edit
                glVertex3f( -circleRadius ,0, 0);
                glVertex3f( -circleRadius ,0,-0.2);
                glVertex3f( -pnts4[0][0]  ,-pnts4[0][1],-0.2);
                glVertex3f( -pnts4[0][0]  ,-pnts4[0][1],0);
            }
            glEnd();

            glColor3f(0.5,0.5,0.5);
            glBegin(GL_QUADS);
            {
                glVertex3f( circleRadius ,0, 0);
                glVertex3f( -circleRadius ,0,0);
                glVertex3f( -pnts4[0][0] ,-pnts4[0][1],0);
                glVertex3f( pnts4[0][0]  ,-pnts4[0][1],0);
            }
            glEnd();
        }
        glPopMatrix();

        glColor3f(0.7,0.7,0.7);
        glBegin(GL_POLYGON);
        {
            glVertex3f(0,pnts2[0][1]+0.2,h3+pnts5[6][0]);
            glVertex3f(-pnts6[1][0],pnts2[0][1],h5-h4+h3-2.4);
            glVertex3f(pnts6[1][0],pnts2[0][1],h5-h4+h3-2.4);
        }
        glEnd();

/// three thin strips from half circle wall //////////////////////////////////
        for( int i=0;i<3;i++)
        {
            glBegin(GL_POLYGON);
            {
                glVertex3f(pnts5[i][0],pnts2[0][1]+0.2,h3+pnts5[i][1]);
                glVertex3f(pnts5[i+1][0],pnts2[0][1]+0.2,h3+pnts5[i+1][1]);
                glVertex3f(-pnts6[1][0],pnts2[0][1],h5-h4+h3-2.4);
            }
            glEnd();
        }
        for( int i=0;i<3;i++)
        {
            glBegin(GL_POLYGON);
            {
                glVertex3f(-pnts5[i][0],pnts2[0][1]+0.2,h3+pnts5[i][1]);
                glVertex3f(-pnts5[i+1][0],pnts2[0][1]+0.2,h3+pnts5[i+1][1]);
                glVertex3f(+pnts6[1][0],pnts2[0][1],h5-h4+h3-2.4);
            }
            glEnd();
        }

/// pair /////////////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        {
            glVertex3f(-pnts5[0][0],pnts2[0][1]+0.2,h3+pnts5[0][1]);
            glVertex3f(pnts7[0][0],pnts7[0][1],pnts7[0][2]);
            glVertex3f(pnts6[1][0],pnts2[0][1],h5-h4+h3-2.4);
        }
        glEnd();
        glBegin(GL_POLYGON);
        {
            glVertex3f(pnts5[0][0],pnts2[0][1]+0.2,h3+pnts5[0][1]);
            glVertex3f(-pnts7[0][0],pnts7[0][1],pnts7[0][2]);
            glVertex3f(-pnts6[1][0],pnts2[0][1],h5-h4+h3-2.4);
        }
        glEnd();

/// pair ///////////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        {
            glVertex3f(-pnts5[0][0],pnts2[0][1]+0.2,h3+pnts5[0][1]);
            glVertex3f(pnts7[0][0],pnts7[0][1],pnts7[0][2]);
            glVertex3f(pnts4[0][0],pnts2[0][1]+0.2,h3-pnts4[0][1]);
        }
        glEnd();
        glBegin(GL_POLYGON);
        {
            glVertex3f(pnts5[0][0],pnts2[0][1]+0.2,h3+pnts5[0][1]);
            glVertex3f(-pnts7[0][0],pnts7[0][1],pnts7[0][2]);
            glVertex3f(-pnts4[0][0],pnts2[0][1]+0.2,h3-pnts4[0][1]);
        }
        glEnd();
    }
    glPopMatrix();
}

void Tower :: drawBeamDetails()
{
    glPushMatrix();
    {
        drawBeamDetailsHalf();
        glRotatef(180,0,0,1);
        drawBeamDetailsHalf();
    }
    glPopMatrix();
}
void Tower :: drawUpperConeHalf()
{
/// lower hexagon co-ordinates //////////////////////////////////
    double pnts1[4][2];
    pnts1[0][0]=2.8;
    pnts1[0][1]=0;
    pnts1[1][0]=(pnts1[0][0]+.428)*cos(PI*67.0/180.0);
    pnts1[1][1]=(pnts1[0][0]+.428)*sin(PI*60.0/180.0);
    pnts1[2][0]=-pnts1[1][0];
    pnts1[2][1]=pnts1[1][1];
    pnts1[3][0]=-pnts1[0][0];
    pnts1[3][1]=0;

/// upper hexagon co-ordinates ///////////////////////////////////
    double pnts2[4][2];
    pnts2[0][0]=.09;
    pnts2[0][1]=0;
    pnts2[1][0]=(pnts2[0][0])*cos(PI*60.0/180.0);
    pnts2[1][1]=(pnts2[0][0])*sin(PI*60.0/180.0);
    pnts2[2][0]=-pnts2[1][0];
    pnts2[2][1]=pnts2[1][1];
    pnts2[3][0]=-pnts2[0][0];
    pnts2[3][1]=0;

    double coneHeight=38.0;

    glPushMatrix();
    {
        glTranslatef(0,0,121.95);
        glColor3f(0.5,0.5,0.5);

        for(int i=0;i<3;i++)
        {
            glColor3f(i*0.2,i*0.2,i*0.2);
            glBegin(GL_QUADS);
            {
                glVertex3f(pnts2[i][0],pnts2[i][1],coneHeight);
                glVertex3f(pnts1[i][0],pnts1[i][1],0);
                glVertex3f(pnts1[i+1][0],pnts1[i+1][1],0);
                glVertex3f(pnts2[i+1][0],pnts2[i+1][1],coneHeight);
            }
            glEnd();
        }

        glTranslatef(0,0,38);
        glColor3f(0,1.0,0);
        shapes.drawPolygon(4,pnts2);
    }
    glPopMatrix();
}
void Tower :: drawUpperCone()
{
    glPushMatrix();
    {
        drawUpperConeHalf();
        glRotatef(180,0,0,1);
        drawUpperConeHalf();
    }

    glPopMatrix();
    /*
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    gluCylinder(quadratic,0.1f,5.0f,10.0f,4,4);
    */
}
#endif // TOWER_H

