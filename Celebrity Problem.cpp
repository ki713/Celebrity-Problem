#include <bits/stdc++.h>
#include <list>
using namespace std;
#define N 8
bool MATRIX[N][N] = {{0,0,1,0},
                    {0,0,1,0},
                    {0,0,0,0},
                    {0,0,1,0}};
bool knows(int a,int b)
{
    return MATRIX[a][b];
}
//return -1 if celebrity is not present
//if celebrity is present then it will return id(0 to n-1)
int findCelebrity(int n)
{
    //create a stack
    stack<int> s;
    
    //celebrity
    int C;


    //push every element in the stack
    for(int i=0;i<n;i++)
    {
        s.push(i);
    }

    //extract to celebrity

    //find potential celebrity
    while(s.size() > 1)
    {
        int A = s.top();
        s.pop();

        int B = s.top();
        s.pop();

        if(knows(A,B))
        {
            s.push(B);
        }
        else
        {
            s.push(A);
        }
    }

    //if there are two people left int the stack and no potential candidate
    if(s.empty())
    {
        return -1;
    }
    C = s.top();
    s.pop();


  
  
for(int i=0;i<n;i++)
{
    //if any person doesn't know C or C doesn't know anybody then return -1
    if(i != C && (knows(C,i)|| !knows(i,C)))
    {
        return -1;
    }
}
    
        return C;
    
 
}

int main(){
    int n=4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
return 0;
}