#pragma once
#include <includes.h>
#include <globals.h>

using namespace globals;


class TFunction {
private:
	struct tFuncs {
		UObject** tFunc;
		std::string tFuncName;
		std::string tFuncDesc = "";
	};

	std::vector<tFuncs> funcs;
	bool bInit = false;

public:
	void Init();
	void Update();
	void Notify(std::string msg);
};

void TFunction::Init() {
	funcs = {

		{ &tfuncs::ReSkillEvent_C, "Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify", "Multihit or godmode" },

	};

	this->Update();
}


void TFunction::Update()
{
	do {
		if (World) {
			for (auto& f : funcs) {
				*f.tFunc = World->FindObject(f.tFuncName.c_str());
			}
			Notify("TFunctions initialized");
			bInit = true;
		}
	} while (!bInit);
}

void TFunction::Notify(std::string msg)
{
#ifdef LOG_INFO
	LOG_INFO("%s", msg.c_str());
#else
	printf("%s\n", msg.c_str());
#endif
}

