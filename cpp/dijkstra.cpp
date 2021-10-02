#include <iostream>
#include <climits>

using namespace std;

void dijkstra(int **input, int n, int e){
    bool visited[n];
    int distance[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    int count = 0;
    while(count < n - 1){
        int minVertex = -1;
        for(int i = 0; i < n; i++){
            if((minVertex == -1 || distance[i] < distance[minVertex]) && !visited[i]){
                minVertex = i;
            }
        }

        visited[minVertex] = true;

        for(int i = 0; i < n; i++){
            if(input[minVertex][i] != 0 && !visited[i]){
                if(distance[i] > distance[minVertex] + input[minVertex][i]){
                    distance[i] = distance[minVertex] + input[minVertex][i];
                }
            }
        }

        count++;

    }

    for(int i = 0; i < n; i++){
        cout<<i<<" "<<distance[i]<<"\n";
    }
}

int main(){

    int n, e;
    cin>>n>>e;
    int **input = new int*[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[n];
        for(int j = 0; j < n; j++){
            input[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[s][d] = w;
        input[d][s] = w;
    }

    dijkstra(input, n, e);

    for(int i = 0; i < n; i++){
        delete []input[i];
    }

    delete []input;

    return 0;
}