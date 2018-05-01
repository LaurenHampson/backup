#include "AdjMatrix.h"

AdjMatrix::AdjMatrix(uint32_t vertexCount)
: mEdges(vertexCount, std::vector<uint32_t>(vertexCount, 0))
{
}

void AdjMatrix::addEdge(uint32_t u, uint32_t v, uint32_t w)
{
	mEdges[u][v] = w;
}

uint32_t AdjMatrix::getEdgeWeight(uint32_t u, uint32_t v) const
{
	//if (mEdges.size() < (u*v))
	//{
	 //   return 0;
//	}
	//else
	//{
		return mEdges[u][v];
	//}
	// TODO
	
	return 0;
}

std::vector<uint32_t> AdjMatrix::getAllIncoming(uint32_t u) const
{
	 std::vector<uint32_t> in;
	//if ((u*u) < mEdges.size())
	//{
    	for (unsigned int i = 0; i < mEdges[u].size(); ++i)
	    {
	        if (mEdges[i][u]>0)
	        {
	            in.push_back(i);
	        }
	    }
	//}
    return in;

}

std::vector<uint32_t> AdjMatrix::getAllOutgoing(uint32_t u) const
{
	std::vector<uint32_t> out;
	if ((u*u) <= mEdges.size())
	{
    	for (unsigned int i = 0; i < mEdges[u].size(); ++i)
	    {
	        if (mEdges[u][i]>0)
	        {
	            out.push_back(i);
	        }
	    }
	}
	return out;
}