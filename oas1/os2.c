/*rollno=44   name=anurag   Q.1=Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries.
Since there 
can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone 
gets a fair share of his time.
 He will log into the system from 10am to 12am only. He wants to have separate requests 
queues for students and faculty, where faculty quese is given a higher priority.
 Implement a strategy for the same. 

The summary at the end of the session should include the total time he spent on handling queries and average
query time.
*/



#include<stdio.h>

#include<string.h>

#include<pthread.h>



int stud_size=0,tech_size=0;

int check=0;

int min_av_student=1000,stud_loc,min_turn=100;

int min_av_teacher=1000,tech_loc;


//Burst_time
    int r_time;     
//Remaining burst time
    int ar_time;  
//arrival time of quere
    char person_name[20]; 
  //Name of the counsumer
    int turn;     
  //repeation record
};


{
    printf("sr_no.\tName\t\tPosition\tArrival_time\tRemaining_Burst_time\tturn\n");
  
  char buff[20];
  
  if(a[0].priority==1)
       
 strcpy(buff,"Student");
  
  else
        strcpy(buff,"Teacher");  
  

    for(int i=0;i<size;i++)

    {
        
        printf("%-6d  %-15s %-15s %-15d %-15d %-10d\n",i+1,a[i].person_name,buff,a[i].ar_time,a[i].bt_time,a[i].turn);
    }


}


//funtion will find the best nxt student quere for execution check both arrival time , burst time and repeation of queres 
void pro_min_student()
{min_av_student=1000;
   
 min_turn=10;
  
  for(int i=0;i<stud_size;i++)
  
  {
        if(stud_que[i].bt_time>0 && min_turn>stud_que[i].turn)
  
      if(min_av_student>=stud_que[i].ar_time)
     
   {
                min_av_student=stud_que[i].ar_time;
        
        stud_loc=i;
             
   min_turn=stud_que[i].turn;

             
  // printf("%d",stud_loc);
                //printf("yp\n");
        }

    }

  
 // cout<<stud_que[stud_loc].person_name<<endl;
}


//funtion will find the best nxt teacher quere for execution check both arrival time , burst time and repeation of queres 
void pro_min_teacher()
{
    min_av_teacher=1000;
    min_turn=10;
    for(int i=0;i<tech_size;i++)
    {   
        if(tech_que[i].bt_time>0)
        if(min_av_teacher>=tech_que[i].ar_time && min_turn>stud_que[i].turn)
        {
                min_av_teacher=tech_que[i].ar_time;
                tech_loc=i;
                min_turn=tech_que[i].turn;
                //printf("yoo\n");
        }

    }
    //cout<<tech_que[tech_loc].person_name<<endl;
}

//function will remove the specified node fromm the que array
void remove_element(struct que * temp)
{
    int i=0;
    if(temp->priority==2)
    {   
        while(&stud_que[i]!=temp)
            i++;

        if(i!=stud_size)
            while(i<stud_size-1)
            {   
                strcpy(stud_que[i].person_name,stud_que[i+1].person_name);
                stud_que[i].ar_time=stud_que[i+1].ar_time;
                stud_que[i].bt_time=stud_que[i+1].bt_time;
                i++;
            }
    
    //else
            stud_size--;
    }
 
   if(temp->priority==1)
    {   
        while(&tech_que[i]!=temp)
            i++;

     
   if(i!=tech_size)
            while(i<tech_size-1)
        
    {
                strcpy(tech_que[i].person_name,tech_que[i+1].person_name);
  
              tech_que[i].ar_time=tech_que[i+1].ar_time;
  
              tech_que[i].bt_time=tech_que[i+1].bt_time;
                i++;
            }
  
      //else
            tech_size--;
    }

}


/printing of quere table 
        printf("List Of the Student Quere Submitted\n\n");
   
     print_data(stud_que,stud_size);
     
   printf("\n\nList Of the Teacher Quere Submitted\n\n");
    
    print_data(tech_que,tech_size);
     
   //printf("%d\n",stud_size);
       
 //printf("%d\n",tech_size);
      
  
        printf("NOTE:- Every Quere will be given 20 time Quantum:-\n");

    
    printf("\n\nWait till we call your name: \n\n ");

     
   pro_min_student();
    
    pro_min_teacher();
      
  sleep(6);

     
   if(min_av_student<min_av_teacher )
      
      {
                timer=min_av_student;
            }
   
         else
            {
                timer=min_av_teacher;
            }
    
        
        //calling quere according to there priority and arrival time
    
    while(tech_size!=0||stud_size!=0)
    
    {

            //printf("%d %d \n",min_av_student,min_av_teacher);

            

        
    if(timer>=min_av_teacher)
         
   {
                pthread_create(&p1,NULL,pro,(void *)&tech_que[tech_loc]);
        
        pthread_join(p1,NULL);
                //stud_size--;
            }
    
        else 
          
  {
                pthread_create(&p1,NULL,pro,(void *)&stud_que[stud_loc]);
       
         pthread_join(p1,NULL);
               // tech_size--;

            }

            
//print_data(stud_que,stud_size);
            //print_data(tech_que,tech_size);
   
         //printf("%d\n",stud_size);
            //printf("%d\n",tech_size);
    
        pro_min_student();
            pro_min_teacher();

  
      }
      
  avg_quere_time=Total_quere_time/Quere_count;
  
      sleep(3);
       
 system("clear");
     
   printf("Todays quere taking session has been Ended \n");
  
      printf("\n\nTotal quere taken today = %d \n\nTotal quere time = %d\n\nAverage quere time = %f\n",Quere_count,Total_quere_time,avg_quere_time);
       
 sleep(3);
     
   system("clear");
      
  printf("Logging out .\n");
      
  sleep(2);
        
system("clear");
       
 printf("Logging out . .\n");
   
     sleep(2);
      
  system("clear");
       
 printf("Logging out . . .\n");
   
     sleep(2);
       
 system("clear");
    
    printf("Logged out\n");
    
    
        
    
    }
    else
     
   {
            system("clear");
     
       printf("log In Unsucessfull\n\n");
    
  
      printf("Cannt login during this time of day\n");

        }

}  