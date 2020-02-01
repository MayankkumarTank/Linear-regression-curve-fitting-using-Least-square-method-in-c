#include <stdio.h>
#include <stdlib.h>
/*
Name : Mayankkumar Tank
Roll No. : AU1841057
*/
int main(){
	
	printf("*********************************************************************************************\n");
	printf("\n\t\t\tName : Mayankkumar Tank");
	printf("\n\t\t\tRoll : AU1841057\n");
	printf("\n*********************************************************************************************\n");
	
	int n;
	printf("Enter Total Number of points : ");
	scanf("%d",&n);
	int i,j,k;
	double A[n][3], AT[3][n], b[n][1];
	
	printf("\n*********************************************************************************************\n");
    printf("\nEnter the Height and Weight of students respectively....... : ");
    
	for (i = 0; i < n; i++)
    {
        double h,w;
        scanf("%lf %lf",&h,&w);
       
        A[i][0]=h*h; AT[0][i]=h*h;
        A[i][1]=h;   AT[1][i]=h;
        A[i][2]=1;   AT[2][i]=1;
        b[i][0]=w;
    }

    //Code of calculating AT*A which is 3x3 matrix.
    double ATA[3][3];
    for (i = 0; i < 3; i++)
    {
    	for (j = 0; j < 3; j++)
    	{
    		ATA[i][j] = 0;
    		for (k = 0; k < n; k++)
    		{
    			ATA[i][j] += AT[i][k]*A[k][j];
    		}
   		}
    }

    //Code of calculating AT*b which is 3x1 matrix.
    double ATb[3][1];
    for (i = 0; i < 3; i++)
    {
    	ATb[i][0] = 0;
    	j = 0;
    	for (k = 0; k < n; k++)
    	{
    		ATb[i][0] += AT[i][k]*b[k][j];
    	}
    }

    // x = inverseOf(ATA)*ATb
    //Code of calculating inverse of AT*A which is 3x3 matrix.
    double det = 0;
    for(i = 0; i < 3; i++)
	{
    	det = det + ( ATA[0][i] * (ATA[1][(i+1)%3] * ATA[2][(i+2)%3] - ATA[1][(i+2)%3] * ATA[2][(i+1)%3]) );
    }
   
    double inverseOfATA[3][3];
    
    for (i = 0; i < 3; i++)
    {
    	for (j = 0; j < 3; j++)
    	{
    		inverseOfATA[j][i] = ( (ATA[(i+1)%3][(j+1)%3] * ATA[(i+2)%3][(j+2)%3]) - (ATA[(i+1)%3][(j+2)%3] * ATA[(i+2)%3][(j+1)%3]) )/ det;
    	}
    }

    double coff[3];
    for (i = 0; i < 3; i++)
    {
    	coff[i] = 0;
    	int j = 0;
    	for (k = 0; k < 3; k++)
    	{
    		coff[i] += inverseOfATA[i][k]*ATb[k][j];
    	}
    }
	printf("\n*********************************************************************************************\n");
    printf("Second Degree Polynomial Equation is : y = A*x^2 + B*x + C\n");
    printf("Coefficients of this Equation  A , B , C  :- \n");
    
    printf("\t\tA = %f\n",coff[0]);
    printf("\t\tB = %f\n",coff[1]);
    printf("\t\tC = %f\n",coff[2]);
    
    float Height;
    printf("\n*********************************************************************************************\n");
    
	printf("Enter the height of the student to predict the weight : ");
    scanf("%f",&Height);
    float predictedWeight = coff[0]*Height*Height + coff[1]*Height + coff[2];
    printf("\n*********************************************************************************************\n");
    
    printf("\n\tPredicted Weight is : %f",predictedWeight);

    return 0;

}
/*

*********************************************************************************************

                        Name : Mayankkumar Tank
                        Roll : AU1841057

*********************************************************************************************
Enter Total Number of points : 19

*********************************************************************************************

Enter the Height and Weight of students respectively....... :
160 68
155 78
143 56
162 70
170 72
175 78
167 68
163 54
156 43
172 71
180 65
159 59
169 63
157 62
161 90
171 45
181 62
177 57
140 80

*********************************************************************************************
Second Degree Polynomial Equation is : y = A*x^2 + B*x + C
Coefficients of this Equation  A , B , C  :-
                A = 0.003703
                B = -1.288406
                C = 176.578090

*********************************************************************************************
Enter the height of the student to predict the weight : 185

*********************************************************************************************

        Predicted Weight is : 64.961975
--------------------------------
Process exited after 13.66 seconds with return value 0
Press any key to continue . . .*/
