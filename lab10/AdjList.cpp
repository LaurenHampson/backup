#include "AdjList.h"

AdjList::AdjList(uint32_t vertexCount)
: mEdges(vertexCount)
{
}

void AdjList::addEdge(uint32_t u, uint32_t v, uint32_t w)
{
	mEdges[u].insert(std::make_pair(v, w));
}

uint32_t AdjList::getEdgeWeight(uint32_t u, uint32_t v) const
{
	// TODO
	std::map<uint32_t, uint32_t>::const_iterator it = mEdges[u].find(v);
	
		return it->second;
	
	return 0;
}

std::vector<uint32_t> AdjList::getAllIncoming(uint32_t u) const
{
	std::vector<uint32_t> in;
	// TODO
	for (unsigned int i = 0; i < mEdges.size(); ++i)
	{
		for (std::map<uint32_t, uint32_t>::const_iterator it = mEdges[i].begin();
        it != mEdges[i].end(); ++it)
		{
			if (it->first == u)
			{
				in.push_back(i);
			}
		}
	}
	return in;
}

std::vector<uint32_t> AdjList::getAllOutgoing(uint32_t u) const
{
	std::vector<uint32_t> out;
	//std::map<uint32_t, uint32_t>::const_iterator it = mEdges[u].begin();
	for (std::map<uint32_t, uint32_t>::const_iterator it = mEdges[u].begin();
        it != mEdges[u].end(); ++it)
		out.push_back(it->first);
	// TODO
	return out;
}