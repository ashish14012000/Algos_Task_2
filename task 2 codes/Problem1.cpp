/* TASK 2 TASK 2 TASK 2 TASK 2 TASK 2 TASK 2 TASK 2 TASK 2 */


#include <bits/stdc++.h>
using namespace std;

int maxlen(char str[], int n) // function to compute the maximum possible length
{
    int sum = 0;
    int ma = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '<')
            sum += 1;
        else
            sum -= 1;

        if (sum == 0)
            ma = i;
    }
    return ma + 1;
}

int main()
{  ios_base::sync_with_stdio(false); // for fast input and output

    int t;cin>>t; // taking the number of test cases
    while(t--)
   {
    char str[150];
    scanf("%s",&str); // taking the string input
    int n = strlen(str);
    if(str[0]=='>')
    cout<<"0"<<endl;
    else if( maxlen(str, n)==1)
    cout<<"0"<<endl;
    else
    cout << maxlen(str,n)<< endl; // printing the maximum possible length
   }
}
