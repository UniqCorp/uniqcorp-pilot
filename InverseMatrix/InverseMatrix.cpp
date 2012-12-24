/*
 * Copyright (c) 2012
 * UniqCorp Technologies (I)Pvt Limited.
 */

#include "InverseMatrix.h"

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


