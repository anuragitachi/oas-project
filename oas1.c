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

int stud_size=0,tech_size=0;

int check=0;

int min_av_student=1000,stud_loc,min_turn=100;

int min_av_teacher=1000,tech_loc;


//structure for collection of all the details of the quere
struct que

{
    int priority;     //to differentiate b/w student and teacher
    int bt_time;    
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


//function to get the system current time
void gettime()

{
    time_t rawtime;

   
 time ( &rawtime );
    timeinfo = localtime ( &rawtime );

}


//function to check for the valid time to be loggeg in 1 for ture else 0
void check_time()

{
    gettime();
   
 if(timeinfo->tm_hour>=10 && timeinfo->tm_hour<12)
   
 {
        check=1;
    }
}


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



//function will execute the que and update the que status
void *pro(struct que *temp)

{
    system("clear");
 
   printf("\" %s \" your turn is here \n",temp->person_name);  
  
    
    sleep(4);
    printf("\n\nProcessing your request\n\n");
 
   sleep(4);
    if ((temp->bt_time > 0))  
   
 {
        temp->bt_time -= quantom;
        if (temp->bt_time <=0) 
     
   {
            timer+=temp->bt_time+quantom;
  
          temp->bt_time=0;
   