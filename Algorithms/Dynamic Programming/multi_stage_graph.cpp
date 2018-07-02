#include<bits/stdc++.h>
#define INFINITY 100000
using namespace std;

int minimum(long a , long b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void shortestDist(long *cost,int num_vertices)
{
    int dist[num_vertices],i,j;
    dist[num_vertices-1] = 0;
    for (i = num_vertices-2 ; i >= 0 ; i--)
    {
        dist[i] = INFINITY;
        for (j = i ; j < num_vertices ; j++)
        {
            if (*((cost + i*num_vertices)+j) == INFINITY)
                continue;

            dist[i] = minimum(dist[i], *((cost + i*num_vertices)+j) + dist[j]);
        }
    }
    cout<<"\n\nThe minimum distance from source to sink is: "<<dist[0]<<endl;;
    return;
}

int main(void)
{
    int num_vertices,num_edges,i,j,a,b,weight;
    cout<<"Considering only directed graph...\nEnter a graph having multi_stages...\nEnter number of vertex: "<<endl;
    cin>>num_vertices;
    cout<<"Enter number of edges: "<<endl;
    cin>>num_edges;
    long cost[num_vertices][num_vertices] = {INFINITY};

    for(i=0;i<num_edges;i++)
    {
        cout<<"Enter edges and weights: "<<endl;
        cin>>a>>b>>weight;
        cost[a-1][b-1] = weight;
    }
    shortestDist(&cost[0][0],num_vertices);
    return 0;
}
