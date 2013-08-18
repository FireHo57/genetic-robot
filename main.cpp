#include <functional>
#include <algorithm>

typedef double Score;
//define mechbrain
typedef std::pair<Score,MechBrain> ScoredMech; 
typedef std::function<ScoredMech(MechBrain)> Rater;
typedef std::vector<MechBrain> Mem_Brains;
typedef std::vector<ScoredMech> Scored_Mem_Brains;
typedef std::function<Mem_Brains(Scored_Mem_Brains)> GodProtocol;

Scored_Mem_Brains GateProtocol(const Mem_Brains &_brains, Rater _rater)
{
	Scored_Mem_Brains result;
	
	for(auto &brain : _brains)
	{
		ScoredMech scored(_rater(brain), brain);
		result.push_back(scored);
	}
	
	std::sort(result.begin(), result.end(),
		[](const ScoredMech &_left, const ScoredMech &_right) 
		{
			return (_left.first < _right.first);
		}
	);
	
	return result;
}


