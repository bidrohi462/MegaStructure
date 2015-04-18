#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#ifndef PI
#define PI 3.14159265
#endif // PI

struct point
{
	double x,y,z;
};

class Shapes
{
    public:
        void drawsphere(float radius);
        void drawCylinder(float radius,float len);
        void drawHalfCylinder(float radius,float len);
        void drawHalfCircle(float r);
        void drawWalls(int totalPoint,double p[][2],double height);
        void drawPolygon(int totalPoint,double p[][2]);
        void drawArc(float r, float start_angle, float arc_angle, int num_segments);
        void drawCurvedWall(float r, float start_angle, float arc_angle, int num_segments,double height);
        void drawCurvedRoof(float r, float start_angle, float arc_angle, int num_segments);
        void drawArchShapeOld(float inRadius, float outRadius, float start_angle, float arc_angle, int num_segments, double thickness);
        void drawArchShape(float inRadius, float outRadius, float start_angle, float arc_angle, int num_segments, double thickness);
};

void Shapes :: drawsphere(float radius)
{
    int slices=20;
    int stacks=20;
	struct point points[100][100];
	int i,j;
	double h,r;
	for(i=0;i<=stacks;i++)
	{
		h=radius*sin(((double)i/(double)stacks)*(PI/2));
		r=sqrt(radius*radius-h*h);
		for(j=0;j<=slices;j++)
		{
			points[i][j].x=r*cos(((double)j/(double)slices)*2*PI);
			points[i][j].y=r*sin(((double)j/(double)slices)*2*PI);
			points[i][j].z=h;
		}

	}
	//int color=1;
	for(i=0;i<stacks;i++)
	{
	    //color=1-color;
		for(j=0;j<slices;j++)
		{
		    //color=1-color;
			glColor3f((double)i/(double)stacks,(double)i/(double)stacks,(double)i/(double)stacks);
			//glColor3f(color,color,color);
			glBegin(GL_QUADS);{
				glVertex3f(points[i][j].x,points[i][j].y,points[i][j].z);
				glVertex3f(points[i][j+1].x,points[i][j+1].y,points[i][j+1].z);
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,points[i+1][j+1].z);
				glVertex3f(points[i+1][j].x,points[i+1][j].y,points[i+1][j].z);

			}glEnd();
		}

	}
}


void Shapes :: drawCylinder(float radius,float len)
{
    int slices=20;
    int stacks=20;
	struct point points[100][100];
	int i,j;
	double h,r;
	for(i=0;i<=stacks;i++)
	{
		h=len*sin(((double)i/(double)stacks)*(PI/2));
		r=radius;
		for(j=0;j<=slices;j++)
		{
			points[i][j].x=r*cos(((double)j/(double)slices)*2*PI);
			points[i][j].y=r*sin(((double)j/(double)slices)*2*PI);
			points[i][j].z=h;
		}

	}
	double color=0.5;
	for(i=0;i<stacks;i++)
	{
	    for(j=0;j<slices;j++)
		{
		   glColor3f(color,color,color);
			glBegin(GL_QUADS);{
				glVertex3f(points[i][j].x,points[i][j].y,points[i][j].z);
				glVertex3f(points[i][j+1].x,points[i][j+1].y,points[i][j+1].z);
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,points[i+1][j+1].z);
				glVertex3f(points[i+1][j].x,points[i+1][j].y,points[i+1][j].z);

			}glEnd();
		}

	}
}

void Shapes :: drawHalfCylinder(float radius,float len)
{
    int slices=20;
    int stacks=20;
	struct point points[100][100];
	int i,j;
	double h,r;
	for(i=0;i<=stacks;i++)
	{
		h=len*sin(((double)i/(double)stacks)*(PI/2));
		r=radius;
		for(j=0;j<=slices;j++)
		{
			points[i][j].x=r*cos(((double)j/(double)slices)*PI);
			points[i][j].y=r*sin(((double)j/(double)slices)*PI);
			points[i][j].z=h;
		}

	}
	//double color=0.5;
	for(i=0;i<stacks;i++)
	{
	    for(j=0;j<slices;j++)
		{
            //glColor3f(color,color,color);
			glBegin(GL_QUADS);{
				glVertex3f(points[i][j].x,points[i][j].y,points[i][j].z);
				glVertex3f(points[i][j+1].x,points[i][j+1].y,points[i][j+1].z);
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,points[i+1][j+1].z);
				glVertex3f(points[i+1][j].x,points[i+1][j].y,points[i+1][j].z);

			}glEnd();
		}

	}
}

void Shapes :: drawWalls(int totalPoint,double p[][2],double height)
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
void Shapes :: drawPolygon(int totalPoint,double p[][2])
{
    glBegin(GL_POLYGON);
    for(int i=0;i<totalPoint;i++)
    {
        glVertex2f(p[i][0],p[i][1]);
    }
    glEnd();
}

void Shapes :: drawHalfCircle(float r)
{
    float cx=0, cy=0;
    int num_segments=60;
	float theta = PI / float(num_segments-1);
	float tangetial_factor = tanf(theta);//calculate the tangential factor

	float radial_factor = cosf(theta);//calculate the radial factor

	float x = r;//we start at angle = 0

	float y = 0;

    //glColor3f(0,1.0,0);
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
	for(int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex

		//calculate the tangential vector
		//remember, the radial vector is (x, y)
		//to get the tangential vector we flip those coordinates and negate one of them

		float tx = -y;
		float ty = x;

		//add the tangential vector

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		//correct using the radial factor

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
}

void Shapes :: drawArc(float r, float start_angle, float arc_angle, int num_segments)
{
    float cx=0, cy=0;

    //arc_angle = PI * arc_angle / 180.0;
	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


    //start_angle = PI * start_angle / 180.0;
	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle);

	glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	for(int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);

		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
}

void Shapes :: drawCurvedWall(float r, float start_angle, float arc_angle, int num_segments, double height)
{
    float cx=0, cy=0;

    //arc_angle = PI * arc_angle / 180.0;
	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


    //start_angle = PI * start_angle / 180.0;
	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle);

	float prevx,prevy;

	for(int i = 0; i < num_segments-1; i++)
	{
	    prevx=x;
	    prevy=y;
		glVertex2f(x + cx, y + cy);

		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;

		glBegin(GL_QUADS);
		{
            glVertex3f(prevx,prevy,0);
            glVertex3f(prevx,prevy,height);
            glVertex3f(x,y,height);
            glVertex3f(x,y,0);
		}
		glEnd();
	}
}
void Shapes :: drawCurvedRoof(float r, float start_angle, float arc_angle, int num_segments)
{
    float cx=0, cy=0;

    //arc_angle = PI * arc_angle / 180.0;
	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);

    //start_angle = PI * start_angle / 180.0;
	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle);

	//float prevx,prevy;
    glBegin(GL_POLYGON);
	for(int i = 0; i < num_segments; i++)
	{
	    //prevx=x;
	    //prevy=y;
		glVertex2f(x + cx, y + cy);

		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
}

void Shapes :: drawArchShapeOld(float inRadius, float outRadius, float start_angle, float arc_angle, int num_segments, double thickness)
{
    //float cx=0, cy=0;
    double innerShift=-2;

	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


    //start_angle = PI * start_angle / 180.0;
	float x = outRadius * cosf(start_angle);//we now start at the start angle
	float y = outRadius * sinf(start_angle);

	float inX = inRadius * cosf(start_angle);
	float inY = inRadius * sinf(start_angle);

	float prevx,prevy,prevInX,prevInY;
	double colour = 0.0;

	for(int i = 0; i < num_segments-2; i++)
	{
	    prevx=x;
	    prevy=y;

		//glVertex2f(x + cx, y + cy);
/// update outer circle
		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;

        //colour+=0.2;
        glColor3f(colour+0.2,colour+0.2,colour+0.2);
		glBegin(GL_QUADS);
		{
            glVertex3f(prevx,prevy,-thickness/2.0);
            glVertex3f(prevx,prevy,thickness/2.0);
            glVertex3f(x,y,thickness/2.0);
            glVertex3f(x,y,-thickness/2.0);
		}
		glEnd();

/// update inner circle

        prevInX=inX;
        prevInY=inY;

        glColor3f(1,0,0);
        glPushMatrix();
        {
            glTranslatef(inX -5, inY ,0);
            //drawHalfCircle(5);
        }
        glPopMatrix();
        float txin = -inY;
        float tyin = inX;
        inX += txin * tangetial_factor;
		inY += tyin * tangetial_factor;

		inX *= radial_factor;
		inY *= radial_factor;

		//colour+=0.2;
		/// inner edge
        glColor3f(colour+0.4,colour+0.4,colour+0.4);
        prevInX+=innerShift;
        inX+=innerShift;
		glBegin(GL_QUADS);
		{
            glVertex3f(prevInX,prevInY,-thickness/2.0);
            glVertex3f(prevInX,prevInY,thickness/2.0);
            glVertex3f(inX,inY,thickness/2.0);
            glVertex3f(inX,inY,-thickness/2.0);
		}
		glEnd();
		inX-=innerShift;
		prevInX-=innerShift;

/// curve side wall

        //colour+=0.2;
        glColor3f(colour+0.6,colour+0.6,colour+0.6);
        prevInX+=innerShift;
        inX+=innerShift;
		glBegin(GL_QUADS);
		{
            glVertex3f(prevInX,prevInY,-thickness/2.0);
            glVertex3f(prevx,prevy,-thickness/2.0);
            glVertex3f(x,y,-thickness/2.0);
            glVertex3f(inX,inY,-thickness/2.0);
		}
		glEnd();
		inX-=innerShift;
		prevInX-=innerShift;

		//colour+=0.2;
        glColor3f(colour+0.6,colour+0.6,colour+0.6);
        prevInX+=innerShift;
        inX+=innerShift;
		glBegin(GL_QUADS);
		{
            glVertex3f(prevInX,prevInY,thickness/2.0);
            glVertex3f(prevx,prevy,thickness/2.0);
            glVertex3f(x,y,thickness/2.0);
            glVertex3f(inX,inY,thickness/2.0);
		}
		glEnd();
		inX-=innerShift;
		prevInX-=innerShift;
	}
	static bool printed = false;
	if(!printed)
    {
            printed=true;
        	printf("x=%f,y=%f\n",x,y);
    }

}
void Shapes :: drawArchShape(float inRadius, float outRadius, float start_angle, float arc_angle, int num_segments, double thickness)
{
    float cx=0, cy=0;
    double innerShift=-2;

	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


    //start_angle = PI * start_angle / 180.0;
	float x = outRadius * cosf(start_angle);//we now start at the start angle
	float y = outRadius * sinf(start_angle);

	float inX = inRadius * cosf(start_angle);
	float inY = inRadius * sinf(start_angle);

	float prevx,prevy,prevInX,prevInY;
	double colour = 0.0;

    //glBegin(GL_LINE_STRIP);
	for(int i = 0; i < num_segments-3; i++)
	{
	    prevx=x;
	    prevy=y;

		//glVertex3f(0,y,x);

/// update outer circle
		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;

        //colour+=0.2;
        glColor3f(colour+0.2,colour+0.2,colour+0.2);
		glBegin(GL_QUADS);
		{
            glVertex3f(-thickness/2.0,prevy,prevx);
            glVertex3f(thickness/2.0,prevy,prevx);
            glVertex3f(thickness/2.0,y,x);
            glVertex3f(-thickness/2.0,y,x);
		}
		glEnd();

/// update inner circle

        prevInX=inX;
        prevInY=inY;

        glColor3f(1,0,0);
        glPushMatrix();
        {
            glTranslatef(inX -5, inY ,0);
            //drawHalfCircle(5);
        }
        glPopMatrix();
        float txin = -inY;
        float tyin = inX;
        inX += txin * tangetial_factor;
		inY += tyin * tangetial_factor;

		inX *= radial_factor;
		inY *= radial_factor;

		//colour+=0.2;
		/// inner edge
        glColor3f(colour+0.4,colour+0.4,colour+0.4);
        prevInX+=innerShift;
        inX+=innerShift;
		glBegin(GL_QUADS);
		{
            glVertex3f(-thickness/2.0,prevInY,prevInX);
            glVertex3f(thickness/2.0,prevInY,prevInX);
            glVertex3f(thickness/2.0,inY,inX);
            glVertex3f(-thickness/2.0,inY,inX);
		}
		glEnd();
		inX-=innerShift;
		prevInX-=innerShift;

/// curve side wall

        //colour+=0.2;
        glColor3f(colour+0.6,colour+0.6,colour+0.6);
        prevInX+=innerShift;
        inX+=innerShift;
		glBegin(GL_QUADS);
		{
            glVertex3f(-thickness/2.0,prevInY,prevInX);
            glVertex3f(-thickness/2.0,prevy,prevx);
            glVertex3f(-thickness/2.0,y,x);
            glVertex3f(-thickness/2.0,inY,inX);
		}
		glEnd();
		inX-=innerShift;
		prevInX-=innerShift;

		//colour+=0.2;
        glColor3f(colour+0.6,colour+0.6,colour+0.6);
        prevInX+=innerShift;
        inX+=innerShift;
        glBegin(GL_QUADS);
		{
            glVertex3f(thickness/2.0,prevInY,prevInX);
            glVertex3f(thickness/2.0,prevy,prevx);
            glVertex3f(thickness/2.0,y,x);
            glVertex3f(thickness/2.0,inY,inX);
		}
		glEnd();
        /*
		glBegin(GL_QUADS);
		{
            glVertex3f(prevInX,prevInY,thickness/2.0);
            glVertex3f(prevx,prevy,thickness/2.0);
            glVertex3f(x,y,thickness/2.0);
            glVertex3f(inX,inY,thickness/2.0);
		}
		glEnd();
		*/
		inX-=innerShift;
		prevInX-=innerShift;

	}
	// glEnd();
/// lower irregular part

    double yTrans = 62;
    double minHeight = 50;
    double span = 8.850;

    glPushMatrix();
    {
        //drawHalfCircle(14.5);
        glTranslatef(0,yTrans,0);
        //glTranslatef(0,2*yTrans,0);
        //yTrans=0;

        //glColor3f(1.0,0,0);
    /// pair /////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        {
            glVertex3f(-thickness/2.0,y-yTrans,x);
            glVertex3f(-thickness/2.0,0,-minHeight);
            glVertex3f(-thickness/2.0,0,-minHeight+span);
            glVertex3f(-thickness/2.0,inY-yTrans,inX-2.0);
        }
        glEnd();

        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        {
            glVertex3f(thickness/2.0,y-yTrans,x);
            glVertex3f(thickness/2.0,0,-minHeight);
            glVertex3f(thickness/2.0,0,-minHeight+span);
            glVertex3f(thickness/2.0,inY-yTrans,inX-2.0);
        }
        glEnd();
    /// pair /////////////////////////////////////////////////////////////////
        glColor3f(0,1.0,0);
        glBegin(GL_POLYGON);
        {
            glVertex3f(thickness/2.0,y-yTrans,x);
            glVertex3f(-thickness/2.0,y-yTrans,x);
            glVertex3f(-thickness/2.0,0,-minHeight);
            glVertex3f(thickness/2.0,0,-minHeight);
        }
        glEnd();
        glColor3f(0,0,1.0);
        glBegin(GL_POLYGON);
        {
            glVertex3f(thickness/2.0,inY-yTrans,inX-2.0);
            glVertex3f(-thickness/2.0,inY-yTrans,inX-2.0);
            glVertex3f(-thickness/2.0,0,-minHeight+span);
            glVertex3f(thickness/2.0,0,-minHeight+span);
        }
        glEnd();
        //drawHalfCircle(14.5);
        /// end of the arch attached to base
        glPushMatrix();
        {
            double slope = (x+minHeight)/(y-yTrans);
            double zz = -77 ;
            double xx =(zz+minHeight)/slope-7;
            //xx=-25;

            //glRotatef(14,0,0,1);
            double shiftX = 0;
            glColor3f(0,0.5,1.0);
            glBegin(GL_LINE_LOOP);
            {
                glVertex3f(thickness/2.0+shiftX,xx,zz);
                glVertex3f(-thickness/2.0+shiftX,xx,zz);
                glVertex3f(-thickness/2.0,0,-minHeight+span);
                glVertex3f(thickness/2.0,0,-minHeight+span);
            }
            glEnd();

            xx+=10;
            glBegin(GL_POLYGON);
            {
                glVertex3f(thickness/2.0,xx,zz);
                glVertex3f(-thickness/2.0,xx,zz);
                glVertex3f(-thickness/2.0,0,-minHeight);
                glVertex3f(thickness/2.0,0,-minHeight);
            }
            glEnd();
        }
        glPopMatrix();
    }
    glPopMatrix();
    //glTranslatef(0,0,-72);
    //drawHalfCircle(10);

	static bool printed = false;
	if(!printed)
    {
            printed=true;
        	printf("z=%f,y=%f,inz=%f,iny=%f\n",x,y,inX,inY);
        	printf("y-ytrans=%f,iny-ytras=%f\n",y-yTrans,inY-yTrans);
    }

}

#endif // PRIMITIVES_H

