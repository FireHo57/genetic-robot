#include <functional>
#include <iostream>
#include <stdint.h>
#include <memory>
#include <vector>

class Mech
{
public:
	typedef std::unique_ptr<Mech> u_ptr;
	
public:
	inline double awesomeness() const { return 999999.0; }
};

typedef double Score;
typedef std::pair<Score,Mech::u_ptr> ScoredMech;
typedef std::function<ScoredMech(Mech::u_ptr)> FitnessFunction;
typedef std::vector<Mech::u_ptr> MechCollection;
typedef std::vector<ScoredMech> ScoredMechs;

ScoredMech ScoreMechFitness(Mech::u_ptr _mech)
{
	ScoredMech result(0, std::move(_mech));
	
	result.first += result.second->awesomeness();
	// modify result.first (the score) some more
	
	return result;
}

ScoredMechs GetBestMechs(MechCollection &_mechs, FitnessFunction _fn)
{
	ScoredMechs scored;
	ScoredMechs result;
	
	for(auto &mech : _mechs)
	{
		ScoredMech scoredMech = _fn(std::move(mech));
		scored.push_back(scoredMech);
	}
	
	// sort scored
	
	// get the first <so many results>
	
	return result;
}

MechCollection GenerateMechCollection()
{
	MechCollection result;
	return result;
}

int main(int _argc, char *_argv[])
{
	MechCollection mechs = GenerateMechCollection();
	
	ScoredMechs best = GetBestMechs(mechs, ScoreMechFitness);
	
	// do stuff with best
	
	return 0;
}

