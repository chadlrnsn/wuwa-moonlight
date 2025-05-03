
namespace structs {

struct Distance
{
	float Min;
	float Max;
	float Current;

	Distance(float Min = 0.0, float Max = 10000.0, float Current = 1000) : Min(Min), Max(Max), Current(Current) {}
};

struct MinMax
{
	float Min;
	float Max;
	float Current;

	MinMax(float Min = 0.0, float Max = 100, float Current = 0) : Min(Min), Max(Max), Current(Current) {}
};

}
