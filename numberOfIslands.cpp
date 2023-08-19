#include<stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//std::vector<std::vector<int> > grids{{1,1,1,1,0},{1,1,0,1,0},{1,1,0,0,0},{0,0,0,0,1}};
std::vector<std::vector<int> > grids{{1,1,1,1,0,0,1,1},{1,1,0,1,0,0,0,1},{1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,1}};
void link( int x, int y)
{
    cout<<"link x="<<x<<" y="<<y<<endl;
    grids[x][y]=0;
        if ((y+1  < grids[0].size() ) &&(grids[x][y+1]==1))
        {  link(x,y+1);  };
        if((y-1  >=0 )&& (grids[x][y-1]==1)) //bug fix
        {  link(x,y-1); };
        if( (x+1  < grids.size()  ) &&( grids[x+1][y] == 1 ))
        {  link( x+1,y); };
        if((x-1  >=0 ) &&(grids[x-1][y]==1)) //bug fix
        {  link(x-1,y);  };
     return ;
}

int number_of_islands_2()
{
    int number_of_islands=0;
//    std::vector<std::vector<int> > grids{{1,1,1,1,0},{1,1,0,1,0},{1,1,0,0,0},{0,0,0,0,1}};
    for(int i=0; i<grids.size(); i++)
    {
        for(int j=0; j<grids[0].size();j++)
        {
//            cout<<"x,y"<<i<<" : "<<j<<" value:"<<grids[i][j]<<endl;
            if (grids[i][j]==1)
            {
                    link(i,j);
                    number_of_islands++;
                    cout<<number_of_islands<<endl;
            }
        }
    }
    return number_of_islands;
}

int main()
{
    int ir= number_of_islands_2();
    cout<<"number of islands = "<<ir<<endl;
    return  0;
}
