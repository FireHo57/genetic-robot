#include <functional>
#include <algorithm>
#include <iostream>

class MechBrain
{
public:
	inline MechBrain(int _magic)
		: mMagic(_magic) {
	}
	inline int magic() const { return mMagic; }
	
private:
	int mMagic;
};

typedef double Score;
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
		ScoredMech scored = _rater(brain);
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

int main(int _argc, char *_argv[])
{
	Mem_Brains brains = { MechBrain(4), MechBrain(-10), MechBrain(94) };
	
	auto scored = GateProtocol(brains,
		[](MechBrain _brain) -> ScoredMech
		{
			ScoredMech result(_brain.magic(), _brain);
			return result;
		}
	);
	
	for(auto s : scored)
	{
		std::cout << s.first << std::endl;
	}
	
	return 0;
}

