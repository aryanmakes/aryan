/* 
Name : SAYYAD HUJEFA AYUB
Class : SE AIML 
RollNO :- 39
Problem Statement:  Implement the C program for Page Replacement Algorithms: FCFS, LRU, and Optimal for 
frame size as minimum three.
*/
 #include<stdio.h>
 int main()
 {
 int q[20],p[50],c=0,c1,d,f,i,j,k=0,n,r,t,b[20],c2[20];
 printf("Enter no of pages:");
 scanf("%d",&n);
 printf("Enter the reference string:");
 for(i=0;i<n;i++)
            scanf("%d",&p[i]);
 printf("Enter no of frames:");
 scanf("%d",&f);
 q[k]=p[k];
 printf("\n\t%d\n",q[k]);
 c++;
 k++;
 for(i=1;i<n;i++)
            {
                        c1=0;
                        for(j=0;j<f;j++)
                        {
                                    if(p[i]!=q[j])
                                    c1++;
                        }
                        if(c1==f)
                        {
                                    c++;
                                    if(k<f)
                                    {
                                                q[k]=p[i];
                                                k++;
                                                for(j=0;j<k;j++)
                                                printf("\t%d",q[j]);
                                                printf("\n");
                                    }
                                    else
                                    {
                                                for(r=0;r<f;r++)
                                                {
                                                            c2[r]=0;
                                                            for(j=i-1;j<n;j--)
                                                            {
                                                            if(q[r]!=p[j])
                                                            c2[r]++;
                                                            else
                                                            break;
                                                }
                                    }
                                    for(r=0;r<f;r++)
                                     b[r]=c2[r];
                                    for(r=0;r<f;r++)
                                    {
                                                for(j=r;j<f;j++)
                                                {
                                                            if(b[r]<b[j])
                                                            {
                                                                        t=b[r];
                                                                        b[r]=b[j];
                                                                        b[j]=t;
                                                            }
                                                }
                                    }
                                    for(r=0;r<f;r++)
                                    {
                                                if(c2[r]==b[0])
                                                q[r]=p[i];
                                                printf("\t%d",q[r]);
 }
                                    printf("\n");
                        }
            }
 }
 printf("\nThe no of page faults is %d\n",c);
 }
 /*
 error@DESKTOP-OFL03QL:~/OS code$ gcc LRU.c -o abc
error@DESKTOP-OFL03QL:~/OS code$ ./abc
Enter no of pages:10
Enter the reference string:3 2 1 4 3 2 1 6 7 4
Enter no of frames:4

        3
        3       2
        3       2       1
        3       2       1       4
        3       2       1       6
        7       2       1       6
        7       4       1       6

The no of page faults is 7
 */