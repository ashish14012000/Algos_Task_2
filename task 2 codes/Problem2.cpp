/* TASK 2 TASK 2 TASK 2 TASK 2 TASK 2 TASK 2 TASK 2 TASK 2 */


#include<bits/stdc++.h>
#define ll int64_t

using namespace std;

vector<ll> initialize(vector<ll>& A) // function to create the difference vector
{
    ll n = A.size();
    vector<ll> D(n + 1);

    D[0] = A[0]; D[n] = 0;
    for (ll i=1;i<n;i++)
        D[i] = A[i]-A[i-1];

    return D;
}

void update(vector<ll> &D,ll l,ll r,ll x) // function to update the difference vector D
{
    D[l]+= x;
    D[r+1]-= x;
}

ll Arr(vector<ll> &A, vector<ll> &D)   // function to store the final values after all updates
{
    for (ll i=0;i<A.size();i++)
    {
        if (i==0)
            A[i]= D[i];

        else
            A[i]=D[i]+A[i-1];
    }
}

int main()
{ ios_base::sync_with_stdio(false);  // for fast input and output

  map<ll,ll> m;          /* Creating a map to store the positions asked in the queries as keys
                             and their position as values (i.e. position in the sorted order of keys */
  map<ll,ll>::iterator j;

 ll q,i,k=0,n;
 cin>>n>>q;

 vector<ll> v;         // creating a vector to store the positions asked in the queries

 vector< pair<pair<ll,ll>,ll > > v1; /* this vector contains the range of positions to updated along
                                        with the update value */
 for(i=0;i<q;i++)
 {
    ll a,b,c;
    cin>>a>>b>>c;
    v1.push_back(make_pair(make_pair(a,b),c));
    v.push_back(a);
    v.push_back(b);
 }

 for(i=0;i<v.size();i++)
 m.insert(make_pair(v[i],0));

 for(j=m.begin();j!=m.end();j++)
 {
     j->second +=k;
     k++;
 }

 vector<ll> A;
 for(j=m.begin();j!=m.end();j++)
    A.push_back(j->first);

  vector<ll> D = initialize(A);   /* This vector contains the difference array of vector A */

                           /* Range of positions asked originally is replaced by the positions of these positions
                              in the sorted form of these positions  */
  for(i=0;i<v1.size();i++)
  {
     v1[i].first.first=m.find(v1[i].first.first)->second;
     v1[i].first.second=m.find(v1[i].first.second)->second;
  }

  for(i=0;i<q;i++)
    update(D,v1[i].first.first,v1[i].first.second,v1[i].second); /* updating the difference vector D */

  Arr(A,D);
  ll g=0;
  for(i=0;i<A.size();i++)
    g=max(g,A[i]);

  cout<<max(g,n)<<endl; // printing the maximum value after all updates //
}
