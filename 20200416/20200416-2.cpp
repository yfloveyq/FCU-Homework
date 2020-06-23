#include<iostream>
#include <cstring>
using namespace std;

struct person
{
    char lastName[15];
    char firstName[15];
    char age[4];
};

int main()
{
    int account;
    char a[20]="unassigned";

    struct person nameage={"unassigned","","0"};
    FILE *cfPtr;
    if((cfPtr=fopen("nameage.txt","wb"))==NULL)
    {
        cout<<"File could not be opened";
    }
    else
    {
        for(int i=1;i<=100;i++)
        {
            fwrite(&nameage,sizeof(struct person),1,cfPtr);
            fprintf(cfPtr,"\n");
        }
        fseek(cfPtr,0*sizeof(struct person),SEEK_SET);
        for(int i=1;i<=3;i++)
        {
            struct person nameage={"","","0"};
            cout<<"Enter lastname, firstname, and age.\n";
            cin>>nameage.lastName>>nameage.firstName>>nameage.age;
            fwrite(&nameage,sizeof(struct person),1,cfPtr);
            fprintf(cfPtr,"\n");
        }
        fclose(cfPtr);
    }

    if((cfPtr=fopen("nameage.txt","rb+"))==NULL)
    {
        cout<<"File could not be opened";
    }
    else
    {
        while(1)
        {
            cout<<"Enter account to update(1-100).\n";
            cin>>account;
            fseek(cfPtr,((account-1)*sizeof(struct person)+((account-1)*1)),SEEK_SET);
            fread(&nameage,sizeof(struct person),1,cfPtr);
            if(strncmp(nameage.lastName,a,20)==0)
            {
                cout<<"Account "<<account<<" has not info.\n";
            }
            else
            {
                cout<<nameage.lastName<<" ";
                cout<<nameage.firstName<<" ";
                cout<<nameage.age;
                cout<<"\nEnter new age:";
                cin>>nameage.age;
                cout<<nameage.lastName<<" ";
                cout<<nameage.firstName<<" ";
                cout<<nameage.age;
                fseek(cfPtr,((account-1)*sizeof(struct person)+((account-1)*1)),SEEK_SET);
                fwrite(&nameage,sizeof(struct person),1,cfPtr);
                break;
            }
        }
        fclose(cfPtr);
    }

    if((cfPtr=fopen("nameage.txt","rb+"))==NULL)
    {
        cout<<"File could not be opened";
    }
    else
    {
        while(1)
        {
            int number;
            cout<<"\nEnter account to delete(1-100).\n";
            cin>>number;
            fseek(cfPtr,((number-1)*sizeof(struct person)+((number-1)*1)),SEEK_SET);
            fread(&nameage,sizeof(struct person),1,cfPtr);
            if(strncmp(nameage.lastName,a,20)==0)
            {
                cout<<"Account "<<number<<" does not exist.";
            }
            else
            {
                fseek(cfPtr,((number-1)*sizeof(struct person)+((number-1)*1)),SEEK_SET);
                struct person nameage={"unassigned","","0"};
                fwrite(&nameage,sizeof(struct person),1,cfPtr);
                break;
            }
        }
        fclose(cfPtr);
    }
}
