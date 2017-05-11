    #include <iostream>
    #include <iomanip>
    #include <algorithm>
    using namespace std;

    int main()

    {
        //Variables for storing elements
        double matrix[3][3];
        double inversediagmatrix[3];
        double phiDQ [3];
        double sumofphiDQ=0;
        double ans[3];
        //Variables for iterations
        int i, j,k,l,m,n,o;
        int numofiter; 
        int userinput;
        //Variables to store and allow steady state calculations
        double steadystatein [3]={1,0,0};
        double steadystateout [3]= {0,0,0};
        double temp [3] = {0,0,0};
        int row1sum=0;
        int row2sum=0;
        int row3sum=0;
        //Variables for iteration/ tracking
        int count =1;
        int count2 = 1;

        //Get Matrix from user
        for (i =0; i <3; i++)
            {
                for(j=0;j<3;j++)
                    {
                        cout << "Enter Matrix a" << i << ','<<j<<" :";
                        cin >> matrix[i][j];
                    }
            }

            //Create Inverse Diagonal Matrix
            for (i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {   if(i==j)
                    {
                        
                        inversediagmatrix[i] =-1/matrix[i][j];
                    }

                }
            }
            //Obtain sum of each row in Matrix
        for (k=0; k<3; k++)
            {
                if (count==1)
                {
                    for (l=0;l<3;l++)
                    {   if (k == l)
                        {;}
                        else
                        row1sum = row1sum + matrix[k][l];
                    }
                }
                        else
                        if (count==2)
                {
                    for (m=0;m<3;m++)
                    {
                        if (k == m)
                        {;}
                        else
                        row2sum = row2sum + matrix[k][m];
                    }
                }
                        else
                        if (count==3)
                {
                    for (n=0;n<3;n++)
                    {
                        if (k == n)
                        {;}
                        else
                        row3sum = row3sum + matrix[k][n];
                    }
                }
                    count++;
            }
            //Create S Matrix
            for (k=0; k<3; k++)
            {
                for(o=0;o<3;o++)
                {
                    if(count2 == 1)
                    {
                        if (k ==o)
                        {
                            matrix[k][o]=0;
                        }
                        else
                        matrix[k][o] = matrix[k][o]/row1sum;
                    }
                        if(count2 == 2)
                    {
                        if (k ==o)
                        {
                            matrix[k][o]=0;
                        }
                        else
                        matrix[k][o] = matrix[k][o]/row2sum;
                    }
                        if(count2 == 3)
                    {
                        if (k ==o)
                        {
                            matrix[k][o]=0;
                        }
                        else
                        matrix[k][o] = matrix[k][o]/row3sum;
                    }
                }
                count2++;
            }
               //Iterative Steady State 
                cout << "How many iterations for steady state distribution? (100 is always a good choice)";
                cin >> userinput;

                //Steady state calculations and swapping
            for (numofiter=0;numofiter<= userinput; numofiter++)
            { 
                for (j=0;j<3;j++)
                {   
                    for (i=0;i<3;i++)
                    {   
                    steadystateout[j]=steadystatein[i]*matrix[i][j]+steadystateout[j];
                    }
                }
            
                copy(begin(steadystateout), end(steadystateout), begin(temp));
                for (int reset=0; reset<3;reset++)
                {
                    steadystateout[reset]=0;
                }
                copy(begin(temp), end(temp),begin(steadystatein));
            }
            //Phi DQ calculation
            for(i=0;i<3;i++)
            {
                phiDQ[i] = inversediagmatrix[i]*steadystatein[i];
            }
            //Sum of PhiDQ
            for(i=0;i<3;i++)
            {
                sumofphiDQ = sumofphiDQ + phiDQ[i];
            }
            //Answer Calculation
            for(i=0;i<3;i++)
            {
                ans[i] = phiDQ[i]/sumofphiDQ;
            }
                //Print out of calculation results
                cout << "Steady State Distribution:" << "(";
                for (i =0; i <3; i++)
                {
                    for(j=0;j<3;j++)
                        {
                            if (i==j)
                            cout << setprecision(3)<<steadystatein[i]<<' ';
                        }
                        
                }
                cout << ")" << endl;
                cout << "Solution is:" << "(";

                for (i =0; i <3; i++)
                {
                    for(j=0;j<3;j++)
                        {
                            if (i==j)
                            cout << setprecision(3)<<ans[i]<<' ';
                        }
                        
                }
                cout << ")";

                cin.get();
                return 0;
        }

