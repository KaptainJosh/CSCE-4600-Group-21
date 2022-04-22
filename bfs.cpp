/* Credit to GeeksForGeeks for BFS Implementation */

#include "./bfs.hpp"

using namespace std;

// function to add edge to the graph
void addEdge(int x,int y, vector<vector<int> >& adj)
{
	adj[x][y] = 1;
}

// Function to perform BFS on the graph
void bfs(vector<vector<int> >& adj, int dimension, vector<set<int> >& num)
{
	for (int i = 0; i < dimension; i++)
	{
		int start = i;
		// Visited vector to so that
		// a vertex is not visited more than once
		// Initializing the vector to false as no
		// vertex is visited at the beginning
		vector<bool> visited(adj.size(), false);
		vector<int> q;
		q.push_back(start);

		// Set source as visited
		visited[start] = true;

		int vis;
		std::set<int> nums;
		while (!q.empty()) {
			vis = q[0];
			//set<int> nums;
			// Print the current node
			//cout << vis << " ";
			nums.insert(vis);
			// cout << endl;
			// for (int i = 0; i < adj[vis].size(); i++)
			// {
			// 	cout << adj[vis][i] << " ";
			// }
			// cout << endl;
			q.erase(q.begin());

			// For every adjacent vertex to the current vertex
			for (int i = 0; i < adj[vis].size(); i++) {
				if (adj[vis][i] == 1 && (!visited[i])) {

					// Push the adjacent node to the queue
					q.push_back(i);

					// Set
					visited[i] = true;
				}
			}
		}

		//cout << endl;
		num.push_back(nums);
		// for (set<int>::iterator itr = nums.begin(); itr != nums.end(); itr++)
		// {
		// 	cout << *itr << " ";
		// }

		//cout << endl;
	}
}

// Driver code
/**int main()
{
	// number of vertices
	int v = 6;


	// adjacency matrix
	vector<vector<int> > adj= vector< vector<int> >(v,vector<int>(v,0));
	vector<set<int> > num;
	//set<int> nums;

	addEdge(0,0, adj);
	addEdge(1,1, adj);
	addEdge(2,2, adj);
	addEdge(3,3, adj);
	addEdge(4,4, adj);
	addEdge(5,5, adj);
	addEdge(3,0, adj);
	addEdge(4,1, adj);
	addEdge(5,2, adj);
	addEdge(3,2, adj);
	addEdge(1,3, adj);
	addEdge(0,4, adj);
	addEdge(1,5, adj);

	// perform bfs on the graph
	bfs(adj, v, num);
	// cout << "END OF BFS" << endl;
	// for (int i = 0; i < num.size(); i++)
	// {
	// 	for (set<int>::iterator itr = num.at(i).begin(); itr != num.at(i).end(); itr++)
	// 	{
	// 		cout << *itr << " ";
	// 	}

	// 	cout << endl;
	// }

	return 0;
}**/

