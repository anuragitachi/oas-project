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

#include<stdlib.h>

#include<time.h>


int stud_size=0,tech_size=0;

int check=0;

int min_av_student=1000,stud_loc,min_turn=100;

int min_av_teacher=1000,tech_loc;

int quantom=20,size;

int timer=0;

struct tm * timeinfo;


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


//stud_que array for student queres

//tech_que array for teacher queres
struct que stud_que[10],tech_que[10];


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



//function will print all the detailes of the queres
void print_data(struct que a[],int size)

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
           
 printf("\" %s \" quere is completly executed :\n",temp->person_name);
       
     remove_element(temp);
           
 //size--;
        }
        else
      
  {
            timer+=quantom;
       
     //printf("%d",temp->bt_time);
  
          printf("\nSorry for the inconvinance \n");
  
          printf("\" %s \" quere is to big you Wait for Your next turn\n",temp->person_name);
            temp->turn++;
        
        }
        sleep(5);
        
       
    }
     pthread_exit(NULL);
}

//main function 
int main()
{
    pthread_t p1;

    int Total_quere_time=0,Quere_count=0;
    float avg_quere_time=0;
    //check_time();
    check=1;
    system("clear");
    printf("Suresh Welcome To Online Quere System:\n");
    sleep(3);
    system("clear");
    printf("Logging in .\n");
    sleep(2);
    system("clear");
    printf("Logging in . .\n");
    sleep(2);
    system("clear");
    printf("Logging in . . .\n");
        

    // check the loggin in critaria    
    if(check==1)
    {
        int flag1=1;
        sleep(2);
        system("clear");
        printf("Logged In Succesfull\n");
        while(flag1)
        {
            char name[20],position[20];
            int arival_time,burst_time;
            sleep(1);
            system("clear");
            //taking quere from the user
            printf("Welcome to Quere Solutions\n");       
   
         printf("\nEnter the  quere details in the form:\n");
      
      printf("\nEnter your name: ");
          
  scanf("%s",name);
         
   printf("\nEnter your position(student/teacher): ");
     
       scanf("%s",position);
           
 printf("\nEnter your arrival time: ");
     
       scanf("%d",&arival_time);
         
   printf("\nEnter your quere time needed: ");
    
        scanf("%d",&burst_time);

         
   struct que *temp;

       
     if(strcmp(position,"student")==0||strcmp(position,"STUDENT")==0)
      
      {
                temp=&stud_que[stud_size];
          
      //printf("helo\n");
             
   stud_size++;
                temp->priority=2;
            }
      
      else if(strcmp(position,"teacher")==0||strcmp(position,"TEACHER")==0)
      

      {
                temp=&tech_que[tech_size];
                
//printf("yoo\n");
           
     tech_size++;
             
   temp->priority=1;
            }

     
       temp->ar_time=arival_time;
        
    temp->bt_time=burst_time;
         
   temp->r_time=burst_time;
      
      strcpy(temp->person_name,name);
       
     temp->turn=1;

       
     Total_quere_time+=burst_time;
   
         Quere_count++;


       
     printf("\n\nAdd another form(Y/N)\n");
      
      char ch;
            scanf("%c",&ch);
         
   scanf("%c",&ch);
         
   if(ch=='y'||ch=='Y')
            flag1=1;
      
      else
            flag1=0; 
           
                     

        }
        system("clear");

        
//printing of quere table 
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