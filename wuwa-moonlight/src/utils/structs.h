
namespace structs {

struct Distance
{
	float Min;
	float Max;
	float Current;

	Distance(float Min = 0.0, float Max = 10000.0, float Current = 1000) : Min(Min), Max(Max), Current(Current) {}
};


template<typename T>
struct MinMax
{
	T Min;
	T Max; 
	T Current;

	MinMax(T Min = T{}, T Max = T{}, T Current = T{}) : Min(Min), Max(Max), Current(Current) {}
};

}
