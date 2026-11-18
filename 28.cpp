
#include <iostream>
using namespace std;

int adj[20][20], visited[20], n;

void createGraph()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
}

void DFS(int v)
{
    cout << v + 1 << " ";
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int v)
{
    int queue[20], front = 0, rear = 0;

    visited[v] = 1;
    queue[rear++] = v;

    while(front < rear)
    {
        v = queue[front++];
        cout << v + 1 << " ";

        for(int i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int choice, start;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;

    do
    {
        cout << "\n\n----- GRAPH MENU -----";
        cout << "\n1. Create Graph";
        cout << "\n2. DFS Traversal";
        cout << "\n3. BFS Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createGraph();
                break;

            case 2:
                if(n == 0)
                {
                    cout << "Create graph first!";
                    break;
                }

                for(int i = 0; i < n; i++)
                    visited[i] = 0;

                cout << "Enter starting city (1 to " << n << "): ";
                cin >> start;

                if(start < 1 || start > n)
                {
                    cout << "Invalid city!";
                    break;
                }

                cout << "DFS Traversal: ";
                DFS(start - 1);
                break;

            case 3:
                if(n == 0)
                {
                    cout << "Create graph first!";
                    break;
                }

                for(int i = 0; i < n; i++)
                    visited[i] = 0;

                cout << "Enter starting city (1 to " << n << "): ";
                cin >> start;

                if(start < 1 || start > n)
                {
                    cout << "Invalid city!";
                    break;
                }

                cout << "BFS Traversal: ";
                BFS(start - 1);
                break;

            case 4:
                cout << "Exiting program.";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while(choice != 4);

    return 0;
}
