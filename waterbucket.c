#include <stdio.h>
#include<time.h>
int manual();
int automatic();
int begin();
int changemode();
int manual_dial(int dial);
int changetemp();
int change_temp_by_dial();
int change_temp_by_mobileapp();
int off();
int temp_drop();
int temp;
int manual_sig=0;
clock_t sec;
float curr_temp=22;

int temp_drop()
{
        sec=clock()-sec;
        curr_temp-=(sec*0.01)/CLOCKS_PER_SEC;
        if(curr_temp<22)
        curr_temp=22;
        if(curr_temp>100)
        curr_temp=100;
        printf("Current water temperature = %f\n",curr_temp);
    
}
int main()
{	
	printf("----Electric Water Bucket-----\n");
    printf("Current water temperature = %f\n",curr_temp);
    begin();
}
int begin()
{
    int start;
    printf("Press 1 - To start \nPress 2 - To off \n");
    scanf("%d",&start);
    if(start==1)
    {
        changemode();
    }
    else if(start==2)
    {
        off();
    }
    else{
        printf("Invalid input\n");
        begin();
    }

}
int off()
{
    printf("Electric water bucket Turned Off.\n");
}
int changemode()
{
    int mode;
    printf("Press 1 - for Manual mode\nPress 2 - for Automatic mode\n");
    printf("press 3 to turn off\n");
    scanf("%d",&mode);
    if(mode==1)
    manual();
    else if(mode==2)
    automatic();
    else if(mode==3)
    off();
    else
    {
        printf("invalid input\n");
        changemode();
    }
}
int manual()
{
    int current;
    printf("----Manual mode-----\n");
    temp_drop();
    printf("Enter the value through dial ranging from 0(No current) to 100(Full current).\n");
    scanf("%d",&current);
    manual_sig=0;
    manual_dial(current);
}

int manual_dial_temp_inc(int m_curr)
{
    sec=clock()-sec;
    curr_temp+=(sec*m_curr*0.02)/CLOCKS_PER_SEC;
    printf("Current set to %d\n", m_curr);
}

int manual_dial(int current)
{
    int change;
     if(current>=0 && current<=100){
        do{
            
            if(++manual_sig==1)
            {
                sec=clock();
            }
            manual_dial_temp_inc(current);
            temp_drop();
            
            printf("\nPress 1 - If u want to change the current value again.\n");
            printf("Press 2 - If u want to change the mode.\n");
            scanf("%d", &change);
            if(change==1)
            {
                printf("enter value of current from 0 to 100\n");
                scanf("%d",&current);
                manual_dial(current);
                break;
            }
            else if(change==2)
            {
                changemode();
                break;
            }
            else
            {
                printf("invalid input\n");
                manual_dial(current);
                break;

            }
    }while(current>=0 && current<=100);
    } 
    else
    {
        printf("invalid input\n");
        manual();
    }
}


int automatic()
{
    int choice,t;
	printf("----Automatic Mode----\n");
    printf("Enter the temperature from 0 to 100 degree celsius.\n");
    scanf("%d",&t);
    if(t>=0 && t<=100)
    {
      
        curr_temp=t;
        printf("Automatic mode is ON and temperature is set to %f degree celsius\n", curr_temp);
        printf("Press 1 if You want to change the temperature or\n");
        printf("Press 2 if you want to EXIT the Automatic Mode and ENTER in Manual Mode.\n");
        printf("press 3 to turned off\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            changetemp();
        }
        else if(choice==2)
        {
            manual();
        }
        else if(choice==3)
        {
            off();
        }
        else
        {
            printf("Invalid Input\n");
            automatic();
        }
    }
    
    else
    {
        printf("Invalid Input\n");
        automatic();
    }

}
int changetemp()
{
    int choice;
    printf("Press 1 to change the temperature by dial\n");
    printf("Press 2 to set temperature directly by Mobile App or\n");
    printf("Press 3 if you want to EXIT the Automatic Mode and ENTER in Manual Mode\n");
    printf("press 4 to turned off\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        change_temp_by_dial();
    }
    else if(choice==2)
    {
        change_temp_by_mobileapp();
    }
    else if(choice==3)
    {
        manual();
    }
    else if(choice==4)
    {
        off();
    }
    else
    {
        printf("Invalid Input\n");
        changetemp();
    }
}
int change_temp_by_dial()
{
    int choice;
    printf("Pess 1 to rotate dial clockwise(temperature will increase by 1)\n");
    printf("Pess 2 to rotate dial anticlockwise(temperature will decrease by 1)\n");
    printf("Press 3 to set temperature directly by Mobile App or\n");
    printf("Press 4 if you want to EXIT the Automatic Mode and ENTER in Manual Mode\n");
    printf("press 5 to turned off\n");
    scanf("%d",&choice);
     if(choice==1)
    {
        if(curr_temp>=100)
        {
            printf("Temperature is reached to 100 and cannot increase further\n");
            change_temp_by_dial();
        }
        else
        {
            curr_temp++;
            printf("Temperature incresed by 1 and set to %f degree celsius\n", curr_temp);
            change_temp_by_dial();
        }
        
    }
    else if(choice==2)
    {
        if(curr_temp<=0)
        {
            printf("Temperature is reached to 0 and cannot decrease further\n");
            change_temp_by_dial();
        }
        else
        {
            curr_temp--;
            printf("Temperature decresed by 1 and set to %f degree celsius\n", curr_temp);
            change_temp_by_dial();
        }
        
    }
    else if(choice==3)
    {
        change_temp_by_mobileapp();
    }
    else if(choice==4)
    {
        manual();
    }
    else if(choice==5)
    {
        off();
    }
    else
    {
        printf("Invalid Input\n");
        change_temp_by_dial();
    }

}
int change_temp_by_mobileapp()
{
    int t;
    printf("----Mobile App----\n");
    printf("Enter the temperature from 0 to 100\n");
    scanf("%d",&t);
    if(t>=0 && t<=100)
    {
        curr_temp=t;
        printf("Temperature is set to %f\n", curr_temp);
        changetemp();
    }
    else
    {
        printf("Invalid Input\n");
        change_temp_by_mobileapp();
    }
    
}




