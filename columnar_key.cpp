#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

char plain[50]={'\0'};//For input
char ctext[50]={'\0'};
int key[6];
int col=5;
int temp[20][5]={'\0'};

void decrypt(char ctext2[],int length)
{


    int row;
    if(length%col==0)
        row=length/col;
    else
        row=(length/col)+1;
    //int row=ceil(length/col);

    //Clearing temp
	for(int i=0;i<row;i++)
    {
        for(int k=0;k<col;k++)
        temp[i][k]='\0';
    }

    int inc=0;
	for(int i=0;i<col;i++)
	{
	    int col_no=key[i]-1;
	    for(int k=0;k<row;k++)
		{
		    int buff=ctext2[inc++];

		    if(buff!=' ')
            {
                    temp[k][col_no]=buff;
            }
            else
            {
                k--;
            }
		}
	}


    inc=0;
    int count=0;
    for(int i=0;i<row;i++)
    {
        for(int k=0;k<col;k++)
        {
            plain[inc++]=(char)temp[i][k];
            count++;
            if(count>4)
            {
                plain[inc++]=' ';
                count=0;
            }
        }
    }
    for(int i=inc-1;i>=0;i--)
    {
        if(plain[i]=='x')
            plain[i]=' ';
    }


}

void encrypt(char plain2[],int length)
{

    int row;
    if(length%col==0)
        row=length/col;
    else
        row=(length/col)+1;
    //int row=ceil(length/col);

    int inc=0;

	for(int i=0;i<row;i++)
	{
	    for(int k=0;k<col;k++)
		{
		    int buff=plain2[inc++];

		    if(buff!=' ')
            {
                temp[i][k]=buff;
                if(temp[i][k]=='\0')
                {
                    temp[i][k]='x';
                }
            }
            else
            {
                k--;
            }
		}
	}

	for(int i=0;i<row;i++)
    {
        cout<<endl;
        for(int k=0;k<col;k++)
        {
            cout<<(char)temp[i][k]<<" ";
        }
    }
cout<<endl;


        inc=0;
        int count=0;
        for(int i=0;i<col;i++)
        {
            int col_no=key[i]-1;
            for(int k=0;k<row;k++)
            {
                ctext[inc++]=(char)temp[k][col_no];
                count++;
                if(count>4)
                {
                    ctext[inc++]=' ';
                    count=0;
                }
            }
        }

}

int main()
{

	int length;

	cout<<"Enter plain text ";
	cin.getline(plain,50);
    cout<<"Enter order";

    for(int i=0;i<5;i++)
    {
        cin>>key[i];
        for(int q=0;q<i;q++)
        {
                while(key[i]==key[q])
                {
                    cout<<"\nRepeated entry enter again";
                    cin>>key[i];
                    q=0;
                }
        }

    }
	length=strlen(plain);

	encrypt(plain,length);
	cout<<"\nEcrypt text is "<<ctext;
	decrypt(ctext,length);
	cout<<"\nDecrypt text is "<<plain;
	return 0;
}
