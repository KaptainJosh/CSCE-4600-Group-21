#include "knot-detector.hpp"

//Determine if the given graph has a knot
//reachableSets maps a vertex to the set of vertices reachable from that vertex
bool checkForKnots(std::vector<std::set<int> > reachableSets)
{
	//Iterate through every vertex to see if there is a knot at that vertex
	for (int vertex = 0; vertex < reachableSets.size(); vertex++)
	{
		auto reachableSet = reachableSets[vertex];
		bool knotAtVertex = true;
		
		//Check if every vertex reachable from this one has the same reachable set
		for (int reachableVertex : reachableSet)
		{
			auto secondReachableSet = reachableSets[reachableVertex];

			//If the reachable sets are not the same, there is no knot at this vertex
			if (secondReachableSet != reachableSet)
			{
				knotAtVertex = false;
				break;
			}
		}

		//If no reachable sets were different, i.e., all were the same, then there is a knot at this vertex
		//So, return true - no need to do any more work
		if (knotAtVertex)
		{
			return true;
		}
	}

	//If we reached this point, then there wasn't a knot at any vertex
	//So, there's no knot in the graph
	return false;
}