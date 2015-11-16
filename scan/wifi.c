#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ROW 10
#define COL 4

typedef struct data
{
     double AP1;//HCL-404
     double AP2;//E403
     double AP3;//E406
     //double AP4;//Randy
     /* Add a new Access Point below */
     double AP5;//ICL3
     double AP6;//Lab411
     char *pos;

}data;

int main(int argc, char *argv[])
{
    int i;
    int j;
    int icount = 0;
    int jcount = 0;
    /* define the user enter */
    double t1,t2,t3,t4,t5,t6;

    FILE *fPtr;
    fPtr = fopen("/home/pi/scan/test.txt", "r");

    /* if (fPtr) {
        printf("Success to read the Database\n\n");
    }
    else {
        printf("Fail to read the Database!");
    }*/

    struct data database[ROW][COL] = {0};// y x
	double test[ROW][COL] = {0};// y x
	double temp = 0;



     database[0][0].pos = "HCL404 to LIN YUNG SIN";
     database[0][1].pos = "HCL404 to ZHAN HONG";
     database[1][0].pos = "HCL404 to LIU WEI CHENG";
     database[1][1].pos = "HCL404 to LU HANG TING";
     database[1][2].pos = "HCL404 Door";
     database[2][0].pos = "E403 TO 2 0";
     database[2][1].pos = "E403 TO 2 1";
     database[2][2].pos = "E403 TO 2 2";
     database[3][0].pos = "E403 TO 3 0";
     database[3][1].pos = "E403 TO 3 1";
     database[3][2].pos = "E403 DOOR";
     database[4][2].pos = "E406 TO 4 2";
     database[5][3].pos = "E406 TO YEH CHUN YEN";
     database[5][2].pos = "ICL3 E406 DOOR";
     database[8][0].pos = "sidewalk to E411";
     database[7][2].pos = "LU HUANG DOOR";
     database[8][1].pos = "sidewalk to paper";
     database[8][3].pos = "sidewalk to meeting";
     database[9][3].pos = "meeting";
	 
	 


    for( i = 0;i<ROW;i++)
    {
            for( j = 0;j < COL;j++)
            {

                fscanf(fPtr,"%lf %lf %lf %lf %lf",&database[i][j].AP1,&database[i][j].AP2,&database[i][j].AP3,&database[i][j].AP5,&database[i][j].AP6);
                /*printf("[%d,%d] = AP1-> %.3lf AP2-> %.3lf AP3-> %.3lf AP4-> %.3lf AP5-> %.3lf\n",i,j,database[i][j].AP1,database[i][j].AP2,database[i][j].AP3,database[i][j].AP4,database[i][j].AP5);
*/
            }
    }
		//printf("\n");

    	/* transform */
    	 for( i = 0;i<ROW;i++)
    	{
            for( j = 0;j < COL;j++)
            {       //avoid calculating error we use 101 minus the values of APs
                    database[i][j].AP1 = 101 - database[i][j].AP1;
                    database[i][j].AP2 = 101 - database[i][j].AP2;
                    database[i][j].AP3 = 101 - database[i][j].AP3;
                    //database[i][j].AP4 = 101 - database[i][j].AP4;
                    database[i][j].AP5 = 101 - database[i][j].AP5;
                    database[i][j].AP6 = 101 - database[i][j].AP6;
            }
    	}
		//while(1)
		//{
			//printf("Please input test: ");

			//while (scanf("%lf %lf %lf %lf lf",&t1,&t2,&t3,&t4,&t5)!=EOF)
			//{
				t1 =  (float)atoi(argv[1]); 
				t2 =  (float)atoi(argv[2]); 
				t3 =  (float)atoi(argv[3]); 
				//t4 =  (float)atoi(argv[4]); 
				t5 =  (float)atoi(argv[4]);
				t6 =  (float)atoi(argv[5]);

				//scanf("%lf %lf %lf %lf lf",&t1,&t2,&t3,&t4,&t5);
				
 				t1 = 101 - t1;
 				t2 = 101 - t2;
 				t3 = 101 - t3;
 				//t4 = 101 - t4;
				t5 = 101 - t5;
                t6 = 101 - t6;

    			for( i=0; i<ROW; i++)
				{
					for( j=0; j<COL; j++)
					{   //KNN with k = 1
						test[i][j] = pow(fabs(1/t1-1/database[i][j].AP1),2) + pow(fabs(1/t2-1/database[i][j].AP2),2)+ pow(fabs(1/t3-1/database[i][j].AP3),2) + pow(fabs(1/t5-1/database[i][j].AP5),2) + pow(fabs(1/t6-1/database[i][j].AP6),2);
						//printf("[%d,%d] = %11.8lf\n",i,j,test[i][j]);
					}
				}

				/* init the temp */
				temp = test[0][0];
				/* find the position */
				for( i=0; i<ROW; i++)
				{
					for( j=0; j<COL; j++)
					{
		  				if(temp>=test[i][j])
						{
							temp = test[i][j];
			 				icount = i;
							jcount = j;
						/* printf("%d %d ",icount,jcount); */
						}/* if end */
					}/* second for end */
				}/* first for end */
					//printf("The position of min = [%d,%d]\n %s\n",icount,jcount,database[icount][jcount].pos);
				    //	printf("%s\n",database[icount][jcount].pos);
                                  

                                         printf("%d %d\n",icount,jcount);

			//}/* second while end */
		//}/* first while end */
		
		fclose(fPtr);

    
    return 0;

}


