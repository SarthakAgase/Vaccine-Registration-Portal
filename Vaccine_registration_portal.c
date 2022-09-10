#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct patient
{
    char firstname[30];
    char lastname[30];
    char contact[12];
    char aadhar[14];
    char location[30];
    int age, id, day, month, year;
}details;

void registration_form();
void Vaccination_Certificate();
void choice();
void head(void);
void tail(void);
void total();
void symptoms_spread();
void vaccination();
void registration();
void precautionary_measures();
void who_guidelines();
void faq();

int main (void)
{
    head();
    choice();

    return 0;    
}

void registration_form(void)
{
    int last_id = 0,t;
    //These are two file pointers to read previously registered data and to store new data
    FILE *save_data, *retrieve_data;
    printf(
    "\n----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\tEnter Your Age: ");
    scanf("%d", &details.age);
    if(details.age>=15)
    {
        retrieve_data = fopen("data.txt","r");
        //this while loop runs and read data from file until it encounters End of the file and stores the last id it read before EOF in last_id
        while(fscanf(retrieve_data,"%d %s %s %s %s %s %d %d %d %d",&details.id,details.firstname,details.lastname,details.contact,details.aadhar,details.location,&details.age,&details.day,&details.month,&details.year) != EOF)
        {
            last_id = details.id;
        }
        //Below are registration details to input by user
        printf("\n\tRegistartion ID : %d\n",++last_id);
        details.id = last_id;
        printf("\n\tFill the following details\n");
        printf("\n\tFirstname : ");
        scanf("%s",details.firstname);
        printf("\n\tLastname : ");
        scanf("%s",details.lastname);
        
        do
        {
            printf("\n\tMobile.No : ");
            scanf("%s", details.contact);
            //this do while loop ensures the mob.no is 10 digits only
            t = 0;
            if(strlen(details.contact) != 10)
            {
                t = 1;
                printf("\n\tEnter a valid Mobile.No");
            }
            else
            {
                for(int i=0;i<10;i++)
                {
                    if(details.contact[i]>'9' || details.contact[i]<'0')
                    {
                        t = 1;
                        printf("\n\tEnter a valid Mobile.No in digits\n");
                    }    
                }
            }
        }while(t);

        
        do
        {
            printf("\n\tAadhar.No : ");
            scanf("%s", details.aadhar);
            //this do while loop ensures aadhar.no is 12 digits only
            t = 0;
            if(strlen(details.aadhar) != 12)
            {
                t = 1;
                printf("\n\tEnter a valid Aadhar.No\n");
            }
            else
            {
                for(int i=0;i<10;i++)
                {
                    if(details.aadhar[i]>'9' || details.aadhar[i]<'0')
                    {
                        t = 1;
                        printf("\n\tEnter a valid Aadhar.No in digits\n");
                    }    
                }
            }
        }while(t); 

        printf("\n\tLocation : ");
        scanf("%s",details.location);

        printf("\n\n");
        printf("_____________________________________________________________________________________________________________________________ \n");
        printf("\t                                                                                                \n");
        printf("\t                                          Registered Details Successfully                             \n");
        printf("\t                             Visit the %s Govt. Hospital after 2 days for Vaccination                   \n",details.location);
        printf("_____________________________________________________________________________________________________________________________ \n");

        // below is a function for time.h library i use it to get the day, month, year from computer store it in variables i have defined already
        time_t current;
        time(&current);
        struct tm *local = localtime(&current);
        details.day = local ->tm_mday;
        details.month = local ->tm_mon + 1;
        details.year = local ->tm_year + 1900;

        // here i am printing all th data inputed by users in a txt file named data.txt
        save_data = fopen("data.txt","a");
        fprintf(save_data,"%d \t%s %s \t%s \t%s \t%s  \t%d  \t%d-%d-%d\n", details.id,details.firstname,details.lastname,details.contact,details.aadhar,details.location,details.age,details.day,details.month,details.year);
        fclose(save_data);
        fclose(retrieve_data);
    }
    else
    printf("You are not eligible for vaccination");
}

void Vaccination_Certificate()
{
    FILE *read;
    read=fopen("data.txt","r");
    if(read==NULL)
    {
        printf("NO data Found");
        choice();
    }
    int p_id;
    printf("\n------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\tEnter Id : ");
    scanf("%d",&p_id);
    int flag=0;
    while(fscanf(read,"%d \t%s \t%s \t%s \t%s \t%s \t%d \t%d-%d-%d\n",&details.id,details.firstname,details.lastname,details.contact,details.aadhar,details.location,&details.age,&details.day,&details.month,&details.year)!=EOF)
    {

        if(details.id==p_id)
        {
            flag=1;
            printf("\n\t    _____________________________________________________________________________________________________\n");
            printf("\t    |  _______________________________________________________________________________________________  |\n");
            printf("\t    | |                                                                                               | |\n");
            printf("\t    | |                                     Vaccination Certificate                                   | |\n");
            printf("\t    | |_______________________________________________________________________________________________| |\n");
            printf("\t    |___________________________________________________________________________________________________|\n");
            printf("\t                                                                                                      \n");
            printf("\t        ID: %d                                                                                        \n", details.id);
            printf("\t                                                                                                      \n");
            printf("\t        Name: %s %s                                                                                   \n", details.firstname, details.lastname);
            printf("\t                                                                                                      \n");
            printf("\t        Age: %d                                                                                       \n", details.age);
            printf("\t                                                                                                      \n");
            printf("\t        Contact: %s                                                                                   \n", details.contact);
            printf("\t                                                                                                      \n");
            printf("\t        Aadhar: %s                                                                                   \n", details.aadhar);
            printf("\t                                                                                                      \n");
            printf("\t        Location: %s                                                                                  \n",details.location);
            printf("\t                                                                                                      \n");
            printf("\t        Registration Date:  %d-%d-%d                                                                  \n",details.day,details.month,details.year);
            printf("\t                                                                                                      \n");
            printf("\t        Visit %s Govt Hospital For Vaccination after Two Days                                        \n",details.location);
            printf("\t                                                                                                      \n");
            printf("\t     ___________________________________________________________________________________________________\n");
            printf("\t    |___________________________________________________________________________________________________|\n\n\n");
        }
    }
    if(flag==0)
    {
        printf("File Not found for ID: %d\n",p_id);
    }
    fclose(read);
}

void head(void)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf(
    "===============================================================================================================================\n");
    printf(
    "\n\t\t\t\t\t\tMinistry Of Health & Family welfare"
    "\n\t\t\t\t\t\t\tGovernment of India\n\n"
    "-------------------------------------------------------------------------------------------------------------------------------\n");

 
    printf("\t       ___________________________________________________________________________________________________ \n");
    printf("\t      |                                                                                                   | \n");
    printf("\t      |                          WELCOME TO COVID VACCINE REGISTRATION PORTAL                             | \n");
    printf("\t      |___________________________________________________________________________________________________| \n");

    


    printf("\n\n\tTill everyone is vaccinated , let us not forgot our responsibilities .");
    printf("\n\tEven after receiving the covid -19 vaccine continue taking all precautions .");
    printf("\n\t\t-->  wash your hands    \n\t\t-->  wear masks    \n\t\t-->  keep social distance");

    printf(
    "\n\n\n\tHelpline Number : +91-11-23978046"
    "\n\tToll Free : 1075"
    "\n\tHelpline Email ID : ncov2019@gov.in");


}

void tail(void)
{
    printf("\t   _________________________________________________________________________________________________________\n");
    printf("\t  |  _____________________________________________________________________________________________________  |\n");
    printf("\t  | |                                                                                                     | |\n");
    printf("\t  | |                                       THANKS FOR VISITING. :)                                       | |\n");
    printf("\t  | |_____________________________________________________________________________________________________| |\n");
    printf("\t  |_________________________________________________________________________________________________________|\n");
    printf("\t                                                                                                             \n");
}

void choice()
{
    char c[4];
    do
    {
        int choose;
        printf(
        "\n\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\t[1] ENTER 1 for Registration of Vaccine\n");
        printf("\t[2] ENTER 2 to Generate your Vaccination Certificate\n");
        printf("\t[3] ENTER 3 for Frequently Asked Questions\n");
        printf("\t[4] ENTER 4 for Total Registered Patients\n");
        printf("\t[5] ENTER 0 Exit\n\n");
        printf("\tEnter the number of the option which you want to select: ");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
            {
                registration_form();
                break;
            }
            case 2:
            {
                Vaccination_Certificate();
                break;
            }
            case 3:
            {
                faq();
                break;
            }
            case 4:
            {
                total();
                break;
            }
            case 0:
            {
                tail();
                exit(0);
            }
            default:
                printf("Enter a valid option number");

        }
        printf("\n\tDo you want to continue (press yes/no)?\n");
        printf("\t");
        scanf("%s",c);
        if(strcmp(c,"no")==0 || strcmp(c,"NO")==0 || strcmp(c,"No")==0)
        tail();
    }while(strcmp(c,"yes")==0 || strcmp(c,"YES")==0 || strcmp(c,"Yes")==0);
}

void total()
{
    int total_registered = 0;
    FILE *total;
    total = fopen("data.txt","r");
    while(fscanf(total,"%d \t%s \t%s \t%s \t%s \t%s \t%d \t%d-%d-%d\n",&details.id,details.firstname,details.lastname,details.contact,details.aadhar,details.location,&details.age,&details.day,&details.month,&details.year)!=EOF)
    {
        total_registered = details.id;
    }
    printf("\n-------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("\n\tTotal Registered Patients: %d\n\n",total_registered);
}

void faq()
{
    int in1;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n====================================================================================================================\n");
    printf("\n\t\t\t\t\t\t\t\tCOVID-19\n");
    printf("\t\t\t\t\t\t\tFREQUENTY ASKED QUESTIONS\n");
    printf("\n-------------------------------------------------------------------------------------------------------------------\n");

    printf(
 "\n\t\t\tCoronaviruses (CoV) are a large family of viruses that cause illness"
 "\n\t\tranging from the common cold to more severe diseases. A novel corona virus"
 "\n\t\t(nCoV) is a new strain that has not been previously identified in humans."
 "\n\t\t\tThe virus can spread from an infected person's mouth or nose in small"
 "\n\t\tliquid particles nwhen they cough, sneeze, speak, sing or breathe. These"
 "\n\t\tparticles range from larger nrespiratory droplets to smaller aerosols."
 "\n\t\t\tYou can be infected by breathing in the virus if you are near someone"
 "\n\t\twho has COVID-19, nor by touching a contaminated surface and then your eyes,"
 "\n\t\tnose or mouth. The virus spreads more easily indoors and in crowded places.");

    printf("\n\n--------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\t\t ENTER 1 for FAQ related to COVID-19 Registration Process\n");
    printf("\t\t ENTER 2 for FAQ related to COVID-19 Vaccination\n");
    printf("\t\t ENTER 3 for FAQ related to COVID-19 Symptoms & Spread\n");
    printf("\t\t ENTER 4 to know WHO Guidelines\n");
    printf("\t\t ENTER 5 to know Precautionary measures\n");
    printf("\t\t ENTER 0 to return to main menu\n");
        do
        {
            printf("\n\t\t ENTER Respective choice : ");
            scanf("%d", &in1);
                switch (in1)
                {
                case 1:
                    registration();
                    break;
                case 2:
                    vaccination();
                    break;
                case 3:
                    symptoms_spread();
                    break;
                case 4:
                    who_guidelines();
                    break;
                case 5:
                    precautionary_measures();
                    break;
                case 0:
                    break;
                default:
                    printf("Enter valid input\n");
                }
        } while (in1>6);

}

void registration()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("================================================================================================================================\n");
    printf("\t\t\t\t\t\tFAQ FOR REGISTRATION PROCESS\n");
    printf("================================================================================================================================\n");
    printf("\n\t[1] Where can I get the vaccine from?\n\tANS: Vaccines are available from Government and Private Health Facilities known as COVID Vaccination Centres (CVCs).");
    printf("\n\n--------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t[2] What documents are required for registration of eligible beneficiary?\n\tANS: Any of the below mentioned ID with Photo may be produced at the time of registration:\n\t\t ---> Aadhaar Card\n\t\t ---> Driving License\n\t\t ---> Health Insurance Smart Card issued under the scheme of Ministry of Labour\n\t\t ---> Mahatma Gandhi National Rural Employment Guarantee Act (MGNREGA) Job Card\n\t\t ---> Official identity cards issued to MPs/MLAs/MLCs\n\t\t ---> PAN Card\n\t\t ---> Passbooks issued by Bank/Post Office\n\t\t ---> Passport\n\t\t ---> Pension Document\n\t\t ---> Service Identity Card issued to employees by Central/ State Govt./ Public Limited Companies\n\t\t ---> Voter ID.");
    printf("\n\n--------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t[3] How will the beneficiary receive information about due date of vaccination?\n\tANS: Following online registration, beneficiary will receive SMS on their registered mobile number about \n\t     the due date, place and time of vaccination.");
    printf("\n\n--------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t[4] Will I get any certificate that I am vaccinated?\n\tAND: Yes, a provisional certificate would be provided after the first dose. On completion of second dose,\n\t     when you receive the message for completion of schedule it would include a link to download digital\n\t     certificate of vaccination for your perusal. This certificate can be then be saved in the digi-locker.");
    printf("\n\n--------------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("\n");
    int input;
    do
    {
    printf("\tEnter 1 to continue or 0 to go back : ");
    scanf("%d",&input);
    printf("\n");
        switch (input)
        {
        case 1:
            vaccination();
            break;
        case 0:
            faq();
        default:
            printf("\tEnter valid input.\n");
        }
    }while (input>1);
    
}

void vaccination()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("===========================================================================================================================================================\n");
    printf("\t\t\t\t\t\t\t\t   FAQ FOR VACCINATION\n");
    printf("===========================================================================================================================================================\n");
    
    printf("\n\n\t[1] Is it mandatory to take the vaccine?\n\tANS: Vaccination for COVID-19 is voluntary. However, it is advisable to receive the complete schedule of COVID-19 vaccine\n\t     for protecting oneself against this disease and also to limit the spread of this disease to the close contacts\n\t     including family members, friends, relatives and co-workers.");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("\n\t[2] Can a person presently having COVID-19 (confirmed or suspected) infection be vaccinated?\n\tANS: Person with confirmed or suspected COVID-19 infection may increase the risk of spreading the same to others at vaccination\n\t     site. For this reason, infected individuals should defer vaccination for 14 days after symptoms resolution.");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n\t[3] Which vaccine is better between Covisheild and Covaxin?\n\tANS:There is no head-to-head comparison done between the two vaccines being used in India so one cannot choose one\n\t    over the other. Both would work fine in preventing the infection as well as prevent a person from going into severe\n\t    state of thedisease. As a long-term effect, it would be preventing death for elderly people or those who have comorbidities.");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n\t[4] What medications should be avoided before taking COVID-19 vaccine and for how long?\n\tANS:Currently, there is no such instruction. One can take one's regular medication uninterruptedly. Just inform the \n\t    vaccinator about the medicines you consume.");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n\t[5] Should you avoid alcohol after receiving the COVID-19 vaccine?\n\tANS:As per experts, there is no evidence of alcohol impairing the effectiveness of the vaccine.");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n\t[6] Do I need to use the mask/other COVID-19 appropriate precautions after receiving the vaccine?\n\tANS:Yes, it is absolutely necessary that everyone who has received the COVID-19 vaccine should continue to follow the \n\t    COVID-19 appropriate behaviour ");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n");   
    int input;
    do
    {
    printf("\tEnter 1 to continue or 0 to go back : ");
    scanf("%d",&input);
    printf("\n");
        switch (input)
        {
        case 1:
            symptoms_spread();
            break;
        case 0:
            faq();
        default:
            printf("\tEnter valid input.\n");
        }
    }while (input>1);
    
}

void symptoms_spread()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("==================================================================================================================================\n");
    printf("\t\t\t\t\t\t\tFAQ FOR SYMPTOMS & SPREAD\n");
    printf("==================================================================================================================================\n");
    
    printf("\n\t[1]What are the symptoms of COVID-19?\n\tANS: Symptoms of severe COVID-19 disease include:\n\t\t--->Shortness of breath\n\t\t--->Loss of appetite\n\t\t--->High temperature (above 38 C)\n\t     Most common symptoms:\n\t\t--->Fever\n\t\t--->Dry cough\n\t\t--->Fatigue\n\t     Other less common symptoms are:\n\t\t--->Loss of taste or smell\n\t\t--->Nasal congestion\n\t\t--->Sore throat");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("\t[2] Can COVID-19 be caught from a person who has no symptoms?\n\tANS: The main way the disease spreads is through respiratory droplets expelled by someone who\n\t     is coughing. People who are infected but do not show symptoms can also spread the virus to others.");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\t[3] How long is the incubation period for COVID-19?\n\tANS: The 'incubation period' means the time between catching the virus and beginning to have symptoms of\n\t     the disease. Most estimates of the incubation period for COVID-19 range from 1-14 days, most commonly\n\t     around five days. These estimates will be updated as more data become available.");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\t[4] How long does the virus survive on surfaces?\n\tANS: It is not certain how long the virus that causes COVID-19 survives on surfaces, but it seems to behave\n\t     like other coronaviruses. Studies suggest that coronaviruses (including preliminary information on the\n\t     COVID-19 virus) may persist on surfaces for a few hours or up to several days");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\t[5] Is it safe to receive a package from any area where COVID-19 has been reported?\n\tANS: Yes. The likelihood of an infected person contaminating commercial goods is low and risk of catching\n\t     the virus that causes COVID-19 from a package that has been moved, travelled, and exposed to different\n\t     conditions and temperature is also low.");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n");
    int input;
    do
    {
    printf("\tEnter 1 to continue or 0 to go back : ");
    scanf("%d",&input);
    printf("\n");
        switch (input)
        {
        case 1:
            who_guidelines();
            break;
        case 0:
            faq();
        default:
            printf("\tEnter valid input.\n");
        }
    }while (input>1);
    
}

void who_guidelines()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("==================================================================================================================================\n");
    printf("\t\t\t\t\t* Guidelines by WORLD HEALTH ORGANISATION *\n");
    printf("==================================================================================================================================\n");

    printf("\n\tProtect yourself and others from COVID-19 by following these precautions:\n\n");
    printf("\t    > Get vaccinated as soon as it’s your turn.\n");
    printf("\t    > Keep a distance of at least 1 metre from others.\n");
    printf("\t    > Open windows when possible.\n");
    printf("\t    > Wear a mask.\n");
    printf("\t    > Clean hands.\n");
    printf("\t    > Cover coughs and sneezes.\n");
    printf("\t    > Stay home when sick.\n");
    
     printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n\tAfter vaccination precautions:\n\n");
    printf("\t    > Keep a safe distance from others and avoid crowds.\n");
    printf("\t    > Wear a well-fitting mask covering your mouth and nose.\n");
    printf("\t    > When indoors with others, ensure good ventilation, such as by opening a windowe.\n");
    printf("\t    > Clean your hands frequently.\n");
    printf("\t    > Clean hands.\n");
    printf("\t    > Cover coughs and sneezes.\n");
    printf("\t    > Cover any cough or sneeze in your bent elbow.\n");
    printf("\n\n\n\n");

    printf("\n");
    int input;
    do
    {
    printf("\tEnter 1 to continue or 0 to go back : ");
    scanf("%d",&input);
    printf("\n");
        switch (input)
        {
        case 1:
            precautionary_measures();
            break;
        case 0:
            faq();
        default:
            printf("\tEnter valid input.\n");
        }
    }while (input>1);
    
}

void precautionary_measures()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("===========================================================================================================================\n");
    printf("\n\t\t\t\t\t\tPrecautions for Covid-19\n\n");
    printf("===========================================================================================================================\n");

    printf("\n\n\tTo prevent the spread of COVID-19:\n\n");
    printf("\t--> Maintain a safe distance from others (at least 1 metre), even if they don't appear to be sick.\n"
           "\t--> Wear a mask in public, especially indoors or when physical distancing is not possible.\n"
           "\t--> Choose open, well-ventilated spaces over closed ones. Open a window if indoors.\n"
           "\t--> Clean your hands often. Use soap and water, or an alcohol-based hand rub.\n"
           "\t--> Get vaccinated when it's your turn. Follow local guidance about vaccination.\n"
           "\t--> Cover your nose and mouth with your bent elbow or a tissue when you cough or sneeze.\n"
           "\t--> Stay home if you feel unwell.\n\n");
    
    printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t\t\t\t   # END OF FAQ !!!\n");
    printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
    int input;
    do
    {

    printf("\n\n\tEnter 0 to go back : ");
    scanf("%d",&input);
        switch (input)
        {
        case 0:
            faq();
        default:
            printf("\tEnter valid input.\n");
        }
    }while (input>0);

    
}