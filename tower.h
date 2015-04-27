#ifndef TOWER_H
#define TOWER_H

#include <cmath>
#include "primitives.h"
#include "texture.h"

class Tower
{
    private:
        Shapes shapes;
        Texture tr;
        double lowerBaseHeight;
        double lowerBaseRadius;
        double upperBaseHeight;
        double railingRadius;
        double railingHeight;
        double beamHeight;
        double coneStartingHeight;
        void drawLowerBase();
        void drawUpperBase();
        void drawSingleBeam();
        void drawMajorBeams();
        void drawBeamDetailsHalf();
        void drawBeamDetails();
        void drawUpperConeHalf();
        void drawUpperCone();
        void drawSingleArch(double thickness, bool beam);
        void drawArch();
        void drawRoundedBeam(double radius, double angle, int slices);
        void drawBeams(int count);

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
    coneStartingHeight=121.95;
    railingRadius = 0.1;
    railingHeight=1.065;
}

void Tower :: drawTower()
{
    drawLowerBase();
	drawUpperBase();
    drawMajorBeams();
    drawUpperCone();
    drawArch();
    ///
    /// comment by bidrohi
    /// shapes.drawRoundedBeam(20.0, 120.0, 15);
    ///
    //drawBeams(12);
}

void Tower :: drawLowerBase()
{
    glColor3f(0.5,0.5,0.5);
    shapes.drawHalfCylinder(lowerBaseRadius,lowerBaseHeight);
    glPushMatrix();{
        glColor3f(0.7,0.7,0.7);
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
        double pnts7[][2]={
            {-lowerBaseRadius+4.456,0}
            ,{-lowerBaseRadius+4.456,-10}
        };

        glColor3f(0.8,0.8,0.8);
        shapes.drawWalls(2,pnts7,0.8);

        glColor3f(0.5,0.5,0.5);
        shapes.drawHalfCylinder(lowerBaseRadius-4.456,0.8);

        glColor3f(0.8,0.8,0.8);
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
        //shapes.drawHalfCircle(20);
/// circular railing //////////////////////////////////////////
        int lowRailCount = 30;
        double rotAng=180.0/lowRailCount;
        glColor3f(0.5,0.5,0.5);

        glPushMatrix();
        {
            for(int i=0;i<lowRailCount-1;i++)
            {
                glRotatef(rotAng,0,0,1);
                glPushMatrix();
                {
                    glTranslatef(lowerBaseRadius-4.6,0,0);
                    glColor3f(0.5,0.5,0.5);
                    shapes.drawVertRailing(0,0,0,railingRadius,railingHeight+0.1);
                    glPushMatrix();
                    {

                        glTranslatef(0,0,railingHeight+0.1);
                        glColor3f(0.5,0.5,0.5);
                        shapes.drawHorzRailing(0,0,
                                (lowerBaseRadius-4.6)*(1-cos(rotAng*PI/180))-0.16,
                                (lowerBaseRadius-4.6)*(sin(rotAng*PI/180)),
                                railingRadius);
                    }
                    glPopMatrix();
                }
                glPopMatrix();

            }
        }
        glPopMatrix();

        lowRailCount=6;
        double segLen = (pnts7[0][1]+9.807)/lowRailCount;
        glPushMatrix();
        {
            glTranslatef(-lowerBaseRadius+4.6,segLen,0);
            for(int i=0;i<lowRailCount+1;i++)
            {
                glTranslatef(0,-segLen,0);
                shapes.drawVertRailing(0,0,0,
                                   railingRadius,railingHeight+0.1);

                if(i==lowRailCount)break;
                glPushMatrix();
                {
                    glTranslatef(0,0,railingHeight+0.1);
                    shapes.drawHorzRailing(0,0,0,-segLen,railingRadius);
                }
                glPopMatrix();
            }
        }
        glPopMatrix();

        glColor3f(0.8,0.8,0.8);
        shapes.drawHalfCircle(lowerBaseRadius-4.456);

/// drawing irregular shaped portion in upper layer
        //glColor3f(0.8,0.8,0.8);
        double pnts6[][2]={
            {lowerBaseRadius-4.456,0}
            ,{-lowerBaseRadius+4.456+1.369,-10}
            //,{-lowerBaseRadius+4.456,-9.804}
            //,{-lowerBaseRadius+4.456,-10}
            ,{0,-33.411}
        };
        shapes.drawPolygon(3,pnts6);
        double pnts8[][2]={
            {lowerBaseRadius-4.456,0}
            ,{-lowerBaseRadius+4.456,0}
            ,{-lowerBaseRadius+4.456,-10}
            ,{-lowerBaseRadius+4.456+1.369,-10}
        };
        shapes.drawPolygon(4,pnts8);
        double pnts9[][2]={
            {-lowerBaseRadius+4.456,-10}
            ,{-lowerBaseRadius+4.456+1.369,-10}
        };
        glColor3f(0.5,0.5,0.5);
        shapes.drawWalls(2,pnts9,-0.8);
        int totalStairStep = 5;
        double stairTrans = -0.8/totalStairStep;
        double stairWidth = 2.57/totalStairStep;

        double shiftune = 5.0;

        double slop = (-10+33.411)/(-lowerBaseRadius+4.456+1.369);
        glColor3f(0,0,0);

        glPushMatrix();
        {
            glTranslatef(0,2*stairWidth,0);
            glColor3f(0.8,0.8,0.8);
            glBegin(GL_POLYGON);
                {
                    glVertex3f(-lowerBaseRadius+shiftune-stairWidth,slop*(-lowerBaseRadius+shiftune)-33.411,0);
                    glVertex3f(-lowerBaseRadius+shiftune-stairWidth,slop*(-lowerBaseRadius+shiftune)-33.411,stairTrans);
                    glVertex3f(-stairWidth,-33.411,stairTrans);
                    glVertex3f(-stairWidth,-33.411,0);
                }
                glEnd();
            //glTranslatef(0,stairWidth,0);
            for(int i=0;i<totalStairStep-1;i++)
            {
                //glTranslatef(0,-stairWidth,stairTrans);
                glTranslatef(0,-stairWidth,stairTrans);
                glColor3f(0.3,0.3,0.3);
                glBegin(GL_POLYGON);
                {
                    glVertex3f(-lowerBaseRadius+shiftune,
                               slop*(-lowerBaseRadius+shiftune)-33.411,0);
                    glVertex3f(-lowerBaseRadius+shiftune-stairWidth,
                        slop*(-lowerBaseRadius+shiftune)-33.411,0);
                    glVertex3f(-stairWidth,-33.411,0);
                    glVertex3f(0,-33.411,0);
                }
                glEnd();

                glColor3f(0.8,0.8,0.8);
                glBegin(GL_POLYGON);
                {
                    glVertex3f(-lowerBaseRadius+shiftune-stairWidth,slop*(-lowerBaseRadius+shiftune)-33.411,0);
                    glVertex3f(-lowerBaseRadius+shiftune-stairWidth,slop*(-lowerBaseRadius+shiftune)-33.411,stairTrans);
                    glVertex3f(-stairWidth,-33.411,stairTrans);
                    glVertex3f(-stairWidth,-33.411,0);
                }
                glEnd();
            }

        }
        glPopMatrix();

    }glPopMatrix();
}

void Tower :: drawUpperBase()
{
    glTranslatef(2,-4.8,lowerBaseHeight+0.85);
    glRotatef(30,0,0,1);
    glColor3f(0.1,0.5,0.5);
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
    glColor3f(0.7,0.7,0.7);

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


/// railings of upper base ////////////////////////////

    glPushMatrix();
    {
        //glTranslatef(.5,2.4,-1.0);
        glTranslatef(0,3,-1.0);
        //shapes.drawHalfCircle(13.8);
        glRotatef(4,0,0,1);
        glColor3f(1,1,1);
        shapes.drawRoundPipe(13.8,0.424,190,50);
    }
    glPopMatrix();
    double pnts6[][2]={
        {x[0]-railingRadius,y[0]-railingRadius}
        ,{x[1]-railingRadius*1.5,y[1]}
        ,{x[2]-railingRadius,y[2]}
        ,{x[3]-railingRadius,y[3]+railingRadius}
        ,{x[4]-railingRadius,y[4]+railingRadius}
    };

    glColor3f(0.5,0.5,0.5);

    /// vertical railings
    for(int i=0;i<4;i++)
    {
        shapes.drawVertRailing(pnts6[i][0],pnts6[i][1],0,railingRadius,railingHeight);
        shapes.drawVertRailing(-pnts6[i][0],pnts6[i][1],0,railingRadius,railingHeight);
    }
    int segments=10;
    double railGap=pnts6[0][0]*2/segments;
    double segX=railGap;
    double segY=0.0;

    /// intermediate railings start ////////////////////////////////////
    for(int i=1;i<segments;i++)
    {
        shapes.drawVertRailing(-pnts6[0][0]+i*segX,pnts6[0][1],0,
                               railingRadius,railingHeight);
    }
    /// pair ////////////////////////////////////////////////////////////
    for(int i=0;i<3;i++)
    {
        double ang;
        int sign = 1;
        ang = atan((pnts6[i+1][1]-pnts6[i][1])/(pnts6[i+1][0]-pnts6[i][0]));
        segX = railGap*cos(ang);
        segY = railGap*sin(ang);
        //printf("ang=%lf,segx=%lf,segy=%lf\n",ang,segX,segY);
        segments = (pnts6[i+1][0]-pnts6[i][0])/segX;
        if(segments<0)
        {
            segments=-segments;
            sign = -1;
        }
        //printf("segment %d\n",segments);
        for(int j=1;j<segments;j++)
        {
            shapes.drawVertRailing(pnts6[i][0]+sign*j*segX,
                                   pnts6[i][1]+sign*j*segY,0,
                                   railingRadius,railingHeight);
        }
    }
    for(int i=0;i<3;i++)
    {
        double ang;
        int sign = -1;
        ang = atan((pnts6[i+1][1]-pnts6[i][1])/(pnts6[i+1][0]-pnts6[i][0]));
        segX = railGap*cos(ang);
        segY = railGap*sin(ang);
        //printf("ang=%lf,segx=%lf,segy=%lf\n",ang,segX,segY);
        segments = (pnts6[i+1][0]-pnts6[i][0])/segX;
        if(segments<0)
        {
            segments=-segments;
            sign = 1;
        }
        //printf("segment %d\n",segments);
        for(int j=1;j<segments;j++)
        {
            shapes.drawVertRailing(-pnts6[i][0]+sign*j*segX,
                                   pnts6[i][1]-sign*j*segY,0,
                                   railingRadius,railingHeight);
        }
    }
    /// pair end //////////////////////////////////////////////////////
    /// intermediate railings end here /////////////////////////////////
    /// horizontal railings start //////////////////////////////////////
    glPushMatrix();
    {
        glTranslatef(0,0,railingHeight);
        for(int i=0;i<4;i++)
        {
                shapes.drawHorzRailing(pnts6[i][0],pnts6[i][1],
                                   pnts6[i+1][0],pnts6[i+1][1],
                                   railingRadius);
        }
        for(int i=0;i<4;i++)
        {
                shapes.drawHorzRailing(-pnts6[i][0],pnts6[i][1],
                                   -pnts6[i+1][0],pnts6[i+1][1],
                                   railingRadius);
        }
        shapes.drawHorzRailing(pnts6[0][0],pnts6[0][1],
                                   -pnts6[0][0],pnts6[0][1],
                                   railingRadius);
    }
    glPopMatrix();
/// railings end here //////////////////////////////////////////////
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
void Tower :: drawSingleArch(double thickness, bool beam=false)
{
    /// marker starts
    double arcStartHeight = 23;
    double arcEndHeight = 122;

    glPushMatrix();
    {
        glColor3f(0,0.7,0);
        glTranslatef(0,0,23);
        shapes.drawHalfCircle(10);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glColor3f(0,0.7,0);
        glTranslatef(0,0,116);
        //shapes.drawHalfCircle(10);
    }
    glPopMatrix();
    /// marker ends

    //double radius = 126.5;
    double radius = 80;
    double span = (arcEndHeight-arcStartHeight)/2.0;
    //double stAng = -21.37;
    //double stAng = asin(span/radius)*180/PI;
    double stAng = asin(span/radius);
    //double x = span * tan(stAng);
    //double x = span * tan(PI*stAng/180.0);
    glPushMatrix();
    {
        glColor3f(1.0,1.0,0);

        //glRotatef(-35,0,0,1);
        glTranslatef(0,0,(arcStartHeight+arcEndHeight)/2.0);
        shapes.drawHalfCircle(14.5);
        glTranslatef(0,-sqrt(radius*radius-span*span),0);
        //shapes.drawHalfCircle(15);
        glColor3f(1,0,0);

        /// comment out this for drawArchShapeOld
        //glRotatef(-90,0,1,0);

        //glRotatef(20,0,0,1);
        //shapes.drawArc(50,20*PI/180.0,120*PI/180.0,10);
        //shapes.drawHalfCircle(radius);
        //shapes.drawArc(radius,(90-stAng)*PI/180.0,2*stAng*PI/180.0,10);
        //shapes.drawCurvedWall(radius,(90-stAng)*PI/180.0,2*stAng*PI/180.0,10,thickness);
        //shapes.drawArchShape(radius-3,radius,(90-stAng)*PI/180.0,2*stAng*PI/180.0,10,thickness);
        shapes.drawArchShape(radius-3,radius,(PI/2.0-stAng),2*stAng,12,thickness,beam);

/// lower irregular part of the arch
/*
        double yTrans = +sqrt(radius*radius-span*span);

        double x=-28.612865;
        double y= 85.330551;
        double inX=-29.659113;
        double inY= 82.486206;
        glTranslatef(0,yTrans,0);
        //glColor3f(0,1,1);
        //shapes.drawHalfCircle(10);

        glBegin(GL_POLYGON);
        {
            glVertex3f(-thickness/2.0,y-yTrans,x);
            glVertex3f(-thickness/2.0,0,-span);
            glVertex3f(-thickness/2.0,0,-span+8.850);
            glVertex3f(-thickness/2.0,inY-yTrans,inX);
        }
        glEnd();
*/


    }
    glPopMatrix();
}
void Tower :: drawArch()
{
    double ang = 40;
    glPushMatrix();
    {
        glRotatef(-ang,0,0,1);
        drawSingleArch(1, true);
        glRotatef(2*ang,0,0,1);
        drawSingleArch(1);
    }
    glPopMatrix();
}

void Tower::drawRoundedBeam(double radius, double angle, int slices) {
	double angle_inc=angle/(double)slices;
	double slice_size=M_PI*radius/180*angle_inc;

	glPushMatrix(); {
		glRotatef((180.0-angle)/2, 0, 0, -1);
		glTranslatef(-radius, 0, 0);
		glRotatef(90.0, -1, 0, 0);
		glPushMatrix(); {
			for(int i=0; i<slices; i++) {
				shapes.drawCylinder(0.5, slice_size);
				glTranslatef(-1.0, 0, slice_size);
				glRotatef(angle_inc, 0, 1, 0);
				glTranslatef(1.0, 0, 0);
			}
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Tower::drawBeams(int count)
{
	//glTranslatef(0, 0, 45);
	//glRotatef(5, 0, 0, -1);
	//glTranslatef(10, 10, 0);
	//drawRoundedBeam(6.0, 120.0, 15);
}

#endif // TOWER_H
