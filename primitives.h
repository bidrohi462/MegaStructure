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
	double color=0.5;
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

	float prevx,prevy;
    glBegin(GL_POLYGON);
	for(int i = 0; i < num_segments; i++)
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
	}
	glEnd();
}
#endif // PRIMITIVES_H

