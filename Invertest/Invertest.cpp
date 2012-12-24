// Invertest.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
float c[3][3];

int findcofact(float *a[])
{
	int i,j;
	//float a[3][3] = **Mat;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if (i==0)
			{
				if(j==0)
				{
					c[i][j] = (a[i+1][j+1]*a[i+2][j+2]) - (a[i+1][j+2]*a[i+2][j+1]);
				}
				if(j==1)
				{
					c[i][j] = (a[i+1][j-1]*a[i+2][j+1]) - (a[i+1][j+1]*a[i+2][j-1]);
				}
				if(j==2)
				{
					c[i][j] = (a[i+1][j-2]*a[i+2][j-1]) - (a[i+1][j-1]*a[i+2][j-2]);
				}
			}

			if (i==1)
			{
				if(j==0)
				{
					c[i][j] = (a[i-1][j+1]*a[i+1][j+2]) - (a[i-1][j+2]*a[i+1][j+1]);
				}
				if(j==1)
				{
					c[i][j] = (a[i-1][j-1]*a[i+1][j+1]) - (a[i-1][j+1]*a[i+1][j-1]);
				}
				if(j==2)
				{
					c[i][j] = (a[i-1][j-2]*a[i+1][j-1]) - (a[i-1][j-1]*a[i+1][j-2]);
				}
			}

			if (i==2)
			{
				if(j==0)
				{
					c[i][j] = (a[i-2][j+1]*a[i-1][j+2]) - (a[i-2][j+2]*a[i-1][j+1]);
				}
				if(j==1)
				{
					c[i][j] = (a[i-2][j-1]*a[i-1][j+1]) - (a[i-2][j+1]*a[i-1][j-1]);
				}
				if(j==2)
				{
					c[i][j] = (a[i-2][j-2]*a[i-1][j-1]) - (a[i-2][j-1]*a[i-1][j-2]);
				}
			}

		}
	}
	return 0;
}
/**
 * @function InverseMatrix
 * @param Mat[In] - Matrix to be converted 
 * @param IMat[out] - Inverse Matrix
 * @returns 0 on success, -1 on if the given matrix is singular matrix or not a square matrix
 */
int InverseMatrix(float *Mat[],float *IMat[])
{
	float det = 0;
	int i,j;
	findcofact(Mat);
	det = (Mat[0][0] * c[0][0]) - (Mat[0][1] * c[0][1]) + (Mat[0][2] * c[0][2]);
	if (det == 0)
		return -1;
	printf("Det %f\n",det);

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			IMat[i][j] = c[j][i]/det;

			if(1 == (i+j)%2)
				IMat[i][j] = -IMat[i][j];
		}
	}

	return 0;
}

int main(int argc, char* argv[])
{
	float *a[3],*b[3]; 
	int i,j;
	for(i=0;i<3;i++)
		a[i] = (float *)malloc(3);
	for(i=0;i<3;i++)
		b[i] = (float *)malloc(3);
	printf("hi");
	a[0][0]=1;
	a[0][1]=2;
	a[0][2]=3;
	a[1][0]=0;
	a[1][1]=1;
	a[1][2]=4;
	a[2][0]=5;
	a[2][1]=6;
	a[2][2]=0;
	if(InverseMatrix(a,b) == -1)
		return 0;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%f ",c[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%f ",b[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		free(a[i]);
		free(b[i]);
	}
	return 0;
}

