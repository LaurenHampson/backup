#include <fstream>
#include <limits>
#include <map>
#include <vector>

struct Edge
{
	Edge(uint32_t from, uint32_t to, uint32_t weight) 
	: mFrom(from), mTo(to), mWeight(weight) {}
	uint32_t mFrom;
	uint32_t mTo;
<<<<<<< HEAD
	uint32_t mWeight;
=======
	int mWeight;
>>>>>>> 2112a1c24943e92385b44ba3f67f353c3f842e91
};

using Graph = std::vector<Edge>;
using Distances = std::vector<int>;
using Predecessors = std::vector<uint32_t>;

uint32_t readGraph(std::istream& input, Graph& graph)
{
	uint32_t vertCount = 0;
	uint32_t edgeCount = 0;
	input >> vertCount >> edgeCount;

	for (uint32_t i = 0; i < edgeCount; ++i)
	{
		uint32_t u, v;
		int w;
		input >> u >> v >> w;
		graph.push_back(Edge(u, v, w));
	}
	return vertCount;
}

void writePath(std::ostream& output, const Predecessors& predecessors, uint32_t v)
{
	// TODO
<<<<<<< HEAD
	if (v == 0)
	{

		output << 0 << " ";
		return;
	}
	writePath(output, predecessors, predecessors[v]);
	output << v << " ";
	/*for (unsigned int i = 0; i < v; i++)
	{
		output << predecessors[i] << " ";
	}*/

=======
>>>>>>> 2112a1c24943e92385b44ba3f67f353c3f842e91
}

void writeOutput(std::ostream& output, bool cycle, const Distances& distances, const Predecessors& predecessors)
{
	if (cycle)
	{
		output << "error: negative-gas-consumption cycle" << std::endl;
	}
	else if (distances[distances.size() - 1] == std::numeric_limits<int>::max())
	{
		output << "error: no path to campsite" << std::endl;
	}
	else
	{
		output << "path: ";
		writePath(output, predecessors, distances.size() - 1);
		output << std::endl;
		output << "cost: " << distances[distances.size() - 1] << std::endl;
	}
}

bool BellmanFord(const Graph& graph, Distances& distances, Predecessors& predecessors)
{
<<<<<<< HEAD
	/*Input: 
    V: the list of vertices
    E: the list of edges
    src: the start vertex
Output:
    D: the list of shortest distances from src to each vertex
    P: the list of predecessors for each vertex

initialize all distances to be positive infinity
initialzie all predecessors to be None

D[src] = 0

for i from 0 to |V| - 1:
    for each edge (u, v) with weight w in E:
        if D[u] + w < D[v]:
            D[v] = D[u] + w
            P[v] = u

for each edge (u, v) with weight w in E:
    if D[u] + w < D[v]:
        found negative-weight cycle*/

	//graph is the list of edges
	uint32_t src = 0;


	/*for (unsigned int x = 0; x < graph.size(); x++)
	{
		distances[x] = std::numeric_limits<int>::infinity();
		predecessors[x] = 0;

	}*/

	distances[0] = 0;

	for (unsigned int i = 0; i < distances.size(); i++)
	{
		for(unsigned int b = 0; b < graph.size(); b++)
		{
			uint32_t u = graph[b].mFrom;
			uint32_t v = graph[b].mTo;
			if(distances[u] != std::numeric_limits<int>::max() && (distances[u] + (int)graph[b].mWeight) < distances[v])
			{
				distances[v] = distances[u] + (int)graph[b].mWeight;
				predecessors[v] = u;

			}
		}
	}


	for (unsigned int c = 0; c < graph.size(); c++)
	{

			uint32_t u = graph[c].mFrom;
			uint32_t v = graph[c].mTo;
		if(distances[u] != std::numeric_limits<int>::max() &&(distances[u] + (int)graph[c].mWeight) < distances[v])
		{
			return true;
		}
	}
=======
>>>>>>> 2112a1c24943e92385b44ba3f67f353c3f842e91
	// TODO
	return false;
}

int main(int argc, char* argv[])
{
	// read input
	Graph graph;
	std::ifstream input(argv[1]);
	uint32_t vertCount = readGraph(input, graph);
	input.close();

	// find shortest path
	Distances distances(vertCount, std::numeric_limits<int>::max());
	Predecessors predecessors(vertCount, 0);
	bool cycle = BellmanFord(graph, distances, predecessors);

	// write output
	std::ofstream output(argv[2]);
	writeOutput(output, cycle, distances, predecessors);
	output.close();

	return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 2112a1c24943e92385b44ba3f67f353c3f842e91
